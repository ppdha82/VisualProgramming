#pragma once


// CMiddleView ���Դϴ�.

class CMiddleView : public CView
{
	DECLARE_DYNCREATE(CMiddleView)

protected:
	CMiddleView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMiddleView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


