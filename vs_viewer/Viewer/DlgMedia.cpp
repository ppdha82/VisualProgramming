// DlgMedia.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Viewer.h"
#include "DlgMedia.h"
#include "afxdialogex.h"
#include "Media.h"
#include "VideoDecompress.h"

#define TIMER_MEDIA		(1004)
#define	SCALE_FACTOR	(1)//2)

// CDlgMedia 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMedia, CDialogEx)

CDlgMedia::CDlgMedia(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMedia::IDD, pParent)
{
	_m_pMedia = NULL;
	_m_pVDec = NULL;
	framecnt = 0;
}

CDlgMedia::~CDlgMedia()
{
	if( _m_pMedia )
		::DestroyMedia(&_m_pMedia);
}

void CDlgMedia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMedia, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgMedia::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgMedia::OnBnClickedCancel)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlgMedia 메시지 처리기입니다.


void CDlgMedia::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
}


void CDlgMedia::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


BOOL CDlgMedia::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetTimer(TIMER_MEDIA, 100, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CDlgMedia::SetMediaFileName(CString strFName)
{
	if( ::CreateMedia(strFName, &_m_pMedia) )
	{
		return TRUE;
	}

	return FALSE;
}


BOOL CDlgMedia::DestroyWindow()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	KillTimer(TIMER_MEDIA);

	return CDialogEx::DestroyWindow();
}

BOOL CDlgMedia::_Output(CFrame * pFrame, CDC * pDC)
{
	CSize sizeSrc = _m_dib.GetBitmapSize();

	if( !pDC )
	{
		CDC * pDC = GetDC();
		_m_dib.StretchDIBits(pDC,
					0, 0, sizeSrc.cx/SCALE_FACTOR, sizeSrc.cy/SCALE_FACTOR,
					//0, 0, sizeSrc.cx, sizeSrc.cy);
					0, sizeSrc.cy, sizeSrc.cx, -1*sizeSrc.cy);	// 상하반전
		for( int i=0; i<15; i++ )
		{
			CBrush brush = RGB(0, 0, 255);
			pDC->FrameRect(&pFrame->m_dspTable[i], &brush);
		}
		CString str;
		str.Format("%d.%.3d", pFrame->time, pFrame->millitm/1000);
		str.Append(_T(" no pDC"));
		pDC->TextOut(0, 0, str);

		CString localTime;
		SYSTEMTIME systime;
		GetLocalTime(&systime);
		localTime.Format("%d:%d:%d + frame %d", systime.wMinute, systime.wSecond, systime.wMilliseconds, pFrame->framecnt);
		pDC->TextOut(0, 20, localTime);

		ReleaseDC(pDC);
	}
	else
	{
		_m_dib.StretchDIBits(pDC,
					0, 0, sizeSrc.cx/SCALE_FACTOR, sizeSrc.cy/SCALE_FACTOR,
					//0, 0, sizeSrc.cx, sizeSrc.cy);
					0, sizeSrc.cy, sizeSrc.cx, -1*sizeSrc.cy);	// 상하반전
		CRect  rc(10, 10, 40, 40);
		CBrush brush = RGB(0, 0, 255);
		pDC->FrameRect(&rc, &brush);
		CString str;
		str.Format("%d.%.3d", pFrame->time, pFrame->millitm/1000);
		str.Append(_T(" pDC"));
		pDC->TextOut(0, 0, str);
	}

	return TRUE;
}

void CDlgMedia::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if( nIDEvent == TIMER_MEDIA )
	{
		if( _m_pMedia )
		{
			CFrame * pFrame = NULL;
			if( _m_pMedia->GetNextStream(&pFrame) )
			{
				// display
				if( !_m_pVDec )
				{
					if( ::VideoDecompressCreate(VLT_FFMPEG, &_m_pVDec) )
					{
						ST_VIDEO_DECOMPRESS_INIT	st_init;

						st_init.codectype	= VCT_H264;
						if( !_m_pVDec->InitDecompress(&st_init) )
						{
							 ::VideoDecompressDestroy(_m_pVDec);
							 _m_pVDec = NULL;
						}
					}
				}

				if( _m_pVDec )
				{
					unsigned char * pBuffer = NULL;
					unsigned long lLength = 0;
					if( pFrame->GetStream(&pBuffer, &lLength) )
					{
						ST_VIDEO_DECOMPRESS_RESULT decResult;
						if( _m_pVDec->Decompress(pBuffer, lLength, &decResult) )
						{
							CSize size = _m_dib.GetBitmapSize();
							if( size != decResult.dimention )
							{
								_m_dib.CloseBMP();
								_m_dib.Create(decResult.dimention.cx, decResult.dimention.cy, 24);
								SetWindowPos(NULL, 0, 0, decResult.dimention.cx/SCALE_FACTOR, decResult.dimention.cy/SCALE_FACTOR, SWP_NOMOVE);
							}

							YUV2RGB((BYTE*)_m_dib.GetBitmapImage(),
									decResult.pImageBuffer[0], decResult.pImageBuffer[2], decResult.pImageBuffer[1],
									decResult.dimention.cx, decResult.dimention.cy,
									decResult.dimention.cx*3,
									decResult.image_linesize[0],
									decResult.image_linesize[1]);

							framecnt++;
							pFrame->framecnt = framecnt;

							_Output(pFrame, NULL);
						}
						else
							ASSERT(0);
					}
				}

				delete pFrame;
			}
			else
			{
				TRACE("Error GetNextStream !!\n");
				KillTimer(TIMER_MEDIA);
			}
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}
