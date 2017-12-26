#pragma once

#include "dib.h"

// CDlgMedia ��ȭ �����Դϴ�.
class IMedia;
class IVideoDecompress;
class CFrame;

class CDlgMedia : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMedia)

public:
	CDlgMedia(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgMedia();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MEDIA };
	unsigned int framecnt;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
