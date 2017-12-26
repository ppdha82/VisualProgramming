// ProgressBar.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ProgressBar.h"
#include "afxdialogex.h"


// CProgressBar 대화 상자입니다.

IMPLEMENT_DYNAMIC(CProgressBar, CDialog)

CProgressBar::CProgressBar(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressBar::IDD, pParent)
{

}

CProgressBar::~CProgressBar()
{
}

void CProgressBar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, c_Progress);
}


BEGIN_MESSAGE_MAP(CProgressBar, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_AUTO, &CProgressBar::OnBnClickedButtonAuto)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CProgressBar::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_STEPBYSTEP, &CProgressBar::OnBnClickedButtonStepbystep)
END_MESSAGE_MAP()


// CProgressBar 메시지 처리기입니다.


void CProgressBar::OnBnClickedButtonAuto()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0;i < 100;i++) {
		c_Progress.SetPos(i);
		Sleep(10);
	}
}


void CProgressBar::OnBnClickedButtonReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	c_Progress.SetPos(0);
}


void CProgressBar::OnBnClickedButtonStepbystep()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	c_Progress.SetStep(2);
	c_Progress.StepIt();
}


BOOL CProgressBar::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	c_Progress.SetRange(0, 99);
	c_Progress.SetPos(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
