
// MFCProtocolDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCPocoClient.h"
#include "MFCPocoClientDlg.h"
#include "afxdialogex.h"
#include "type.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//#include <iostream>
//#include "Poco/Net/StreamSocket.h"
//#include "Poco/Net/SocketAddress.h"
//
//#define BUFFER_SIZE 1024
//
//using Poco::Net::SocketAddress;
//using Poco::Net::StreamSocket;

//int main(int argc, const char * argv[])
//{
//	SocketAddress address("127.0.0.1", 8099);
//	StreamSocket socket(address);
//	char buffer[BUFFER_SIZE];
//	while (true)
//	{
//		if (socket.available())
//		{
//			int len = socket.receiveBytes(buffer, BUFFER_SIZE);
//			buffer[len] = '\0';
//			std::cout << "" << buffer << std::endl;
//		}
//	}
//	return 0;
//}

//
////Poco 的　TcpServer 是一个多线程的　Tcp 服务器。
//class MyTcpServerConnection : public TCPServerConnection
//{
//public:
//	MyTcpServerConnection(const StreamSocket& s) :TCPServerConnection(s)
//	{
//	/* socket().setBlocking(false); */
//	}
//	void run(void);
//};
//
///**
//* @brief MyTcpServerConnection::run 处理链接请求的主函数
//*/
//void MyTcpServerConnection::run(void)
//{
//	StreamSocket& ss = socket();
//	try
//	{
//		char buf[1024] = { 0 };
//		int n = ss.receiveBytes(buf, sizeof(buf));
//		while (n > 0)
//		{
//			ss.sendBytes(buf, n);
//			n = ss.receiveBytes(buf, sizeof(buf));
//			std::stringstream ssbuf(buf);
//			TRACE("recvData(%d):%s\r\n", n,ssbuf.str().c_str());
//			
//			socket().sendBytes(ssbuf.str().data(), ssbuf.str().length());
//		}
//		TRACE("MyTcpServerConnection run");
//	}
//	catch (Poco::Exception& e)
//	{
//		/*std::cout << e.what() << std::endl;*/
//		TRACE("exception:%s\r\n", e.displayText());
//	}
//}
//
//class MyTcpServer : public TCPServerConnectionFactory
//{
//public:
//	inline TCPServerConnection* createConnection(const StreamSocket &socket)
//	{
//		TRACE("MyTcpServer建立与客户端连接\r\n");
//		return new MyTcpServerConnection(socket);
//	}
//};



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// MFCPocoClientDlg 对话框



MFCPocoClientDlg::MFCPocoClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MFCPocoClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MFCPocoClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MFCPocoClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &MFCPocoClientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFCPocoClientDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_TEST01, &MFCPocoClientDlg::OnBnClickedButtonTest01)
	ON_BN_CLICKED(IDC_BUTTON1, &MFCPocoClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &MFCPocoClientDlg::OnBnClickedButtonConnect)
END_MESSAGE_MAP()


// MFCPocoClientDlg 消息处理程序

