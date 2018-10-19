
// MFCProtocolDemoDlg.cpp : ʵ���ļ�
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
////Poco �ġ�TcpServer ��һ�����̵߳ġ�Tcp ��������
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
//* @brief MyTcpServerConnection::run �������������������
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
//		TRACE("MyTcpServer������ͻ�������\r\n");
//		return new MyTcpServerConnection(socket);
//	}
//};



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// MFCPocoClientDlg �Ի���



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


// MFCPocoClientDlg ��Ϣ��������

BOOL MFCPocoClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
    

	SocketAddress sa("192.168.51.3", 8099);
	pTcpClient = new StreamSocket(sa);
	

	//_CrtSetBreakAlloc(143);

	// TODO:  �ڴ����Ӷ���ĳ�ʼ������
	//ServerSocket serverSocket(8099);
	//Timespan timeout(10, 0);
	//serverSocket.setReceiveTimeout(timeout);
	//pmServerParams = new Poco::Net::TCPServerParams;
	//pmServerParams->setMaxQueued(100);//�趨���е���󳤶ȡ�
	//pmServerParams->setMaxThreads(100);//�趨TcpServer ����̵߳ĸ�����
	//pmServer = new Poco::Net::TCPServer(new MyTcpServer, serverSocket);
	//pmServer->start();

	/*while (1)
	{
		Sleep(10);
	}
	server.stop();*/
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void MFCPocoClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR MFCPocoClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void MFCPocoClientDlg::OnBnClickedOk()
{
	// TODO:  �ڴ����ӿؼ�֪ͨ�����������
	CDialogEx::OnOK();
}


void MFCPocoClientDlg::OnBnClickedCancel()
{
	//TODO:�ڴ����ӿؼ�֪ͨ�����������
	CDialogEx::OnCancel();
}

////Э������ͷ1	ͨ�ŷ�ʽ1	 �����1 ���ݳ���1  ���� ����  �����Ƿ�������־1	У��λ1 Э�������־1
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

//m_receiveOffset -= 1;//ƫ�Ƴ��ȼ�һ
//strncpy_s(m_receiveDataTemp, &m_receiveData[1], m_receiveOffset);//ɾ���������
//memset(m_receiveData, 0, sizeof(m_receiveData));
//strncpy_s(m_receiveDataTemp, m_receiveDataTemp, m_receiveOffset);
//
//OnData(m_receiveData, frameLen, dataIsOver);//���һ֡���д���
//m_receiveOffset -= frameLen;//�������鳤�ȼ���
//strncpy_s(m_receiveDataTemp, m_receiveData, m_receiveOffset);//ɾ������
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
//���ܣ����Խ���������ְ�����
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
void MFCPocoClientDlg::OnBnClickedButtonTest01()
{
	//TODO:  �ڴ����ӿؼ�֪ͨ�����������
	//char *pData = "01234567890123456789012345678901234567890123456789";
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x50 };//��С���ݲ���
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x01, 0x01,0x55,0x01, 0x00, 0x50 };//���ݲ���1
	unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x02, 0x02, 0x55, 0x66, 0x01, 0x00, 0x50 };//���ݲ���2
	//4F, 00, 01, 02, 02, 55, 66, 01, 00, 50 
	OnReceiveData(dataMin,10);
}

