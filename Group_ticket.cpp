//Group_ticket.ccpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Group_ticket.h"
#include<iostream>
using namespace std;
//�޲ι��캯��
Group_ticket::Group_ticket()
{
	group_ticket = 0;
}
//�вι��캯��
Group_ticket::Group_ticket(string tina, float pri, int da,  int peo_us,int group):Single_ticket(tina, pri, da, peo_us),group_ticket(group) {}
//buyʹ�ô˺�������һ���������ļ�group_ticket.dat�����ļ�����д��ʣ���Ʊ�����������û����"�����빺Ʊ����"��ָ��
//��������
//����ֵ��float���Ź�Ʊʣ���Ʊ����
float Group_ticket::buy()
{
	Ticket::price = 188.88;
	ofstream outfile("group_ticket.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	Group_ticket gro_ticket[1];//������һ�����飬�������һ�����Ź�Ʊ
	cout << "�����빺Ʊ����:" << endl;
	cin >> group_ticket;
	gro_ticket[0].group_ticket = 100 - group_ticket;
	outfile.write((char*)&gro_ticket[0], sizeof(gro_ticket[0]));
	outfile.close();
	return gro_ticket[0].group_ticket;
}