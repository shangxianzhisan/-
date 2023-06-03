//Scenic.cpp formain function
//auther 22510515018linyang
//time 2023.05.14

#include"Scenic.h"
//有参构造函数
Scenic::Scenic(string tina, float pri, int da, int peo_us, int mon_peo, int group, string touna, int nu, int pa, string scna, int touda, float sa, int totletick) :Tourist(tina, pri, da,  peo_us, mon_peo, group, touna, nu, pa), scenic_name(scna), tourist_date(touda), sale(sa), total_ticket_sales(totletick){}
//result1使用此函数打开二进制文件single_ticket.dat，读出剩余的单人票
//参数：无
//返回值：void
void Scenic::result1()
{
    ifstream infile("single_ticket.dat", ios::in | ios::binary);
    if (!infile)
    {
        cerr << "open erorr" << endl;
        exit(1);
    }
    Single_ticket single_ticket[1];
    infile.read((char*)&single_ticket[0], sizeof(single_ticket[0]));
    infile.close();
    cout << "剩余票数为:" << single_ticket[0].people_use << endl;
}
//result2使用此函数打开二进制文件monthly_pass.dat，读出剩余的月票
//参数：无
//返回值：void
void Scenic::result2()
{
    ifstream infile("monthly_pass.dat", ios::in | ios::binary);
    if (!infile)
    {
        cerr << "open erorr" << endl;
        exit(1);
    }
    Monthly_pass monthly_ticket[1];
    infile.read((char*)&monthly_ticket[0], sizeof(monthly_ticket[0]));
    infile.close();
    cout << "剩余票数为:" << monthly_ticket[0].people_use << endl;
}
//result1使用此函数打开二进制文件group_ticket.dat，读出剩余的团购票
//参数：无
//返回值：void
void Scenic::result3()
{
    ifstream infile("group_ticket.dat", ios::in | ios::binary);
    if (!infile)
    {
        cerr << "open erorr" << endl;
        exit(1);
    }
    Group_ticket gro_ticket[1];
    infile.read((char*)&gro_ticket[0], sizeof(gro_ticket[0]));
    infile.close();
    cout << "剩余票数为:" << gro_ticket[0].people_use << endl;
}
//query_sales使用此函数实现查询销售额的功能
//参数：无
//返回值：void
void Scenic::query_sales()
{
    Single_ticket single_ticket[1];
    Monthly_pass monthly_ticket[1];
    Group_ticket gro_ticket[1];
    ifstream infile1("single_ticket.dat", ios::in | ios::binary);
    if (!infile1)
    {
        cerr << "open single_ticket.dat error" << endl;
        exit(1);
    }
    ifstream infile2("monthly_pass.dat", ios::in | ios::binary);
    if (!infile2)
    {
        cerr << "open monthly_pass.dat error" << endl;
        exit(1);
    }
    ifstream infile3("group_ticket.dat", ios::in | ios::binary);
    if (!infile3)
    {
        cerr << "open group_ticket.dat error" << endl;
        exit(1);
    }
    infile1.read((char*)&single_ticket[0], sizeof(single_ticket[0]));
    infile2.read((char*)&monthly_ticket[0], sizeof(monthly_ticket[0]));
    infile3.read((char*)&gro_ticket[0], sizeof(gro_ticket[0]));
    infile1.close();
    infile2.close();
    infile3.close();
    system("cls");
    printf("\n\n\n");
    printf("\t\t**************************欢迎查询销售额**********************\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                          1---单人票                      **\n");
    printf("\t\t**                          2---团购票                      **\n");
    printf("\t\t**                          3---月票                        **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t****************************************************************");
    printf("\n请您选择你需要的操作(1-3):  ");
    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "输入有误，请重新输入!" << endl;
            system("pause");
            fflush(stdin);
            continue;
        }
        switch (choice)
        {
        case 1:
            sale = Single_ticket::people_use * 28.88;
            cout << "销售额为：" << sale << endl;
            break;
        case 2:sale = Monthly_pass::people_use * 98.88;
            cout << "销售额为：" << sale << endl;
            break;
        case 3:sale = Group_ticket::people_use * 188.88;
            cout << "销售额为：" << sale << endl;
            break;
        default:cout << "输入有误，请重新输入你的选择:" << endl;
            break;
        }
    }
}
//query_ticket使用此函数实现查询剩余票数的功能
//参数：无
//返回值：void
void Scenic::query_ticket() 
{

    printf("\n\n\n");
    printf("\t\t**************************欢迎查询票数**********************\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                          1---单人票                      **\n");
    printf("\t\t**                          2---团购票                      **\n");
    printf("\t\t**                          3---月票                        **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t****************************************************************");
    printf("\n请您选择你需要的操作(1-3):  ");
    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "输入有误，请重新输入!" << endl;
            system("pause");
            fflush(stdin);
            continue;
        }
        switch (choice)
        {
        case 1:result1();
            break;
        case 2:result2();
            break;
        case 3:result3();
            break;
        default:cout << "输入有误，请重新输入你的选择:" << endl;
            break;
        }
    }
}
//query_user使用此函数实现查询用户数的功能
//参数：无
//返回值：void
void Scenic::query_user()
{
	ifstream infile("login.dat", ios::in | ios::binary);
    if (!infile)
    {
        cerr << "open error" << endl;
        exit(1);
    }
    Tourist people[1];
    infile.read((char*)&people[0], sizeof(people[0]));
    cout << "用户数为：" << people[0].people_number << endl;
}
//inside_function使用此函数使工作人员能够查询景区的销售情况
//参数：无
//返回值：无
void Scenic::inside_function()
{
    int password_work = 0;//工作人员密码
    cout << "请输入密码:" << endl;
    cin >> password_work;
    system("cls");
    do
    {
        if (password_work == 0)
        {
            Scenic sce("景区", 28.88, 15, 56, 56,18, "游客", 56, 56, "景区名", 0, 0, 0);
            printf("\n\n\n");
            printf("\t\t**************************欢迎访问管理员模式************************\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**                          1---查询销售额                        **\n");
            printf("\t\t**                          2---查询用户数                        **\n");
            printf("\t\t**                          3---查询剩余票数                      **\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**********************************************************************");
            printf("\n请您选择你需要的操作(1-3):  ");
            int choice;
            while (1)
            {
                cin >> choice;
                if (choice == 0)
                {
                    cout << "输入有误，请重新输入!" << endl;
                    system("pause");
                    fflush(stdin);
                    continue;
                }
                switch (choice)
                {
                case 1:system("cls");
                    cout << "\n\t\t\t  查询销售额\n\n";
                    sce.query_sales();;
                    break;
                case 2:system("cls");
                    cout << "\n\t\t\t  查询用户数\n\n";
                    sce.query_user();
                    break;
                case 3:system("cls");
                    cout << "\n\t\t\t  查询剩余票数\n\n";
                    sce.query_ticket();
                    break;
                default:cout << "输入有误，请重新输入你的选择:" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "密码错误,请重新输入!" << endl;
        }
    } while (1);
}
