//Monthly_pass.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Monthly_pass.h"
//�޲ι��캯��
Monthly_pass::Monthly_pass()
{
	month_people_use = 0;
}
//�вι��캯��
Monthly_pass::Monthly_pass(string tina, float pri, int da, int peo_us, int mon_peo) :Single_ticket(tina,pri,da,peo_us), month_people_use(mon_peo){}
//buyʹ�ô˺�������һ���������ļ�monthly_pass.dat�����ļ�����д��ʣ���Ʊ�����������û����"�����빺Ʊ����"��ָ��
//��������
//����ֵ��float����Ʊʣ���Ʊ����
float Monthly_pass::buy()
{
	Ticket::price = 98.88;
	ofstream outfile("monthly_pass.dat", ios::out | ios::binary);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	Monthly_pass monthly_ticket[1];//������һ�����飬�������һ������Ʊ
	cout << "��������Ҫ����������" << endl;
	cin >> month_people_use;
	monthly_ticket[0].month_people_use = 100 - month_people_use;
	outfile.write((char*)&monthly_ticket[0], sizeof(monthly_ticket[0]));
	outfile.close();
	return monthly_ticket[0].month_people_use;
}