/**************************************************************
//���ܣ����յ����ݻ���,����жϣ��ְ�����
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
unsigned char m_receiveData[FRAME_MAX_LEN] = {};    //��������
unsigned int  m_receiveOffset = 0;                  //���������ƫ��
void MFCPocoClientDlg::OnReceiveData(const unsigned char *pData, unsigned int length)
{
	TRACE("------------------------�����������----------------------------\r\n");
	/*for (size_t i = 0; i < length; i++)
	{
		TRACE("      ��������:0x%0.2x\r\n", *(pData+i));
	}*/
	TRACE("   �����������:%d\r\n", m_receiveOffset);
	memcpy_s(&m_receiveData[m_receiveOffset], FRAME_MAX_LEN - m_receiveOffset, pData, length);
	m_receiveOffset += length;
	TRACE("����������ݳ���:%d\r\n", m_receiveOffset);
	TRACE("------------------------�������ݰ�----------------------------\r\n");
	//Э������ͷ1	ͨ�ŷ�ʽ1	 �����1 ���ݳ���1  ���� ����  �����Ƿ�������־1	У��λ1 Э�������־1
	while (m_receiveOffset >= FRAME_MIN_LEN)
	{
		if (m_receiveData[0] != REQ_STX)//Э������ͷ��־
		{
			m_receiveOffset -= 1;//ƫ�Ƴ��ȼ�һ
			memmove(m_receiveData, &m_receiveData[1], m_receiveOffset);
			m_receiveData[m_receiveOffset] = 0;
			TRACE("Э������ͷ��־����ɾ��һ��m_receiveData  :%s\r\n", m_receiveData);
			TRACE("Э������ͷ��־����ɾ��һ��m_receiveOffset:%d\r\n", m_receiveOffset);
			continue;
		}
		unsigned int messagetype = m_receiveData[1]; //ͨ�ŷ�ʽ
		unsigned int cmdLen  = m_receiveData[2];     //�����
		unsigned int dataLen = m_receiveData[3];     //���ݳ���
	    //
		unsigned int frameLen = cmdLen + dataLen + TRAN_CTRL_LEN + ADDR_CODE_LEN; //֡��
		TRACE("  Э������ͷ��־:0x%0.2x\r\n", m_receiveData[0]);
		TRACE("       ͨ�ŷ�ʽ:0x%0.2x\r\n", messagetype);
		TRACE("       �����:0x%0.2x\r\n", cmdLen);
		TRACE("       ���ݳ���:0x%0.2x\r\n", dataLen);
		
		if (m_receiveOffset < frameLen) //����֡δ����
		{
			TRACE("����֡δ����frameLen       :%s\r\n", frameLen);
			TRACE("����֡δ����m_receiveOffset:%d\r\n", m_receiveOffset);
			return;
		}
		if (m_receiveData[frameLen - 1] != REQ_EXT) //Э�������־
		{
			m_receiveOffset -= 1;//ƫ�Ƴ��ȼ�һ
			memmove(m_receiveData, m_receiveData + 1, m_receiveOffset);
			TRACE("Э�������־����ɾ��һ��m_receiveData  :%s\r\n", m_receiveData);
			TRACE("Э�������־����ɾ��һ��m_receiveOffset:%d\r\n", m_receiveOffset);
			continue;
		}

		for (size_t i = 0; i < cmdLen; i++)
		{
			TRACE("          ����:0x%0.2x\r\n", *(&m_receiveData[4] + i));
		}

		for (size_t i = 0; i < dataLen; i++)
		{
			TRACE("          ����:0x%0.2x\r\n", *(&m_receiveData[4] + m_receiveData[4] + i));

		}

		unsigned char checkCode = m_receiveData[frameLen - 2];//У��λ
		unsigned int dataIsOver = m_receiveData[frameLen - 3];//�����Ƿ�������־
		TRACE("�����Ƿ�������־:0x%0.2x\r\n", dataIsOver);
		TRACE("        У��λ:0x%0.2x\r\n", checkCode);
		TRACE("   Э�������־:0x%0.2x\r\n", m_receiveData[frameLen - 1]);
		TRACE("         ֡��:0x%0.2x %d\r\n", frameLen, frameLen);
		if (CaclCheckSum(&m_receiveData[1], cmdLen + dataLen + TRAN_CTRL_LEN) != checkCode)
		{
			m_receiveOffset -= 1;//ƫ�Ƴ��ȼ�һ
			memmove(m_receiveData, m_receiveData + 1, m_receiveOffset);
			TRACE("У��λ����ɾ��һ���ֽ�m_receiveOffset:%d\r\n", m_receiveOffset);
			continue;
		}
		
		OnData(m_receiveData, frameLen);//���һ֡���д���
		TRACE("-------------------------ɾ�����---------------------------\r\n");
		m_receiveOffset -= frameLen;//�������鳤�ȼ���
		memmove(m_receiveData, m_receiveData + frameLen, m_receiveOffset);//ɾ������
		TRACE("ɾ��һ֡m_receiveOffset:%d\r\n", m_receiveOffset);
	}
}

