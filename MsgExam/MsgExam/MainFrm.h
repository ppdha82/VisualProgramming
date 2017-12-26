
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once
#include "afxext.h"

#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "RentView.h"
#include "VideoView.h"
#include "CustomerView.h"

class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
public:		// ������ View Class������ ������ �����ϵ��� Ư���� ������.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
protected:
	CSplitterWnd m_wndSplitter;
public:
	CSplitterWnd m_wndSplitterUp;
public:
	CVideoView*		g_pVideoView;
	CCustomerView*	g_pCustomerView;
	CRentView*		g_pRentView;

	bool m_bFirst;
	void SwitchToForm(unsigned int ViewID);
	afx_msg void OnRentManager();
	afx_msg void OnCustomerManager();
	afx_msg void OnVideoManager();
};


