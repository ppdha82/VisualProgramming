// BrushDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "BrushDlg.h"
#include "afxdialogex.h"


// CBrushDlg ��ȭ �����Դϴ�.

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


// CBrushDlg �޽��� ó�����Դϴ�.
