#pragma once


// CCalcDlg ��ȭ �����Դϴ�.

class CCalcDlg : public CDialog
{
	DECLARE_DYNAMIC(CCalcDlg)

public:
	CCalcDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCalcDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
private:
	int m_nNum1;
	int m_nNum2;
	int m_nResult;
public:
	void setNum1(int num)
	{
		m_nNum1 = num;
	}

	int getNum1(void)
	{
		return m_nNum1;
	}

	void setNum2(int num)
	{
		m_nNum2 = num;
	}

	int getNum2(void)
	{
		return m_nNum2;
	}

	void setNumResult(int num)
	{
		m_nResult = num;
	}

	int getNumResult(void)
	{
		return m_nResult;
	}


	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonClear();
};
