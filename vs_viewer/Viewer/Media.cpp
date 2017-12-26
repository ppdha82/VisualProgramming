#include "StdAfx.h"
#include "Media.h"

///////////////////////////////////////////////////////////
// class CFrame
CFrame::CFrame(void)
{
	m_pData				= NULL;
	m_lDataSize			= 0;

	framecnt = 0;

	DestroyBuffer();
}

CFrame::~CFrame(void)
{
	if( m_pData )
	{
		delete [] m_pData;
		m_pData = NULL;
	}
}

BOOL	CFrame::CreateBuffer(unsigned long lSize)
{
	DestroyBuffer();

	m_pData = new unsigned char[lSize];
	if( m_pData )
	{
		m_lDataSize = lSize;
		return TRUE;
	}

	return FALSE;
}

BOOL	CFrame::DestroyBuffer(void)
{
	int i = 0;

	if( m_pData )
	{
		delete [] m_pData;
		m_pData = NULL;
	}

	m_lDataSize = 0;
	for( i=0; i<MAX_NUM_OF_EVENTS; i++ )
		m_dspTable[i] = CRect(CPoint(0, 0), CSize(0, 0));

	return TRUE;
}

BOOL	CFrame::CloneFrame(CFrame * pFrame)
{
	if( !pFrame )
		return FALSE;

	DestroyBuffer();

	CreateBuffer(pFrame->m_lDataSize);
	//m_inx = pFrame->m_inx;
	memcpy((void*)m_pData, (const void*)pFrame->m_pData, pFrame->m_lDataSize);

	return TRUE;
}

BOOL	CFrame::GetStream(unsigned char ** ppBuffer, unsigned long * pLength)
{
	if( ppBuffer && pLength &&
		m_pData	&& m_lDataSize )
	{
		*ppBuffer	= (unsigned char*)(m_pData);
		*pLength	= m_lDataSize;//m_inx.framesize;

		return TRUE;
	}

	return FALSE;
}

BOOL CreateMedia(const CString strFName, IMedia ** ppMedia)
{
	CString strT = strFName;
	strT.MakeLower();
	if( strT.Find(".h264") != -1 )
	{
		CMediaH264 * pMedia = new CMediaH264;
		if( !pMedia->SetMediaFile(strFName) )
		{
			delete pMedia;
			return FALSE;
		}
		*ppMedia = (IMedia*)pMedia;
	}
	else if( strT.Find(".ssf") != -1 )
	{
		CMediaSSF * pMedia = new CMediaSSF;
		if( !pMedia->SetMediaFile(strFName) )
		{
			delete pMedia;
			return FALSE;
		}
		*ppMedia = (IMedia*)pMedia;
	}
	else if( strT.Find(".vs") != -1 )
	{
		CMediaVS * pMedia = new CMediaVS;
		if( !pMedia->SetMediaFile(strFName) )
		{
			delete pMedia;
			return FALSE;
		}
		*ppMedia = (IMedia*)pMedia;
	}
	else
	{
		ASSERT(0);
		return FALSE;
	}

	return TRUE;
}

BOOL DestroyMedia(IMedia ** ppMedia)
{
	ASSERT(ppMedia);

	if( !ppMedia )
		return FALSE;

	ASSERT(*ppMedia);

	if( !(*ppMedia) )
		return FALSE;

	switch((*ppMedia)->GetMediaType())
	{
	case IMedia::MEDIA_H264:
		delete (CMediaH264*)*ppMedia;
		break;
	case IMedia::MEDIA_SSF:
		delete (CMediaSSF*)*ppMedia;
		break;
	case IMedia::MEDIA_VS:
		delete (CMediaVS*)*ppMedia;
		break;
	default:
		ASSERT(0);
		return FALSE;
	}

	*ppMedia = NULL;

	return TRUE;
}

///////////////////////////////////////////////////////////
// class CMediaH264
CMediaH264::CMediaH264(void)
{
}


CMediaH264::~CMediaH264(void)
{
	if( _m_fMedia.m_hFile != CFile::hFileNull )
		_m_fMedia.Close();
	if( _m_fMediaTxt )
		fclose(_m_fMediaTxt);
}

