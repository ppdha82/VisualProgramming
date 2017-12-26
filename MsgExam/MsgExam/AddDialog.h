#pragma once
#include "afxwin.h"


// CAddDialog 대화 상자입니다.

class CAddDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddDialog)

public:
	CAddDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ADD_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strHP;
	CString m_strEmail;
	int m_nGubun;
	CComboBox c_Gubun;
	virtual BOOL OnInitDialog();
};
