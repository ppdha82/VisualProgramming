// VideoView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "VideoView.h"


// CVideoView

IMPLEMENT_DYNCREATE(CVideoView, CFormView)

CVideoView::CVideoView()
	: CFormView(CVideoView::IDD)
{

}

CVideoView::~CVideoView()
{
}

void CVideoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVideoView, CFormView)
END_MESSAGE_MAP()


// CVideoView 진단입니다.

#ifdef _DEBUG
void CVideoView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CVideoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CVideoView 메시지 처리기입니다.
