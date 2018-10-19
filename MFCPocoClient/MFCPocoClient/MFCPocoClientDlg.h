
// MFCProtocolDemoDlg.h : ͷ�ļ�
//

#pragma once

//#include "SocketConnectorTest.h"
#include "ClientServiceHandler.h"

#include <Poco/Net/SocketReactor.h>
#include <Poco/Net/SocketAddress.h>
//#include <Poco/Net/SocketConnector.h>
using Poco::Net::SocketReactor;
using Poco::Net::SocketAddress;
//using Poco::Net::SocketConnector;

#include "Poco/Net/ServerSocket.h"
//#include <Poco/Net/TCPServer.h>
//#include <Poco/Net/TCPServerConnectionFactory.h>
//#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/StreamSocket.h>
//
//
//
//#include <Poco/Timespan.h>
//
//
//#include <iostream>
//#include <sstream>
//using namespace std;
//
//using Poco::Net::TCPServerConnectionFactory;
//using Poco::Net::TCPServerConnection;//���캯����Ҫ StreamSocket
using Poco::Net::StreamSocket;
//
//using Poco::Net::TCPServer;
//using Poco::Net::TCPServerParams;
//
using Poco::Net::ServerSocket;
//
//using Poco::Timespan;



// MFCPocoClientDlg �Ի���
class MFCPocoClientDlg : public CDialogEx
{
// ����
public:
	MFCPocoClientDlg(CWnd* pParent = NULL);	// ��׼���캯��
public:
	StreamSocket *pTcpClient;

	/*TCPServer *pmServer;
	TCPServerParams::Ptr pmServerParams;*/

// �Ի�������
	enum { IDD = IDD_MFCPROTOCOLDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
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
	afx_msg void OnBnClickedButtonConnect();
};
