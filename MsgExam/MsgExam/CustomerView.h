#pragma once



// CCustomerView �� ���Դϴ�.
#define __CHAP13_VIEW_CHANGE__

class CCustomerView : public CFormView
{
	DECLARE_DYNCREATE(CCustomerView)

#if defined(__CHAP13_VIEW_CHANGE__)
public:
#else
protected:
#endif
	CCustomerView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CCustomerView();

public:
	enum { IDD = IDD_CUSTOMERVIEW };
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


