#pragma once
#include "afxwin.h"


// CDlgExam701 대화 상자입니다.

class CDlgExam701 : public CDialog
{
	DECLARE_DYNAMIC(CDlgExam701)

public:
	CDlgExam701(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgExam701();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TEST_7_01 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonTest701Add();
	afx_msg void OnBnClickedButtonTest701Delete();
private:
	CString inputString;
	CListBox listBoxExam;
public:
	void emptyInputString(void)
	{
		inputString.Empty();
	}

	void addStringToListBox(CString input)
	{
		listBoxExam.AddString(input);
	}

	void delStringFromListBox(int index)
	{
		listBoxExam.DeleteString(index);
	}

	int getIndexFromListBox()
	{
		return listBoxExam.GetCurSel();
	}
};