BOOL MFCPocoClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
    

	SocketAddress sa("192.168.51.3", 8099);
	pTcpClient = new StreamSocket(sa);
	

	//_CrtSetBreakAlloc(143);

	// TODO:  在此添加额外的初始化代码
	//ServerSocket serverSocket(8099);
	//Timespan timeout(10, 0);
	//serverSocket.setReceiveTimeout(timeout);
	//pmServerParams = new Poco::Net::TCPServerParams;
	//pmServerParams->setMaxQueued(100);//设定队列的最大长度。
	//pmServerParams->setMaxThreads(100);//设定TcpServer 最大线程的个数。
	//pmServer = new Poco::Net::TCPServer(new MyTcpServer, serverSocket);
	//pmServer->start();

	/*while (1)
	{
		Sleep(10);
	}
	server.stop();*/
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void MFCPocoClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void MFCPocoClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR MFCPocoClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void MFCPocoClientDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void MFCPocoClientDlg::OnBnClickedCancel()
{
	//TODO:在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

////协议数据头1	通信方式1	 命令长度1 数据长度1  命令 数据  数据是否完整标志1	校验位1 协议结束标志1
//typedef struct{
//	unsigned char startTag;
//	unsigned char messageType;
//	unsigned char cmdLen;
//	unsigned char dataLen;
//	unsigned char cmd[CMD_MAX_LEN];
//	unsigned char data[DATA_MAX_LEN];
//	unsigned char dataOver;
//	unsigned char dataCRC;
//	unsigned char endTag;
//}PACKAGE_MES, *P_PACKAGE_MES;
//

//m_receiveOffset -= 1;//偏移长度减一
//strncpy_s(m_receiveDataTemp, &m_receiveData[1], m_receiveOffset);//删除这个数据
//memset(m_receiveData, 0, sizeof(m_receiveData));
//strncpy_s(m_receiveDataTemp, m_receiveDataTemp, m_receiveOffset);
//
//OnData(m_receiveData, frameLen, dataIsOver);//完成一帧进行处理
//m_receiveOffset -= frameLen;//接收数组长度减少
//strncpy_s(m_receiveDataTemp, m_receiveData, m_receiveOffset);//删除数据
//memset(m_receiveData, 0, sizeof(m_receiveData));
//strncpy_s(m_receiveDataTemp, m_receiveDataTemp, m_receiveOffset);

//void* ay_memmove(void* dst, const void* src, size_t count)
//{
//	assert(NULL != src && NULL != dst);
//	char* tmpdst = (char*)dst;
//	char* tmpsrc = (char*)src;
//
//	if (tmpdst <= tmpsrc || tmpdst >= tmpsrc + count)
//	{
//		while (count--)
//		{
//			*tmpdst++ = *tmpsrc++;
//		}
//	}
//	else
//	{
//		tmpdst = tmpdst + count - 1;
//		tmpsrc = tmpsrc + count - 1;
//		while (count--)
//		{
//			*tmpdst-- = *tmpsrc--;
//		}
//	}
//
//	return dst;
//}

//if (m_receiveOffset < FRAME_MAX_LEN - length){
//	TRACE("---------------------------------------\r\n");
//	/*TRACE("pData :%s\r\n", pData);
//	TRACE("length:%d\r\n", length);*/
//	//memmove(m_receiveData, &m_receiveData[1], m_receiveOffset);
//	TRACE("m_receiveOffset:%d\r\n", m_receiveOffset);
//	TRACE("len            :%d\r\n", FRAME_MAX_LEN - m_receiveOffset);
//	memcpy_s(&m_receiveData[m_receiveOffset], FRAME_MAX_LEN - m_receiveOffset, pData, length);
//	m_receiveOffset += length;
//	//TRACE("m_receiveData  :%s\r\n", m_receiveData);
//	TRACE("m_receiveOffset:%d\r\n", m_receiveOffset);
//}
//else
//{
//	memset(m_receiveData, 0, sizeof(m_receiveData));
//	m_receiveOffset = 0;
//}


/**************************************************************
//功能：测试接收组包，分包处理
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
void MFCPocoClientDlg::OnBnClickedButtonTest01()
{
	//TODO:  在此添加控件通知处理程序代码
	//char *pData = "01234567890123456789012345678901234567890123456789";
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x50 };//最小数据测试
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x01, 0x01,0x55,0x01, 0x00, 0x50 };//数据测试1
	unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x02, 0x02, 0x55, 0x66, 0x01, 0x00, 0x50 };//数据测试2
	//4F, 00, 01, 02, 02, 55, 66, 01, 00, 50 
	OnReceiveData(dataMin,10);
}

/**************************************************************
//功能：接收到数据缓存,组包判断，分包处理
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
unsigned char m_receiveData[FRAME_MAX_LEN] = {};    //接收数组
unsigned int  m_receiveOffset = 0;                  //接收数组的偏移
void MFCPocoClientDlg::OnReceiveData(const unsigned char *pData, unsigned int length)
{
	TRACE("------------------------接收数据组包----------------------------\r\n");
	/*for (size_t i = 0; i < length; i++)
	{
		TRACE("      缓存数据:0x%0.2x\r\n", *(pData+i));
	}*/
	TRACE("   缓存放入数据:%d\r\n", m_receiveOffset);
	memcpy_s(&m_receiveData[m_receiveOffset], FRAME_MAX_LEN - m_receiveOffset, pData, length);
	m_receiveOffset += length;
	TRACE("缓存放入数据长度:%d\r\n", m_receiveOffset);
	TRACE("------------------------解析数据包----------------------------\r\n");
	//协议数据头1	通信方式1	 命令长度1 数据长度1  命令 数据  数据是否完整标志1	校验位1 协议结束标志1
	while (m_receiveOffset >= FRAME_MIN_LEN)
	{
		if (m_receiveData[0] != REQ_STX)//协议数据头标志
		{
			m_receiveOffset -= 1;//偏移长度减一
			memmove(m_receiveData, &m_receiveData[1], m_receiveOffset);
			m_receiveData[m_receiveOffset] = 0;
			TRACE("协议数据头标志错误删除一个m_receiveData  :%s\r\n", m_receiveData);
			TRACE("协议数据头标志错误删除一个m_receiveOffset:%d\r\n", m_receiveOffset);
			continue;
		}
		unsigned int messagetype = m_receiveData[1]; //通信方式
		unsigned int cmdLen  = m_receiveData[2];     //命令长度
		unsigned int dataLen = m_receiveData[3];     //数据长度
	    //
		unsigned int frameLen = cmdLen + dataLen + TRAN_CTRL_LEN + ADDR_CODE_LEN; //帧长
		TRACE("  协议数据头标志:0x%0.2x\r\n", m_receiveData[0]);
		TRACE("       通信方式:0x%0.2x\r\n", messagetype);
		TRACE("       命令长度:0x%0.2x\r\n", cmdLen);
		TRACE("       数据长度:0x%0.2x\r\n", dataLen);
		
		if (m_receiveOffset < frameLen) //数据帧未完整
		{
			TRACE("数据帧未完整frameLen       :%s\r\n", frameLen);
			TRACE("数据帧未完整m_receiveOffset:%d\r\n", m_receiveOffset);
			return;
		}
		if (m_receiveData[frameLen - 1] != REQ_EXT) //协议结束标志
		{
			m_receiveOffset -= 1;//偏移长度减一
			memmove(m_receiveData, m_receiveData + 1, m_receiveOffset);
			TRACE("协议结束标志错误删除一个m_receiveData  :%s\r\n", m_receiveData);
			TRACE("协议结束标志错误删除一个m_receiveOffset:%d\r\n", m_receiveOffset);
			continue;
		}

		for (size_t i = 0; i < cmdLen; i++)
		{
			TRACE("          命令:0x%0.2x\r\n", *(&m_receiveData[4] + i));
		}

		for (size_t i = 0; i < dataLen; i++)
		{
			TRACE("          数据:0x%0.2x\r\n", *(&m_receiveData[4] + m_receiveData[4] + i));

		}

		unsigned char checkCode = m_receiveData[frameLen - 2];//校验位
		unsigned int dataIsOver = m_receiveData[frameLen - 3];//数据是否完整标志
		TRACE("数据是否完整标志:0x%0.2x\r\n", dataIsOver);
		TRACE("        校验位:0x%0.2x\r\n", checkCode);
		TRACE("   协议结束标志:0x%0.2x\r\n", m_receiveData[frameLen - 1]);
		TRACE("         帧长:0x%0.2x %d\r\n", frameLen, frameLen);
		if (CaclCheckSum(&m_receiveData[1], cmdLen + dataLen + TRAN_CTRL_LEN) != checkCode)
		{
			m_receiveOffset -= 1;//偏移长度减一
			memmove(m_receiveData, m_receiveData + 1, m_receiveOffset);
			TRACE("校验位错误删除一个字节m_receiveOffset:%d\r\n", m_receiveOffset);
			continue;
		}
		
		OnData(m_receiveData, frameLen);//完成一帧进行处理
		TRACE("-------------------------删包完成---------------------------\r\n");
		m_receiveOffset -= frameLen;//接收数组长度减少
		memmove(m_receiveData, m_receiveData + frameLen, m_receiveOffset);//删除数据
		TRACE("删除一帧m_receiveOffset:%d\r\n", m_receiveOffset);
	}
}

