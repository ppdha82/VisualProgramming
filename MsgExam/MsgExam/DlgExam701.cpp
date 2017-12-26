// DlgExam701.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "DlgExam701.h"
#include "afxdialogex.h"


// CDlgExam701 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgExam701, CDialog)

CDlgExam701::CDlgExam701(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExam701::IDD, pParent)
	, inputString(_T(""))
{

}

CDlgExam701::~CDlgExam701()
{
}

void CDlgExam701::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEST_701, inputString);
	DDX_Control(pDX, IDC_LIST_TEST_701, listBoxExam);
}


BEGIN_MESSAGE_MAP(CDlgExam701, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_TEST_701_ADD, &CDlgExam701::OnBnClickedButtonTest701Add)
	ON_BN_CLICKED(IDC_BUTTON_TEST_701_DELETE, &CDlgExam701::OnBnClickedButtonTest701Delete)
END_MESSAGE_MAP()


// CDlgExam701 �޽��� ó�����Դϴ�.

void CDlgExam701::OnBnClickedButtonTest701Add()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	addStringToListBox(inputString);
	emptyInputString();
	UpdateData(FALSE);
}


void CDlgExam701::OnBnClickedButtonTest701Delete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	int currentSelect = getIndexFromListBox();
	delStringFromListBox(currentSelect);
}
