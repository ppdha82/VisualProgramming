#pragma once


// CBrushDlg ��ȭ �����Դϴ�.

class CBrushDlg : public CPropertyPage
{
	DECLARE_DYNAMIC(CBrushDlg)

public:
	CBrushDlg();
	virtual ~CBrushDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
