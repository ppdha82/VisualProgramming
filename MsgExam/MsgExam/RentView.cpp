// RentView.cpp : 구현 파일입니다.
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


// CRentView 진단입니다.

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


// CRentView 메시지 처리기입니다.
