// MyDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// CMyDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDlg::IDD, pParent)
	, m_strName(_T(""))
	, m_strHPhone(_T(""))
	, m_strEmail(_T(""))
{

}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_EMAIL, m_strEmail);
	DDX_Text(pDX, IDC_HPHONE, m_strHPhone);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyDlg �޽��� ó�����Դϴ�.
