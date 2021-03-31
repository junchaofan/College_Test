#ifndef TCP_SENDER_H
#define TCP_SENDER_H
#include "RdtSender.h"
class TCPSender :public RdtSender {
private:
	int base;                       //最早的未确认分组的序号
	int nextseqnum;                 //最小的未使用序号
	int length;                     //序号空间范围  
	int *last_ack;                  //冗余last_ACK
	Packet *packetWaitingAck;		//已发送并等待Ack的数据包组

public:
	bool getWaitingState();
	bool send(Message &message);						//发送应用层下来的Message，由NetworkServiceSimulator调用,如果发送方成功地将Message发送到网络层，返回true;如果因为发送方处于等待正确确认状态而拒绝发送Message，则返回false
	void receive(Packet &ackPkt);						//接受确认Ack，将被NetworkServiceSimulator调用	
	void timeoutHandler(int seqNum);					//Timeout handler，将被NetworkServiceSimulator调用

public:
	TCPSender();
	void show();
	bool is_equal();
	virtual ~TCPSender();
};
#endif