BOOL CMediaH264::SetMediaFile(CString strMediaFile)
{
	strMediaFile.MakeLower();
	if( strMediaFile.Find(".h264") == -1 )
		return FALSE;

	if( _m_fMedia.m_hFile != CFile::hFileNull )
		_m_fMedia.Close();

	if( !_m_fMedia.Open(strMediaFile.operator LPCTSTR(), CFile::modeRead) )
		return FALSE;

	// txt
	_m_fMediaTxt = NULL;
	if( _m_fMediaTxt )
		fclose(_m_fMediaTxt);
	strMediaFile += ".txt";
	_m_fMediaTxt = fopen(strMediaFile.operator LPCTSTR(), "rt");

	if( !_m_fMediaTxt )
		return FALSE;
	
	return TRUE;
}

BOOL CMediaH264::GetNextStream(CFrame ** ppFrame)
{
	int param1, param2;
	if( fscanf(_m_fMediaTxt, "%d %d", &param1, &param2) == EOF )
		return FALSE;

	CFrame * pFrame = new CFrame;

	ASSERT(pFrame);

	if( !pFrame )
		return FALSE;

	pFrame->m_lDataSize = param2;
	if( !pFrame->CreateBuffer(pFrame->m_lDataSize) )
		return FALSE;

	UINT count = _m_fMedia.Read((void*)pFrame->m_pData, pFrame->m_lDataSize);
	*ppFrame = pFrame;

	return TRUE;
}


///////////////////////////////////////////////////////////
// class CMediaSSF
#include "pes_header.h"

CMediaSSF::CMediaSSF(void)
{
}


CMediaSSF::~CMediaSSF(void)
{
	if( _m_fMedia.m_hFile != CFile::hFileNull )
		_m_fMedia.Close();
}

BOOL CMediaSSF::SetMediaFile(CString strMediaFile)
{
	strMediaFile.MakeLower();
	if( strMediaFile.Find(".ssf") == -1 )
		return FALSE;

	if( _m_fMedia.m_hFile != CFile::hFileNull )
		_m_fMedia.Close();

	if( !_m_fMedia.Open(strMediaFile.operator LPCTSTR(), CFile::modeRead | CFile::shareDenyNone) )
		return FALSE;
	
	return TRUE;
}

#define SSF_HDR_SIZE   (PES_VIDEO_HEADER_SIZE)
BOOL CMediaSSF::GetNextStream(CFrame ** ppFrame)
{
	BOOL bRtn = FALSE;
	CFrame * pFrame = new CFrame;

	ASSERT(pFrame);

	if( !pFrame )
		return FALSE;

	unsigned char hdr[SSF_HDR_SIZE];
	do
	{
		if( _m_fMedia.Read(hdr, SSF_HDR_SIZE) )
		{
			unsigned long sCode = packet_start_code((const unsigned char*)hdr);
			unsigned int hdrsize = pes_header_size((const unsigned char*)hdr);
			if( pes_is_video_frame((const unsigned char*)hdr) )
			{
				unsigned int packetsize = current_packet_length((const unsigned char*)hdr);

				pFrame->time = pes_timestamp_sec((const unsigned char*)hdr);
				pFrame->millitm = pes_timestamp_usec((const unsigned char*)hdr);
				pFrame->m_lDataSize = packetsize - hdrsize;

				if( !pFrame->CreateBuffer(pFrame->m_lDataSize) )
					break;
				UINT count = _m_fMedia.Read((void*)pFrame->m_pData, pFrame->m_lDataSize);
				*ppFrame = pFrame;

				bRtn = TRUE;
			}
			else
			{
				ASSERT(0);
				break;
			}
		}
	} while(0);

	if( !bRtn )
	{
		if( pFrame )
			delete pFrame;
	}

	return bRtn;
}


///////////////////////////////////////////////////////////
// class CMediaVS
//#include "pes_header.h"
#include "SrnDspTable.h"

CMediaVS::CMediaVS(void)
{
}


CMediaVS::~CMediaVS(void)
{
	if( _m_fMedia.m_hFile != CFile::hFileNull )
		_m_fMedia.Close();
}

