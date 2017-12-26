#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "atltypes.h"


// CSliderExamDlg 대화 상자입니다.

class CSliderExamDlg : public CDialog
{
	DECLARE_DYNAMIC(CSliderExamDlg)

public:
	CSliderExamDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSliderExamDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_SLIDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()
public:
	CStatic c_Red;
	CSliderCtrl c_SliderRed;
	CStatic c_Green;
	CSliderCtrl c_SliderGreen;
	CStatic c_Blue;
	CSliderCtrl c_SliderBlue;
	CRect m_rectPic;
	COLORREF m_rectColor;
	virtual BOOL OnInitDialog();
	void changeRectColor(void);
	afx_msg void OnNMReleasedcaptureSliderRed(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderGreen(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureSliderBlue(NMHDR *pNMHDR, LRESULT *pResult);
};
