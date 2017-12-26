// ImageTab.cpp : 구현 파일입니다.
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


// CImageTab 메시지 처리기입니다.

void CImageTab::OnBnClickedTest901()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMsgExamView *pView;
	pView=(CMsgExamView *)m_Parent;
	pView->ImageTabSheet = NULL;    
	DestroyWindow();
	delete this;
	CPropertySheet::OnClose();
}
