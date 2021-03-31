#ifndef SR_RDT_RECEIVER_H
#define SR_RDT_RECEIVER_H
#include "RdtReceiver.h"
class SRRdtReceiver :public RdtReceiver {
private:
	int base;                       //接收基序号
	int length;                     //序号空间范围  
	bool *rcv_ack;                   //存放ACK
	Packet *packetWaitingAck;		//已发送并等待Ack的数据包组
public:
	SRRdtReceiver();
	virtual ~SRRdtReceiver();

public:
	void show();
	void receive(Packet &packet);	//接收报文，将被NetworkService调用
};

#endif