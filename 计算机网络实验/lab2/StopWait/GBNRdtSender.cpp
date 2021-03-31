#include "stdafx.h"
#include "Global.h"
#include "GBNRdtSender.h"
GBNRdtSender::GBNRdtSender(){
	base = 0;
	length = 1 << SEQ_LENGTH;
	nextseqnum = 0;
	packetWaitingAck = new Packet[length];
}

GBNRdtSender::~GBNRdtSender()
{
}

void GBNRdtSender::show() {
	cout << "���ͷ���������:" << endl;
	for (int i = 0; i < nextseqnum - base; i++) {
		cout << "����" << i << "���" << base + i;
		pUtils->printPacket("��������", packetWaitingAck[(base+i)%length]);
	}
}

bool GBNRdtSender::send(Message &message) {
	if ( nextseqnum - base == WINDOW_SIZE) {
		//��������
		return false;
	}
	int num = nextseqnum % length;
	//����δ��
	packetWaitingAck[num].acknum = -1;//����ACK
	packetWaitingAck[num].seqnum = nextseqnum;
	packetWaitingAck[num].checksum = 0;
	memcpy(packetWaitingAck[num].payload, message.data, sizeof(message.data));
	packetWaitingAck[num].checksum = pUtils->calculateCheckSum(packetWaitingAck[num]);
	if (base == nextseqnum) {
		//�������ͷ���ʱ��
		pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
	}
	nextseqnum += 1;
	show();
	//����ģ�����绷����sendToNetworkLayer��ͨ������㷢�͵��Է�
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[num]);
	return true;
}

void GBNRdtSender::receive(Packet &ackPkt) {
	//���У����Ƿ���ȷ
	int checkSum = pUtils->calculateCheckSum(ackPkt);
	//���У�����ȷ������ȷ�����=���ͷ��ѷ��Ͳ��ȴ�ȷ�ϵ����ݰ����
	if (checkSum == ackPkt.checksum) {
		pUtils->printPacket("ȷ�ϱ����ѵ���", ackPkt);
		base = ackPkt.acknum + 1;
		if (base == nextseqnum) {
			//�رն�ʱ��
			pns->stopTimer(SENDER, 0);
		}else {
			//������ʱ��
			pns->stopTimer(SENDER, 0);
			pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
		}
	}
	else {
		pUtils->printPacket("�յ�������", ackPkt);
		cout << endl;
	}
}

void GBNRdtSender::timeoutHandler(int seqNum) {
	//������ʱ�������·�������δȷ������,seqNum������
	pns->stopTimer(SENDER, seqNum);
	pns->startTimer(SENDER, Configuration::TIME_OUT, seqNum);			//�����������ͷ���ʱ��
	show();
	for (int i = 0; i < nextseqnum - base; i++) {
		//���·������ݰ�
		pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[(i+base)%length]);
	}
}


bool GBNRdtSender::getWaitingState() {
	//������������true
	return nextseqnum - base == WINDOW_SIZE;
}