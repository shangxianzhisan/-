//Ticket.h for Class Ticket Header
//auther 22510515018linyang
//time 2023.05.14

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
#ifndef TICKET
#define TICKET
//定义了一个票基类
class Ticket
{
public:
	Ticket();
	Ticket(string, float, int);
	virtual float buy()  = 0;
protected:
	string ticket_name;
	float price;
	int date;
};
#endif
