// ImageResize.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ImageResize.h"
#include "ImageTab.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "afxdialogex.h"


// CImageResize ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CImageResize, CPropertyPage)

CImageResize::CImageResize()
	: CPropertyPage(CImageResize::IDD)
	, resolutionResize(0)
{

}

CImageResize::~CImageResize()
{
}

void CImageResize::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, resolutionResize);
}


BEGIN_MESSAGE_MAP(CImageResize, CPropertyPage)
	ON_BN_CLICKED(IDOK_TEST9_01_RESIZE, &CImageResize::OnBnClickedTest901Resize)
	ON_BN_CLICKED(ID_TEST9_01_CANCEL_RESIZE, &CImageResize::OnBnClickedTest901CancelResize)
END_MESSAGE_MAP()


// CImageResize �޽��� ó�����Դϴ�.
void CImageResize::OnBnClickedTest901Resize()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CImageTab *pParWnd = (CImageTab*)this->GetParent();
    CMsgExamView *pView = (CMsgExamView  *)pParWnd->m_Parent;
	pView->imageResolution = this->resolutionResize;
	pView->Invalidate();
}




void CImageResize::OnBnClickedTest901CancelResize()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CImageTab *pParWnd = (CImageTab*)this->GetParent();
    CMsgExamView *pView = (CMsgExamView  *)pParWnd->m_Parent;
	pView->ImageTabSheet = NULL;
	DestroyWindow();
}
