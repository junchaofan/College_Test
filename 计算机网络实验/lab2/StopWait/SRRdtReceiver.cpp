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
	cout << "接收方窗口内容:" << endl;
	for (int i = 0; i < WINDOW_SIZE && rcv_ack[(base + i) % length]; i++) {
		cout << "分组" << i << "序号" << base + i;
		pUtils->printPacket("报文内容", packetWaitingAck[(base + i) % length]);
	}
}


SRRdtReceiver::~SRRdtReceiver()
{
}

void SRRdtReceiver::receive(Packet &packet) {
	//检查校验和是否正确
	int checkSum = pUtils->calculateCheckSum(packet);
	//如果校验和正确，同时收到报文的序号处于窗口内
	if (checkSum == packet.checksum && packet.seqnum >= base && packet.seqnum < base + WINDOW_SIZE) {
		//判断该分组是否被接收过
		if (rcv_ack[packet.seqnum%length]) {
			printf("该分组已被接收过\n");
		}
		//缓存该分组
		rcv_ack[packet.seqnum%length] = true;
		packetWaitingAck[packet.seqnum%length] = packet;
		pUtils->printPacket("接收方接收分组", packet);

		//发送选择ACK
		cout << "接收方发送选择ACK" << endl;
		Packet c_ack;
		c_ack.acknum = packet.seqnum;
		c_ack.seqnum = -1;   //忽略
		c_ack.checksum = 0;
		memcpy(c_ack.payload, packet.payload, sizeof(packet.payload));
		c_ack.checksum = pUtils->calculateCheckSum(c_ack);
		pns->sendToNetworkLayer(SENDER, c_ack);

		//分组序号等于基序号
		if (packet.seqnum == base) {
			show();
			//取出Message，向上递交给应用层
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
		c_ack.seqnum = -1;   //忽略
		c_ack.checksum = 0;
		memcpy(c_ack.payload, packet.payload, sizeof(packet.payload));
		c_ack.checksum = pUtils->calculateCheckSum(c_ack);
		pns->sendToNetworkLayer(SENDER, c_ack);
	}
	
}