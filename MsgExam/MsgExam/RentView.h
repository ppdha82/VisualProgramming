#pragma once



// CRentView �� ���Դϴ�.
#define __CHAP13_VIEW_CHANGE__

class CRentView : public CFormView
{
	DECLARE_DYNCREATE(CRentView)
#if defined(__CHAP13_VIEW_CHANGE__)
public:
#else
protected:
#endif
	CRentView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CRentView();

public:
	enum { IDD = IDD_RENTVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};


