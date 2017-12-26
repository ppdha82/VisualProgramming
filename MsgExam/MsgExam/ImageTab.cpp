// ImageTab.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ImageTab.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"


// CImageTab

IMPLEMENT_DYNAMIC(CImageTab, CPropertySheet)

CImageTab::CImageTab(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	m_Parent = pParentWnd;
	AddPage(&ImageChangePage);
	AddPage(&ImageResizePage);
}

CImageTab::CImageTab(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_Parent = pParentWnd;
	AddPage(&ImageChangePage);
	AddPage(&ImageResizePage);
}

CImageTab::~CImageTab()
{
}


BEGIN_MESSAGE_MAP(CImageTab, CPropertySheet)
	ON_BN_CLICKED(IDCANCEL_TEST9_01, &CImageTab::OnBnClickedTest901)
END_MESSAGE_MAP()


// CImageTab �޽��� ó�����Դϴ�.

void CImageTab::OnBnClickedTest901()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMsgExamView *pView;
	pView=(CMsgExamView *)m_Parent;
	pView->ImageTabSheet = NULL;    
	DestroyWindow();
	delete this;
	CPropertySheet::OnClose();
}
