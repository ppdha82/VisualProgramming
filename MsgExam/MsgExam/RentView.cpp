// RentView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "RentView.h"


// CRentView

IMPLEMENT_DYNCREATE(CRentView, CFormView)

CRentView::CRentView()
	: CFormView(CRentView::IDD)
{

}

CRentView::~CRentView()
{
}

void CRentView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRentView, CFormView)
END_MESSAGE_MAP()


// CRentView �����Դϴ�.

#ifdef _DEBUG
void CRentView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CRentView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRentView �޽��� ó�����Դϴ�.
