// Info.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "Info.h"
#include "afxdialogex.h"


// CInfo ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInfo, CDialogEx)

CInfo::CInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInfo::IDD, pParent)
	, m_strName(_T(""))
	, m_strHP(_T(""))
	, m_strEmail(_T(""))
{

}

CInfo::~CInfo()
{
}

void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_HP, m_strHP);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_Control(pDX, IDC_EDIT_MEMO, c_Memo);
}


BEGIN_MESSAGE_MAP(CInfo, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_DONE, &CInfo::OnBnClickedButtonDone)
END_MESSAGE_MAP()


// CInfo �޽��� ó�����Դϴ�.


void CInfo::OnBnClickedButtonDone()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CString temp;

	temp = " �̸� : ";
	temp += m_strName;
	temp += "\r\n �ڵ��� ��ȣ : ";
	temp += m_strHP;
	temp += "\r\n �̸��� : ";
	temp += m_strEmail;
	m_strName.Empty();
	m_strHP.Empty();
	m_strEmail.Empty();
	UpdateData(FALSE);
	c_Memo.SetWindowText(temp);
}
