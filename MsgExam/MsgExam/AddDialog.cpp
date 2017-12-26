// AddDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "AddDialog.h"
#include "afxdialogex.h"


// CAddDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CAddDialog, CDialog)

CAddDialog::CAddDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDialog::IDD, pParent)
	, m_strName(_T(""))
	, m_strHP(_T(""))
	, m_strEmail(_T(""))
	, m_nGubun(0)
{

}

CAddDialog::~CAddDialog()
{
}

void CAddDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_HP, m_strHP);
	DDX_Text(pDX, IDC_EDIT_EMAIL, m_strEmail);
	DDX_CBIndex(pDX, IDC_COMBO_FRIENDLY_SECTION, m_nGubun);
	DDX_Control(pDX, IDC_COMBO_FRIENDLY_SECTION, c_Gubun);
}


BEGIN_MESSAGE_MAP(CAddDialog, CDialog)
END_MESSAGE_MAP()


// CAddDialog 메시지 처리기입니다.


BOOL CAddDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	c_Gubun.InsertString(0, _T("학교 동창"));
	c_Gubun.InsertString(1, _T("직장 동료"));
	c_Gubun.InsertString(2, _T("교회 친구"));
	c_Gubun.InsertString(3, _T("은사"));
	c_Gubun.InsertString(4, _T("기타"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
