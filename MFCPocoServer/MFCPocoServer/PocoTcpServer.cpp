#include "stdafx.h"
//
//#include "PocoTcpServer.h"
//
//#include "Config.h"
//
//#include <winsvc.h>
//
////#include "Poco/Net/ServerSocket.h"
////#include <Poco/Net/TCPServer.h>
////#include <Poco/Net/TCPServerConnectionFactory.h>
////#include <Poco/Net/TCPServerConnection.h>
////#include <Poco/Net/StreamSocket.h>
////#include <Poco/Timespan.h>
////#include <Poco/DateTimeFormat.h>
////
////using Poco::Net::TCPServerConnectionFactory;
////using Poco::Net::TCPServerConnection;
////using Poco::Net::StreamSocket;
////using Poco::Net::TCPServer;
////using Poco::Net::TCPServerParams;
////using Poco::Net::ServerSocket;
////using Poco::Timespan;
////using Poco::DateTimeFormat;
//
//void PocoTcpServer::initialize(Application& self)
//{
//	ServerApplication::loadConfiguration();
//	ServerApplication::initialize(self);
//}
//
//void PocoTcpServer::uninitialize()
//{
//	ServerApplication::uninitialize();
//}
//
//int PocoTcpServer::main(const std::vector<std::string>& args)
//{
//	unsigned short port = (unsigned short)config().getInt("CustomTCPServer.port", ServerPort);
//
//	//unsigned short port = (unsigned short)config().getInt("PocoTcpServer.port", 12346);
//	//string format(config().getString("PocoTcpServer.format",DateTimeFormat::ISO8601_FORMAT));
//
//	//// 1. Bind a ServerSocket with an address
//	//ServerSocket serverSocket(port);
//
//	//// 2. Pass the ServerSocket to a TCPServer
//	//TCPServer server(new PocoTcpServer(format), serverSocket);
//
//	//// 3. Start the TCPServer
//	//server.start();
//
//	//// 4. Wait for termination
//	//waitForTerminationRequest();
//
//	//// 5. Stop the TCPServer
//	//server.stop();
//
//	return Application::EXIT_OK;
//}
//
//
//
