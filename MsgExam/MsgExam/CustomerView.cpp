// CustomerView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "CustomerView.h"


// CCustomerView

IMPLEMENT_DYNCREATE(CCustomerView, CFormView)

CCustomerView::CCustomerView()
	: CFormView(CCustomerView::IDD)
{

}

CCustomerView::~CCustomerView()
{
}

void CCustomerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCustomerView, CFormView)
END_MESSAGE_MAP()


// CCustomerView 진단입니다.

#ifdef _DEBUG
void CCustomerView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCustomerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCustomerView 메시지 처리기입니다.
