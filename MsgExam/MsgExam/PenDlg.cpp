// PenDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "PenDlg.h"
#include "afxdialogex.h"


// CPenDlg ��ȭ �����Դϴ�.

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


// CPenDlg �޽��� ó�����Դϴ�.
