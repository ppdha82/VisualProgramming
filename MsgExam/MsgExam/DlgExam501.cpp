// DlgExam501.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "DlgExam501.h"
#include "afxdialogex.h"


// CDlgExam501 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgExam501, CDialog)

CDlgExam501::CDlgExam501(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgExam501::IDD, pParent)
	, horizontalStatus(0)
	, verticalStatus(0)
	, textExam501(_T(""))
	, applyValueHorizontal(FALSE)
{

}

CDlgExam501::~CDlgExam501()
{
}

void CDlgExam501::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_TEST_5_01_LEFT, horizontalStatus);
	DDX_Radio(pDX, IDC_TEST_5_01_TOP, verticalStatus);
	DDX_Text(pDX, IDC_EDIT_TEST_5_01, textExam501);
	DDX_Control(pDX, IDC_TEST_5_01_TOP, applyTop);
	DDX_Control(pDX, IDC_TEST_5_01_LEFT, applyLeft);
	DDX_Control(pDX, IDC_TEST_5_01_CENTER, applyCenter);
	DDX_Control(pDX, IDC_TEST_5_01_RIGHT, applyRight);
	DDX_Control(pDX, IDC_TEST_5_01_MIDDLE, applyMiddle);
	DDX_Control(pDX, IDC_TEST_5_01_BOTTOM, applyBottom);
	DDX_Radio(pDX, IDC_APPLY_HORIZONTAL, applyValueHorizontal);
}


BEGIN_MESSAGE_MAP(CDlgExam501, CDialog)
	ON_BN_CLICKED(IDC_APPLY_HORIZONTAL, &CDlgExam501::OnBnClickedApplyHorizontal)
	ON_BN_CLICKED(IDC_APPLY_VERTICAL, &CDlgExam501::OnBnClickedApplyVertical)
	ON_BN_CLICKED(IDC_APPLY_BOTH, &CDlgExam501::OnBnClickedApplyBoth)
END_MESSAGE_MAP()


// CDlgExam501 메시지 처리기입니다.


void CDlgExam501::OnBnClickedApplyHorizontal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	showLeftRadio(SW_SHOW);
	showRightRadio(SW_SHOW);
	showCenterRadio(SW_SHOW);

	showTopRadio(SW_HIDE);
	showBottomRadio(SW_HIDE);
	showMiddleRadio(SW_HIDE);
}


void CDlgExam501::OnBnClickedApplyVertical()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	showLeftRadio(SW_HIDE);
	showRightRadio(SW_HIDE);
	showCenterRadio(SW_HIDE);

	showTopRadio(SW_SHOW);
	showBottomRadio(SW_SHOW);
	showMiddleRadio(SW_SHOW);
}


void CDlgExam501::OnBnClickedApplyBoth()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	showLeftRadio(SW_SHOW);
	showRightRadio(SW_SHOW);
	showCenterRadio(SW_SHOW);

	showTopRadio(SW_SHOW);
	showBottomRadio(SW_SHOW);
	showMiddleRadio(SW_SHOW);
}
