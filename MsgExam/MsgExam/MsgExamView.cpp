
// MsgExamView.cpp : CMsgExamView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MsgExam.h"
#endif

#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "MainFrm.h"
#include "MyDlg.h"
#include "ShapeDlg.h"
#include "DlgExam501.h"
#include "CalcDlg.h"
#include "DlgExam701.h"
#include "ImageTab.h"
#include "TreeExam.h"
#include "ListExamDlg.h"
#include "SliderExamDlg.h"
#include "ProgressBar.h"
#include "Point3D.h"
#include "Info.h"
#include "TabSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define	RED				0
#define	GREEN			1
#define	BLUE			2
#define	PURPLE			3

#define	CIRCLE_DLG		0
#define	RECTANGLE_DLG	1
#define	LINE_DLG		2

#define	TOP_EXAM501		0
#define	MIDDLE_EXAM501	1
#define	BOTTOM_EXAM501	2

#define	LEFT_EXAM501	0
#define	CENTER_EXAM501	1
#define	RIGHT_EXAM501	2


#define MAX_BITMAP_ID	4
int bmpIDmap[MAX_BITMAP_ID] = {IDB_BITMAP1, IDB_BITMAP2, IDB_BITMAP3, IDB_BITMAP4};

// CMsgExamView

IMPLEMENT_DYNCREATE(CMsgExamView, CView)

