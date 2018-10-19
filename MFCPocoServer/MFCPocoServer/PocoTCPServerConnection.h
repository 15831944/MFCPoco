
#ifndef POCO_TCP_CONNECTION_H
#define POCO_TCP_CONNECTION_H

#include <string>
#include <sstream>
using namespace std;

#include "MFCPocoServerDlg.h"

#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/StreamSocket.h"
using Poco::Net::TCPServerConnection;
using Poco::Net::StreamSocket;

#include "Poco/Net/TCPServerConnectionFactory.h"
using Poco::Net::TCPServerConnectionFactory;


class PocoTCPServerConnection : public TCPServerConnection
{
public:
	PocoTCPServerConnection(
		CWnd *pMainDlg,
		const StreamSocket& s,
		const std::string& arg1,
		int arg2,
		double arg3);
	void run();
public:
	CWnd  *pMainDlg;
	string _arg1;
	int _arg2;
	double _arg3;
};


class PocoTCPConnectionFactory : public TCPServerConnectionFactory
{
public:
	PocoTCPConnectionFactory(
		CWnd *main,
		const string arg1, 
		int arg2, 
		double arg3);
	TCPServerConnection* createConnection(const Poco::Net::StreamSocket& socket);
public:
	CWnd  *pMainDlg;
	string  _arg1;
	int      _arg2;
	double   _arg3;
};


#endif


