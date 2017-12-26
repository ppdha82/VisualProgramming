#include "StdAfx.h"
#include "VideoDecompress.h"

BOOL	VideoDecompressCreate(VIDEO_LIB_TYPE libtype, IVideoDecompress ** ppDecompress)
{
	if( !ppDecompress )
		return FALSE;

	*ppDecompress = (IVideoDecompress*)new CVideoDecompressFFMpeg;

	return TRUE;
}

BOOL	VideoDecompressDestroy(IVideoDecompress * pDecompress)
{
	if( !pDecompress )
		return FALSE;

	delete (CVideoDecompressFFMpeg*)pDecompress;

	return TRUE;
}


CVideoDecompressFFMpeg::CVideoDecompressFFMpeg(void)
{
	::ZeroMemory(&m_init, sizeof(ST_VIDEO_DECOMPRESS_INIT));
}

CVideoDecompressFFMpeg::~CVideoDecompressFFMpeg(void)
{
}

//virtual
BOOL	CVideoDecompressFFMpeg::InitDecompress(ST_VIDEO_DECOMPRESS_INIT * pDecInit)
{
	if( !pDecInit )
	{
		ASSERT(0);
		return FALSE;
	}
	if( pDecInit->codectype == VCT_H264 )
	{
		if( (avCodec = avcodec_find_decoder(CODEC_ID_H264)) == NULL )
			return FALSE;
	}
	else if( pDecInit->codectype == VCT_JPEG )
	{
		if( (avCodec = avcodec_find_decoder(CODEC_ID_MJPEG)) == NULL )
			return FALSE;
	}
	else
		return FALSE;
	m_init	= *pDecInit;

	if( (avcCtx = avcodec_alloc_context()) == NULL )
		return FALSE;

	if (avcodec_open (avcCtx, avCodec) < 0)
		return FALSE;

	if( (avFrm = avcodec_alloc_frame()) == NULL )
		return FALSE;

	return TRUE;
}

//virtual
BOOL	CVideoDecompressFFMpeg::ReleaseDecompress(void)
{
	::ZeroMemory(&m_init, sizeof(ST_VIDEO_DECOMPRESS_INIT));

	return TRUE;
}

//virtual
BOOL	CVideoDecompressFFMpeg::Decompress(unsigned char * pBuffer, int nSize, ST_VIDEO_DECOMPRESS_RESULT * pDecResult)
{
	int nReturn			= -1;
	int got_picture_ptr	= 0;

	nReturn = avcodec_decode_video(avcCtx, avFrm, &got_picture_ptr, (const uint8_t *)pBuffer, nSize);
	if( nReturn > 0 )
	{
		if( pDecResult )
		{
			pDecResult->dimention.cx	= avcCtx->width;
			pDecResult->dimention.cy	= avcCtx->height;
			pDecResult->videoformat		= VF_YUV411;
			memcpy((void*)pDecResult->pImageBuffer, (const void*)avFrm->data, sizeof(uint8_t*)*4);
			memcpy((void*)pDecResult->image_linesize, (const void*)avFrm->linesize, sizeof(int)*4);
			pDecResult->nBufferSize		= avcCtx->width * avcCtx->height * 3 / 2;
		}

		return TRUE;
	}

	return FALSE;
}

