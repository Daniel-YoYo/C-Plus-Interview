
// dm02_����checkdouble.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cdm02_����checkdoubleApp:
// �йش����ʵ�֣������ dm02_����checkdouble.cpp
//

class Cdm02_����checkdoubleApp : public CWinApp
{
public:
	Cdm02_����checkdoubleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cdm02_����checkdoubleApp theApp;