#pragma once


// CCalcDlg 대화 상자입니다.

class CCalcDlg : public CDialog
{
	DECLARE_DYNAMIC(CCalcDlg)

public:
	CCalcDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCalcDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CALC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
