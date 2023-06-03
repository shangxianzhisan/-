//Single_ticket.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Single_ticket.h"
#include"Tourist.h"
//无参构造函数
Single_ticket::Single_ticket()
{
	people_use = 0;
}
//有参构造函数
Single_ticket::Single_ticket(string tina, float pri, int da,  int peo_us):Ticket(tina,pri,da),people_use(peo_us){}
//buy使用此函数创建了一个二进制文件single_ticket.dat，向文件里面写入剩余的票数，并且向用户输出"请输入购票人数"的指令
//参数：无
//返回值：float（单人票剩余的票数）
float Single_ticket::buy()
{
	Ticket::price = 28.88;
	ofstream outfile("single_ticket.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open single_ticket.dat error" << endl;
		exit(1);
	}
	Single_ticket single_ticket[1];//定义了一个数组，里面存了一百张单人票
	cout << "请输入需要购买的人数：" << endl;
	cin >>  people_use;
	single_ticket[0].people_use = 100 - people_use;
	outfile.write((char*)&single_ticket[0], sizeof(single_ticket[0]));
	outfile.close();
	return single_ticket[0].people_use;
}