
// MsgExamDoc.cpp : CMsgExamDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MsgExam.h"
#endif

#include "MsgExamDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMsgExamDoc

IMPLEMENT_DYNCREATE(CMsgExamDoc, CDocument)

BEGIN_MESSAGE_MAP(CMsgExamDoc, CDocument)
	ON_COMMAND(ID_TEST_4_01, &CMsgExamDoc::OnTest401)
	ON_COMMAND(32813, &CMsgExamDoc::OnTest402HorizonCenter)
	ON_COMMAND(32812, &CMsgExamDoc::OnTest402HorizonLeft)
	ON_COMMAND(ID_TEST_402_HORIZON_RIGHT, &CMsgExamDoc::OnTest402HorizonRight)
	ON_COMMAND(ID_TEST_402_VERTICAL_UP, &CMsgExamDoc::OnTest402VerticalUp)
	ON_COMMAND(ID_TEST_402_VERTICAL_MIDDLE, &CMsgExamDoc::OnTest402VerticalMiddle)
	ON_COMMAND(ID_TEST_402_VERTICAL_DOWN, &CMsgExamDoc::OnTest402VerticalDown)
//	ON_COMMAND(ID_CHAP9_COLORDLG, &CMsgExamDoc::OnChap9Colordlg)
END_MESSAGE_MAP()


// CMsgExamDoc 생성/소멸

CMsgExamDoc::CMsgExamDoc()
	: m_TestPoint401(0)
	, str(_T(""))
	, statusHorizontal(CENTER)
	, statusVertical(MIDDLE)
	, chapter(0)
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	m_TestRect401.top = 0;
	m_TestRect401.bottom = 0;
	m_TestRect401.left = 0;
	m_TestRect401.right = 0;

	m_TestOutputRect402.top = 0;
	m_TestOutputRect402.bottom = 0;
	m_TestOutputRect402.left = 0;
	m_TestOutputRect402.right = 0;

	m_TestPoint401.x = 0;
	m_TestPoint401.y = 0;
}

CMsgExamDoc::~CMsgExamDoc()
{
}

BOOL CMsgExamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	m_ptArray.RemoveAll();
	m_ptArrayChar.RemoveAll();

	return TRUE;
}




// CMsgExamDoc serialization

void CMsgExamDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		if (getChapter() == EXAM12_1) {
			ar << m_ptArrayChar.GetSize();

			for (int i = 0;i < m_ptArrayChar.GetSize();i++) {
				ar << m_ptArrayChar[i];
			}
		}
		else {
			ar << m_ptArray.GetSize();

			for (int i = 0;i < m_ptArray.GetSize();i++) {
				ar << m_ptArray[i];
			}
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		if (getChapter() == EXAM12_1) {
			m_ptArrayChar.RemoveAll();
			CPoint point;
			int size;

			ar >> size;

			for (int i = 0;i < size;i++) {
				ar >> point;
				m_ptArrayChar.Add(point);
			}
		}
		else {
			m_ptArray.RemoveAll();
			CPoint point;
			int size;

			ar >> size;

			for (int i = 0;i < size;i++) {
				ar >> point;
				m_ptArray.Add(point);
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CMsgExamDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CMsgExamDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMsgExamDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMsgExamDoc 진단

#ifdef _DEBUG
void CMsgExamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMsgExamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMsgExamDoc 명령

void CMsgExamDoc::OnTest401()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_TestPoint401 = m_TestRect401.CenterPoint();

	m_TestPoint402.x = 0;
	m_TestPoint402.y = 0;
	m_TestRect402.SetRectEmpty();
	str.Empty();

	UpdateAllViews(NULL);
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
#define	TEST_OUTPUT_RECT_BOTTOM_OUTER	10
#define	TEST_OUTPUT_RECT_TOP_OUTER		-10
#define	TEST_OUTPUT_RECT_LEFT_OUTER		-80
#define	TEST_OUTPUT_RECT_RIGHT_OUTER	80

void CMsgExamDoc::OnTest402HorizonCenter()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int horizon;
	int vertical;
	str.Format(L"Horizon Center");
	m_TestPoint401 = m_TestRect401.CenterPoint();
	m_TestPoint402 = m_TestRect402.CenterPoint();

	horizon = GetStatusHorizontal();
	vertical = GetStatusVertical();

	if (horizon != CENTER) {
		SetStatusHorizontal(CENTER);
		horizon = GetStatusHorizontal();
	}

	if (vertical != CENTER) {
		SetStatusVertical(vertical);
	}

	CalculateBorder(horizon, vertical, &m_TestPoint402);

	UpdateAllViews(NULL);
}


void CMsgExamDoc::OnTest402HorizonLeft()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int horizon;
	int vertical;
	str.Format(L"Horizon Left");
	// 사각형의 중앙 값을 얻는다.
	m_TestPoint401 = m_TestRect401.CenterPoint();
	m_TestPoint402 = m_TestRect402.CenterPoint();

	horizon = GetStatusHorizontal();
	vertical = GetStatusVertical();

	if (horizon != LEFT) {
		SetStatusHorizontal(LEFT);
		horizon = GetStatusHorizontal();
	}

	CalculateBorder(horizon, vertical, &m_TestPoint402);

	// 사각형의 중앙 값을 중심으로 좌 우 위 아래의 위치 값을 정한다. => 절대 위치 값 계산

	UpdateAllViews(NULL);
}   


void CMsgExamDoc::OnTest402HorizonRight()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int horizon;
	int vertical;
	str.Format(L"Horizon Right");
	m_TestPoint401 = m_TestRect401.CenterPoint();
	m_TestPoint402 = m_TestRect402.CenterPoint();

	horizon = GetStatusHorizontal();
	vertical = GetStatusVertical();

	if (horizon != RIGHT) {
		SetStatusHorizontal(RIGHT);
		horizon = GetStatusHorizontal();
	}

	CalculateBorder(horizon, vertical, &m_TestPoint402);

	UpdateAllViews(NULL);
}