BEGIN_MESSAGE_MAP(CMsgExamView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_COMMAND(ID_TEXT_BLACK, &CMsgExamView::OnTextBlack)
	ON_COMMAND(ID_TEXT_BLUE, &CMsgExamView::OnTextBlue)
	ON_COMMAND(ID_TEXT_GREEN, &CMsgExamView::OnTextGreen)
	ON_COMMAND(ID_TEXT_RED, &CMsgExamView::OnTextRed)
ON_UPDATE_COMMAND_UI(ID_TEXT_BLACK, &CMsgExamView::OnUpdateTextBlack)
ON_UPDATE_COMMAND_UI(ID_TEXT_RED, &CMsgExamView::OnUpdateTextRed)
ON_UPDATE_COMMAND_UI(ID_TEXT_GREEN, &CMsgExamView::OnUpdateTextGreen)
ON_UPDATE_COMMAND_UI(ID_TEXT_BLUE, &CMsgExamView::OnUpdateTextBlue)
ON_WM_CONTEXTMENU()
ON_COMMAND(ID_BACK_BLACK, &CMsgExamView::OnBackBlack)
ON_COMMAND(ID_BACK_BLUE, &CMsgExamView::OnBackBlue)
ON_COMMAND(ID_BACK_GREEN, &CMsgExamView::OnBackGreen)
ON_COMMAND(ID_BACK_RED, &CMsgExamView::OnBackRed)
ON_UPDATE_COMMAND_UI(ID_BACK_BLUE, &CMsgExamView::OnUpdateBackBlue)
ON_UPDATE_COMMAND_UI(ID_BACK_BLACK, &CMsgExamView::OnUpdateBackBlack)
ON_UPDATE_COMMAND_UI(ID_BACK_GREEN, &CMsgExamView::OnUpdateBackGreen)
ON_UPDATE_COMMAND_UI(ID_BACK_RED, &CMsgExamView::OnUpdateBackRed)
ON_COMMAND(ID_TEST_4_05, &CMsgExamView::OnTest405)
ON_COMMAND(ID_MYDIALOG, &CMsgExamView::OnMydialog)
ON_COMMAND(ID_SHAPESELECT, &CMsgExamView::OnShapeselect)
ON_COMMAND(ID_TEST_5_01, &CMsgExamView::OnTest501)
ON_COMMAND(ID_CALC_EXECUTE, &CMsgExamView::OnCalcExecute)
ON_COMMAND(ID_TEST_6_01, &CMsgExamView::OnTest601)
ON_COMMAND(ID_TEST_7_01, &CMsgExamView::OnTest701)
ON_COMMAND(ID_CHAP8_GDIEXAM, &CMsgExamView::OnChap8Gdiexam)
ON_COMMAND(ID_CHAP8_BITMAPEXAM, &CMsgExamView::OnChap8Bitmapexam)
ON_WM_RBUTTONDOWN()
ON_COMMAND(ID_EXAM8_01_RED, &CMsgExamView::OnExam801Red)
ON_COMMAND(ID_EXAM8_01_GREEN, &CMsgExamView::OnExam801Green)
ON_COMMAND(ID_EXAM8_01_BLUE, &CMsgExamView::OnExam801Blue)
ON_COMMAND(ID_EXAM8_02_HATCH_HORIZONTAL, &CMsgExamView::OnExam802HatchHorizontal)
ON_COMMAND(ID_EXAM8_02_HATCH_VERTICAL, &CMsgExamView::OnExam802HatchVertical)
ON_COMMAND(ID_EXAM8_02_HATCH_45DEG_LTOR, &CMsgExamView::OnExam802Hatch45degLtor)
ON_COMMAND(ID_EXAM8_02_HATCH_45DEG_RTOL, &CMsgExamView::OnExam802Hatch45degRtol)
ON_COMMAND(ID_EXAM8_02_HATCH_CROSS, &CMsgExamView::OnExam802HatchCross)
ON_COMMAND(ID_EXAM8_02_HATCH_45DEG_CROSS, &CMsgExamView::OnExam802Hatch45degCross)
ON_WM_CREATE()
ON_COMMAND(ID_CHAP9_FONT_MENU, &CMsgExamView::OnChap9FontMenu)
ON_COMMAND(ID_CHAP9_MODALESS_MENU, &CMsgExamView::OnChap9ModalessMenu)
ON_COMMAND(ID_TEST_TEST_9_01, &CMsgExamView::OnTestTest901)
ON_COMMAND(ID_CHAP10_1, &CMsgExamView::OnChap101)
ON_COMMAND(ID_CHAP10_2, &CMsgExamView::OnChap102)
ON_COMMAND(ID_CHAP10_3, &CMsgExamView::OnChap103)
ON_COMMAND(ID_CHAP10_SLIDER, &CMsgExamView::OnChap10Slider)
ON_COMMAND(ID_CHAP11_WM_CHAR, &CMsgExamView::OnChap11Wm)
ON_WM_CHAR()
ON_COMMAND(ID_CHAP11_WM_KEYDOWN, &CMsgExamView::OnChap11WmKeydown)
ON_WM_KEYDOWN()
ON_COMMAND(ID_CHAP11_WM_LBUTTONDOWN, &CMsgExamView::OnChap11WmLbuttondown)
ON_WM_LBUTTONDOWN()
ON_COMMAND(ID_CHAP11_WM_MOUSEMOVE, &CMsgExamView::OnChap11WmMousemove)
ON_WM_MOUSEMOVE()
ON_COMMAND(ID_BRUSH_RED, &CMsgExamView::OnBrushRed)
ON_COMMAND(ID_BRUSH_GREEN, &CMsgExamView::OnBrushGreen)
ON_COMMAND(ID_BRUSH_BLUE, &CMsgExamView::OnBrushBlue)
ON_COMMAND(ID_EXAM_11_1_RESIZE_100, &CMsgExamView::OnExam111Resize100)
ON_COMMAND(ID_EXAM_11_1_RESIZE_50, &CMsgExamView::OnExam111Resize50)
ON_COMMAND(ID_EXAM_11_1_RESIZE_25, &CMsgExamView::OnExam111Resize25)
ON_COMMAND(ID_EXAM_11_1_RESIZE_10, &CMsgExamView::OnExam111Resize10)
ON_COMMAND(ID_EXAM_11_1_IMAGE_1, &CMsgExamView::OnExam111Image1)
ON_COMMAND(ID_EXAM_11_1_IMAGE_2, &CMsgExamView::OnExam111Image2)
ON_COMMAND(ID_EXAM_11_1_IMAGE_3, &CMsgExamView::OnExam111Image3)
ON_COMMAND(ID_EXAM_11_1_IMAGE_4, &CMsgExamView::OnExam111Image4)
ON_COMMAND(ID_CHAP12_ARRAY_OBJECT, &CMsgExamView::OnChap12ArrayObject)
ON_COMMAND(ID_CHAP12_TEMPLATE_ARRAY, &CMsgExamView::OnChap12TemplateArray)
ON_COMMAND(ID_CHAP12_TEMPLATE_LIST, &CMsgExamView::OnChap12TemplateList)
ON_COMMAND(ID_CHAP12_ARRAY_STORE, &CMsgExamView::OnChap12ArrayStore)
ON_COMMAND(ID_TEST_EXAM_12_1, &CMsgExamView::OnTest_EXAM_12_1)
ON_COMMAND(ID_CHAP13_FOAMVIEW, &CMsgExamView::OnChap13Foamview)
ON_COMMAND(ID_CHAP9_STYLE_MENU, &CMsgExamView::OnChap9StyleMenu)
ON_COMMAND(ID_CHAP9_COLORDLG, &CMsgExamView::OnChap9Colordlg)
ON_COMMAND(ID_TEST_PROGRESSBAR, &CMsgExamView::OnTestProgressbar)
END_MESSAGE_MAP()

// CMsgExamView 생성/소멸

CMsgExamView::CMsgExamView()
	: m_ShapeType(0)
	, m_nColor(0)
	, m_bColorApply(FALSE)
	, horizontalStatus(0)
	, verticalStatus(0)
	, textExam501(_T(""))
	, m_pDlg(NULL)
	, ImageTabSheet(NULL)
	, imageNumber(0)
	, imageResolution(0)
	, chap11_char(0)
	, x_pos(0)
	, pt(0)
	, mousePos(0)
	, mouseDragPos(0)
	, mouseDragFlag(0)
	, imgResolution_Exam11(0)
	, imgNumber_Exam11(0)
	, lButtonFlag(0)
	, brushStyle(HS_HORIZONTAL)
	, dotType(PS_SOLID)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_TextColor = RGB(255, 255, 255);
	m_BackColor = RGB(255, 255, 255);
	brColor = RGB(255, 0, 0);
	m_PenColor = RGB(0, 0, 255);
}

CMsgExamView::~CMsgExamView()
{
}

BOOL CMsgExamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}
 
// CMsgExamView 그리기

