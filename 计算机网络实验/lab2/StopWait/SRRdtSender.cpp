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
	cout << "发送方窗口内容:" << endl;
	for (int i = 0; i < nextseqnum - base; i++) {
		cout << "分组" << i << "序号" << base + i;
		pUtils->printPacket("报文内容", packetWaitingAck[(base + i) % length]);
	}
}

bool SRRdtSender::send(Message &message) {
	if (nextseqnum - base == WINDOW_SIZE) {
		//窗口已满
		return false;
	}
	int num = nextseqnum % length;
	//窗口未满
	packetWaitingAck[num].acknum = -1;//忽略ACK
	packetWaitingAck[num].seqnum = nextseqnum;
	packetWaitingAck[num].checksum = 0;
	memcpy(packetWaitingAck[num].payload, message.data, sizeof(message.data));
	packetWaitingAck[num].checksum = pUtils->calculateCheckSum(packetWaitingAck[num]);
	//启动对应定时器
	pns->startTimer(SENDER, Configuration::TIME_OUT, nextseqnum);
	nextseqnum += 1;
	show();
	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送到对方
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[num]);
	return true;
}

void SRRdtSender::receive(Packet &ackPkt) {
	//检查校验和是否正确
	int checkSum = pUtils->calculateCheckSum(ackPkt);
	//如果校验和正确，并且确认序号=发送方已发送并等待确认的数据包序号
	if (checkSum == ackPkt.checksum) {
		pUtils->printPacket("发送方已接收确认报文", ackPkt);
		cout << endl;
		pns->stopTimer(SENDER, ackPkt.acknum);
		//若在窗口内
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
	//重启定时器并重新发送对应未确定报文
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[seqNum%length]);
	pns->stopTimer(SENDER, seqNum);
	pns->startTimer(SENDER, Configuration::TIME_OUT, seqNum);			//重新启动对应定时器
	show();
}


bool SRRdtSender::getWaitingState() {
	//窗口已满返回true
	return nextseqnum - base == WINDOW_SIZE;
}