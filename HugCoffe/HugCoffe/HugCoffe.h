
// HugCoffe.h : HugCoffe ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHugCoffeApp:
// �� Ŭ������ ������ ���ؼ��� HugCoffe.cpp�� �����Ͻʽÿ�.
//

class CHugCoffeApp : public CWinApp
{
public:
	CHugCoffeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHugCoffeApp theApp;
