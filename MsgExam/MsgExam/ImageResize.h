#pragma once


// CImageResize ��ȭ �����Դϴ�.

class CImageResize : public CPropertyPage
{
	DECLARE_DYNAMIC(CImageResize)

public:
	CWnd* pParent;

	CImageResize();
	virtual ~CImageResize();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_TEST9_01_ResizeImage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTest901Resize();
	int resolutionResize;
	afx_msg void OnBnClickedTest901CancelResize();
};
