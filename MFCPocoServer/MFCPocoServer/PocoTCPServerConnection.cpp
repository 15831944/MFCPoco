#include "stdafx.h"
#include "PocoTCPServerConnection.h"

#include "Poco/Util/Application.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Exception.h"
#include "Poco/Config.h"
#include "Poco/DateTimeFormat.h"

using Poco::Util::Application;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;

#define WM_SERVER_MESSAGE   WM_USER+1000；

PocoTCPServerConnection::PocoTCPServerConnection(CWnd *mainDlg,const StreamSocket &s,const string& arg1, int arg2, double arg3):
	TCPServerConnection(s), pMainDlg(mainDlg), _arg1(arg1), _arg2(arg2), _arg3(arg3)
{
}


void PocoTCPServerConnection::run()
{
	//Application& app = Application::instance();
	//// 日志输出连接的TCP用户的地址（IP和端口）
	//app.logger().information("Request from " + this->socket().peerAddress().toString());
	//

	    StreamSocket& message = socket();
		MFCPocoServerDlg *pDlg = (MFCPocoServerDlg *)pMainDlg;
		try
		{
			char buf[1024] = { 0 };
			int n = message.receiveBytes(buf, sizeof(buf));
			while (n > 0)
			{
				message.sendBytes(buf, n);
				//TRACE("message(%d):%s\r\n",n, buf);
				pDlg->OnTcpServerMessage(buf,n);
				memset(buf,0,sizeof(buf));
				n = 0;
				n = message.receiveBytes(buf, sizeof(buf));
			}
			TRACE("PocoTCPServerConnection run exit");
		}
		catch (Poco::Exception& e)
		{
			/*std::cout << e.what() << std::endl;*/
			TRACE("exception:%s\r\n", e.displayText());
		}


	//HWND hWnd = AfxGetApp()->GetMainWnd()->GetSafeHwnd(); //第一种
	//::SendMessage(::GetParent(hWnd), WM_SERVER_MESSAGE, a, b); //第二种

	//CMainFrame *pFrame;
	//pFrame = (CMainFrame*)AfxGetMainWnd();
	//PostMessageW(pFrame->m_hWnd, WM_MY_MESSAGE, NULL, NULL);
	//pFrame = (CMainFrame*)AfxGetMainWnd();


	//try
	//{
	//	//string format(config().getString("PocoTcpServer.format", DateTimeFormat::ISO8601_FORMAT));
	//	// 向客户端发送数据，这里以发送一个表示时间的字符串为例
	//	Timestamp now;
	//	string dt(DateTimeFormatter::format(now, ""));
	//	dt.append("\r\n");
	//	socket().sendBytes(dt.data(), (int)dt.length());
	//}
	//catch (Poco::Exception& e)
	//{
	//	app.logger().log(e);
	//}
}


PocoTCPConnectionFactory::PocoTCPConnectionFactory(CWnd *mainDlg, const string arg1, int arg2, double arg3):
	pMainDlg(mainDlg),
	_arg1(arg1),
	_arg2(arg2),
	_arg3(arg3)
{
}

TCPServerConnection* PocoTCPConnectionFactory::createConnection(const Poco::Net::StreamSocket& socket)
{
	TRACE("new PocoTCPServerConnection");
	return new PocoTCPServerConnection(pMainDlg,socket, _arg1, _arg2, _arg3);
}

