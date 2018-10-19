#include "stdafx.h"
//#include "SocketConnectorTest.h"
//
//#include <iostream>
//#include "Poco/Observer.h"
//#include "Poco/Net/SocketNotification.h"
//#include "Poco/Net/SocketReactor.h"
//#include "Poco/Net/SocketAddress.h"
//#include "Poco/Net/StreamSocket.h"
//
//
//#define MAX_RECV_BUF_SIZE      1024
//#define MAX_ONSEND_INTERVAL    5000    /// ms
//
//using Poco::Observer;
//using Poco::Net::ReadableNotification;
//using Poco::Net::WritableNotification;
//using Poco::Net::TimeoutNotification;
//using Poco::Net::SocketNotification;
//using Poco::Net::SocketReactor;
//using Poco::Net::SocketAddress;
//using Poco::Net::StreamSocket;
//
//
//	class ClientServiceHandler
//	{
//	public:
//		ClientServiceHandler(StreamSocket& socket, SocketReactor& reactor) :
//			m_socket(socket),
//			m_reactor(reactor),
//			m_or(*this, &ClientServiceHandler::onReadable),
//			m_ow(*this, &ClientServiceHandler::onWritable),
//			m_ot(*this, &ClientServiceHandler::onTimeout),
//			m_timeout(false),
//			m_closeOnTimeout(false)
//		{
//			sm_IsConnect = true;
//			m_reactor.addEventHandler(m_socket, m_or);
//			m_reactor.addEventHandler(m_socket, m_ow);
//			m_reactor.addEventHandler(m_socket, m_ot);
//		}
//
//		~ClientServiceHandler()
//		{
//			m_reactor.removeEventHandler(m_socket, Poco::Observer<ClientServiceHandler, Poco::Net::ReadableNotification>(*this, &ClientServiceHandler::onReadable));
//			m_reactor.removeEventHandler(m_socket, Poco::Observer<ClientServiceHandler, Poco::Net::WritableNotification>(*this, &ClientServiceHandler::onWritable));
//			m_reactor.removeEventHandler(m_socket, Poco::Observer<ClientServiceHandler, Poco::Net::TimeoutNotification>(*this, &ClientServiceHandler::onTimeout));
//		}
//
//		void onReadable(ReadableNotification* pNf)
//		{
//			pNf->release();
//			char cRecvBuf[MAX_RECV_BUF_SIZE] = { "" };
//			int nRecvLength = m_socket.receiveBytes(cRecvBuf, sizeof(cRecvBuf));
//			if (nRecvLength > 0)
//			{
//				m_strRecvBuf = cRecvBuf;
//			}
//			else
//			{
//				std::cout << "ServiveHandler Read Error." << std::endl;
//				sm_IsConnect = false;
//				m_reactor.stop();
//				m_socket.close();
//				delete this;
//			}
//		}
//
//		void onWritable(WritableNotification* pNf)
//		{
//			pNf->release();
//			m_strRecvBuf = "Poco Test demo.";
//			int nSndLength = m_socket.sendBytes(m_strRecvBuf.c_str(), m_strRecvBuf.length());
//			if (nSndLength < 0)
//			{
//				std::cout << "ServiveHandler Wirte Error." << std::endl;
//			}
//			Poco::Thread::sleep(MAX_ONSEND_INTERVAL);
//		}
//
//		void onTimeout(TimeoutNotification* pNf)
//		{
//			pNf->release();
//			std::cout << "ServiveHandler TimeOut." << std::endl;
//			m_timeout = true;
//			if (m_closeOnTimeout)
//			{
//				sm_IsConnect = false;
//				m_reactor.stop();
//				m_socket.close();
//				delete this;
//			}
//		}
//
//	public:
//		static bool IsConnect()
//		{
//			return sm_IsConnect;
//		}
//
//	private:
//		StreamSocket m_socket;
//		SocketReactor& m_reactor;
//		Observer<ClientServiceHandler, ReadableNotification> m_or;
//		Observer<ClientServiceHandler, WritableNotification> m_ow;
//		Observer<ClientServiceHandler, TimeoutNotification> m_ot;
//		std::string m_strRecvBuf;
//		bool m_timeout;
//		bool m_closeOnTimeout;
//	private:
//		static bool sm_IsConnect;
//
//	};
//	bool ClientServiceHandler::sm_IsConnect = false;
//
//
