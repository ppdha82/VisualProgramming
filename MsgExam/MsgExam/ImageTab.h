#pragma once

#include "ImageChange.h"
#include "ImageResize.h"

// CImageTab

class CImageTab : public CPropertySheet
{
	DECLARE_DYNAMIC(CImageTab)
public:
	CWnd *m_Parent;
	CImageChange ImageChangePage;
	CImageResize ImageResizePage;

public:
	CImageTab(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CImageTab(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CImageTab();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTest901();
};


