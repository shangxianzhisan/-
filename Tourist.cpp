//Tourist.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Tourist.h"
//静态变量初始化
int Tourist::people_number = 0;
float Tourist::remaining_sum = 0;
//无参构造函数
Tourist::Tourist()
{
	tourist_name = "0";
	password = 0;
}
//有参构造函数
Tourist::Tourist(string tina, float pri, int da, int peo_us, int mon_peo,int group, string touna, int nu, int pa) :Single_ticket(tina, pri, da, peo_us), Monthly_pass(tina, pri, da, peo_us, mon_peo), Group_ticket(tina, pri, da, peo_us,group), tourist_name(touna), num(nu), password(pa){}
//login使用此函数实现注册的功能，创建一个二进制文件login.dat，向里面写入注册的人数，并且向用户输出相应的指令
//参数：无
//返回值：void
void Tourist::login()
{
	do
	{
		cout << "请输入需要注册人数" << endl;
		cin >> people_number;
		people_number= 0+ people_number;
		if (people_number >= 100)
		{
			cout << "今日注册人数过多，请重新选择你的注册人数!" << endl;
		}
		else
		{
			break;
		}
	} while (1);
	ofstream outfile("login.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	Tourist tourist[100];
	Tourist people[1];
	people[0].people_number = people_number;
	outfile.write((char*)&people[0], sizeof(people[0]));
	cout << "请输入你的姓名和自定义的账号以及密码:" << endl;
	for (int i = 0;i < people_number;i++)
	{
		cin >> tourist[i].tourist_name >> tourist[i].num >> tourist[i].password;
	}
	for (int i = 0;i < people_number;i++)
	{
		outfile.write((char*)&tourist[i], sizeof(tourist[i]));
	}
	outfile.close();
}
//enter使用此函数实现登录的功能，打开二进制文件login.dat，读取里面注册的信息，验证信息是否正确，正确后进入下一个界面，选择充值，查询，购买操作
//参数：无
//返回值：void
void Tourist::enter()
{
	Tourist tourist[100];
	ifstream infile("login.dat", ios::in | ios::binary);
	if (!infile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	for (int i = 0;i < 100;i++)
	{
		infile.read((char*)&tourist[i], sizeof(tourist[i]));
	}
	infile.close();
	do
	{
		cout << "请输入姓名,自定义的账号以及密码：" << endl;
		cin >> tourist_name >> num >> password;
		system("cls");
		int temp = -1;
		for (int i = 0;i < 100;i++)
		{
			if (tourist[i].tourist_name == tourist_name && tourist[i].num == num && tourist[i].password == password)
			{
				cout << "登录成功" << endl;
				temp = i;
				break;
			}
		}
		if (temp == 0)
		{
			cout << "输入的信息不符合，登录失败,请重新登录!" << endl;
			continue;
		}
		else
		{
			break;
		}
	} while (1);
	while (1)
	{
		printf("\n\n\n");
		printf("\t\t**************************欢迎访问景区售票系统****************\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                          1---充值                        **\n");
		printf("\t\t**                          2---查询                        **\n");
		printf("\t\t**                          3---购买                        **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t****************************************************************");
		printf("\n请您选择你需要的操作(1-3):  ");
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			cout << "输入有误，请重新输入!" << endl;
			system("pause");
			fflush(stdin);
			continue;
		}
		switch (choice)
		{
		case 1:system("cls");
			cout << "\n\t\t\t\t充值\n";
			recharge();
			break;
		case 2:system("cls");
			cout << "\n\t\t\t\t查询\n";
			inquire();
			break;
		case 3:system("cls");
			cout << "\n\t\t\t\t购买\n";
			buy();
			break;
		default:cout << "输入有误，请重新输入你的选择:" << endl;
			break;
		}
	}
}
//recharge使用此函数达到充值的要求，创建一个二进制文件money.dat，向里面写入账户的余额
//参数：无
//返回值：void
void Tourist::recharge()
{
	ofstream outfile("money.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	Tourist tou[1];
	float money = 0;
	cout << "请输入需要充值的金额：" << endl;
	cin >> tou[0].remaining_sum;
	tou[0].remaining_sum += money;
	outfile.write((char*)&tou[0], sizeof(tou[0]));
	outfile.close();
	cout << "您的余额为：" << tou[0].remaining_sum << endl;
}
//inquire使用此函数达到查询的功能，打开二进制文件money.dat，读取里面充值的信息，向用户输出余额为多少
//参数：无
//返回值：void
void Tourist::inquire()
{
	Tourist tou[1];
	ifstream infile("money.dat", ios::in | ios::binary);
	if (!infile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	infile.read((char*)&tou[0], sizeof(tou[0]));
	cout << "您的余额为：" << tou[0].remaining_sum << endl;
}
//buy使用此函数实现游客买票的功能
//参数：无
//返回值：void
float Tourist::buy()
{
	int choice = 0;
	Tourist touri[1];
	ifstream infile("money.dat", ios::in | ios::binary);
	if (!infile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	infile.read((char*)&touri[0], sizeof(touri[0]));
	infile.close();
	int temp = -1;
	while (1)
	{ 
		printf("\n\n\n");
		printf("\t\t**************************欢迎访问景区售票系统****************\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                          1---单人票： 28.88              **\n");
		printf("\t\t**                          2---团购票 ：98.88              **\n");
		printf("\t\t**                          3---月票  ：188.88              **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t****************************************************************");
		printf("\n请您选择你需要的操作(1-3):  ");
			cin >> choice;
			if (choice == 0)
			{
				cout << "输入有误，请重新输入!" << endl;
				system("pause");
				fflush(stdin);
				continue;
			}
			switch (choice)
			{
			case 1:system("cls");
				Single_ticket::buy();
				if (touri[0].remaining_sum > Single_ticket::people_use * Ticket::price)
				{
					cout << "购票成功，祝您玩得快乐!" << endl;
					temp = 1;
				}
				else
				{
					cout << "余额不足，请重新输入你的选择" << endl;
				}
				touri[0].remaining_sum = touri[0].remaining_sum - Single_ticket::people_use * Ticket::price;
				break;
			case 2:system("cls");
				Monthly_pass::buy();
				if (touri[0].remaining_sum > Monthly_pass::month_people_use * Ticket::price)
				{
					cout << "购票成功，祝您玩得快乐!" << endl;
					temp = 1;
				}
				else
				{
					cout << "余额不足，请重新输入你的选择" << endl;
				}
				touri[0].remaining_sum = touri[0].remaining_sum - Monthly_pass::month_people_use * Ticket::price;
				break;
			case 3:system("cls");
				Group_ticket::buy();
				if (touri[0].remaining_sum > Ticket::price * Group_ticket::group_ticket)
				{
					cout << "购票成功，祝您玩得快乐!" << endl;
					temp = 1;
				}
				else
				{
					cout << "余额不足，请重新输入你的选择" << endl;
				}
				touri[0].remaining_sum = touri[0].remaining_sum - Ticket::price * Group_ticket::group_ticket;
				break;
			default:cout << "输入有误，请重新输入你的选择:" << endl;
			break;
			}
			if (temp == 1)
			{
				break;
			}
	}
	return touri[0].remaining_sum;
}