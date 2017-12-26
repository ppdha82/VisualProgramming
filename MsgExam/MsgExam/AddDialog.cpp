// AddDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "AddDialog.h"
#include "afxdialogex.h"


// CAddDialog ��ȭ �����Դϴ�.

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


// CAddDialog �޽��� ó�����Դϴ�.


BOOL CAddDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	c_Gubun.InsertString(0, _T("�б� ��â"));
	c_Gubun.InsertString(1, _T("���� ����"));
	c_Gubun.InsertString(2, _T("��ȸ ģ��"));
	c_Gubun.InsertString(3, _T("����"));
	c_Gubun.InsertString(4, _T("��Ÿ"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
