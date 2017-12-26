#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CListExamDlg ��ȭ �����Դϴ�.

class CListExamDlg : public CDialog
{
	DECLARE_DYNAMIC(CListExamDlg)

public:
	CListExamDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CListExamDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_LIST_EXAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	void InsertColumn(void);
	virtual BOOL OnInitDialog();
	CListCtrl c_List;
	CImageList m_LargeImageList;
	CImageList m_SmallImageList;
	void LoadImageList(void);
	void AddSampleData(void);
	afx_msg void OnBnClickedButtonChap103Add();
	afx_msg void OnBnClickedButtonChap103Del();
};
