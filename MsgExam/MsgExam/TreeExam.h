#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTreeExam 대화 상자입니다.

class CTreeExam : public CDialog
{
	DECLARE_DYNAMIC(CTreeExam)

public:
	CTreeExam(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTreeExam();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
	CTreeCtrl c_Tree;
	CString m_strSel;
	CString m_strData;
	HTREEITEM m_hRoot;
	CImageList m_ImgList;
	virtual BOOL OnInitDialog();
	afx_msg void OnTvnSelchangingTree1(NMHDR *pNMHDR, LRESULT *pResult);
	HTREEITEM m_hSelectItem;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMod();
	afx_msg void OnBnClickedButtonDel();
};