/**************************************************************
//功能：计算校验位求与运算
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
unsigned char MFCPocoClientDlg::CaclCheckSum(const unsigned char *pData, unsigned int length)
{
	//TRACE("---------------------------------------------------------\r\n");
	unsigned char sum = 0;
	for (unsigned int i = 0; i < length; i++)
	{
		//TRACE("求与运算:0x%0.2x\r\n", pData[i]);
		sum &= pData[i];
	}
	//TRACE("计算校验位求与运算:0x%0.2x\r\n", sum);
	return sum;
}

/**************************************************************
//功能：完成一帧进行处理
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
void MFCPocoClientDlg::OnData(const unsigned char *pData, unsigned int dataLen)
{
	//协议数据头1	通信方式1	 命令长度1 数据长度1  命令 数据  数据是否完整标志1	校验位1 协议结束标志1
	TRACE("---------------------------组包完成-------------------------\r\n");
	TRACE("     协议数据头:0x%0.2x\r\n", pData[0]);
	TRACE("      通信方式:0x%0.2x\r\n", pData[1]);
	TRACE("      命令长度:0x%0.2x\r\n", pData[2]);
	TRACE("      数据长度:0x%0.2x\r\n", pData[3]);
	for (size_t i = 0; i < pData[2]; i++)
	{
		TRACE("          命令:0x%0.2x\r\n",*(&pData[4]+i));
	}
	for (size_t i = 0; i < pData[3]; i++)
	{
		TRACE("          数据:0x%0.2x\r\n", *(&pData[4] + pData[4] + i));

	}
	TRACE("数据是否完整标志:0x%0.2x\r\n", *(&pData[4] + pData[2] + pData[3] + 0));
	TRACE("		   校验位:0x%0.2x\r\n", *(&pData[4] + pData[2] + pData[3] + 1));
	TRACE("   协议结束标志:0x%0.2x\r\n", *(&pData[4] + pData[2] + pData[3] + 2));

	if (dataLen < FRAME_MIN_LEN) //包长小于最小包长
	{
		TRACE("收到的数据报文长度有误");
		return;
	}
	TRACE("---------------------------请求处理-------------------------\r\n");
	switch (pData[4]) //命令
	{
	case ACK_CODE:
		TRACE("处理命令:0x%0.2x\r\n", pData[4]);
		OnAckCode(pData, dataLen);
		break;
	case NAK_CODE:
		TRACE("处理命令:0x%0.2x\r\n", pData[4]);
		OnNakCode(pData, dataLen);
		break;
	case TEST_CODE:
		TRACE("处理命令:0x%0.2x\r\n", pData[4]);
		OnNakCode(pData, dataLen);
		break;
	default:
		TRACE("收到的数据报文命令类型有误");
		break;
	} 
}

/**************************************************************
//功能：ACK_CODE命令处理
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
void MFCPocoClientDlg::OnAckCode(const unsigned char *pData, unsigned int dataLen)
{
	//客户端请求处理
	for (size_t i = 0; i < pData[3]; i++)
	{
		TRACE("请求数据:0x%0.2x\r\n", *(&pData[4] + pData[4] + i));
	}
	//响应客户端 发动一个数据包
	//unsigned char cmd[] = { 0x01 };//命令
	//unsigned char data[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99 };//数据
	//FillCtrlMsg((unsigned char *)cmd, 1, (unsigned char *)data, 10);
}

/**************************************************************
//功能：NAK_CODE命令处理
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
void MFCPocoClientDlg::OnNakCode(const unsigned char *pData, unsigned int dataLen)
{
	for (size_t i = 0; i < pData[3]; i++)
	{
		TRACE("OnNakCode数据:0x%0.2x\r\n", *(&pData[4] + pData[4] + i));
	}
}

/**************************************************************
//功能：测试发送组包
//作者：
//传入参数：
//传出参数：
//修改记录:
**************************************************************/
void MFCPocoClientDlg::OnBnClickedButton1()
{
	//发动一个数据包
	unsigned char cmd[]  = {0x01};//命令
	unsigned char data[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99 };//数据
	FillCtrlMsg((unsigned char *)cmd, 1, (unsigned char *)data,10);
}

