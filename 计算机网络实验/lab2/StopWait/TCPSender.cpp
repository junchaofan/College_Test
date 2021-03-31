#include "stdafx.h"
#include "Global.h"
#include "TCPSender.h"
TCPSender::TCPSender() {
	base = 0;
	length = 1 << SEQ_LENGTH;
	nextseqnum = 0;
	last_ack = new int[3];
	//��ʼ������ACK��
	for (int i = 0; i < 3; i++) {
		last_ack[i] = -2;
	}
	packetWaitingAck = new Packet[length];
}

TCPSender::~TCPSender()
{
}

bool TCPSender::is_equal() {
	return last_ack[0] == last_ack[1] && last_ack[1] == last_ack[2] && last_ack[0] != -2;
}

void TCPSender::show() {
	cout << "���ͷ���������:" << endl;
	for (int i = 0; i < nextseqnum - base; i++) {
		cout << "����" << i << "���" << base + i;
		pUtils->printPacket("��������", packetWaitingAck[(base + i) % length]);
	}
}

bool TCPSender::send(Message &message) {
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

void TCPSender::receive(Packet &ackPkt) {
	//���У����Ƿ���ȷ
	int checkSum = pUtils->calculateCheckSum(ackPkt);
	//���У�����ȷ
	if (checkSum == ackPkt.checksum) {
		if (base > ackPkt.acknum) {
			//��������ACK
			int i = 0;
			cout << "��������ACK" << ackPkt.acknum << endl;
			if (last_ack[0] == ackPkt.acknum) {
				if (last_ack[1] == -2) {
					last_ack[1] = ackPkt.acknum;
				}
				else {
					last_ack[2] = ackPkt.acknum;
				}
			}
			else {
				//��ʼ������ACK��
				for (int i = 0; i < 3; i++) {
					last_ack[i] = -2;
				}
				last_ack[0] = ackPkt.acknum;
			}
			//����������ͬACK
			if (is_equal()) {
				cout << "����������ͬ����ACK��ִ���ش�" << endl;
				pUtils->printPacket("�����ش���������", packetWaitingAck[base%length]);
				pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[base%length]);
				show();
				//��ʼ������ACK��
				for (int i = 0; i < 3; i++) {
					last_ack[i] = -2;
				}
				//getchar();
			}
		}
		//����base
		base = ackPkt.acknum + 1;
		pUtils->printPacket("���ͷ�����ȷ�ϱ���", ackPkt);
		if (base == nextseqnum) {
			//�رն�ʱ��
			pns->stopTimer(SENDER, 0);
		}
		else {
			//������ʱ��
			pns->stopTimer(SENDER, 0);
			pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
		}
	}
	else {
		pUtils->printPacket("���ͷ��յ�������", ackPkt);
		cout << endl;
	}
}

void TCPSender::timeoutHandler(int seqNum) {
	cout << "�ѳ�ʱ" << endl;
	//��ʼ������ACK��
	for (int i = 0; i < 3; i++) {
		last_ack[i] = -2;
	}
	//������ʱ�������·�������δȷ������,seqNum������
	pns->stopTimer(SENDER, 0);
	pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
	//���·���base���ݰ�
	pUtils->printPacket("��ʱ�ش���������", packetWaitingAck[base%length]);
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[base % length]);
	show();
}


bool TCPSender::getWaitingState() {
	//������������true
	return nextseqnum - base == WINDOW_SIZE;
}