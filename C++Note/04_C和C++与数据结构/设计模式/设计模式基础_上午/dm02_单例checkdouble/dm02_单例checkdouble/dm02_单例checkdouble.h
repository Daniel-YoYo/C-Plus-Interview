
// dm02_单例checkdouble.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Cdm02_单例checkdoubleApp:
// 有关此类的实现，请参阅 dm02_单例checkdouble.cpp
//

class Cdm02_单例checkdoubleApp : public CWinApp
{
public:
	Cdm02_单例checkdoubleApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cdm02_单例checkdoubleApp theApp;