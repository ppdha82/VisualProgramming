#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CListExamDlg 대화 상자입니다.

class CListExamDlg : public CDialog
{
	DECLARE_DYNAMIC(CListExamDlg)

public:
	CListExamDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CListExamDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_LIST_EXAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
