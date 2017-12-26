// ListExamDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ListExamDlg.h"
#include "AddDialog.h"
#include "afxdialogex.h"


// CListExamDlg 대화 상자입니다.

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


// CListExamDlg 메시지 처리기입니다.


void CListExamDlg::InsertColumn(void)
{
	CRect rect;
	c_List.GetClientRect(&rect);

	c_List.InsertColumn(0, _T("이름"), LVCFMT_LEFT, 100);
	c_List.InsertColumn(1, _T("핸드폰번호"), LVCFMT_LEFT, 200);

	c_List.InsertColumn(2, _T("이메일"), LVCFMT_LEFT, rect.Width() - 300);
}


BOOL CListExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	InsertColumn();
	LoadImageList();
	AddSampleData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CListExamDlg::LoadImageList(void)
{
	m_LargeImageList.Create(IDB_BITMAP10, 210/* = 853/4 */, 1, RGB(0, 128, 128));
	m_SmallImageList.Create(IDB_BITMAP11, 105/* = 420/4 */, 1, RGB(0, 128, 128));

	c_List.SetImageList(&m_LargeImageList, LVSIL_NORMAL);
	c_List.SetImageList(&m_SmallImageList, LVSIL_SMALL);
}

CString sampleName[] = {_T("곽정원"), _T("한주희"), _T("조진이"), _T("전혜영")};
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int count = c_List.GetItemCount();
	
	for (int i = count - 1;i >= 0;i--) {
		if (c_List.GetItemState(i, LVIS_SELECTED) != 0) {
			c_List.DeleteItem(i);
		}
	}
}
