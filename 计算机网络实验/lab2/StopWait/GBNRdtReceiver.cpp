#include "stdafx.h"
#include "Global.h"
#include "GBNRdtReceiver.h"

GBNRdtReceiver::GBNRdtReceiver():expectSequenceNumberRcvd(0) {
	length = 1 << SEQ_LENGTH;
	lastAckPkt.acknum = -1; //��ʼ״̬�£��ϴη��͵�ȷ�ϰ���ȷ�����Ϊ-1
	lastAckPkt.checksum = 0;
	lastAckPkt.seqnum = -1;	//���Ը��ֶ�
	memset(lastAckPkt.payload, '.', Configuration::PAYLOAD_SIZE);
	lastAckPkt.checksum = pUtils->calculateCheckSum(lastAckPkt);
}


GBNRdtReceiver::~GBNRdtReceiver()
{
}

void GBNRdtReceiver::receive(Packet &packet) {
	//���У����Ƿ���ȷ
	int checkSum = pUtils->calculateCheckSum(packet);
	//���У�����ȷ��ͬʱ�յ����ĵ���ŵ��ڽ��շ��ڴ��յ��ı������
	if (checkSum == packet.checksum && this->expectSequenceNumberRcvd == packet.seqnum) {
		pUtils->printPacket("���շ���ȷ�յ����ͷ��ı���", packet);
		//ȡ��Message�����ϵݽ���Ӧ�ò�
		Message msg;
		memcpy(msg.data, packet.payload, sizeof(packet.payload));
		pns->delivertoAppLayer(RECEIVER, msg);

		lastAckPkt.acknum = packet.seqnum; //ȷ����ŵ����յ��ı������
		memcpy(lastAckPkt.payload, msg.data, sizeof(msg.data));
		lastAckPkt.checksum = pUtils->calculateCheckSum(lastAckPkt);
		pUtils->printPacket("���շ�����ȷ�ϱ���", lastAckPkt);
		pns->sendToNetworkLayer(SENDER, lastAckPkt);	//����ģ�����绷����sendToNetworkLayer��ͨ������㷢��ȷ�ϱ��ĵ��Է�

		this->expectSequenceNumberRcvd += 1;
	}
	else {
		pUtils->printPacket("���շ��յ�������", packet);
		pUtils->printPacket("���շ����·����ϴε�ȷ�ϱ���", lastAckPkt);
		pns->sendToNetworkLayer(SENDER, lastAckPkt);	//����ģ�����绷����sendToNetworkLayer��ͨ������㷢���ϴε�ȷ�ϱ���
	}
}