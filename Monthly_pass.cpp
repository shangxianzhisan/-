//Monthly_pass.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Monthly_pass.h"
//无参构造函数
Monthly_pass::Monthly_pass()
{
	month_people_use = 0;
}
//有参构造函数
Monthly_pass::Monthly_pass(string tina, float pri, int da, int peo_us, int mon_peo) :Single_ticket(tina,pri,da,peo_us), month_people_use(mon_peo){}
//buy使用此函数创建一个二进制文件monthly_pass.dat，向文件里面写入剩余的票数，并且向用户输出"请输入购票人数"的指令
//参数：无
//返回值：float（月票剩余的票数）
float Monthly_pass::buy()
{
	Ticket::price = 98.88;
	ofstream outfile("monthly_pass.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	Monthly_pass monthly_ticket[1];//定义了一个数组，里面存了一百张月票
	cout << "请输入需要购买人数：" << endl;
	cin >> month_people_use;
	monthly_ticket[0].month_people_use = 100 - month_people_use;
	outfile.write((char*)&monthly_ticket[0], sizeof(monthly_ticket[0]));
	outfile.close();
	return monthly_ticket[0].month_people_use;
}
