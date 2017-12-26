#pragma once


// CBrushDlg 대화 상자입니다.

class CBrushDlg : public CPropertyPage
{
	DECLARE_DYNAMIC(CBrushDlg)

public:
	CBrushDlg();
	virtual ~CBrushDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
private:
	int m_nBrushStyle;
public:
	void setBrushStyle(int style)
	{
		m_nBrushStyle = style;
	}

	int getBrushStyle(void)
	{
		return m_nBrushStyle;
	}
};
