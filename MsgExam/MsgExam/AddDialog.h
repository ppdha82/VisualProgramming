#pragma once
#include "afxwin.h"


// CAddDialog ��ȭ �����Դϴ�.

class CAddDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddDialog)

public:
	CAddDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ADD_LIST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strHP;
	CString m_strEmail;
	int m_nGubun;
	CComboBox c_Gubun;
	virtual BOOL OnInitDialog();
};
