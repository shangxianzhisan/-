//Single_ticket.h for Class Single_ticket Header
//auther 22510515018linyang
//time 2023.05.14
#include"Ticket.h"
#ifndef SINGLE_TICKET
#define SINGLE_TICKET
//������һ������Ʊ�࣬���м̳�Ʊ��
class Single_ticket:public Ticket
{
public:
	Single_ticket();
	Single_ticket(string, float, int,int);
	virtual float buy();
	int people_use;//����
};
#endif