/**************************************************************
//���ܣ�����У��λ��������
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
unsigned char MFCPocoClientDlg::CaclCheckSum(const unsigned char *pData, unsigned int length)
{
	//TRACE("---------------------------------------------------------\r\n");
	unsigned char sum = 0;
	for (unsigned int i = 0; i < length; i++)
	{
		//TRACE("��������:0x%0.2x\r\n", pData[i]);
		sum &= pData[i];
	}
	//TRACE("����У��λ��������:0x%0.2x\r\n", sum);
	return sum;
}

/**************************************************************
//���ܣ����һ֡���д���
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
void MFCPocoClientDlg::OnData(const unsigned char *pData, unsigned int dataLen)
{
	//Э������ͷ1	ͨ�ŷ�ʽ1	 �����1 ���ݳ���1  ���� ����  �����Ƿ�������־1	У��λ1 Э�������־1
	TRACE("---------------------------������-------------------------\r\n");
	TRACE("     Э������ͷ:0x%0.2x\r\n", pData[0]);
	TRACE("      ͨ�ŷ�ʽ:0x%0.2x\r\n", pData[1]);
	TRACE("      �����:0x%0.2x\r\n", pData[2]);
	TRACE("      ���ݳ���:0x%0.2x\r\n", pData[3]);
	for (size_t i = 0; i < pData[2]; i++)
	{
		TRACE("          ����:0x%0.2x\r\n",*(&pData[4]+i));
	}
	for (size_t i = 0; i < pData[3]; i++)
	{
		TRACE("          ����:0x%0.2x\r\n", *(&pData[4] + pData[4] + i));

	}
	TRACE("�����Ƿ�������־:0x%0.2x\r\n", *(&pData[4] + pData[2] + pData[3] + 0));
	TRACE("		   У��λ:0x%0.2x\r\n", *(&pData[4] + pData[2] + pData[3] + 1));
	TRACE("   Э�������־:0x%0.2x\r\n", *(&pData[4] + pData[2] + pData[3] + 2));

	if (dataLen < FRAME_MIN_LEN) //����С����С����
	{
		TRACE("�յ������ݱ��ĳ�������");
		return;
	}
	TRACE("---------------------------������-------------------------\r\n");
	switch (pData[4]) //����
	{
	case ACK_CODE:
		TRACE("��������:0x%0.2x\r\n", pData[4]);
		OnAckCode(pData, dataLen);
		break;
	case NAK_CODE:
		TRACE("��������:0x%0.2x\r\n", pData[4]);
		OnNakCode(pData, dataLen);
		break;
	case TEST_CODE:
		TRACE("��������:0x%0.2x\r\n", pData[4]);
		OnNakCode(pData, dataLen);
		break;
	default:
		TRACE("�յ������ݱ���������������");
		break;
	} 
}

/**************************************************************
//���ܣ�ACK_CODE�����
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
void MFCPocoClientDlg::OnAckCode(const unsigned char *pData, unsigned int dataLen)
{
	//�ͻ���������
	for (size_t i = 0; i < pData[3]; i++)
	{
		TRACE("��������:0x%0.2x\r\n", *(&pData[4] + pData[4] + i));
	}
	//��Ӧ�ͻ��� ����һ�����ݰ�
	//unsigned char cmd[] = { 0x01 };//����
	//unsigned char data[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99 };//����
	//FillCtrlMsg((unsigned char *)cmd, 1, (unsigned char *)data, 10);
}

/**************************************************************
//���ܣ�NAK_CODE�����
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
void MFCPocoClientDlg::OnNakCode(const unsigned char *pData, unsigned int dataLen)
{
	for (size_t i = 0; i < pData[3]; i++)
	{
		TRACE("OnNakCode����:0x%0.2x\r\n", *(&pData[4] + pData[4] + i));
	}
}

/**************************************************************
//���ܣ����Է������
//���ߣ�
//���������
//����������
//�޸ļ�¼:
**************************************************************/
void MFCPocoClientDlg::OnBnClickedButton1()
{
	//����һ�����ݰ�
	unsigned char cmd[]  = {0x01};//����
	unsigned char data[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99 };//����
	FillCtrlMsg((unsigned char *)cmd, 1, (unsigned char *)data,10);
}

void MFCPocoClientDlg::FillCtrlMsg(unsigned char *pCmd, unsigned int cmdlen, unsigned char *pData,unsigned int datalen)
{
	//Э������ͷ1	ͨ�ŷ�ʽ1	 �����1  ���ݳ���1  ����1~2  ����0~n  �����Ƿ�������־1	У��λ1 Э�������־1
	unsigned int frameLen = cmdlen + datalen + TRAN_CTRL_LEN + ADDR_CODE_LEN; //֡��
	unsigned char *package = (unsigned char *)malloc(frameLen);
	unsigned char *p = package;
	*p++ = REQ_STX; //Э������ͷ
	*p++ = MESSAGE_TYPE;//ͨ�ŷ�ʽ
	*p++ = cmdlen;
	*p++ = datalen;
	if (cmdlen > 0)
	{
		memcpy(p, pCmd,cmdlen);  //��������
	}
	if (datalen > 0)
	{
		memcpy(p + cmdlen, pData, datalen);  //��������
	}
	*(p + cmdlen + datalen) = MES_OVER; //�����Ƿ�������־
	*(p + cmdlen + datalen + 1) = CaclCheckSum(&package[1], cmdlen + datalen + TRAN_CTRL_LEN);; //У��λ
	*(p + cmdlen + datalen + 2) = REQ_EXT;  //���������
    /*for (size_t i = 0; i < frameLen; i++)
	{
		TRACE("����:0x%0.2x\r\n", package[i]);
	}
    */
    //����һ�������
	OnReceiveData(package,frameLen); 
	if(package != NULL)
	{
		free(package);
		package = NULL;
	}
}



BOOL MFCPocoClientDlg::DestroyWindow()
{
	// TODO: �ڴ�����ר�ô����/����û���
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
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x00, 0x01, 0x01, 0x00, 0x50 };//��С���ݲ���
	//unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x01, 0x01,0x55,0x01, 0x00, 0x50 };//���ݲ���1
	unsigned char dataMin[] = { 0x4F, 0x00, 0x01, 0x02, 0x02, 0x55, 0x66, 0x01, 0x00, 0x50 };//���ݲ���2
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
	//		//SocketConnectorģ��ʵ����SocketConnector.h��
	//		Poco::Net::SocketConnector<SimpleConnectorTest::ClientServiceHandler> connector(sa, reactor);
	//		reactor.run();
	//	}
	//} while (!SimpleConnectorTest::ClientServiceHandler::IsConnect());
}