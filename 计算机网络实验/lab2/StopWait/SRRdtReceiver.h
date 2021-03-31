#ifndef SR_RDT_RECEIVER_H
#define SR_RDT_RECEIVER_H
#include "RdtReceiver.h"
class SRRdtReceiver :public RdtReceiver {
private:
	int base;                       //���ջ����
	int length;                     //��ſռ䷶Χ  
	bool *rcv_ack;                   //���ACK
	Packet *packetWaitingAck;		//�ѷ��Ͳ��ȴ�Ack�����ݰ���
public:
	SRRdtReceiver();
	virtual ~SRRdtReceiver();

public:
	void show();
	void receive(Packet &packet);	//���ձ��ģ�����NetworkService����
};

#endif