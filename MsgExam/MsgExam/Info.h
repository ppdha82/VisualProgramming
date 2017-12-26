#pragma once
#include "afxwin.h"


// CInfo 대화 상자입니다.

class CInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CInfo)

public:
	CInfo(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInfo();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strHP;
	CString m_strEmail;
	afx_msg void OnBnClickedButtonDone();
	CEdit c_Memo;
};
