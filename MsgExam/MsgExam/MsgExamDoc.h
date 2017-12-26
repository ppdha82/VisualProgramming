
// MsgExamDoc.h : CMsgExamDoc Ŭ������ �������̽�
//


#pragma once
#include "atltypes.h"


class CMsgExamDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CMsgExamDoc();
	DECLARE_DYNCREATE(CMsgExamDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CMsgExamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
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
