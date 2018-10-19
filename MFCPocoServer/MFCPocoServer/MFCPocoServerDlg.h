
// MFCProtocolDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "Config.h"
#include "resource.h"
//#include <iostream>
//#include <sstream>
//using namespace std;
//

#include "PocoTCPServerConnection.h"
//#include <string>
//using namespace std;

#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerParams.h>
#include "Poco/Net/ServerSocket.h"
#include "afxcmn.h"
#include "afxwin.h"
//#include <Poco/Net/TCPServerConnectionFactory.h>
//#include <Poco/Net/TCPServerConnection.h>
//#include <Poco/Net/StreamSocket.h>
//#include <Poco/Timespan.h>
//#include "Poco/Timestamp.h"

//using Poco::Net::TCPServerConnectionFactory;
//using Poco::Net::TCPServerConnection;
//using Poco::Net::StreamSocket;

//using Poco::Timespan;
//using Poco::Timestamp;

using Poco::Net::ServerSocket;
using Poco::Net::TCPServer;
using Poco::Net::TCPServerParams;







// MFCPocoServerDlg �Ի���
class MFCPocoServerDlg : public CDialogEx
{
// ����
public:
	MFCPocoServerDlg(CWnd* pParent = NULL);	// ��׼���캯��
public:
	TCPServer *pmServer;
	TCPServerParams::Ptr pmServerParams;

// �Ի�������
	enum { IDD = IDD_MFCPROTOCOLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	int  OnTcpServerMessage(char *buffer, int n);
	void MFCPocoServerDlg::ShowEditMessage(CString m_str);
	void OnReceiveData(const unsigned char *pData, unsigned int length);
	unsigned char CaclCheckSum(const unsigned char *pData, unsigned int length);
	void OnData(const unsigned char *pData, unsigned int dataLen);
	void OnAckCode(const unsigned char *pData, unsigned int dataLen);
	void OnNakCode(const unsigned char *pData, unsigned int dataLen);
	void FillCtrlMsg(unsigned char *pCmd, unsigned int cmdlen, unsigned char *pData, unsigned int datalen);
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonTest01();
	afx_msg void OnBnClickedButton1();
	virtual BOOL DestroyWindow();
	//CRichEditCtrl m_editRcvMessage;
	CEdit m_editRcvMessage;
};