void CMsgExamView::OnDraw(CDC* pDC)
{
	CMsgExamDoc* pDoc = GetDocument();
	CRect rect(200, 200, 1400, 700);
	int width = rect.Width();
	int height = rect.Height();
	GetClientRect(pDoc->m_TestRect401);
	GetClientRect(pDoc->m_TestRect402);

	CString strMsg;
	strMsg.Empty();

	static int result_Test10_1 = -1;

	//GetClientRect(&rect);

	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;

	switch (pDoc->getChapter()) {
		case CHAP5:
		{
			// TODO : 도형안에 색상 적용하기
			COLORREF colors[] = {RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255), RGB(255, 0, 255)};
			CBrush myBrush;
			CBrush *pOldBrush;

			if (m_bColorApply == TRUE) {
				switch (m_nColor) {
				case RED : strMsg = "빨간색";
					break;
				case GREEN : strMsg = "초록색";
					break;
				case BLUE : strMsg = "파란색";
					break;
				case PURPLE : strMsg = "자홍색";
					break;
				}
				myBrush.CreateSolidBrush(colors[m_nColor]);

				pOldBrush = pDC->SelectObject(&myBrush);
			}
			switch (m_ShapeType) {
			case CIRCLE_DLG : strMsg += " 원";
				pDC->Ellipse(&rect);
				break;
			case RECTANGLE_DLG : strMsg += " 사각형";
				pDC->Rectangle(&rect);
				break;
			case LINE_DLG : strMsg += " 선";
				pDC->MoveTo(rect.left, rect.top);
				pDC->LineTo(rect.right, rect.bottom);
				break;
			default:
				// Doc에서 중심 좌표 값을 받아온다.
				pDoc->m_TestRect401.DeflateRect(pDoc->m_TestRect401.Width() / 4, pDoc->m_TestRect401.Height() / 4);
				pDC->Rectangle(&pDoc->m_TestRect401);
				pDC->MoveTo(pDoc->m_TestRect401.left, pDoc->m_TestPoint401.y);
				pDC->LineTo(pDoc->m_TestRect401.right, pDoc->m_TestPoint401.y);
				pDC->MoveTo(pDoc->m_TestPoint401.x, pDoc->m_TestRect401.top);
				pDC->LineTo(pDoc->m_TestPoint401.x, pDoc->m_TestRect401.bottom);
				pDC->DrawText(pDoc->str, pDoc->m_TestOutputRect402, DT_CENTER);
				break;

			}
			pDC->TextOutW(100, 100, strMsg);
		}
		break;

		case CHAP5_01:
			// 여기에 Exam 5 - 01 코드 추가하기
		{
			int posX;
			int posY;
			CString* textMsg = getText();

			switch (getHorizontal()) {
			case CENTER_EXAM501 :
				posX = m_szView.cx >> 1;
				break;
			case LEFT_EXAM501:
				posX = 0;
				break;
			case RIGHT_EXAM501:
				posX = m_szView.cx - 300;
				break;
			}

			switch (getVertical()) {
			case MIDDLE_EXAM501:
				posY = m_szView.cy >> 1;
				break;
			case TOP_EXAM501:
				posY = 0;
				break;
			case BOTTOM_EXAM501:
				posY = m_szView.cy - 20;
				break;
			}
			pDC->TextOutW(posX, posY, textMsg->GetString());
		}
		break;
		case CHAP8:
		{
			CRect rc;
			GetClientRect(&rc);
			int width_chap8 = rc.Width() / 2;
			int height_chap8 = rc.Height() / 2;
			CPen myPen;
			CPen * pOldPen;
			CBrush myBrush;
			CBrush * pOldBrush;

			CFont cFont;
			CFont * oldFont;

			cFont.CreateFont(30, 15, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE,
				DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY, DEFAULT_PITCH, _T("궁서체"));
			
			myPen.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
			pOldPen = pDC->SelectObject(&myPen);
			myBrush.CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));
			pOldBrush = pDC->SelectObject(&myBrush);

			rc.DeflateRect(width_chap8 / 4, height_chap8 / 4);

			pDC->Rectangle(&rc);
			pDC->SelectStockObject(GRAY_BRUSH);
			pDC->Rectangle(50, 50, 100, 100);

			pDC->TextOutW(200, 50, _T("안녕하세요. MFC 테스트입니다."));
			oldFont = pDC->SelectObject(&cFont);
			pDC->TextOutW(200, 100, _T("안녕하세요. MFC 테스트입니다. 짠!!"));

			pDC->SelectObject(oldFont);
			cFont.DeleteObject();
			
			pDC->SelectObject(pOldPen);
			myPen.DeleteObject();
			pDC->SelectObject(pOldBrush);
			myBrush.DeleteObject();
		}
		break;
		case CHAP8_01:
		{
			CDC MemDC;
			MemDC.CreateCompatibleDC(pDC);
			CBitmap bitmap;
			bitmap.LoadBitmapW(IDB_BITMAP4);
			CBitmap *pOldBitmap = (CBitmap *) MemDC.SelectObject(&bitmap);

			pDC->BitBlt(50, 50, 982, 653, &MemDC, 0, 0, SRCCOPY);
			pDC->BitBlt(1100, 400, 200, 200, &MemDC, 200, 200, SRCCOPY);
			MemDC.SelectObject(pOldBitmap);
			bitmap.DeleteObject();
		}
		break;
		case EXAM8_01:
		{
			CRect rc;
			GetClientRect(&rc);
			int width_exam8 = rc.Width();
			int height_exam8 = rc.Height();
			CPen myPen;
			CPen * pOldPen;
			CBrush myBrush;
			CBrush * pOldBrush;
			COLORREF brushColor;

			myPen.CreatePen(getDotType(), 1, penColor);
			pOldPen = pDC->SelectObject(&myPen);
			brushColor = RGB(255, 255, 0);
			myBrush.CreateHatchBrush(getBrushStyle(), brushColor);
			pOldBrush = pDC->SelectObject(&myBrush);

			rc.DeflateRect(width_exam8 / 4, height_exam8 / 4);

			pDC->Rectangle(&rc);
			pDC->SelectStockObject(GRAY_BRUSH);

			pDC->SelectObject(pOldPen);
			myPen.DeleteObject();
			pDC->SelectObject(pOldBrush);
			myBrush.DeleteObject();
		}
		break;
		case CHAP9_01:
		{
			CRect rc;
			GetClientRect(&rc);
			int width_chap9 = rc.Width();
			int height_chap9 = rc.Height();
			CPen myPen;
			CPen * pOldPen;
			CBrush *myBrush;
			
			// 테두리 선 색깔
			myPen.CreatePen(getDotType(), 1, RGB(0, 0, 0));
			pOldPen = pDC->SelectObject(&myPen);
			// 내부 채우기 색깔
			myBrush = &m_Brush;
			
			rc.DeflateRect(width_chap9 / 4, height_chap9 / 4);

			pDC->Rectangle(&rc);
			pDC->SelectObject(myBrush);
						
			myPen.DeleteObject();
		}
		break;
		case CHAP9_02:
		{
			CFont newFont;
			CFont *pOldFont;

			newFont.CreateFontIndirectW(&m_logFont);
			pOldFont = (CFont *)pDC->SelectObject(&newFont);

			pDC->SetTextColor(m_FontColor);
			pDC->TextOutW(100, 100, _T("글꼴 공통 대화상자를 학습 중입니다."));

			pDC->SelectObject(pOldFont);
			newFont.DeleteObject();
		}
		break;
		case CHAP9_03:
		{
			COLORREF colors[] = {RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255), RGB(255, 0, 255)};
			CRect rect;
			CBrush myBrush;
			CBrush *pOldBrush;

			GetClientRect(&rect);

			if (getColorApply() == TRUE) {
				int colorNumber;
				colorNumber = getColor();
				myBrush.CreateSolidBrush(colors[colorNumber]);

				pOldBrush = pDC->SelectObject(&myBrush);
			}

			switch (getShapeType()) {
			case 0:
				pDC->Ellipse(&rect);
				break;
			case 1:
				pDC->Rectangle(&rect);
				break;
			case 2:
				pDC->MoveTo(rect.left, rect.top);
				pDC->LineTo(rect.right, rect.bottom);
				break;
			default:
				MessageBox(_T("잘못된 값입니다요~~~"));
				break;
			}

			if (getColorApply() == TRUE) {
				pDC->SelectObject(pOldBrush);
				myBrush.DeleteObject();
			}
		}
		break;
		case EXAM9_01:
		{
			CDC MemDC;
			MemDC.CreateCompatibleDC(pDC);
			CBitmap bitmap;
			bitmap.LoadBitmapW(bmpIDmap[imageNumber]);
			CBitmap *pOldBitmap = (CBitmap *) MemDC.SelectObject(&bitmap);

//			pDC->BitBlt(50, 50, 982, 653, &MemDC, 0, 0, SRCCOPY);
			pDC->StretchBlt(50, 50, 982 >> imageResolution, 653 >> imageResolution, &MemDC, 0, 0, 982, 653, SRCCOPY);
			pDC->BitBlt(1100, 400, 200, 200, &MemDC, 200, 200, SRCCOPY);
			MemDC.SelectObject(pOldBitmap);
			bitmap.DeleteObject();
		}
		break;
		case CHAP10_1:
		{
			if (result_Test10_1 == -1) {
				result_Test10_1 = m_ImgList.Create(IDB_BITMAP10, 168, 5, ILC_COLOR24);
			}

			m_ImgList.Draw(pDC, 0, CPoint(10, 10), ILD_NORMAL);
			m_ImgList.Draw(pDC, 1, CPoint(200, 10), ILD_NORMAL);
			m_ImgList.Draw(pDC, 2, CPoint(400, 10), ILD_NORMAL);
			m_ImgList.Draw(pDC, 3, CPoint(600, 10), ILD_NORMAL);
			m_ImgList.Draw(pDC, 4, CPoint(800, 10), ILD_NORMAL);
		}
		break;
		case CHAP10_4:
		{
			CPaintDC dc(this);
			CBrush NewBrush;
			CBrush *oldBrush;

			NewBrush.CreateSolidBrush(m_sliderDlg->m_rectColor);
			oldBrush = dc.SelectObject(&NewBrush);
			dc.Rectangle(&m_sliderDlg->m_rectPic);
			dc.SelectObject(oldBrush);
			NewBrush.DeleteObject();
		}
		break;
		case CHAP11_1:
		{
			CClientDC dc(this);
			CString str;

			str.Format(_T("%c"), chap11_char);
			if (chap11_char >= 'A' && chap11_char <= 'Z' || chap11_char >= 'a' && chap11_char <= 'z' || chap11_char >= '0' && chap11_char <= '9') {
				dc.TextOutW(x_pos, 100, str, 1);
			}
		}
		break;
		case CHAP11_2:
		{
			CClientDC dc(this);

			dc.TextOutW(pt.x, pt.y, _T("A"));
		}
		break;
		case CHAP11_3:
		{
			CClientDC dc(this);
			CString str;
			str.Format(_T("위치 : (%d, %d)"), mousePos.x, mousePos.y);

			dc.TextOutW(mousePos.x, mousePos.y, str);
		}
		break;
		case CHAP11_4:
		{
			CClientDC dc(this);
			CBrush newBrush(RGB(255, 0, 0));
			CBrush *pOldBrush = dc.SelectObject(&newBrush);

			if ((mouseDragFlag & MK_LBUTTON) == MK_LBUTTON) {
				dc.Ellipse(mouseDragPos.x - 10, mouseDragPos.y - 10, mouseDragPos.x + 10, mouseDragPos.y + 10);
			}
			newBrush.DeleteObject();
			dc.SelectObject(pOldBrush);
		}
		break;
		case CHAP11_5:
		{
			CClientDC dc(this);
			CBrush newBrush(brColor);
			CBrush *pOldBrush = dc.SelectObject(&newBrush);

			if ((mouseDragFlag & MK_LBUTTON) == MK_LBUTTON) {
				dc.Ellipse(mouseDragPos.x - 10, mouseDragPos.y - 10, mouseDragPos.x + 10, mouseDragPos.y + 10);
			}
			newBrush.DeleteObject();
			dc.SelectObject(pOldBrush);
		}
		break;
		case EXAM11_01:
		{
			CDC MemDC;
			MemDC.CreateCompatibleDC(pDC);
			CBitmap bitmap;
			bitmap.LoadBitmapW(bmpIDmap[imgNumber_Exam11]);
			CBitmap *pOldBitmap = (CBitmap *) MemDC.SelectObject(&bitmap);

			pDC->StretchBlt(50, 50, 982 >> imgResolution_Exam11, 653 >> imgResolution_Exam11, &MemDC, 0, 0, 982, 653, SRCCOPY);
			pDC->BitBlt(1100, 400, 200, 200, &MemDC, 200, 200, SRCCOPY);
			MemDC.SelectObject(pOldBitmap);
			bitmap.DeleteObject();
		}
		break;
		case CHAP12_04:
		{
			CClientDC dc(this);
			CBrush newBrush(brColor);
			CBrush *pOldBrush = dc.SelectObject(&newBrush);

			for (int i = 0;i < pDoc->m_ptArray.GetSize();i++) {
				CPoint point = pDoc->m_ptArray[i];
				dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);
			}

			if ((mouseDragFlag & MK_LBUTTON) == MK_LBUTTON) {
				dc.Ellipse(mouseDragPos.x - 10, mouseDragPos.y - 10, mouseDragPos.x + 10, mouseDragPos.y + 10);
			}
			newBrush.DeleteObject();
			dc.SelectObject(pOldBrush);
		}
		break;
		case EXAM12_1:
		{
			CClientDC dc(this);
			CString str;

			for (int i = 0;i < pDoc->m_ptArrayChar.GetSize();i++) {
				CPoint point = pDoc->m_ptArrayChar[i];
				str.Format(_T("위치 : (%d, %d)"), point.x, point.y);
				dc.TextOutW(point.x, point.y, str);
			}

			if ((mouseDragFlag & MK_LBUTTON) == MK_LBUTTON) {
				str.Format(_T("위치 : (%d, %d)"), mousePos.x, mousePos.y);
				dc.TextOutW(mousePos.x, mousePos.y, str);
			}
		}
		break;
	}

	switch (pDoc->getChapter()) {
		case CHAP9_01:
			// Doc에서 중심 좌표 값을 받아온다.
			pDoc->m_TestRect401.DeflateRect(pDoc->m_TestRect401.Width() / 4, pDoc->m_TestRect401.Height() / 4);
			pDC->Rectangle(&pDoc->m_TestRect401);
			pDC->MoveTo(pDoc->m_TestRect401.left, pDoc->m_TestPoint401.y);
			pDC->LineTo(pDoc->m_TestRect401.right, pDoc->m_TestPoint401.y);
			pDC->MoveTo(pDoc->m_TestPoint401.x, pDoc->m_TestRect401.top);
			pDC->LineTo(pDoc->m_TestPoint401.x, pDoc->m_TestRect401.bottom);
			pDC->DrawText(pDoc->str, pDoc->m_TestOutputRect402, DT_CENTER);
		break;
	}
}


