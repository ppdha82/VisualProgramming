// MyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// CMyDlg 대화 상자입니다.

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


// CMyDlg 메시지 처리기입니다.
