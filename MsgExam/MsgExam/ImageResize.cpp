// ImageResize.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ImageResize.h"
#include "ImageTab.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "afxdialogex.h"


// CImageResize 대화 상자입니다.

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


// CImageResize 메시지 처리기입니다.
void CImageResize::OnBnClickedTest901Resize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CImageTab *pParWnd = (CImageTab*)this->GetParent();
    CMsgExamView *pView = (CMsgExamView  *)pParWnd->m_Parent;
	pView->imageResolution = this->resolutionResize;
	pView->Invalidate();
}




void CImageResize::OnBnClickedTest901CancelResize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CImageTab *pParWnd = (CImageTab*)this->GetParent();
    CMsgExamView *pView = (CMsgExamView  *)pParWnd->m_Parent;
	pView->ImageTabSheet = NULL;
	DestroyWindow();
}
