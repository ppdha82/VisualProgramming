// ImageChange.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ImageChange.h"
#include "ImageTab.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "afxdialogex.h"


// CImageChange ��ȭ �����Դϴ�.

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


// CImageChange �޽��� ó�����Դϴ�.


void CImageChange::OnBnClickedOkTest901()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CImageTab *pParWnd = (CImageTab*)this->GetParent();
    CMsgExamView *pView = (CMsgExamView  *)pParWnd->m_Parent;
	pView->imageNumber = this->imageNumber;
	pView->Invalidate();
}

