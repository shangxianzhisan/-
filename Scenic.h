//Scenic.h for Class Scenic Header
//auther 22510515018linyang
//time 2023.05.14
#include"Tourist.h"
#ifndef SCENIC
#define SCENIC
//定义了一个景区类，公有继承游客类
class Scenic :public Tourist
{
public:
	Scenic(string, float, int, int, int,int, string, int, int,string,int,float,int);
	void query_sales();
	void query_ticket();
	void inside_function();
	void result1();
	void result2();
	void result3();
	static void query_user();
protected:
	string scenic_name;
	int tourist_date;
	float sale;
	int total_ticket_sales;
};
#endif