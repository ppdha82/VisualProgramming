#pragma once
#include "afxcmn.h"


// CProgressBar ��ȭ �����Դϴ�.

class CProgressBar : public CDialog
{
	DECLARE_DYNAMIC(CProgressBar)

public:
	CProgressBar(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CProgressBar();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAuto();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonStepbystep();
	CProgressCtrl c_Progress;
	virtual BOOL OnInitDialog();
};
