
// MsgExam.h : MsgExam ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMsgExamApp:
// �� Ŭ������ ������ ���ؼ��� MsgExam.cpp�� �����Ͻʽÿ�.
//

class CMsgExamApp : public CWinApp
{
public:
	CMsgExamApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMsgExamApp theApp;
