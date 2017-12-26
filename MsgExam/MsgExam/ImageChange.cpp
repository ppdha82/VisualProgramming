// ImageChange.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ImageChange.h"
#include "ImageTab.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "afxdialogex.h"


// CImageChange 대화 상자입니다.

IMPLEMENT_DYNAMIC(CImageChange, CPropertyPage)

CImageChange::CImageChange()
	: CPropertyPage(CImageChange::IDD)
	, imageNumber(0)
{

}

CImageChange::~CImageChange()
{
}

void CImageChange::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_PICTURE_1, imageNumber);
}


BEGIN_MESSAGE_MAP(CImageChange, CPropertyPage)
	ON_BN_CLICKED(ID_OK_TEST9_01, &CImageChange::OnBnClickedOkTest901)
END_MESSAGE_MAP()


// CImageChange 메시지 처리기입니다.


void CImageChange::OnBnClickedOkTest901()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CImageTab *pParWnd = (CImageTab*)this->GetParent();
    CMsgExamView *pView = (CMsgExamView  *)pParWnd->m_Parent;
	pView->imageNumber = this->imageNumber;
	pView->Invalidate();
}

