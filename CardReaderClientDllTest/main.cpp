#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>
#include "CardReaderClientDll.h"

using namespace std;

#pragma comment(lib, "CardReaderClientDll.lib")

string i2str(int a)
{
	char* str = new char[10];
	sprintf(str, "%d", a);
	return string(str);
}

int main(void)
{
// 	int   number   =   12345;  
// 	char   string[25];  
// 	
// 	itoa(number,   string,   10);  
// 
// 	printf( "integer   =   %d   string   =   %s\n ",   number,   i2str(number).c_str());
// 	return   0;

// 	char* buf = "00 03 00 E7 00 2F 75,1";
// 	char devID[512];
// 	int readerId;
// 	string str(buf);
// 
// 	string::size_type loc = str.find(",", 0);
// 	string first = str.substr(0, loc);
// 	strcpy(devID, first.c_str());
// 	string second = str.substr(loc + 1);
// 	readerId = atoi(second.c_str());
// 	cout << devID << ", " << readerId << endl;
// 	return 0;

	Reader* reader = new Reader();
	reader->readerId = 1;

	// ��ʼ���ͻ���
	InitClient("127.0.0.1", 60000);

	// ��ȡ������
	if (0 != GetReader(reader, 1000, 1000))
	{
		printf("getReader Failed.");
	}
	char devID[512];
	int readerId;

	// ��ȡ������id
// 	{
// 		if (0 != GetDevIDAndReaderId(reader, devID, 512, readerId))
// 		{
// 			printf("GetDevIDAndReaderId Failed.");
// 		}
// 		cout << devID << ", " << readerId << endl;
// 	}
	
	// �޸Ķ�����id
// 	{
// 		if (0 != SetReaderIdByDevID(reader, devID, 1))
// 		{
// 			printf("SetReaderIdByDevID Failed.");
// 		}
// 	}
	
	// ��ȡ������id
// 	{
// 		if (0 != GetDevIDAndReaderId(reader, devID, 512, readerId))
// 		{
// 			printf("GetDevIDAndReaderId Failed.");
// 		}
//  		cout << devID << ", " << readerId << endl;
// 	}
	
	// ��ȡ����汾���ն�����
// 	char appVer[512];
// 	char devType[512];
// 	{
// 		if (0 != GetAppVerAndDevType(reader, appVer, 512, devType, 512))
// 		{
// 			printf("GetAppVerAndDevType Failed.");
// 		}
// 		cout << appVer << ", " << devType << endl;
// 	}

	// ��ȡоƬid(���ø�λ֮��������, �����)
// 	char chipID[512];
// 	{
// 		if (0 != GetChipID(reader, chipID, 512))
// 		{
// 			printf("GetChipID failed.");
// 		}
// 		cout << chipID << endl;
// 	}

	// ���A����B�����Ƿ��п�
// 	int cardA;
// 	int cardB;
// 	{
// 		if (0 != IsCardReady(reader, cardA, cardB))
// 		{
// 			printf("IsCardReady failed.");
// 		}
// 		cout << cardA << ", " << cardB << endl;
// 	}
	
	// ��λӦ��
	SmartCom::string retCode;
	{
		if (0 != ResetCard(reader, retCode))
		{
			printf("ResetCard failed.");
		}
		cout << retCode.c_str() << endl;
	}

	// ִ�е�������(ִ��ǰ��Ҫ�ȸ�λӦ��)
	char* apdu = "00820000083132333435363738";
	{
		if (0 != CardApdu(reader, apdu, retCode, 1))
		{
			printf("CardApdu failed.");
		}
		cout << retCode.c_str() << endl;
	}

	// �ͷŶ�����
	if (0 != ReleaseReader(reader))
	{
		printf("ReleaseReader Failed.");
	}

	// �����ͻ�����Դ
	CleanUpClient();
	delete reader; // �ͷ��ڴ�

	return 0;
}