// ShapeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MsgExam.h"
#include "ShapeDlg.h"
#include "MsgExamDoc.h"
#include "MsgExamView.h"
#include "afxdialogex.h"


// CShapeDlg ��ȭ �����Դϴ�.

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


// CShapeDlg �޽��� ó�����Դϴ�.


void CShapeDlg::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	setRedEnable(getColorApply());
	setGreenEnable(getColorApply());
	setBlueEnable(getColorApply());
	setMagentaEnable(getColorApply());
}


void CShapeDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	pView->m_pDlg = NULL;

	CDialog::OnCancel();
}


void CShapeDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnBnClickedChap5Apply();

	if (pView->m_pDlg != NULL) {
		pView->m_pDlg = NULL;
	}

	CDialog::OnOK();
}


void CShapeDlg::OnBnClickedChap5Apply()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	pView->setColorApply(getColorApply());
	pView->setColor(getColor());
	pView->setShapeType(getShape());
	pView->Invalidate();
}
