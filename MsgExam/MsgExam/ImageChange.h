#pragma once


// CImageChange ��ȭ �����Դϴ�.

class CImageChange : public CPropertyPage
{
	DECLARE_DYNAMIC(CImageChange)

public:
	CWnd* pParent;

	CImageChange();
	virtual ~CImageChange();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_TEST9_01_SelectImage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int imageNumber;
	afx_msg void OnBnClickedOkTest901();
};
