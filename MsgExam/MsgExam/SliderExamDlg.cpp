// SliderExamDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "SliderExamDlg.h"
#include "afxdialogex.h"

#define MAX_COLOR_VALUE	255

// CSliderExamDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSliderExamDlg, CDialog)

CSliderExamDlg::CSliderExamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSliderExamDlg::IDD, pParent)
{

}

CSliderExamDlg::~CSliderExamDlg()
{
}

void CSliderExamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_RED, c_Red);
	DDX_Control(pDX, IDC_SLIDER_RED, c_SliderRed);
	DDX_Control(pDX, IDC_STATIC_GREEN, c_Green);
	DDX_Control(pDX, IDC_SLIDER_GREEN, c_SliderGreen);
	DDX_Control(pDX, IDC_STATIC_BLUE, c_Blue);
	DDX_Control(pDX, IDC_SLIDER_BLUE, c_SliderBlue);
}


BEGIN_MESSAGE_MAP(CSliderExamDlg, CDialog)
	ON_WM_PAINT()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_RED, &CSliderExamDlg::OnNMReleasedcaptureSliderRed)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_GREEN, &CSliderExamDlg::OnNMReleasedcaptureSliderGreen)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_BLUE, &CSliderExamDlg::OnNMReleasedcaptureSliderBlue)
END_MESSAGE_MAP()


// CSliderExamDlg 메시지 처리기입니다.

BOOL CSliderExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	c_SliderRed.SetRange(0, MAX_COLOR_VALUE);
	c_SliderGreen.SetRange(0, MAX_COLOR_VALUE);
	c_SliderBlue.SetRange(0, MAX_COLOR_VALUE);

	GetDlgItem(IDC_STATIC_PICTURE)->GetWindowRect(&m_rectPic);

	ScreenToClient(&m_rectPic);

	m_rectColor = RGB(MAX_COLOR_VALUE, MAX_COLOR_VALUE, MAX_COLOR_VALUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CSliderExamDlg::OnPaint()
{
	CPaintDC dc(this);
	CBrush NewBrush;
	CBrush* oldBrush;

	NewBrush.CreateSolidBrush(m_rectColor);
	oldBrush = dc.SelectObject(&NewBrush);
	dc.Rectangle(&m_rectPic);
	dc.SelectObject(oldBrush);
	NewBrush.DeleteObject();

	CDialog::OnPaint();
}


void CSliderExamDlg::changeRectColor(void)
{
	int nRed	= c_SliderRed.GetPos();
	int nGreen	= c_SliderGreen.GetPos();
	int nBlue	= c_SliderBlue.GetPos();

	CString strTemp;
	strTemp.Format(_T("%3d"), nRed);
	c_Red.SetWindowTextW(strTemp);
	
	strTemp.Empty();
	strTemp.Format(_T("%3d"), nGreen);
	c_Green.SetWindowTextW(strTemp);

	strTemp.Empty();
	strTemp.Format(_T("%3d"), nBlue);
	c_Blue.SetWindowTextW(strTemp);

	m_rectColor = RGB(nRed, nGreen, nBlue);

	InvalidateRect(&m_rectPic);
}


void CSliderExamDlg::OnNMReleasedcaptureSliderRed(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	changeRectColor();
	*pResult = 0;
}


void CSliderExamDlg::OnNMReleasedcaptureSliderGreen(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	changeRectColor();
	*pResult = 0;
}


void CSliderExamDlg::OnNMReleasedcaptureSliderBlue(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	changeRectColor();
	*pResult = 0;
}