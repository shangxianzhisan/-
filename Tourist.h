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
//定义了一个游客类。公有继承单人票类，月票类，团购票类
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
	string tourist_name;//姓名
	int num;//账号
	int password;//密码
	static float remaining_sum;//余额
	static int people_number;//人数
};
#endif

