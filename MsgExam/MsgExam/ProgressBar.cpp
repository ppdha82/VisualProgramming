// ProgressBar.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ProgressBar.h"
#include "afxdialogex.h"


// CProgressBar ��ȭ �����Դϴ�.

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


// CProgressBar �޽��� ó�����Դϴ�.


void CProgressBar::OnBnClickedButtonAuto()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	for (int i = 0;i < 100;i++) {
		c_Progress.SetPos(i);
		Sleep(10);
	}
}


void CProgressBar::OnBnClickedButtonReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	c_Progress.SetPos(0);
}


void CProgressBar::OnBnClickedButtonStepbystep()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	c_Progress.SetStep(2);
	c_Progress.StepIt();
}


BOOL CProgressBar::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	c_Progress.SetRange(0, 99);
	c_Progress.SetPos(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
