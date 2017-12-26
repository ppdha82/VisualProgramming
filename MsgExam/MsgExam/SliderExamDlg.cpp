// SliderExamDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "SliderExamDlg.h"
#include "afxdialogex.h"

#define MAX_COLOR_VALUE	255

// CSliderExamDlg ��ȭ �����Դϴ�.

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


// CSliderExamDlg �޽��� ó�����Դϴ�.

BOOL CSliderExamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	c_SliderRed.SetRange(0, MAX_COLOR_VALUE);
	c_SliderGreen.SetRange(0, MAX_COLOR_VALUE);
	c_SliderBlue.SetRange(0, MAX_COLOR_VALUE);

	GetDlgItem(IDC_STATIC_PICTURE)->GetWindowRect(&m_rectPic);

	ScreenToClient(&m_rectPic);

	m_rectColor = RGB(MAX_COLOR_VALUE, MAX_COLOR_VALUE, MAX_COLOR_VALUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	changeRectColor();
	*pResult = 0;
}


void CSliderExamDlg::OnNMReleasedcaptureSliderGreen(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	changeRectColor();
	*pResult = 0;
}


void CSliderExamDlg::OnNMReleasedcaptureSliderBlue(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	changeRectColor();
	*pResult = 0;
}