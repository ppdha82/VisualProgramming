
// MainFrm.h : CMainFrame 클래스의 인터페이스
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
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//protected:  // 컨트롤 모음이 포함된 멤버입니다.
public:		// 예제의 View Class에서의 참조가 가능하도록 특성을 변경함.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 생성된 메시지 맵 함수
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


