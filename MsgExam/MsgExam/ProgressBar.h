#pragma once
#include "afxcmn.h"


// CProgressBar 대화 상자입니다.

class CProgressBar : public CDialog
{
	DECLARE_DYNAMIC(CProgressBar)

public:
	CProgressBar(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CProgressBar();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonAuto();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonStepbystep();
	CProgressCtrl c_Progress;
	virtual BOOL OnInitDialog();
};
