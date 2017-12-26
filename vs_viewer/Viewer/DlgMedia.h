#pragma once

#include "dib.h"

// CDlgMedia 대화 상자입니다.
class IMedia;
class IVideoDecompress;
class CFrame;

class CDlgMedia : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMedia)

public:
	CDlgMedia(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMedia();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_MEDIA };
	unsigned int framecnt;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	BOOL SetMediaFileName(CString strFName);

protected:
	IMedia * _m_pMedia;
	IVideoDecompress * _m_pVDec;
	CDib _m_dib;
	BOOL _Output(CFrame * pFrame, CDC * pDC);

public:
	virtual BOOL DestroyWindow();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
