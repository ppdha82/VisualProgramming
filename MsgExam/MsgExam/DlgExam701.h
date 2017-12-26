#pragma once
#include "afxwin.h"


// CDlgExam701 ��ȭ �����Դϴ�.

class CDlgExam701 : public CDialog
{
	DECLARE_DYNAMIC(CDlgExam701)

public:
	CDlgExam701(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgExam701();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_TEST_7_01 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
