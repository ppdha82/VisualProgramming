// CalcDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "CalcDlg.h"
#include "afxdialogex.h"


// CCalcDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCalcDlg, CDialog)

CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalcDlg::IDD, pParent)
	, m_nNum1(0)
	, m_nNum2(0)
	, m_nResult(0)
{

}

CCalcDlg::~CCalcDlg()
{
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM1, m_nNum1);
	DDV_MinMaxInt(pDX, m_nNum1, 0, 100);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_nNum2);
	DDV_MinMaxInt(pDX, m_nNum2, 0, 100);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_nResult);
}


BEGIN_MESSAGE_MAP(CCalcDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalcDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalcDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalcDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalcDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalcDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CCalcDlg 메시지 처리기입니다.


void CCalcDlg::OnBnClickedButtonPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	setNumResult(getNum1() + getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	setNumResult(getNum1() - getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonMultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	setNumResult(getNum1() * getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	setNumResult(getNum1() / getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	setNum1(0);
	setNum2(0);
	setNumResult(0);
	UpdateData(FALSE);
}
