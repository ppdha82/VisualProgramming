// CalcDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "CalcDlg.h"
#include "afxdialogex.h"


// CCalcDlg ��ȭ �����Դϴ�.

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


// CCalcDlg �޽��� ó�����Դϴ�.


void CCalcDlg::OnBnClickedButtonPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	setNumResult(getNum1() + getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	setNumResult(getNum1() - getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonMultiply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	setNumResult(getNum1() * getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	setNumResult(getNum1() / getNum2());
	UpdateData(FALSE);
}


void CCalcDlg::OnBnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	setNum1(0);
	setNum2(0);
	setNumResult(0);
	UpdateData(FALSE);
}
