// RightView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "RightView.h"


// CRightView

IMPLEMENT_DYNCREATE(CRightView, CListView)

CRightView::CRightView()
{

}

CRightView::~CRightView()
{
}

BEGIN_MESSAGE_MAP(CRightView, CListView)
END_MESSAGE_MAP()


// CRightView �����Դϴ�.

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CRightView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRightView �޽��� ó�����Դϴ�.