// CMsgExamView 인쇄

BOOL CMsgExamView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMsgExamView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMsgExamView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMsgExamView 진단

#ifdef _DEBUG
void CMsgExamView::AssertValid() const
{
	CView::AssertValid();
}

void CMsgExamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMsgExamDoc* CMsgExamView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMsgExamDoc)));
	return (CMsgExamDoc*)m_pDocument;
}
#endif //_DEBUG


// CMsgExamView 메시지 처리기


void CMsgExamView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("윈도우 크기 변경 \n 현재 윈도우 사이즈는 x : %d, y : %d 입니다."), cx, cy);
#if defined(_DEBUG_ON_)
	MessageBox(str);
#endif
	m_szView.cx = cx;
	m_szView.cy = cy;
	cView = CSize(cx, cy);
	pt = CPoint(cx / 2, cy / 2);
}


void CMsgExamView::OnTextBlack()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
#if defined(_DEBUG_ON_)
	MessageBox(_T("검정색"));
#endif
	m_TextColor = RGB(0, 0, 0);
	Invalidate();
}


void CMsgExamView::OnTextBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
#if defined(_DEBUG_ON_)
	MessageBox(_T("파란색"));
#endif
	m_TextColor = RGB(0, 0, 255);
	Invalidate();
}


void CMsgExamView::OnTextGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
#if defined(_DEBUG_ON_)
	MessageBox(_T("초록색"));
