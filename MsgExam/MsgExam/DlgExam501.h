#pragma once
#include "afxwin.h"


// CDlgExam501 대화 상자입니다.

class CDlgExam501 : public CDialog
{
	DECLARE_DYNAMIC(CDlgExam501)

public:
	CDlgExam501(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgExam501();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TEST_5_01 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTest501();
private:
	int horizontalStatus;
	int verticalStatus;
public:
	void setHorizontal(int horizon)
	{
		horizontalStatus = horizon;
	}
	
	void setVertical(int vertical)
	{
		verticalStatus = vertical;
	}

	int getHorizontal(void)
	{
		return horizontalStatus;
	}

	int getVertical(void)
	{
		return verticalStatus;
	}
private:
	CString textExam501;
public:
	void setText(CString text)
	{
		textExam501.Empty();
		textExam501.Format(text.GetString());
	}

	CString* getText(void)
	{
		return &textExam501;
	}
private:
	CButton applyTop;
	CButton applyLeft;
	CButton applyCenter;
	CButton applyRight;
	CButton applyMiddle;
	CButton applyBottom;
public:
	void showTopRadio(int top)
	{
		applyTop.ShowWindow(top);
	}
	void showLeftRadio(int left)
	{
		applyLeft.ShowWindow(left);
	}
	void showCenterRadio(int center)
	{
		applyCenter.ShowWindow(center);
	}
	void showRightRadio(int right)
	{
		applyRight.ShowWindow(right);
	}
	void showMiddleRadio(int middle)
	{
		applyMiddle.ShowWindow(middle);
	}
	void showBottomRadio(int bottom)
	{
		applyBottom.ShowWindow(bottom);
	}
private:
	int applyValueHorizontal;
public:
	int getValueHorizontal(void)
	{
		return applyValueHorizontal;
	}
	afx_msg void OnBnClickedApplyHorizontal();
	afx_msg void OnBnClickedApplyVertical();
	afx_msg void OnBnClickedApplyBoth();
};
