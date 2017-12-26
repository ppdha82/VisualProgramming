
// MsgExamView.h : CMsgExamView 클래스의 인터페이스
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"

class CShapeDlg;
class CImageTab;
class CSliderExamDlg;

#define __CHAP13_VIEW_CHANGE__

class CMsgExamView : public CView
{
public:
	CShapeDlg *m_pDlg;
	CImageTab *ImageTabSheet;

	CSliderExamDlg *m_sliderDlg;
#if defined(__CHAP13_VIEW_CHANGE__)
public:
#else
protected: // serialization에서만 만들어집니다.
#endif
	CMsgExamView();
	DECLARE_DYNCREATE(CMsgExamView)

// 특성입니다.
public:
	CMsgExamDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMsgExamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CSize m_szView;
	afx_msg void OnTextBlack();
	afx_msg void OnTextBlue();
	afx_msg void OnTextGreen();
	afx_msg void OnTextRed();
	COLORREF m_TextColor;
	COLORREF m_BackColor;
	afx_msg void OnUpdateTextBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateTextBlue(CCmdUI *pCmdUI);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnBackBlack();
	afx_msg void OnBackBlue();
	afx_msg void OnBackGreen();
	afx_msg void OnBackRed();
	afx_msg void OnUpdateBackBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBackRed(CCmdUI *pCmdUI);
	afx_msg void OnTest405();
	afx_msg void OnMydialog();
	afx_msg void OnShapeselect();
private:
	int m_ShapeType;
	int m_nColor;
	BOOL m_bColorApply;
	CBrush m_Brush;

public:
	void setShapeType(int shape) {
		m_ShapeType = shape;
	}
	void setColor(int color) {
		m_nColor = color;
	}
	void setColorApply(BOOL colorApply) {
		m_bColorApply = colorApply;
	}
	int getShapeType() {
		return m_ShapeType;
	}
	int getColor() {
		return m_nColor;
	}
	BOOL getColorApply() {
		return m_bColorApply;
	}
	afx_msg void OnTest501();
private:
	int horizontalStatus;
	int verticalStatus;
	int brushStyle;

public:
	void setHorizontal(int horizon)
	{
		horizontalStatus = horizon;
	}
	
	void setVertical(int vertical)
	{
		verticalStatus = vertical;
	}

	int getHorizontal(void)
	{
		return horizontalStatus;
	}

	int getVertical(void)
	{
		return verticalStatus;
	}

	void setBrushStyle(int style)
	{
		brushStyle = style;
	}
	int getBrushStyle(void)
	{
		return brushStyle;
	}

private:
	COLORREF m_PenColor;
public:
	void setPenColor(COLORREF color)
	{
		m_PenColor = color;
	}
	COLORREF getPenColor(void)
	{
		return m_PenColor;
	}
private:
	int dotType;
public:
	void setDotType(int type)
	{
		dotType = type;
	}
	int getDotType(void)
	{
		return dotType;
	}

private:
	CString textExam501;
public:
	void setText(CString text)
	{
		textExam501.Empty();
		textExam501.Format(text.GetString());
	}

	CString* getText(void)
	{
		return &textExam501;
	}
	afx_msg void OnCalcExecute();
	afx_msg void OnTest601();
	afx_msg void OnTest701();
	afx_msg void OnChap8Gdiexam();
	afx_msg void OnChap8Bitmapexam();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

	COLORREF penColor;
	afx_msg void OnExam801Red();
	afx_msg void OnExam801Green();
	afx_msg void OnExam801Blue();

	afx_msg void OnExam802HatchHorizontal();
	afx_msg void OnExam802HatchVertical();
	afx_msg void OnExam802Hatch45degLtor();
	afx_msg void OnExam802Hatch45degRtol();
	afx_msg void OnExam802HatchCross();
	afx_msg void OnExam802Hatch45degCross();
	LOGFONT m_logFont;
	COLORREF m_FontColor;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChap9FontMenu();
	afx_msg void OnChap9ModalessMenu();
	afx_msg void OnTestTest901();

public:
	int imageNumber;
	int imageResolution;
	CImageList m_ImgList;
	afx_msg void OnChap101();
	afx_msg void OnChap102();
	afx_msg void OnChap103();
	afx_msg void OnChap10Slider();
	afx_msg void OnChap11Wm();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	UINT chap11_char;
	int x_pos;
	afx_msg void OnChap11WmKeydown();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CSize cView;
	CPoint pt;
	afx_msg void OnChap11WmLbuttondown();
	CPoint mousePos;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChap11WmMousemove();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint mouseDragPos;
	UINT mouseDragFlag;
	COLORREF brColor;
	afx_msg void OnBrushRed();
	afx_msg void OnBrushGreen();
	afx_msg void OnBrushBlue();
	afx_msg void OnExam111Resize100();
	int imgResolution_Exam11;
	int imgNumber_Exam11;
	afx_msg void OnExam111Resize50();
	afx_msg void OnExam111Resize25();
	afx_msg void OnExam111Resize10();
	afx_msg void OnExam111Image1();
	afx_msg void OnExam111Image2();
	afx_msg void OnExam111Image3();
	afx_msg void OnExam111Image4();
	afx_msg void OnChap12ArrayObject();
	afx_msg void OnChap12TemplateArray();
	afx_msg void OnChap12TemplateList();
	afx_msg void OnChap12ArrayStore();
	afx_msg void OnTest_EXAM_12_1();
	UINT lButtonFlag;
	afx_msg void OnChap13Foamview();
	afx_msg void OnChap9StyleMenu();
	afx_msg void OnChap9Colordlg();
	afx_msg void OnTestProgressbar();
};

#ifndef _DEBUG  // MsgExamView.cpp의 디버그 버전
inline CMsgExamDoc* CMsgExamView::GetDocument() const
   { return reinterpret_cast<CMsgExamDoc*>(m_pDocument); }
#endif

