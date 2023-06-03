//Group_ticket.ccpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Group_ticket.h"
#include<iostream>
using namespace std;
//无参构造函数
Group_ticket::Group_ticket()
{
	group_ticket = 0;
}
//有参构造函数
Group_ticket::Group_ticket(string tina, float pri, int da,  int peo_us,int group):Single_ticket(tina, pri, da, peo_us),group_ticket(group) {}
//buy使用此函数创建一个二进制文件group_ticket.dat，向文件里面写入剩余的票数，并且向用户输出"请输入购票人数"的指令
//参数：无
//返回值：float（团购票剩余的票数）
float Group_ticket::buy()
{
	Ticket::price = 188.88;
	ofstream outfile("group_ticket.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	Group_ticket gro_ticket[1];//定义了一个数组，里面存了一百张团购票
	cout << "请输入购票人数:" << endl;
	cin >> group_ticket;
	gro_ticket[0].group_ticket = 100 - group_ticket;
	outfile.write((char*)&gro_ticket[0], sizeof(gro_ticket[0]));
	outfile.close();
	return gro_ticket[0].group_ticket;
}