#endif
	m_TextColor = RGB(0, 255, 0);
	Invalidate();
}


void CMsgExamView::OnTextRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
#if defined(_DEBUG_ON_)
	MessageBox(_T("빨간색"));
#endif
	m_TextColor = RGB(255, 0, 0);
	Invalidate();
}


void CMsgExamView::OnUpdateTextBlack(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_TextColor == RGB(0, 0, 0));
}


void CMsgExamView::OnUpdateTextRed(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_TextColor == RGB(255, 0, 0));
}


void CMsgExamView::OnUpdateTextGreen(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_TextColor == RGB(0, 255, 0));
}


void CMsgExamView::OnUpdateTextBlue(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_TextColor == RGB(0, 0, 255));
}


void CMsgExamView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//CString str;
	//str.Format(_T("px : %ld, py : %ld", point.x, point.y));
	//MessageBox(str);
	CMenu menu;
	menu.LoadMenu(IDR_MAINFRAME);
	CMenu *pContextMenu = menu.GetSubMenu(4);
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}


void CMsgExamView::OnBackBlack()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_BackColor = RGB(0, 0, 0);
	Invalidate();
}


void CMsgExamView::OnBackBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_BackColor = RGB(0, 0, 255);
	Invalidate();
}


void CMsgExamView::OnBackGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_BackColor = RGB(0, 255, 0);
	Invalidate();
}


