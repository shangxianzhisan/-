//Single_ticket.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Single_ticket.h"
#include"Tourist.h"
//�޲ι��캯��
Single_ticket::Single_ticket()
{
	people_use = 0;
}
//�вι��캯��
Single_ticket::Single_ticket(string tina, float pri, int da,  int peo_us):Ticket(tina,pri,da),people_use(peo_us){}
//buyʹ�ô˺���������һ���������ļ�single_ticket.dat�����ļ�����д��ʣ���Ʊ�����������û����"�����빺Ʊ����"��ָ��
//��������
//����ֵ��float������Ʊʣ���Ʊ����
float Single_ticket::buy()
{
	Ticket::price = 28.88;
	ofstream outfile("single_ticket.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open single_ticket.dat error" << endl;
		exit(1);
	}
	Single_ticket single_ticket[1];//������һ�����飬�������һ���ŵ���Ʊ
	cout << "��������Ҫ�����������" << endl;
	cin >>  people_use;
	single_ticket[0].people_use = 100 - people_use;
	outfile.write((char*)&single_ticket[0], sizeof(single_ticket[0]));
	outfile.close();
	return single_ticket[0].people_use;
}