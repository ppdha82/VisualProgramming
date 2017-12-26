// Info.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "Info.h"
#include "afxdialogex.h"


// CInfo 대화 상자입니다.

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


// CInfo 메시지 처리기입니다.


void CInfo::OnBnClickedButtonDone()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString temp;

	temp = " 이름 : ";
	temp += m_strName;
	temp += "\r\n 핸드폰 번호 : ";
	temp += m_strHP;
	temp += "\r\n 이메일 : ";
	temp += m_strEmail;
	m_strName.Empty();
	m_strHP.Empty();
	m_strEmail.Empty();
	UpdateData(FALSE);
	c_Memo.SetWindowText(temp);
}
