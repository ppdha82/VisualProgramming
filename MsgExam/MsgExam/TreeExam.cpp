// TreeExam.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "TreeExam.h"
#include "afxdialogex.h"


// CTreeExam 대화 상자입니다.

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


// CTreeExam 메시지 처리기입니다.


BOOL CTreeExam::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ImgList.Create(IDB_BITMAP10, 168, 5, ILD_NORMAL);

	c_Tree.SetImageList(&m_ImgList, TVSIL_NORMAL);
	m_hRoot = c_Tree.InsertItem(_T("루트"), 0, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTreeExam::OnTvnSelchangingTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_hSelectItem = pNMTreeView->itemNew.hItem;
	m_strSel = c_Tree.GetItemText(m_hSelectItem);
	UpdateData(FALSE);

	*pResult = 0;
}


void CTreeExam::OnBnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_strData.IsEmpty() == FALSE) {
		c_Tree.InsertItem(m_strData, 2, 3, m_hSelectItem);
		c_Tree.Expand(m_hSelectItem, TVE_EXPAND);
	}
	else {
		AfxMessageBox(_T("노드로 추가할 텍스트를 입력하세요."));
	}

	m_strData.Empty();
	UpdateData(FALSE);
}


void CTreeExam::OnBnClickedButtonMod()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_strData.IsEmpty() == FALSE) {
		c_Tree.SetItemText(m_hSelectItem, m_strData);
		m_strSel = m_strData;
	}
	else {
		AfxMessageBox(_T("수정할 노드의 텍스트를 입력하세요."));
	}

	m_strData.Empty();
	UpdateData(FALSE);}


void CTreeExam::OnBnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_hSelectItem != m_hRoot) {
		int result = MessageBox(_T("정말 삭제하시겠습니까?"), _T("삭제"), MB_YESNO);
		if (result == IDYES) {
			c_Tree.DeleteItem(m_hSelectItem);
			m_strSel.Empty();
		}
		else {
			AfxMessageBox(_T("루트 노드는 삭제해서는 안됩니다."));
		}
	}
	UpdateData(FALSE);
}