int CMsgExamDoc::GetStatusHorizontal(void)
{
	return statusHorizontal;
}


int CMsgExamDoc::GetStatusVertical(void)
{
	return statusVertical;
}


void CMsgExamDoc::SetStatusHorizontal(int placeHorizontal)
{
	statusHorizontal = placeHorizontal;
}


void CMsgExamDoc::SetStatusVertical(int placeVertical)
{
	statusVertical = placeVertical;
}


bool CMsgExamDoc::CalculateBorder(int placeHorizontal, int placeVertical, CPoint *CenterPoint)
{
	switch(placeHorizontal) {
	case LEFT:
		m_TestOutputRect402.left = (m_TestPoint402.x + m_TestRect402.left) / 2 + TEST_OUTPUT_RECT_LEFT_OUTER;
		m_TestOutputRect402.right = (m_TestPoint402.x + m_TestRect402.left) / 2 + TEST_OUTPUT_RECT_RIGHT_OUTER;
		break;
	case RIGHT:
		m_TestOutputRect402.left = (m_TestPoint402.x + m_TestRect402.right) / 2 + TEST_OUTPUT_RECT_LEFT_OUTER;
		m_TestOutputRect402.right = (m_TestPoint402.x + m_TestRect402.right) / 2 + TEST_OUTPUT_RECT_RIGHT_OUTER;
		break;
	case CENTER:
		m_TestOutputRect402.left = m_TestPoint402.x + TEST_OUTPUT_RECT_LEFT_OUTER;
		m_TestOutputRect402.right = m_TestPoint402.x + TEST_OUTPUT_RECT_RIGHT_OUTER;
		break;
	}

	switch(placeVertical) {
	case UP:
		m_TestOutputRect402.bottom = (m_TestPoint402.y + m_TestRect402.top) / 2 + TEST_OUTPUT_RECT_BOTTOM_OUTER;
		m_TestOutputRect402.top = (m_TestPoint402.y + m_TestRect402.top) / 2 + TEST_OUTPUT_RECT_TOP_OUTER;
		break;
	case DOWN:
		m_TestOutputRect402.bottom = (m_TestPoint402.y + m_TestRect402.bottom) / 2 + TEST_OUTPUT_RECT_BOTTOM_OUTER;
		m_TestOutputRect402.top = (m_TestPoint402.y + m_TestRect402.bottom) / 2 + TEST_OUTPUT_RECT_TOP_OUTER;
		break;
	case MIDDLE:
		m_TestOutputRect402.bottom = m_TestPoint402.y + TEST_OUTPUT_RECT_BOTTOM_OUTER;
		m_TestOutputRect402.top = m_TestPoint402.y + TEST_OUTPUT_RECT_TOP_OUTER;
		break;
	}
	return true;
}


void CMsgExamDoc::OnTest402VerticalUp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int horizon;
	int vertical;
	str.Format(L"Vertical Up");
	// 사각형의 중앙 값을 얻는다.
	m_TestPoint401 = m_TestRect401.CenterPoint();
	m_TestPoint402 = m_TestRect402.CenterPoint();

	horizon = GetStatusHorizontal();
	vertical = GetStatusVertical();

	if (vertical != UP) {
		SetStatusVertical(UP);
		vertical = GetStatusVertical();
	}

	CalculateBorder(horizon, vertical, &m_TestPoint402);

	// 사각형의 중앙 값을 중심으로 좌 우 위 아래의 위치 값을 정한다. => 절대 위치 값 계산

	UpdateAllViews(NULL);
}


void CMsgExamDoc::OnTest402VerticalMiddle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int horizon;
	int vertical;
	str.Format(L"Vertical Middle");
	// 사각형의 중앙 값을 얻는다.
	m_TestPoint401 = m_TestRect401.CenterPoint();
	m_TestPoint402 = m_TestRect402.CenterPoint();

	horizon = GetStatusHorizontal();
	vertical = GetStatusVertical();

	if (vertical != MIDDLE) {
		SetStatusVertical(MIDDLE);
		vertical = GetStatusVertical();
	}

	CalculateBorder(horizon, vertical, &m_TestPoint402);

	// 사각형의 중앙 값을 중심으로 좌 우 위 아래의 위치 값을 정한다. => 절대 위치 값 계산

	UpdateAllViews(NULL);
}


void CMsgExamDoc::OnTest402VerticalDown()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int horizon;
	int vertical;
	str.Format(L"Vertical Down");
	// 사각형의 중앙 값을 얻는다.
	m_TestPoint401 = m_TestRect401.CenterPoint();
	m_TestPoint402 = m_TestRect402.CenterPoint();

	horizon = GetStatusHorizontal();
	vertical = GetStatusVertical();

	if (vertical != DOWN) {
		SetStatusVertical(DOWN);
		vertical = GetStatusVertical();
	}

	CalculateBorder(horizon, vertical, &m_TestPoint402);

	// 사각형의 중앙 값을 중심으로 좌 우 위 아래의 위치 값을 정한다. => 절대 위치 값 계산

	UpdateAllViews(NULL);
}


bool CMsgExamDoc::getBackColor(COLORREF& color)
{
	color = m_bkColor;

	return true;
}


void CMsgExamDoc::setBackColor(COLORREF color)
{
	m_bkColor = color;
}

