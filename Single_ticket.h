//Single_ticket.h for Class Single_ticket Header
//auther 22510515018linyang
//time 2023.05.14
#include"Ticket.h"
#ifndef SINGLE_TICKET
#define SINGLE_TICKET
//定义了一个单人票类，公有继承票类
class Single_ticket:public Ticket
{
public:
	Single_ticket();
	Single_ticket(string, float, int,int);
	virtual float buy();
	int people_use;//人数
};
#endif
