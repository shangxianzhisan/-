//Tourist.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Tourist.h"
//��̬������ʼ��
int Tourist::people_number = 0;
float Tourist::remaining_sum = 0;
//�޲ι��캯��
Tourist::Tourist()
{
	tourist_name = "0";
	password = 0;
}
//�вι��캯��
Tourist::Tourist(string tina, float pri, int da, int peo_us, int mon_peo,int group, string touna, int nu, int pa) :Single_ticket(tina, pri, da, peo_us), Monthly_pass(tina, pri, da, peo_us, mon_peo), Group_ticket(tina, pri, da, peo_us,group), tourist_name(touna), num(nu), password(pa){}
//loginʹ�ô˺���ʵ��ע��Ĺ��ܣ�����һ���������ļ�login.dat��������д��ע����������������û������Ӧ��ָ��
//��������
//����ֵ��void
void Tourist::login()
{
	do
	{
		cout << "��������Ҫע������" << endl;
		cin >> people_number;
		people_number= 0+ people_number;
		if (people_number >= 100)
		{
			cout << "����ע���������࣬������ѡ�����ע������!" << endl;
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
	cout << "����������������Զ�����˺��Լ�����:" << endl;
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
//enterʹ�ô˺���ʵ�ֵ�¼�Ĺ��ܣ��򿪶������ļ�login.dat����ȡ����ע�����Ϣ����֤��Ϣ�Ƿ���ȷ����ȷ�������һ�����棬ѡ���ֵ����ѯ���������
//��������
//����ֵ��void
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
		cout << "����������,�Զ�����˺��Լ����룺" << endl;
		cin >> tourist_name >> num >> password;
		system("cls");
		int temp = -1;
		for (int i = 0;i < 100;i++)
		{
			if (tourist[i].tourist_name == tourist_name && tourist[i].num == num && tourist[i].password == password)
			{
				cout << "��¼�ɹ�" << endl;
				temp = i;
				break;
			}
		}
		if (temp == 0)
		{
			cout << "�������Ϣ�����ϣ���¼ʧ��,�����µ�¼!" << endl;
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
		printf("\t\t**************************��ӭ���ʾ�����Ʊϵͳ****************\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                          1---��ֵ                        **\n");
		printf("\t\t**                          2---��ѯ                        **\n");
		printf("\t\t**                          3---����                        **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t****************************************************************");
		printf("\n����ѡ������Ҫ�Ĳ���(1-3):  ");
		int choice;
		cin >> choice;
		if (choice == 0)
		{
			cout << "������������������!" << endl;
			system("pause");
			fflush(stdin);
			continue;
		}
		switch (choice)
		{
		case 1:system("cls");
			cout << "\n\t\t\t\t��ֵ\n";
			recharge();
			break;
		case 2:system("cls");
			cout << "\n\t\t\t\t��ѯ\n";
			inquire();
			break;
		case 3:system("cls");
			cout << "\n\t\t\t\t����\n";
			buy();
			break;
		default:cout << "���������������������ѡ��:" << endl;
			break;
		}
	}
}
//rechargeʹ�ô˺����ﵽ��ֵ��Ҫ�󣬴���һ���������ļ�money.dat��������д���˻������
//��������
//����ֵ��void
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
	cout << "��������Ҫ��ֵ�Ľ�" << endl;
	cin >> tou[0].remaining_sum;
	tou[0].remaining_sum += money;
	outfile.write((char*)&tou[0], sizeof(tou[0]));
	outfile.close();
	cout << "�������Ϊ��" << tou[0].remaining_sum << endl;
}
//inquireʹ�ô˺����ﵽ��ѯ�Ĺ��ܣ��򿪶������ļ�money.dat����ȡ�����ֵ����Ϣ�����û�������Ϊ����
//��������
//����ֵ��void
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
	cout << "�������Ϊ��" << tou[0].remaining_sum << endl;
}
//buyʹ�ô˺���ʵ���ο���Ʊ�Ĺ���
//��������
//����ֵ��void
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
		printf("\t\t**************************��ӭ���ʾ�����Ʊϵͳ****************\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                          1---����Ʊ�� 28.88              **\n");
		printf("\t\t**                          2---�Ź�Ʊ ��98.88              **\n");
		printf("\t\t**                          3---��Ʊ  ��188.88              **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t**                                                          **\n");
		printf("\t\t****************************************************************");
		printf("\n����ѡ������Ҫ�Ĳ���(1-3):  ");
			cin >> choice;
			if (choice == 0)
			{
				cout << "������������������!" << endl;
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
					cout << "��Ʊ�ɹ���ף����ÿ���!" << endl;
					temp = 1;
				}
				else
				{
					cout << "���㣬�������������ѡ��" << endl;
				}
				touri[0].remaining_sum = touri[0].remaining_sum - Single_ticket::people_use * Ticket::price;
				break;
			case 2:system("cls");
				Monthly_pass::buy();
				if (touri[0].remaining_sum > Monthly_pass::month_people_use * Ticket::price)
				{
					cout << "��Ʊ�ɹ���ף����ÿ���!" << endl;
					temp = 1;
				}
				else
				{
					cout << "���㣬�������������ѡ��" << endl;
				}
				touri[0].remaining_sum = touri[0].remaining_sum - Monthly_pass::month_people_use * Ticket::price;
				break;
			case 3:system("cls");
				Group_ticket::buy();
				if (touri[0].remaining_sum > Ticket::price * Group_ticket::group_ticket)
				{
					cout << "��Ʊ�ɹ���ף����ÿ���!" << endl;
					temp = 1;
				}
				else
				{
					cout << "���㣬�������������ѡ��" << endl;
				}
				touri[0].remaining_sum = touri[0].remaining_sum - Ticket::price * Group_ticket::group_ticket;
				break;
			default:cout << "���������������������ѡ��:" << endl;
			break;
			}
			if (temp == 1)
			{
				break;
			}
	}
	return touri[0].remaining_sum;
}