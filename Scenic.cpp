//Scenic.cpp formain function
//auther 22510515018linyang
//time 2023.05.14

#include"Scenic.h"
//�вι��캯��
Scenic::Scenic(string tina, float pri, int da, int peo_us, int mon_peo, int group, string touna, int nu, int pa, string scna, int touda, float sa, int totletick) :Tourist(tina, pri, da,  peo_us, mon_peo, group, touna, nu, pa), scenic_name(scna), tourist_date(touda), sale(sa), total_ticket_sales(totletick){}
//result1ʹ�ô˺����򿪶������ļ�single_ticket.dat������ʣ��ĵ���Ʊ
//��������
//����ֵ��void
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
    cout << "ʣ��Ʊ��Ϊ:" << single_ticket[0].people_use << endl;
}
//result2ʹ�ô˺����򿪶������ļ�monthly_pass.dat������ʣ�����Ʊ
//��������
//����ֵ��void
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
    cout << "ʣ��Ʊ��Ϊ:" << monthly_ticket[0].people_use << endl;
}
//result1ʹ�ô˺����򿪶������ļ�group_ticket.dat������ʣ����Ź�Ʊ
//��������
//����ֵ��void
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
    cout << "ʣ��Ʊ��Ϊ:" << gro_ticket[0].people_use << endl;
}
//query_salesʹ�ô˺���ʵ�ֲ�ѯ���۶�Ĺ���
//��������
//����ֵ��void
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
    printf("\t\t**************************��ӭ��ѯ���۶�**********************\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                          1---����Ʊ                      **\n");
    printf("\t\t**                          2---�Ź�Ʊ                      **\n");
    printf("\t\t**                          3---��Ʊ                        **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t****************************************************************");
    printf("\n����ѡ������Ҫ�Ĳ���(1-3):  ");
    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "������������������!" << endl;
            system("pause");
            fflush(stdin);
            continue;
        }
        switch (choice)
        {
        case 1:
            sale = Single_ticket::people_use * 28.88;
            cout << "���۶�Ϊ��" << sale << endl;
            break;
        case 2:sale = Monthly_pass::people_use * 98.88;
            cout << "���۶�Ϊ��" << sale << endl;
            break;
        case 3:sale = Group_ticket::people_use * 188.88;
            cout << "���۶�Ϊ��" << sale << endl;
            break;
        default:cout << "���������������������ѡ��:" << endl;
            break;
        }
    }
}
//query_ticketʹ�ô˺���ʵ�ֲ�ѯʣ��Ʊ���Ĺ���
//��������
//����ֵ��void
void Scenic::query_ticket() 
{

    printf("\n\n\n");
    printf("\t\t**************************��ӭ��ѯƱ��**********************\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                          1---����Ʊ                      **\n");
    printf("\t\t**                          2---�Ź�Ʊ                      **\n");
    printf("\t\t**                          3---��Ʊ                        **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t****************************************************************");
    printf("\n����ѡ������Ҫ�Ĳ���(1-3):  ");
    while (1)
    {
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            cout << "������������������!" << endl;
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
        default:cout << "���������������������ѡ��:" << endl;
            break;
        }
    }
}
//query_userʹ�ô˺���ʵ�ֲ�ѯ�û����Ĺ���
//��������
//����ֵ��void
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
    cout << "�û���Ϊ��" << people[0].people_number << endl;
}
//inside_functionʹ�ô˺���ʹ������Ա�ܹ���ѯ�������������
//��������
//����ֵ����
void Scenic::inside_function()
{
    int password_work = 0;//������Ա����
    cout << "����������:" << endl;
    cin >> password_work;
    system("cls");
    do
    {
        if (password_work == 0)
        {
            Scenic sce("����", 28.88, 15, 56, 56,18, "�ο�", 56, 56, "������", 0, 0, 0);
            printf("\n\n\n");
            printf("\t\t**************************��ӭ���ʹ���Աģʽ************************\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**                          1---��ѯ���۶�                        **\n");
            printf("\t\t**                          2---��ѯ�û���                        **\n");
            printf("\t\t**                          3---��ѯʣ��Ʊ��                      **\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**                                                                **\n");
            printf("\t\t**********************************************************************");
            printf("\n����ѡ������Ҫ�Ĳ���(1-3):  ");
            int choice;
            while (1)
            {
                cin >> choice;
                if (choice == 0)
                {
                    cout << "������������������!" << endl;
                    system("pause");
                    fflush(stdin);
                    continue;
                }
                switch (choice)
                {
                case 1:system("cls");
                    cout << "\n\t\t\t  ��ѯ���۶�\n\n";
                    sce.query_sales();;
                    break;
                case 2:system("cls");
                    cout << "\n\t\t\t  ��ѯ�û���\n\n";
                    sce.query_user();
                    break;
                case 3:system("cls");
                    cout << "\n\t\t\t  ��ѯʣ��Ʊ��\n\n";
                    sce.query_ticket();
                    break;
                default:cout << "���������������������ѡ��:" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "�������,����������!" << endl;
        }
    } while (1);
}