void CMsgExamView::OnBackRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_BackColor = RGB(255, 0, 0);
	Invalidate();
}


void CMsgExamView::OnUpdateBackBlue(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_BackColor == RGB(0, 0, 255));
}


void CMsgExamView::OnUpdateBackBlack(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_BackColor == RGB(0, 0, 0));
}


void CMsgExamView::OnUpdateBackGreen(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_BackColor == RGB(0, 255, 0));
}


void CMsgExamView::OnUpdateBackRed(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(m_BackColor == RGB(255, 0, 0));
}


void CMsgExamView::OnTest405()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// 배경이 빨간색
	m_BackColor = RGB(255, 0, 0);
	Invalidate(TRUE);
}


void CMsgExamView::OnMydialog()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMyDlg dlg;

	int res = dlg.DoModal();

	if (res == IDCANCEL) {
		MessageBox(_T("<취소> 버튼이 눌려서 대화상자가 닫힘"));
		return;
	}
	else if (res == IDOK) {
		MessageBox(_T("<확인> 버튼이 눌려서 대화상자가 닫힘"));
	}
	CString strMsg;

	strMsg.Format(_T("\n 이름 : %s \n 이메일 : %s \n 핸드폰 번호 : %s"), dlg.m_strName, dlg.m_strEmail, dlg.m_strHPhone);
	MessageBox(strMsg);
}


void CMsgExamView::OnShapeselect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP5);

	if (m_pDlg == NULL) {
		m_pDlg = new CShapeDlg(this);
		m_pDlg->setColorApply(this->getColorApply());
		m_pDlg->setShape(this->getShapeType());
		m_pDlg->setColor(this->getColor());
		m_pDlg->Create(IDD_DIALOG_SHAPE, this);
		m_pDlg->ShowWindow(SW_SHOW);
	}
	Invalidate();
}

void CMsgExamView::OnTest501()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDlgExam501 dlg;
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP5_01);

	if (dlg.DoModal() == IDCANCEL) return;

	setHorizontal(dlg.getHorizontal());
	setVertical(dlg.getVertical());
	setText(dlg.getText()->GetString());

	Invalidate();
}


void CMsgExamView::OnCalcExecute()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CCalcDlg dlg;
	int result = dlg.DoModal();
	CString strMsg;

	if(result == IDOK) {
		strMsg.Format(_T("[수1] %d [수2] %d [결과값] %d  "), dlg.getNum1(), dlg.getNum2(), dlg.getNumResult());
		MessageBox(strMsg);
	}
}


void CMsgExamView::OnTest601()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDlgExam501 dlg;
	CMsgExamDoc* pDoc = GetDocument();

	int result = dlg.DoModal();

	pDoc->setChapter(CHAP5_01);
	if(result == IDCANCEL) {
		return;
	}

	setHorizontal(dlg.getHorizontal());
	setVertical(dlg.getVertical());
	setText(dlg.getText()->GetString());

	Invalidate();
}


void CMsgExamView::OnTest701()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDlgExam701 dlg;
	CMsgExamDoc* pDoc = GetDocument();

	int result = dlg.DoModal();
	pDoc->setChapter(CHAP7_01);

	if (result == IDOK) {
		MessageBox(_T("OKOKOK"));
	}
	else if (result == IDCANCEL) {
		MessageBox(_T("CANCEL CANCEL"));
	}
}


void CMsgExamView::OnChap8Gdiexam()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP8);
	Invalidate();
}


void CMsgExamView::OnChap8Bitmapexam()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP8_01);
	Invalidate();
}


void CMsgExamView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	static int nChangeBmpID = 0;
	CBitmap bitmap;

	nChangeBmpID++;
	if (nChangeBmpID == MAX_BITMAP_ID) {
		nChangeBmpID = 0;
	}	

	bitmap.LoadBitmapW(bmpIDmap[nChangeBmpID]);

	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CClientDC dc(this);
	CDC MemDC;
	
	MemDC.CreateCompatibleDC(&dc);
	MemDC.SelectObject(&bitmap);

	CRect rect;
	GetClientRect(&rect);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	bitmap.DeleteObject();

	CView::OnRButtonDown(nFlags, point);
}


void CMsgExamView::OnExam801Red()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	penColor = RGB(255, 0, 0);
	Invalidate();
}


void CMsgExamView::OnExam801Green()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	penColor = RGB(0, 255, 0);
	Invalidate();
}


void CMsgExamView::OnExam801Blue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	penColor = RGB(0, 0, 255);
	Invalidate();
}


void CMsgExamView::OnExam802HatchHorizontal()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	setBrushStyle(HS_HORIZONTAL);
	Invalidate();
}


