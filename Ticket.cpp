//Ticket.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Ticket.h"
//�вι��캯��
Ticket::Ticket(string tina,float pri,int da):ticket_name(tina),price(pri),date(da){}
//�޲ι��캯��
Ticket::Ticket()
{
	ticket_name = "0 ";
	price = 0;
	date = 0;
}