// MiddleView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "MiddleView.h"


// CMiddleView

IMPLEMENT_DYNCREATE(CMiddleView, CView)

CMiddleView::CMiddleView()
{

}

CMiddleView::~CMiddleView()
{
}

BEGIN_MESSAGE_MAP(CMiddleView, CView)
END_MESSAGE_MAP()


// CMiddleView 그리기입니다.

void CMiddleView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CMiddleView 진단입니다.

#ifdef _DEBUG
void CMiddleView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CMiddleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMiddleView 메시지 처리기입니다.
