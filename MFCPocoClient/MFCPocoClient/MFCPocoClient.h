
// MFCProtocolDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// MFCPocoClientApp: 
// �йش����ʵ�֣������ MFCProtocolDemo.cpp
//

class MFCPocoClientApp : public CWinApp
{
public:
	MFCPocoClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern MFCPocoClientApp theApp;