// MiddleView.cpp : ���� �����Դϴ�.
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


// CMiddleView �׸����Դϴ�.

void CMiddleView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CMiddleView �����Դϴ�.

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


// CMiddleView �޽��� ó�����Դϴ�.
