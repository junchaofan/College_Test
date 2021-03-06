#ifndef SR_RDT_SENDER_H
#define SR_RDT_SENDER_H
#include "RdtSender.h"
class SRRdtSender :public RdtSender {
private:
	int base;                       //最早的未确认分组的序号
	int nextseqnum;                 //最小的未使用序号
	int length;                     //序号空间范围  
	bool *rcv_ack;                   //存放ACK
	Packet *packetWaitingAck;		//已发送并等待Ack的数据包组

public:
	bool getWaitingState();
	bool send(Message &message);						//发送应用层下来的Message，由NetworkServiceSimulator调用,如果发送方成功地将Message发送到网络层，返回true;如果因为发送方处于等待正确确认状态而拒绝发送Message，则返回false
	void receive(Packet &ackPkt);						//接受确认Ack，将被NetworkServiceSimulator调用	
	void timeoutHandler(int seqNum);					//Timeout handler，将被NetworkServiceSimulator调用

public:
	SRRdtSender();
	void show();
	virtual ~SRRdtSender();
};
#endif