void MFCPocoClientDlg::FillCtrlMsg(unsigned char *pCmd, unsigned int cmdlen, unsigned char *pData,unsigned int datalen)
{
	//协议数据头1	通信方式1	 命令长度1  数据长度1  命令1~2  数据0~n  数据是否完整标志1	校验位1 协议结束标志1
	unsigned int frameLen = cmdlen + datalen + TRAN_CTRL_LEN + ADDR_CODE_LEN; //帧长
	unsigned char *package = (unsigned char *)malloc(frameLen);
	unsigned char *p = package;
	*p++ = REQ_STX; //协议数据头
	*p++ = MESSAGE_TYPE;//通信方式
	*p++ = cmdlen;
	*p++ = datalen;
	if (cmdlen > 0)
	{
		memcpy(p, pCmd,cmdlen);  //命令内容
	}
	if (datalen > 0)
	{
		memcpy(p + cmdlen, pData, datalen);  //数据内容
	}
	*(p + cmdlen + datalen) = MES_OVER; //数据是否完整标志
	*(p + cmdlen + datalen + 1) = CaclCheckSum(&package[1], cmdlen + datalen + TRAN_CTRL_LEN);; //校验位
	*(p + cmdlen + datalen + 2) = REQ_EXT;  //请求结束符
    /*for (size_t i = 0; i < frameLen; i++)
	{
		TRACE("测试:0x%0.2x\r\n", package[i]);
	}
    */
    //发送一个请求包
	OnReceiveData(package,frameLen); 
	if(package != NULL)
	{
		free(package);
		package = NULL;
	}
}



