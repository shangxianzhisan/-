//Tourist.h for Class Tourist Header
//auther 22510515018linyang
//time 2023.05.14

#include"Monthly_pass.h"
#include"Group_ticket.h"
#include<iostream>
#include<string>
using namespace std;
#ifndef TOURIST
#define TOURIST
//������һ���ο��ࡣ���м̳е���Ʊ�࣬��Ʊ�࣬�Ź�Ʊ��
class Tourist:public Single_ticket,public Monthly_pass,public Group_ticket
{
public:
	Tourist();
	Tourist(string, float, int, int, int,int,string,int,int);
	static void login();
	void enter();
	static void recharge();
	void inquire();
	virtual float buy();
protected:
	string tourist_name;//����
	int num;//�˺�
	int password;//����
	static float remaining_sum;//���
	static int people_number;//����
};
#endif

