//Group_ticket.h for Class Group_ticket Header
//auther 22510515018linyang
//time 2023.05.14
#include"Single_ticket.h"
#ifndef GROUP_TICKET
#define GROUP_TICKET

//������һ���Ź�Ʊ�����м̳е���Ʊ��
class Group_ticket :public Single_ticket
{
public:
	Group_ticket();
	Group_ticket(string, float, int, int,int);
	virtual float buy();
	int group_ticket;
};
#endif

