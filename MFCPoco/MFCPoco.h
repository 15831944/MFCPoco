
// MFCPoco.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCPocoApp: 
// �йش����ʵ�֣������ MFCPoco.cpp
//

class CMFCPocoApp : public CWinApp
{
public:
	CMFCPocoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCPocoApp theApp;