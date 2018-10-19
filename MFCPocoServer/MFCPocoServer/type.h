#ifndef TYPE_H
#define TYPE_H


#define FRAME_MAX_LEN       256                     //最大帧长
#define FRAME_MIN_LEN	    8                       //最小帧长
#define DATA_MAX_LEN        247                     //最大数据长0~247(256-2-7)
#define CMD_MAX_LEN        247                      //最大命令长1~2
#define REQ_STX             0x4F                    //请求起始符
#define REQ_EXT             0x50                    //请求结束符
#define RSP_STX             0x3F                    //响应起始符
#define RSP_EXT             0x40                    //响应结束符
#define MESSAGE_TYPE        0x00                    //通信方式
#define MES_OVER            0x01                    //数据是否完整标志
#define TRAN_CTRL_LEN       4                       //传输控制信息长
#define ADDR_CODE_LEN       3                       //地址码长


//命令
#define ACK_CODE          0x01
#define NAK_CODE          0x02
#define TEST_CODE         0x03

#endif