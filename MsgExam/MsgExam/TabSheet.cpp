// TabSheet.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "TabSheet.h"


// CTabSheet

IMPLEMENT_DYNAMIC(CTabSheet, CPropertySheet)

CTabSheet::CTabSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_PenPage);
	AddPage(&m_BrushPage);
}

CTabSheet::CTabSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_PenPage);
	AddPage(&m_BrushPage);
}

CTabSheet::~CTabSheet()
{
}


BEGIN_MESSAGE_MAP(CTabSheet, CPropertySheet)
END_MESSAGE_MAP()


// CTabSheet �޽��� ó�����Դϴ�.
