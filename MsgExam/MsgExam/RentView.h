#pragma once



// CRentView 폼 뷰입니다.
#define __CHAP13_VIEW_CHANGE__

class CRentView : public CFormView
{
	DECLARE_DYNCREATE(CRentView)
#if defined(__CHAP13_VIEW_CHANGE__)
public:
#else
protected:
#endif
	CRentView();           // 동적 만들기에 사용되는 protected 생성자입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};


