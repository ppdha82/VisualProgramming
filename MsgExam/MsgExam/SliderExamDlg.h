#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "atltypes.h"


// CSliderExamDlg ��ȭ �����Դϴ�.

class CSliderExamDlg : public CDialog
{
	DECLARE_DYNAMIC(CSliderExamDlg)

public:
	CSliderExamDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSliderExamDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SLIDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
