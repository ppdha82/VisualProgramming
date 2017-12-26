// TreeExam.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "TreeExam.h"
#include "afxdialogex.h"


// CTreeExam ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTreeExam, CDialog)

CTreeExam::CTreeExam(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeExam::IDD, pParent)
	, m_strSel(_T(""))
	, m_strData(_T(""))
{

}

CTreeExam::~CTreeExam()
{
}

void CTreeExam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, c_Tree);
	DDX_Text(pDX, IDC_EDIT_SEL, m_strSel);
	DDX_Text(pDX, IDC_EDIT_DATA, m_strData);
}


BEGIN_MESSAGE_MAP(CTreeExam, CDialog)
	ON_NOTIFY(TVN_SELCHANGING, IDC_TREE1, &CTreeExam::OnTvnSelchangingTree1)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CTreeExam::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CTreeExam::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CTreeExam::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// CTreeExam �޽��� ó�����Դϴ�.


BOOL CTreeExam::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_ImgList.Create(IDB_BITMAP10, 168, 5, ILD_NORMAL);

	c_Tree.SetImageList(&m_ImgList, TVSIL_NORMAL);
	m_hRoot = c_Tree.InsertItem(_T("��Ʈ"), 0, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CTreeExam::OnTvnSelchangingTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_hSelectItem = pNMTreeView->itemNew.hItem;
	m_strSel = c_Tree.GetItemText(m_hSelectItem);
	UpdateData(FALSE);

	*pResult = 0;
}


void CTreeExam::OnBnClickedButtonAdd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strData.IsEmpty() == FALSE) {
		c_Tree.InsertItem(m_strData, 2, 3, m_hSelectItem);
		c_Tree.Expand(m_hSelectItem, TVE_EXPAND);
	}
	else {
		AfxMessageBox(_T("���� �߰��� �ؽ�Ʈ�� �Է��ϼ���."));
	}

	m_strData.Empty();
	UpdateData(FALSE);
}


void CTreeExam::OnBnClickedButtonMod()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strData.IsEmpty() == FALSE) {
		c_Tree.SetItemText(m_hSelectItem, m_strData);
		m_strSel = m_strData;
	}
	else {
		AfxMessageBox(_T("������ ����� �ؽ�Ʈ�� �Է��ϼ���."));
	}

	m_strData.Empty();
	UpdateData(FALSE);}


void CTreeExam::OnBnClickedButtonDel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_hSelectItem != m_hRoot) {
		int result = MessageBox(_T("���� �����Ͻðڽ��ϱ�?"), _T("����"), MB_YESNO);
		if (result == IDYES) {
			c_Tree.DeleteItem(m_hSelectItem);
			m_strSel.Empty();
		}
		else {
			AfxMessageBox(_T("��Ʈ ���� �����ؼ��� �ȵ˴ϴ�."));
		}
	}
	UpdateData(FALSE);
}
