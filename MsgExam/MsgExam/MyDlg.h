#pragma once


// CMyDlg ��ȭ �����Դϴ�.

class CMyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg)

public:
	CMyDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMyDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strHPhone;
	CString m_strEmail;
};
