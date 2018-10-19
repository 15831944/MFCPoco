
// PoechantTCPConnection.h

#ifndef POCO_TCP_CONNECTION_H
#define POCO_TCP_CONNECTION_H

#include <string>
using namespace std;




#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/StreamSocket.h"
using Poco::Net::TCPServerConnection;
using Poco::Net::StreamSocket;



class PocoTcpConnection : public TCPServerConnection
{
public:
	PocoTcpConnection(StreamSocket& s,const std::string& arg1,int arg2,double arg3);
	void run();
private:
	std::string _arg1;
	int _arg2;
	double _arg3;
};

#endif
