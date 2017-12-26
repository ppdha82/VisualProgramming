#pragma once


// CPenDlg 대화 상자입니다.

class CPenDlg : public CPropertyPage
{
	DECLARE_DYNAMIC(CPenDlg)

public:
	CPenDlg();
	virtual ~CPenDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	int m_nPenStyle;
public:
	void setPenStyle(int style)
	{
		m_nPenStyle = style;
	}

	int getPenStyle(void)
	{
		return m_nPenStyle;
	}
};