BOOL CMediaVS::SetMediaFile(CString strMediaFile)
{
	strMediaFile.MakeLower();
	if( strMediaFile.Find(".vs") == -1 )
		return FALSE;

	if( _m_fMedia.m_hFile != CFile::hFileNull )
		_m_fMedia.Close();

	if( !_m_fMedia.Open(strMediaFile.operator LPCTSTR(), CFile::modeRead | CFile::shareDenyNone) )
		return FALSE;
	
	return TRUE;
}

BOOL CMediaVS::GetNextStream(CFrame ** ppFrame)
{
	BOOL bRtn = FALSE;
	CFrame * pFrame = new CFrame;

	ASSERT(pFrame);

	if( !pFrame )
		return FALSE;

	unsigned char hdr[SSF_HDR_SIZE];
	do
	{
		// PES Header + Video Data + DSP Table *15
		if( _m_fMedia.Read(hdr, SSF_HDR_SIZE) )
		{
			unsigned long sCode = packet_start_code((const unsigned char*)hdr);
			unsigned int hdrsize = pes_header_size((const unsigned char*)hdr);
			if( pes_is_video_frame((const unsigned char*)hdr) )
			{
				unsigned int packetsize = current_packet_length((const unsigned char*)hdr);

				pFrame->time = pes_timestamp_sec((const unsigned char*)hdr);
				pFrame->millitm = pes_timestamp_usec((const unsigned char*)hdr);
				pFrame->m_lDataSize = packetsize - SSF_HDR_SIZE/*hdrsize*/ - sizeof(DspTable)*MAX_NUM_OF_EVENTS;

				if( !pFrame->CreateBuffer(pFrame->m_lDataSize) )
				{
					ASSERT(0);
					break;
				}

				if( pFrame->m_lDataSize != _m_fMedia.Read((void*)pFrame->m_pData, pFrame->m_lDataSize) )
				{
					ASSERT(0);
					break;
				}

				DspTable dsp_t[MAX_NUM_OF_EVENTS];
				if( sizeof(DspTable)*MAX_NUM_OF_EVENTS != _m_fMedia.Read((void*)dsp_t, sizeof(DspTable)*MAX_NUM_OF_EVENTS) )
				{
					ASSERT(0);
					break;
				}

				// big-endian to little-endian
				#define		BSWAP_16(x)		( (((x)>>8)&0x00FF) | (((x)<<8)&0xFF00) )
				#define		BSWAP_32(x)		((( (( (x) <<8)&0xFF00FF00)|(( (x) >>8)&0x00FF00FF))>>16 ) | (( (( (x) <<8)&0xFF00FF00)|(( (x) >>8)&0x00FF00FF))<<16) )
				for( int i=0; i<MAX_NUM_OF_EVENTS; i++ )
				{
					dsp_t[i].d.mLocalTimeMS;
					dsp_t[i].d.mFrameTimeMS;
					dsp_t[i].d.mSummaryTime;
					dsp_t[i].d.mX = BSWAP_16(dsp_t[i].d.mX);
					dsp_t[i].d.mY = BSWAP_16(dsp_t[i].d.mY);
					dsp_t[i].d.mWidth	= BSWAP_16(dsp_t[i].d.mWidth);
					dsp_t[i].d.mHeight	= BSWAP_16(dsp_t[i].d.mHeight);
					dsp_t[i].d.mEventId	= BSWAP_32(dsp_t[i].d.mEventId);
					dsp_t[i].d.mUseage	= (FRAME_USAGE)BSWAP_32(dsp_t[i].d.mUseage);

					if( dsp_t[i].d.mUseage == use_frame )
					{
						pFrame->m_dspTable[i] = CRect(
													CPoint(dsp_t[i].d.mX, dsp_t[i].d.mY),
													CSize(dsp_t[i].d.mWidth, dsp_t[i].d.mHeight));
					}
				}

				*ppFrame = pFrame;

				bRtn = TRUE;
			}
			else
			{
				// end of file
				ASSERT(0);
				break;
			}
		}
	} while(0);

	if( !bRtn )
	{
		if( pFrame )
			delete pFrame;
	}

	return bRtn;
}