void CMsgExamView::OnExam802HatchVertical()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	setBrushStyle(HS_VERTICAL);
	Invalidate();
}


void CMsgExamView::OnExam802Hatch45degLtor()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	setBrushStyle(HS_BDIAGONAL);
	Invalidate();
}


void CMsgExamView::OnExam802Hatch45degRtol()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	setBrushStyle(HS_FDIAGONAL);
	Invalidate();
}


void CMsgExamView::OnExam802HatchCross()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	setBrushStyle(HS_CROSS);
	Invalidate();
}


void CMsgExamView::OnExam802Hatch45degCross()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM8_01);
	setBrushStyle(HS_DIAGCROSS);
	Invalidate();
}


int CMsgExamView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CClientDC dc(this);
	CFont *pFont = dc.GetCurrentFont();
	
	pFont->GetLogFont(&m_logFont);

	return 0;
}


void CMsgExamView::OnChap9FontMenu()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	CFontDialog dlg(&m_logFont);

	if(dlg.DoModal() == IDCANCEL) {
		return;
	}

	pDoc->setChapter(CHAP9_02);

	dlg.GetCurrentFont(&m_logFont);
	m_FontColor = dlg.GetColor();
	Invalidate();
}


void CMsgExamView::OnChap9ModalessMenu()
{
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP9_03);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (m_pDlg == NULL) {
		m_pDlg = new CShapeDlg(this);
		m_pDlg->setColorApply(this->getColorApply());
		m_pDlg->setShape(this->getShapeType());
		m_pDlg->setColor(this->getColor());
		m_pDlg->Create(IDD_DIALOG_SHAPE, this);
		m_pDlg->ShowWindow(SW_SHOW);
	}
	else if (m_pDlg != NULL) {
		m_pDlg->SetFocus();
	}
}


void CMsgExamView::OnTestTest901()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
#if defined(_DEBUG_ON_)
	CImageTab imageTab(_T("Test 9 종합 문제"));
	
	if (imageTab.DoModal() == IDCANCEL) {
		return;
	}
#endif

	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM9_01);

	if (ImageTabSheet == NULL) {
		ImageTabSheet = new CImageTab(_T("Test 9 종합문제"), this);
		ImageTabSheet->Create();
		ImageTabSheet->ShowWindow(SW_SHOW);
	}
#if defined(_DEBUG_ON_)
	else if(ImageTabSheet != NULL) {
		ImageTabSheet->ImageChangePage.SetFocus();
	}
#endif
	Invalidate();
}


void CMsgExamView::OnChap101()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP10_1);
	Invalidate();
}


void CMsgExamView::OnChap102()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();
	CTreeExam dlg;

	pDoc->setChapter(CHAP10_2);
	dlg.DoModal();
}


void CMsgExamView::OnChap103()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();
	CListExamDlg dlg;

	pDoc->setChapter(CHAP10_3);
	dlg.DoModal();
}


void CMsgExamView::OnChap10Slider()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();
	CSliderExamDlg dlg = new CSliderExamDlg(m_sliderDlg);

	pDoc->setChapter(CHAP10_4);

	dlg.DoModal();
}


void CMsgExamView::OnChap11Wm()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_1);
}


void CMsgExamView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rectPos(0, 95, 5, 105);
	chap11_char = nChar;

	rectPos.left = x_pos - 5;
	rectPos.right = x_pos + 5;
	x_pos += 8;

	InvalidateRect(rectPos, 0);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMsgExamView::OnChap11WmKeydown()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_2);
}


void CMsgExamView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	CRect rectPos;

	switch (nChar) {
	case VK_UP:
		pt.y -= 12;
		if (pt.y < 0) {
			pt.y = cView.cy;
		}
		break;
	case VK_DOWN:
		pt.y += 12;
		if (pt.y > cView.cy) {
			pt.y = 0;
		}
		break;
	case VK_LEFT:
		pt.x -= 10;
		if (pt.x < 0) {
			pt.x = cView.cx;
		}
		break;
	case VK_RIGHT:
		pt.x += 10;
		if (pt.x > cView.cx) {
			pt.x = 0;
		}
		break;
	}
	rectPos.left = pt.x - 5;
	rectPos.right = pt.x + 5;
	rectPos.top = pt.y - 5;
	rectPos.bottom = pt.y + 5;

	InvalidateRect(rectPos, 0);
}


void CMsgExamView::OnChap11WmLbuttondown()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_3);
}


void CMsgExamView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMsgExamDoc* pDoc = GetDocument();
	CRect rectPos;
	
	mousePos.x = point.x;
	mousePos.y = point.y;
	lButtonFlag = nFlags;

	rectPos.left = mousePos.x - 20;
	rectPos.right = mousePos.x + 20;
	rectPos.top = mousePos.y - 5;
	rectPos.bottom = mousePos.y + 5;

	InvalidateRect(rectPos, 0);

	pDoc->m_ptArrayChar.Add(point);

	CView::OnLButtonDown(nFlags, point);
}


void CMsgExamView::OnChap11WmMousemove()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_4);
}


void CMsgExamView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rectPos;
	CString msg;
	CMsgExamDoc* pDoc = GetDocument();

	msg.Format(_T("(%d, %d)"), point.x, point.y);

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_wndStatusBar.SetPaneText(2, msg);

	mouseDragPos.x = point.x;
	mouseDragPos.y = point.y;
	mouseDragFlag = nFlags;

	rectPos.left = mouseDragPos.x - 10;
	rectPos.right = mouseDragPos.x + 10;
	rectPos.top = mouseDragPos.y - 10;
	rectPos.bottom = mouseDragPos.y + 10;

	InvalidateRect(rectPos, 0);

	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) {
		pDoc->m_ptArray.Add(point);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMsgExamView::OnBrushRed()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_5);
	brColor = RGB(255, 0, 0);
}


