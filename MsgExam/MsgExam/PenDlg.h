#pragma once


// CPenDlg ��ȭ �����Դϴ�.

class CPenDlg : public CPropertyPage
{
	DECLARE_DYNAMIC(CPenDlg)

public:
	CPenDlg();
	virtual ~CPenDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
