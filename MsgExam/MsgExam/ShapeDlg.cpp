// ShapeDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ShapeDlg.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "afxdialogex.h"


// CShapeDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CShapeDlg, CDialog)

CShapeDlg::CShapeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShapeDlg::IDD, pParent)
	, m_nShape(FALSE)
	, m_nColor(0)
	, m_bColorApply(TRUE)
{
	this->pParent = pParent;
	pView = (CMsgExamView *)pParent;
}

CShapeDlg::~CShapeDlg()
{
}

void CShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nShape);
	DDX_Radio(pDX, IDC_RADIO4, m_nColor);
	DDX_Check(pDX, IDC_CHECK1, m_bColorApply);
	DDX_Control(pDX, IDC_RADIO4, c_Red);
	DDX_Control(pDX, IDC_RADIO5, c_Green);
	DDX_Control(pDX, IDC_RADIO6, c_Blue);
	DDX_Control(pDX, IDC_RADIO7, c_Magenta);
}


BEGIN_MESSAGE_MAP(CShapeDlg, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &CShapeDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDCANCEL, &CShapeDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CShapeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHAP5_APPLY, &CShapeDlg::OnBnClickedChap5Apply)
END_MESSAGE_MAP()


// CShapeDlg 메시지 처리기입니다.


void CShapeDlg::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	setRedEnable(getColorApply());
	setGreenEnable(getColorApply());
	setBlueEnable(getColorApply());
	setMagentaEnable(getColorApply());
}


void CShapeDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pView->m_pDlg = NULL;

	CDialog::OnCancel();
}


void CShapeDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnBnClickedChap5Apply();

	if (pView->m_pDlg != NULL) {
		pView->m_pDlg = NULL;
	}

	CDialog::OnOK();
}


void CShapeDlg::OnBnClickedChap5Apply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	pView->setColorApply(getColorApply());
	pView->setColor(getColor());
	pView->setShapeType(getShape());
	pView->Invalidate();
}
