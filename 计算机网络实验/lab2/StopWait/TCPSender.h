#ifndef TCP_SENDER_H
#define TCP_SENDER_H
#include "RdtSender.h"
class TCPSender :public RdtSender {
private:
	int base;                       //�����δȷ�Ϸ�������
	int nextseqnum;                 //��С��δʹ�����
	int length;                     //��ſռ䷶Χ  
	int *last_ack;                  //����last_ACK
	Packet *packetWaitingAck;		//�ѷ��Ͳ��ȴ�Ack�����ݰ���

public:
	bool getWaitingState();
	bool send(Message &message);						//����Ӧ�ò�������Message����NetworkServiceSimulator����,������ͷ��ɹ��ؽ�Message���͵�����㣬����true;�����Ϊ���ͷ����ڵȴ���ȷȷ��״̬���ܾ�����Message���򷵻�false
	void receive(Packet &ackPkt);						//����ȷ��Ack������NetworkServiceSimulator����	
	void timeoutHandler(int seqNum);					//Timeout handler������NetworkServiceSimulator����

public:
	TCPSender();
	void show();
	bool is_equal();
	virtual ~TCPSender();
};
#endif