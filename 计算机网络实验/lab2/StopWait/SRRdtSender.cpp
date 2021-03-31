#include "stdafx.h"
#include "Global.h"
#include "SRRdtSender.h"
SRRdtSender::SRRdtSender() {
	base = 0;
	length = 1 << SEQ_LENGTH;
	nextseqnum = 0;
	rcv_ack = new bool[length];
	for (int i = 0; i < length; i++) {
		rcv_ack[i] = false;
	}
	packetWaitingAck = new Packet[length];
}

SRRdtSender::~SRRdtSender()
{
}

void SRRdtSender::show() {
	cout << "���ͷ���������:" << endl;
	for (int i = 0; i < nextseqnum - base; i++) {
		cout << "����" << i << "���" << base + i;
		pUtils->printPacket("��������", packetWaitingAck[(base + i) % length]);
	}
}

bool SRRdtSender::send(Message &message) {
	if (nextseqnum - base == WINDOW_SIZE) {
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
	//������Ӧ��ʱ��
	pns->startTimer(SENDER, Configuration::TIME_OUT, nextseqnum);
	nextseqnum += 1;
	show();
	//����ģ�����绷����sendToNetworkLayer��ͨ������㷢�͵��Է�
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[num]);
	return true;
}

void SRRdtSender::receive(Packet &ackPkt) {
	//���У����Ƿ���ȷ
	int checkSum = pUtils->calculateCheckSum(ackPkt);
	//���У�����ȷ������ȷ�����=���ͷ��ѷ��Ͳ��ȴ�ȷ�ϵ����ݰ����
	if (checkSum == ackPkt.checksum) {
		pUtils->printPacket("���ͷ��ѽ���ȷ�ϱ���", ackPkt);
		cout << endl;
		pns->stopTimer(SENDER, ackPkt.acknum);
		//���ڴ�����
		if (ackPkt.acknum >= base && ackPkt.acknum < nextseqnum) {
			rcv_ack[ackPkt.acknum%length] = true;
		}
		if (base == ackPkt.acknum) {
			while (rcv_ack[base%length]) {
				rcv_ack[base%length] = false;
				base = base + 1;
			}
		}
	}
}

void SRRdtSender::timeoutHandler(int seqNum) {
	//������ʱ�������·��Ͷ�Ӧδȷ������
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[seqNum%length]);
	pns->stopTimer(SENDER, seqNum);
	pns->startTimer(SENDER, Configuration::TIME_OUT, seqNum);			//����������Ӧ��ʱ��
	show();
}


bool SRRdtSender::getWaitingState() {
	//������������true
	return nextseqnum - base == WINDOW_SIZE;
}