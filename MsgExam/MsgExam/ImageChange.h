#pragma once


// CImageChange 대화 상자입니다.

class CImageChange : public CPropertyPage
{
	DECLARE_DYNAMIC(CImageChange)

public:
	CWnd* pParent;

	CImageChange();
	virtual ~CImageChange();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TEST9_01_SelectImage };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int imageNumber;
	afx_msg void OnBnClickedOkTest901();
};
