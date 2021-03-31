#include <winsock2.h>
#include <iostream>
#include <cstring>
#include <limits.h>
#include <stdlib.h>
#include <sstream>
#include <thread>
#include <ws2tcpip.h>
#define true 1
using namespace std;

//服务端
//处理http请求报文
void send_404(SOCKET s);
int create_socket(SOCKET s);
void accept_socket(sockaddr_in addrClient,string buffer);
void deal_socket(SOCKET s, string strb, string buffer);
int ThreadFun(SOCKET c,sockaddr_in addrClinet);
//指定动态库的lib文件
#pragma comment(lib,"ws2_32.lib")
string s1 = ".html";
string s2 = ".jpg";
int main() {
	WSADATA WD;
	if (WSAStartup(MAKEWORD(2, 2), &WD) != 0) {
		cout << "WSAStartup Error!" << WSAGetLastError() << endl;
		return 0;
	}
	//创建TCP SOCKET
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET) {
		cout << "Socket Error!" << WSAGetLastError() << endl;
		return 0;
	}
	
	int return_s = create_socket(s);
	while (true && return_s!=-1) {
		//主线程循环接收客户端请求,并返回和客户端通讯的套接字
		sockaddr_in addrClient;
		int len = sizeof(addrClient);
		SOCKET c = accept(return_s, (sockaddr*)&addrClient, &len);
		if (c != INVALID_SOCKET)
		{
			//创建线程并且传入与client通讯套接字
			thread p(ThreadFun, c, addrClient);
			p.detach();
		}
		else
		{
			cout << "Accept Error!" << WSAGetLastError() << endl;
			return 0;
		}
	}
	//关闭套接字
	closesocket(s);
	WSACleanup();
	return 0;
}

int create_socket(SOCKET s) {
	int ad = 0, cnt = 0;
	char cd[20] = {'\0'};
	//绑定socket到一个IP地址和端口
	sockaddr_in addr;
	addr.sin_family = AF_INET;//地址族
	cout << "please input socket font(0 means htons(80)):";
	cin >> ad;
	if (ad > 65535 || ad < 0) {
		cout << "Error input!" << endl;
		return -1;
	}
	addr.sin_port = ad == 0 ? htons(80) : htons(ad);//端口
	cout << "please input socket font(0 means INADDR_ANY, 1 means self_set):";
	cin >> cnt;
	if (cnt == 1) {
		cout << "SET:";
		cin >> cd;
		inet_pton(AF_INET, cd, &addr.sin_addr);//网络字节序
	}
	else if (cnt == 0) {
		cout << "INADDR_ANY is set" << endl;
		addr.sin_addr.S_un.S_addr =	htonl(INADDR_ANY);
	}
	else {
		cout << "Input Error!" << endl;
		return -1;
	}

	if (::bind(s, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		cout << "Bind Error!" << WSAGetLastError() << endl;
		return -1;
	}

	//监听,5代表等待队列长度
	if (listen(s, 10) == SOCKET_ERROR)
	{
		cout << "listen operation failed!" << endl;
		return -1;
	}
	return s;
}

void accept_socket(sockaddr_in addrClient, string buffer){
	cout << "PORT:" << ntohs(addrClient.sin_port) << endl;
	char str[20];
	inet_ntop(AF_INET, &addrClient.sin_addr, str, 20);
	cout << "IP:" << str << endl;
	//stringstream txt(buffer);
	//string stra,strb,strc;
	//txt >> stra;
	//txt >> strb;
	//txt >> strc;
	//cout << stra << " " << strb << " " << strc <<" "<< endl;
	string stra;
	int i = buffer.find("GET");
	int j = buffer.find("HTTP/1.1");
	stra = buffer.substr(i, j - i);
	stra += buffer.substr(j, 8);
	cout << stra << endl;
	return;
}

int ThreadFun(SOCKET c,sockaddr_in addrClient) {
	
	//发送接收消息
	int ret = 0;
	//接收客户端消息
	char buffer[2048] = { '\0' };
	ret = recv(c, buffer, sizeof(buffer), 0);
	//cout << buffer << endl;
	string stra, strb;
	stringstream http_txt(buffer);
	http_txt >> stra;
	http_txt >> strb;
	strb.erase(0, 1);
	if (stra == "GET")
	{
		string newbuf = buffer;
		accept_socket(addrClient,buffer);
		deal_socket(c, strb, newbuf);
	}
	return 0;
}


void deal_socket(SOCKET s, string strb, string buffer) {
	string path, send_buff;
	char site[100],ph[100];
	strcpy(site, strb.c_str);
	//path = "C:\\Users\\fanjunchao\\Desktop\\server\\html\\"+strb;
	_fullpath(ph, site, 100);
	path = ph;
	send_buff = "HTTP/1.1 200 OK\r\n";
	send_buff += "Connection: keep-alive\r\n";
	string str1 = "Content-Type: text/html\r\n";
	string str2= "Content-Type: image/jpg\r\n";
	if (strb.find(s1) != -1)
		send_buff += str1;
	else if (strb.find(s2) != -1)
		send_buff += str2;
	else {
		send_404(s);
		cout << "No Such Files!\n" << endl;
		return;
	}
	FILE *fp;
	int error = fopen_s(&fp, path.c_str(), "rb");
	if (error) {
		if (fp)
			fclose(fp);
		send_404(s);
		cout << "Files Error!\n" << endl;
		return;
	}
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	char *data = new char[length + 1];
	memset(data, 0, length + 1);
	fseek(fp, 0, SEEK_SET);
	send_buff += ("Content-Length: " + to_string(length));
	send_buff += "\r\n\r\n";
	fread(data, sizeof(char), length, fp);
	cout << send_buff;
	send(s, send_buff.c_str(), send_buff.length(), 0);
	send(s, data, length, 0);
	fclose(fp);
}

void send_404(SOCKET s)
{
	string send_buff = "<HTML><TITLE>Not Found</TITLE>\r\n";
	send_buff += "<BODY><h1 align='center'>404</h1><br/><h1 align='center'>file not found.</h1>\r\n";
	send_buff += "</BODY></HTML>\r\n";
	send(s, send_buff.c_str(), send_buff.length(), 0);
	closesocket(s);
}