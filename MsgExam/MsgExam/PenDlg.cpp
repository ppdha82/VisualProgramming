// PenDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "PenDlg.h"
#include "afxdialogex.h"


// CPenDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPenDlg, CPropertyPage)

CPenDlg::CPenDlg()
	: CPropertyPage(CPenDlg::IDD)
	, m_nPenStyle(0)
{

}

CPenDlg::~CPenDlg()
{
}

void CPenDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nPenStyle);
}


BEGIN_MESSAGE_MAP(CPenDlg, CPropertyPage)
END_MESSAGE_MAP()


// CPenDlg 메시지 처리기입니다.
