#include "stdafx.h"
#include "Global.h"
#include "TCPSender.h"
TCPSender::TCPSender() {
	base = 0;
	length = 1 << SEQ_LENGTH;
	nextseqnum = 0;
	last_ack = new int[3];
	//初始化冗余ACK组
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
	cout << "发送方窗口内容:" << endl;
	for (int i = 0; i < nextseqnum - base; i++) {
		cout << "分组" << i << "序号" << base + i;
		pUtils->printPacket("报文内容", packetWaitingAck[(base + i) % length]);
	}
}

bool TCPSender::send(Message &message) {
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

void TCPSender::receive(Packet &ackPkt) {
	//检查校验和是否正确
	int checkSum = pUtils->calculateCheckSum(ackPkt);
	//如果校验和正确
	if (checkSum == ackPkt.checksum) {
		if (base > ackPkt.acknum) {
			//接收冗余ACK
			int i = 0;
			cout << "接收冗余ACK" << ackPkt.acknum << endl;
			if (last_ack[0] == ackPkt.acknum) {
				if (last_ack[1] == -2) {
					last_ack[1] = ackPkt.acknum;
				}
				else {
					last_ack[2] = ackPkt.acknum;
				}
			}
			else {
				//初始化冗余ACK组
				for (int i = 0; i < 3; i++) {
					last_ack[i] = -2;
				}
				last_ack[0] = ackPkt.acknum;
			}
			//接收三次相同ACK
			if (is_equal()) {
				cout << "接收三次相同冗余ACK，执行重传" << endl;
				pUtils->printPacket("快速重传报文内容", packetWaitingAck[base%length]);
				pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[base%length]);
				show();
				//初始化冗余ACK组
				for (int i = 0; i < 3; i++) {
					last_ack[i] = -2;
				}
				//getchar();
			}
		}
		//更新base
		base = ackPkt.acknum + 1;
		pUtils->printPacket("发送方接收确认报文", ackPkt);
		if (base == nextseqnum) {
			//关闭定时器
			pns->stopTimer(SENDER, 0);
		}
		else {
			//重启定时器
			pns->stopTimer(SENDER, 0);
			pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
		}
	}
	else {
		pUtils->printPacket("发送方收到错误报文", ackPkt);
		cout << endl;
	}
}

void TCPSender::timeoutHandler(int seqNum) {
	cout << "已超时" << endl;
	//初始化冗余ACK组
	for (int i = 0; i < 3; i++) {
		last_ack[i] = -2;
	}
	//重启定时器并重新发送所有未确定报文,seqNum不考虑
	pns->stopTimer(SENDER, 0);
	pns->startTimer(SENDER, Configuration::TIME_OUT, 0);
	//重新发送base数据包
	pUtils->printPacket("超时重传报文内容", packetWaitingAck[base%length]);
	pns->sendToNetworkLayer(RECEIVER, packetWaitingAck[base % length]);
	show();
}


bool TCPSender::getWaitingState() {
	//窗口已满返回true
	return nextseqnum - base == WINDOW_SIZE;
}