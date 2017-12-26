#pragma once



// CTabSheet

#include "PenDlg.h"
#include "BrushDlg.h"

class CTabSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CTabSheet)

public:
	CPenDlg m_PenPage;
	CBrushDlg m_BrushPage;

	CTabSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CTabSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CTabSheet();

protected:
	DECLARE_MESSAGE_MAP()
};


