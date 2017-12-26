#pragma once


// CImageResize 대화 상자입니다.

class CImageResize : public CPropertyPage
{
	DECLARE_DYNAMIC(CImageResize)

public:
	CWnd* pParent;

	CImageResize();
	virtual ~CImageResize();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TEST9_01_ResizeImage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTest901Resize();
	int resolutionResize;
	afx_msg void OnBnClickedTest901CancelResize();
};
