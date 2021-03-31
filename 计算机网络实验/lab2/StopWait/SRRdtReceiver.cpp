#include "stdafx.h"
#include "Global.h"
#include "SRRdtReceiver.h"

SRRdtReceiver::SRRdtReceiver() {
	base = 0;
	length = 1 << SEQ_LENGTH;
	rcv_ack = new bool[length];
	for (int i = 0; i < length; i++) {
		rcv_ack[i] = false;
	}
	packetWaitingAck = new Packet[length];
}

void SRRdtReceiver::show() {
	cout << "���շ���������:" << endl;
	for (int i = 0; i < WINDOW_SIZE && rcv_ack[(base + i) % length]; i++) {
		cout << "����" << i << "���" << base + i;
		pUtils->printPacket("��������", packetWaitingAck[(base + i) % length]);
	}
}


SRRdtReceiver::~SRRdtReceiver()
{
}

void SRRdtReceiver::receive(Packet &packet) {
	//���У����Ƿ���ȷ
	int checkSum = pUtils->calculateCheckSum(packet);
	//���У�����ȷ��ͬʱ�յ����ĵ���Ŵ��ڴ�����
	if (checkSum == packet.checksum && packet.seqnum >= base && packet.seqnum < base + WINDOW_SIZE) {
		//�жϸ÷����Ƿ񱻽��չ�
		if (rcv_ack[packet.seqnum%length]) {
			printf("�÷����ѱ����չ�\n");
		}
		//����÷���
		rcv_ack[packet.seqnum%length] = true;
		packetWaitingAck[packet.seqnum%length] = packet;
		pUtils->printPacket("���շ����շ���", packet);

		//����ѡ��ACK
		cout << "���շ�����ѡ��ACK" << endl;
		Packet c_ack;
		c_ack.acknum = packet.seqnum;
		c_ack.seqnum = -1;   //����
		c_ack.checksum = 0;
		memcpy(c_ack.payload, packet.payload, sizeof(packet.payload));
		c_ack.checksum = pUtils->calculateCheckSum(c_ack);
		pns->sendToNetworkLayer(SENDER, c_ack);

		//������ŵ��ڻ����
		if (packet.seqnum == base) {
			show();
			//ȡ��Message�����ϵݽ���Ӧ�ò�
			Message msg;
			while (rcv_ack[base%length]) {
				memcpy(msg.data, packetWaitingAck[base%length].payload, sizeof(packetWaitingAck[base%length].payload));
				pns->delivertoAppLayer(RECEIVER, msg);
				rcv_ack[base%length] = false;
				base += 1;
			}
		}
	}else if (checkSum == packet.checksum && packet.seqnum >= base - WINDOW_SIZE && packet.seqnum < base) {
		Packet c_ack;
		c_ack.acknum = packet.seqnum;
		c_ack.seqnum = -1;   //����
		c_ack.checksum = 0;
		memcpy(c_ack.payload, packet.payload, sizeof(packet.payload));
		c_ack.checksum = pUtils->calculateCheckSum(c_ack);
		pns->sendToNetworkLayer(SENDER, c_ack);
	}
	
}