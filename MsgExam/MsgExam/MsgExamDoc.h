
// MsgExamDoc.h : CMsgExamDoc 클래스의 인터페이스
//


#pragma once
#include "atltypes.h"


class CMsgExamDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CMsgExamDoc();
	DECLARE_DYNCREATE(CMsgExamDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMsgExamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnTest401();
	CRect m_TestRect401;
	CPoint m_TestPoint401;
	CString str;
	CRect m_TestRect402;
	CPoint m_TestPoint402;
	CRect m_TestOutputRect402;
	afx_msg void OnTest402HorizonCenter();
	afx_msg void OnTest402HorizonLeft();
	afx_msg void OnTest402HorizonRight();
private:
	int statusHorizontal;
	int statusVertical;
	enum {
		UP = 0,
		MIDDLE,
		DOWN,
		MAX_VERTICAL
	};
	enum {
		LEFT = 0,
		CENTER,
		RIGHT,
		MAX_HORIZONTAL
	};

public:
	int GetStatusHorizontal(void);
	int GetStatusVertical(void);
	void SetStatusHorizontal(int placeHorizontal);
	void SetStatusVertical(int placeVertical);
	bool CalculateBorder(int placeHorizontal, int placeVertical, CPoint *CenterPoint);
	afx_msg void OnTest402VerticalUp();
	afx_msg void OnTest402VerticalMiddle();
	afx_msg void OnTest402VerticalDown();
private:
	COLORREF m_bkColor;
public:
	bool getBackColor(COLORREF& color);
	void setBackColor(COLORREF color);

private:
	int chapter;
public:
	void setChapter(int chap) {
		chapter = chap;
	}
	int getChapter() {
		return chapter;
	}
public:
	CArray <CPoint, CPoint&> m_ptArray;
	CArray <CPoint, CPoint&> m_ptArrayChar;
};
