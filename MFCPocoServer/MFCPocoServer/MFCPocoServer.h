
// MFCProtocolDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// MFCPocoServerApp: 
// �йش����ʵ�֣������ MFCProtocolDemo.cpp
//

class MFCPocoServerApp : public CWinApp
{
public:
	MFCPocoServerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern MFCPocoServerApp theApp;