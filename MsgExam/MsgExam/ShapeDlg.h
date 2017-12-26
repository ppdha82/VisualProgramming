#pragma once
#include "afxwin.h"


// CShapeDlg ��ȭ �����Դϴ�.
class CMsgExamView;

class CShapeDlg : public CDialog
{
	DECLARE_DYNAMIC(CShapeDlg)
public:
	CWnd* pParent;
	CMsgExamView* pView;

public:
	CShapeDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CShapeDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SHAPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
private:
	int m_nShape;
	int m_nColor;
	BOOL m_bColorApply;

public:
	void setShape(int shape) {
		m_nShape = shape;
	}
	void setColor(int color) {
		m_nColor = color;
	}
	void setColorApply(BOOL colorApply) {
		m_bColorApply = colorApply;
	}
	int getShape(void) {
		return m_nShape;
	}
	int getColor(void) {
		return m_nColor;
	}
	BOOL getColorApply(void) {
		return m_bColorApply;
	}
private:
	CButton c_Red;
	CButton c_Green;
	CButton c_Blue;
	CButton c_Magenta;
public:
	void setRedEnable(BOOL colorApply)
	{
		c_Red.EnableWindow(colorApply);
	}
	void setGreenEnable(BOOL colorApply)
	{
		c_Green.EnableWindow(colorApply);
	}
	void setBlueEnable(BOOL colorApply)
	{
		c_Blue.EnableWindow(colorApply);
	}
	void setMagentaEnable(BOOL colorApply)
	{
		c_Magenta.EnableWindow(colorApply);
	}

public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedChap5Apply();
};
