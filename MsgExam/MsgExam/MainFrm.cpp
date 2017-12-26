
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "MsgExam.h"

#include "MainFrm.h"
#include "RightView.h"
#include "LeftView.h"
#include "MiddleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_RENT_MANAGER, &CMainFrame::OnRentManager)
	ON_COMMAND(ID_CUSTOMER_MANAGER, &CMainFrame::OnCustomerManager)
	ON_COMMAND(ID_VIDEO_MANAGER, &CMainFrame::OnVideoManager)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_SEPARATOR,			// 1�� �г� : ���� �ð� ���
	ID_SEPARATOR,			// 2�� �г� : ���콺 ��ġ�� ���
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame() : m_bFirst(false)
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("���� ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: ���� ������ ��ŷ�� �� ���� �Ϸ��� �� �� ���� �����Ͻʽÿ�.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_wndStatusBar.SetPaneInfo(1, ID_SEPARATOR, SBPS_POPOUT, 100);
	m_wndStatusBar.SetPaneInfo(2, ID_SEPARATOR, SBPS_POPOUT, 100);

	m_wndStatusBar.SetPaneText(1, _T("���� �ð� : "));
	m_wndStatusBar.SetPaneText(2, _T("���콺 ��ġ : "));

	SetTimer(1, 1000, NULL);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTime timer = CTime::GetCurrentTime();
	CString strTimer = timer.Format("%H : %M : %S");

	m_wndStatusBar.SetPaneText(1, strTimer);

	CFrameWnd::OnTimer(nIDEvent);
}

//#define __STATIC_SPLITTER_VER2__
//#define __CHAP13_VIEW_CHANGE__
//#define __EXAM13_STATIC_SPLITTER__

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
#if defined(__STATIC_SPLITTER_VER1__)
	m_wndSplitter.CreateStatic(this, 1, 2);
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CLeftView), CSize(200, 300), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CRightView), CSize(300, 300), pContext);
#elif defined(__STATIC_SPLITTER_VER2__)
	CRect rect;
	GetClientRect(rect);

	m_wndSplitter.CreateStatic(this, 2, 1);
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(CMiddleView), CSize(rect.Width(), rect.Height() / 2), pContext);
	m_wndSplitterUp.CreateStatic(&m_wndSplitter, 1, 2, WS_CHILD | WS_VISIBLE, m_wndSplitter.IdFromRowCol(0, 0));
	m_wndSplitterUp.CreateView(0, 1, RUNTIME_CLASS(CRightView), CSize(rect.Width() / 2, rect.Height() / 2), pContext);
	m_wndSplitterUp.CreateView(0, 0, RUNTIME_CLASS(CLeftView), CSize(rect.Width() / 2 + 25, rect.Height() / 2), pContext);
	m_wndSplitter.SetRowInfo(0, 350, 0);

	return TRUE;
#elif defined(__EXAM13_STATIC_SPLITTER__)
	CRect rect;
	GetClientRect(rect);

	m_wndSplitter.CreateStatic(this, 1, 2);
	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CMiddleView), CSize(rect.Width() / 2, rect.Height()), pContext);
	m_wndSplitterUp.CreateStatic(&m_wndSplitter, 2, 1, WS_CHILD | WS_VISIBLE, m_wndSplitter.IdFromRowCol(0, 1));
	m_wndSplitterUp.CreateView(1, 0, RUNTIME_CLASS(CRightView), CSize(rect.Width() / 2, rect.Height() / 2), pContext);
	m_wndSplitterUp.CreateView(0, 0, RUNTIME_CLASS(CLeftView), CSize(rect.Width() / 2, rect.Height() / 2), pContext);
	m_wndSplitter.SetRowInfo(0, 350, 0);

	return TRUE;
#elif defined(__DYNAMIC_SPLITTER__)
	return m_wndSplitter.Create(this, 2, 2, CSize(10, 10), pContext);
#elif defined(__CHAP13_VIEW_CHANGE__)
	g_pCustomerView = new CCustomerView;
	((CView*) g_pCustomerView)->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, IDD_CUSTOMERVIEW, pContext);
	g_pCustomerView->ShowWindow(SW_HIDE);
	g_pCustomerView->SetDlgCtrlID(IDD_CUSTOMERVIEW);

	g_pRentView = new CRentView;
	((CView*) g_pRentView)->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, IDD_RENTVIEW, pContext);
	g_pRentView->ShowWindow(SW_HIDE);
	g_pRentView->SetDlgCtrlID(IDD_RENTVIEW);

	return CFrameWnd::OnCreateClient(lpcs, pContext);
#else	// __NO_SPLITTER__
	return CFrameWnd::OnCreateClient(lpcs, pContext);
#endif
}


void CMainFrame::SwitchToForm(unsigned int ViewID)
{
	if (m_bFirst == false) {
		g_pVideoView = (CVideoView*)GetActiveView();
		m_bFirst = true;
	}

	CView* pOldActiveView = GetActiveView();
	CView* pNewActiveView = (CView*)GetDlgItem(ViewID);

	if (pNewActiveView != NULL) {
		if (pNewActiveView == pOldActiveView) {
			return;
		}

		pOldActiveView->ShowWindow(SW_HIDE);
		pOldActiveView->SetDlgCtrlID(ViewID);

		SetActiveView(pNewActiveView);
		pNewActiveView->ShowWindow(SW_SHOW);
		pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);

		RecalcLayout();
	}
}


void CMainFrame::OnRentManager()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	SwitchToForm(IDD_RENTVIEW);
}


void CMainFrame::OnCustomerManager()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	SwitchToForm(IDD_CUSTOMERVIEW);
}


void CMainFrame::OnVideoManager()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	SwitchToForm(IDD_VIDEOVIEW);
}
