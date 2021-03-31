// StopWait.cpp : �������̨Ӧ�ó������ڵ㡣
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
	delete pUtils;									//ָ��Ψһ�Ĺ�����ʵ����ֻ��main��������ǰdelete
	delete pns;										//ָ��Ψһ��ģ�����绷����ʵ����ֻ��main��������ǰdelete
	return 0;
}

