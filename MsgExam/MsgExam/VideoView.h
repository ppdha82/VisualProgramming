#pragma once



// CVideoView �� ���Դϴ�.
#define __CHAP13_VIEW_CHANGE__

class CVideoView : public CFormView
{
	DECLARE_DYNCREATE(CVideoView)

#if defined(__CHAP13_VIEW_CHANGE__)
public:
#else
protected:
#endif
	CVideoView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CVideoView();

public:
	enum { IDD = IDD_VIDEOVIEW };
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


