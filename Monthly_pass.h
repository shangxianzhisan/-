//Monthly_pass.h for Class Monthly_pass Header
//auther 22510515018linyang
//time 2023.05.14
#include"Single_ticket.h"
#ifndef MONTHLY_PASS
#define MONTHLY_PASS
//������һ����Ʊ�����м̳е���Ʊ��
class Monthly_pass :public Single_ticket
{
public:
	Monthly_pass();
	Monthly_pass(string, float, int, int,int);
	virtual float buy();
	int month_people_use;
};
#endif
