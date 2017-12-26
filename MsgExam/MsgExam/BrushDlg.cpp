// BrushDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "BrushDlg.h"
#include "afxdialogex.h"


// CBrushDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CBrushDlg, CPropertyPage)

CBrushDlg::CBrushDlg()
	: CPropertyPage(CBrushDlg::IDD)
	, m_nBrushStyle(0)
{

}

CBrushDlg::~CBrushDlg()
{
}

void CBrushDlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nBrushStyle);
}


BEGIN_MESSAGE_MAP(CBrushDlg, CPropertyPage)
END_MESSAGE_MAP()


// CBrushDlg 메시지 처리기입니다.
