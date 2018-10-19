//
//
//
//#ifndef Net_SocketConnectorTest_INCLUDED
//#define Net_SocketConnectorTest_INCLUDED
//
//
//#include "Poco/Net/Net.h"
//#include "Poco/Net/SocketNotification.h"
//#include "Poco/Net/SocketAddress.h"
//#include "Poco/Net/StreamSocket.h"
//#include "Poco/Observer.h"
//
//
//namespace Poco {
//	namespace Net {
//		template <class ServiceHandler>
//		class SocketConnector
//		{
//		public:
//			explicit SocketConnector(SocketAddress& address) :
//				_pReactor(0)
//			{
//				_socket.connectNB(address);
//			}
//
//			SocketConnector(SocketAddress& address, SocketReactor& reactor) :
//				_pReactor(0)
//			{
//				_socket.connectNB(address);
//				registerConnector(reactor);
//			}
//
//			virtual ~SocketConnector()
//			{
//				try
//				{
//					unregisterConnector();
//				}
//				catch (...)
//				{
//					poco_unexpected();
//				}
//			}
//
//			virtual void registerConnector(SocketReactor& reactor)
//			{
//				_pReactor = &reactor;
//				_pReactor->addEventHandler(_socket, Poco::Observer<SocketConnector, ReadableNotification>(*this, &SocketConnector::onReadable));
//				_pReactor->addEventHandler(_socket, Poco::Observer<SocketConnector, WritableNotification>(*this, &SocketConnector::onWritable));
//				_pReactor->addEventHandler(_socket, Poco::Observer<SocketConnector, TimeoutNotification>(*this, &SocketConnector::onTimeout));
//				_pReactor->addEventHandler(_socket, Poco::Observer<SocketConnector, ErrorNotification>(*this, &SocketConnector::onError));
//			}
//
//			virtual void unregisterConnector()
//			{
//				if (_pReactor)
//				{
//					_pReactor->removeEventHandler(_socket, Poco::Observer<SocketConnector, ReadableNotification>(*this, &SocketConnector::onReadable));
//					_pReactor->removeEventHandler(_socket, Poco::Observer<SocketConnector, WritableNotification>(*this, &SocketConnector::onWritable));
//					_pReactor->removeEventHandler(_socket, Poco::Observer<SocketConnector, TimeoutNotification>(*this, &SocketConnector::onTimeout));
//					_pReactor->removeEventHandler(_socket, Poco::Observer<SocketConnector, ErrorNotification>(*this, &SocketConnector::onError));
//				}
//			}
//
//			void onReadable(ReadableNotification* pNotification)
//			{
//				pNotification->release();
//				int err = _socket.impl()->socketError();
//				if (err)
//				{
//					onError(err);
//					unregisterConnector();
//				}
//				else
//				{
//					onConnect();
//				}
//			}
//
//			void onWritable(WritableNotification* pNotification)
//			{
//				pNotification->release();
//				onConnect();
//			}
//
//			void onTimeout(TimeoutNotification* pNotification)
//			{
//				pNotification->release();
//				onError(_socket.impl()->socketError());
//			}
//
//			void onError(ErrorNotification* pNotification)
//			{
//				pNotification->release();
//				onError(_socket.impl()->socketError());
//				/// delete
//			}
//
//			void onConnect()
//			{
//				_socket.setBlocking(true);
//				createServiceHandler();
//				unregisterConnector();
//			}
//
//		protected:
//			virtual ServiceHandler* createServiceHandler()
//			{
//				return new ServiceHandler(_socket, *_pReactor);
//			}
//
//			virtual void onError(int errorCode)
//			{
//				_pReactor->stop();       /// add
//				_socket.close();         /// add
//										 //delete this;             /// add
//			}
//
//			SocketReactor* reactor()
//			{
//				return _pReactor;
//			}
//
//			StreamSocket& socket()
//			{
//				return _socket;
//			}
//
//		private:
//			SocketConnector();
//			SocketConnector(const SocketConnector&);
//			SocketConnector& operator = (const SocketConnector&);
//
//			StreamSocket   _socket;
//			SocketReactor* _pReactor;
//		};
//
//
//	}
//}
//
//
//#endif 
//
//
//
//
