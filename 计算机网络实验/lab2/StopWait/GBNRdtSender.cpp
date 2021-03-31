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
	cout << "发送方窗口内容:" << endl;
	for (int i = 0; i < nextseqnum - base; i++) {
		cout << "分组" << i << "序号" << base + i;
		pUtils->printPacket("报文内容", packetWaitingAck[(base+i)%length]);
	}
}

bool GBNRdtSender::send(Message &message) {
	if ( nextseqnum - base == WINDOW_SIZE) {
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
	if (base == nextseqnum) {
		//启动发送方定时器
		pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
	}
	nextseqnum += 1;
	show();
	//调用模拟网络环境的sendToNetworkLayer，通过网络层发送到对方
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[num]);
	return true;
}

void GBNRdtSender::receive(Packet &ackPkt) {
	//检查校验和是否正确
	int checkSum = pUtils->calculateCheckSum(ackPkt);
	//如果校验和正确，并且确认序号=发送方已发送并等待确认的数据包序号
	if (checkSum == ackPkt.checksum) {
		pUtils->printPacket("确认报文已到达", ackPkt);
		base = ackPkt.acknum + 1;
		if (base == nextseqnum) {
			//关闭定时器
			pns->stopTimer(SENDER, 0);
		}else {
			//重启定时器
			pns->stopTimer(SENDER, 0);
			pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
		}
	}
	else {
		pUtils->printPacket("收到错误报文", ackPkt);
		cout << endl;
	}
}

void GBNRdtSender::timeoutHandler(int seqNum) {
	//重启定时器并重新发送所有未确定报文,seqNum不考虑
	pns->stopTimer(SENDER, seqNum);
	pns->startTimer(SENDER, Configuration::TIME_OUT, seqNum);			//重新启动发送方定时器
	show();
	for (int i = 0; i < nextseqnum - base; i++) {
		//重新发送数据包
		pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[(i+base)%length]);
	}
}


bool GBNRdtSender::getWaitingState() {
	//窗口已满返回true
	return nextseqnum - base == WINDOW_SIZE;
}