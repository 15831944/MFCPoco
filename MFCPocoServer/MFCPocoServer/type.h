#ifndef TYPE_H
#define TYPE_H


#define FRAME_MAX_LEN       256                     //���֡��
#define FRAME_MIN_LEN	    8                       //��С֡��
#define DATA_MAX_LEN        247                     //������ݳ�0~247(256-2-7)
#define CMD_MAX_LEN        247                      //������1~2
#define REQ_STX             0x4F                    //������ʼ��
#define REQ_EXT             0x50                    //���������
#define RSP_STX             0x3F                    //��Ӧ��ʼ��
#define RSP_EXT             0x40                    //��Ӧ������
#define MESSAGE_TYPE        0x00                    //ͨ�ŷ�ʽ
#define MES_OVER            0x01                    //�����Ƿ�������־
#define TRAN_CTRL_LEN       4                       //���������Ϣ��
#define ADDR_CODE_LEN       3                       //��ַ�볤


//����
#define ACK_CODE          0x01
#define NAK_CODE          0x02
#define TEST_CODE         0x03

#endif