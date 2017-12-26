// ListExamDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ListExamDlg.h"
#include "AddDialog.h"
#include "afxdialogex.h"


// CListExamDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CListExamDlg, CDialog)

CListExamDlg::CListExamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListExamDlg::IDD, pParent)
{

}

CListExamDlg::~CListExamDlg()
{
}

void CListExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_CHAP10_3, c_List);
}


BEGIN_MESSAGE_MAP(CListExamDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CHAP10_3_ADD, &CListExamDlg::OnBnClickedButtonChap103Add)
	ON_BN_CLICKED(IDC_BUTTON_CHAP10_3_DEL, &CListExamDlg::OnBnClickedButtonChap103Del)
END_MESSAGE_MAP()


// CListExamDlg �޽��� ó�����Դϴ�.


void CListExamDlg::InsertColumn(void)
{
	CRect rect;
	c_List.GetClientRect(&rect);

	c_List.InsertColumn(0, _T("�̸�"), LVCFMT_LEFT, 100);
	c_List.InsertColumn(1, _T("�ڵ�����ȣ"), LVCFMT_LEFT, 200);

	c_List.InsertColumn(2, _T("�̸���"), LVCFMT_LEFT, rect.Width() - 300);
}


BOOL CListExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InsertColumn();
	LoadImageList();
	AddSampleData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CListExamDlg::LoadImageList(void)
{
	m_LargeImageList.Create(IDB_BITMAP10, 210/* = 853/4 */, 1, RGB(0, 128, 128));
	m_SmallImageList.Create(IDB_BITMAP11, 105/* = 420/4 */, 1, RGB(0, 128, 128));

	c_List.SetImageList(&m_LargeImageList, LVSIL_NORMAL);
	c_List.SetImageList(&m_SmallImageList, LVSIL_SMALL);
}

CString sampleName[] = {_T("������"), _T("������"), _T("������"), _T("������")};
CString sampleEmail[] = {_T("kjw@nate.com"), _T("hjh@nate.com"), _T("jje@nate.com"), _T("jhy@nate.com")};

void CListExamDlg::AddSampleData(void)
{
	CString str;

	for (int i = 0;i < 4;i++) {
		c_List.InsertItem(i, sampleName[i], rand() % 4);
		str.Format(_T("010-%d%d%d%d-%d%d%d%d"), rand() %10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10);
		c_List.SetItemText(i, 1, str);
		c_List.SetItemText(i, 2, sampleEmail[i]);
	}
}


void CListExamDlg::OnBnClickedButtonChap103Add()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CAddDialog dlg;

	if (dlg.DoModal() == IDOK) {
		int nItemNum = c_List.GetItemCount();

		c_List.InsertItem(nItemNum, dlg.m_strName, dlg.m_nGubun);
		c_List.SetItemText(nItemNum, 1, dlg.m_strHP);
		c_List.SetItemText(nItemNum, 2, dlg.m_strEmail);
	}
}


void CListExamDlg::OnBnClickedButtonChap103Del()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int count = c_List.GetItemCount();
	
	for (int i = count - 1;i >= 0;i--) {
		if (c_List.GetItemState(i, LVIS_SELECTED) != 0) {
			c_List.DeleteItem(i);
		}
	}
}