void CMsgExamView::OnBrushGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_5);
	brColor = RGB(0, 255, 0);
}


void CMsgExamView::OnBrushBlue()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP11_5);
	brColor = RGB(0, 0, 255);
}


void CMsgExamView::OnExam111Resize100()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgResolution_Exam11 = 0;
	Invalidate();
}


void CMsgExamView::OnExam111Resize50()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgResolution_Exam11 = 1;
	Invalidate();
}


void CMsgExamView::OnExam111Resize25()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgResolution_Exam11 = 2;
	Invalidate();
}


void CMsgExamView::OnExam111Resize10()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgResolution_Exam11 = 3;
	Invalidate();
}


void CMsgExamView::OnExam111Image1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgNumber_Exam11 = 0;
	Invalidate();
}


void CMsgExamView::OnExam111Image2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgNumber_Exam11 = 1;
	Invalidate();
}


void CMsgExamView::OnExam111Image3()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgNumber_Exam11 = 2;
	Invalidate();
}


void CMsgExamView::OnExam111Image4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM11_01);
	imgNumber_Exam11 = 3;
	Invalidate();
}


void CMsgExamView::OnChap12ArrayObject()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP12_01);

	CStringArray array;
	CString str(_T("배열 객체를 생성하자마자 배열 원소의 개수 : "));
	CString temp;

	temp.Format(_T("%d"), array.GetSize());
	str.Append(temp);

	array.Add(_T("사과"));
	array.Add(_T("배"));
	array.Add(_T("바나나"));
	array.Add(_T("파인애플"));
	
	temp.Empty();
	temp.Format(_T("%d"), array.GetSize());
	str.Append(_T("\n배열 객체에 Add 메소드로 원소를 추가 후 배열 원소의 개수 : "));
	str.Append(temp);
	str.Append(_T("\n배열의 내용을 출력\n"));
	temp.Empty();
	for (int i = 0;i < array.GetSize();i++) {
		temp.Append(array[i].GetString());
		temp.Append(_T(" "));
	}
	str.Append(temp);

	array.InsertAt(2, _T("메롱메롱"));
	temp.Empty();
	temp.Append(_T("\n"));
	for (int i = 0;i < array.GetSize();i++) {
		temp.Append(_T(" "));
		temp.Append(array[i].GetString());
	}
	str.Append(temp);

	array.RemoveAt(3);
	temp.Empty();
	temp.Append(_T("\n"));
	for (int i = 0;i < array.GetSize();i++) {
		temp.Append(_T(" "));
		temp.Append(array[i].GetString());
	}
	str.Append(temp);

	MessageBox(str);
}


void CMsgExamView::OnChap12TemplateArray()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP12_02);

	CArray<CPoint3D, CPoint3D&> array;
	array.SetSize(5);

	for (int i = 0;i < array.GetSize();i++) {
		array[i] = CPoint3D((i + 1) * 10, (i + 1) * 10, (i + 1) * 10);
	}
	 
	for (int i = 0;i < array.GetSize();i++) {
		array[i].Prn();
	}
}


void CMsgExamView::OnChap12TemplateList()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP12_03);

	CList<CPoint3D, CPoint3D&> list;

	for (int i = 0;i < 5;i++) {
		list.AddTail (CPoint3D ((i + 1) * 10, (i + 1) * 10, (i + 1) * 10));
	}

	POSITION pos = list.GetHeadPosition();

	while (pos != NULL) {
		CPoint3D data = list.GetNext(pos);
		data.Prn2();
	}
}


void CMsgExamView::OnChap12ArrayStore()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP12_04);
}


void CMsgExamView::OnTest_EXAM_12_1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(EXAM12_1);
}


void CMsgExamView::OnChap13Foamview()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMsgExamDoc* pDoc = GetDocument();

	pDoc->setChapter(CHAP13_FOAM_VIEW);

	CInfo dlg;

	dlg.DoModal();
}


void CMsgExamView::OnChap9StyleMenu()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CTabSheet myDlg(_T("스타일 탭 대화상자"));
	CMsgExamDoc* pDoc = GetDocument();

	myDlg.m_PenPage.setPenStyle(getDotType());
	myDlg.m_BrushPage.setBrushStyle(getBrushStyle());

	if (myDlg.DoModal() == IDCANCEL) {
		return;
	}
	m_Brush.DeleteObject();
	m_Brush.CreateHatchBrush(myDlg.m_BrushPage.getBrushStyle(), 0);
	setDotType(myDlg.m_PenPage.getPenStyle());
	pDoc->setChapter(CHAP9_01);
	pDoc->UpdateAllViews(NULL);
}


void CMsgExamView::OnChap9Colordlg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg(getPenColor());
	CMsgExamDoc* pDoc = GetDocument();
	
	if (dlg.DoModal() == IDCANCEL)
	{
		return;
	}
	m_Brush.DeleteObject();
	m_Brush.CreateSolidBrush(dlg.GetColor());
	
	pDoc->setChapter(CHAP9_01);
	pDoc->UpdateAllViews(NULL);
}


void CMsgExamView::OnTestProgressbar()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CProgressBar dlg;
	dlg.DoModal();
}
