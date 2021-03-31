// StopWait.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Global.h"
#include "RdtSender.h"
#include "RdtReceiver.h"
#include "StopWaitRdtSender.h"
#include "StopWaitRdtReceiver.h"
#include "GBNRdtSender.h"
#include "GBNRdtReceiver.h"
#include "SRRdtSender.h"
#include "SRRdtReceiver.h"
#include "TCPSender.h"

int main(int argc, char** argv[])
{
	RdtSender *ps;
	RdtReceiver *pr;
	int i=1;
	switch (i) {
	
	case 1: {
		ps = new GBNRdtSender();
		pr = new GBNRdtReceiver();  
		break;
	}
	case 2: {
		ps = new SRRdtSender();
		pr = new SRRdtReceiver();
		break;
	}
	case 3: {
		ps = new TCPSender();
		pr = new GBNRdtReceiver();
		break;
	}
	default: {
		ps = new StopWaitRdtSender();
		pr = new StopWaitRdtReceiver();
		break;
	}
	}
	pns->init();
	pns->setRtdSender(ps);
	pns->setRtdReceiver(pr);
	pns->setInputFile("input.txt");
	pns->setOutputFile("output.txt");
	pns->start();
	delete ps;
	delete pr;
	delete pUtils;									//指向唯一的工具类实例，只在main函数结束前delete
	delete pns;										//指向唯一的模拟网络环境类实例，只在main函数结束前delete
	return 0;
}

