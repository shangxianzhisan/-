//main.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Scenic.h"
void Welcome() //���˵�
{

    printf("\n\n\n");
    printf("\t\t**************************��ӭ���ʾ�����Ʊϵͳ****************\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                          1---ע��                        **\n");
    printf("\t\t**                          2---��¼                        **\n");
    printf("\t\t**                          3---����Աģʽ                  **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t****************************************************************");
    printf("\n����ѡ������Ҫ�Ĳ���(1-3):  ");
};
int main() 
{
    system("color 0E");
    Scenic scenic("����", 28.88, 15, 569, 56, 18, "�ο�", 56, 56, "������", 0, 0, 0);
    int choiceeee = 0;
    while (1)
    {
        system("cls");
        Welcome();
        cin >> choiceeee;
        if (choiceeee == 0)
        {
            cout << "������������������!" << endl;
            system("pause");
            fflush(stdin);
            continue;
        }
        switch (choiceeee)
        {
        case 1:system("cls");
            cout << "\n\t\t\t  ע��\n\n";
            scenic.login();
            break;
        case 2:system("cls");
            cout << "\n\t\t\t\t��¼\n";
            scenic.enter();
            break;
        case 3:system("cls");
            cout << "\n\t\t\t\t����Աģʽ\n";
            scenic.inside_function();
            break;
        default:cout << "���������������������ѡ��:" << endl;
            break;
        }
    }
    return 0;
}