BOOL MFCPocoClientDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	/*if (pmServer != nullptr) {
		delete(pmServer);
		pmServer = nullptr;
		TRACE("DestroyWindow pserver\r\n");
	}*/

	return CDialogEx::DestroyWindow();
}


void MFCPocoClientDlg::OnBnClickedButtonConnect()
{
	


	//char *pData = "01234567890123456789012345678901234567890123456789";
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x50 };//最小数据测试
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x01, 0x01,0x55,0x01, 0x00, 0x50 };//数据测试1
	unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x02, 0x02, 0x55, 0x66, 0x01, 0x00, 0x50 };//数据测试2
	pTcpClient->sendBytes(dataMin,10);


	//int nPort = 8099;
	//std::string strIpAddr("127.0.0.1");
	//SocketAddress sa(strIpAddr.c_str(), nPort);
	//SocketReactor reactor;
	//Poco::Net::SocketConnector<ClientServiceHandler> connector(sa, reactor);
	//reactor.run();

	//do
	//{
	//	{
	//		SocketReactor reactor;
	//		//SocketConnector模板实现于SocketConnector.h中
	//		Poco::Net::SocketConnector<SimpleConnectorTest::ClientServiceHandler> connector(sa, reactor);
	//		reactor.run();
	//	}
	//} while (!SimpleConnectorTest::ClientServiceHandler::IsConnect());
}
