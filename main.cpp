//main.cpp for main function
//auther 22510515018linyang
//time 2023.05.14
#include"Scenic.h"
void Welcome() //主菜单
{

    printf("\n\n\n");
    printf("\t\t**************************欢迎访问景区售票系统****************\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                          1---注册                        **\n");
    printf("\t\t**                          2---登录                        **\n");
    printf("\t\t**                          3---管理员模式                  **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t**                                                          **\n");
    printf("\t\t****************************************************************");
    printf("\n请您选择你需要的操作(1-3):  ");
};
int main() 
{
    system("color 0E");
    Scenic scenic("景区", 28.88, 15, 569, 56, 18, "游客", 56, 56, "景区名", 0, 0, 0);
    int choiceeee = 0;
    while (1)
    {
        system("cls");
        Welcome();
        cin >> choiceeee;
        if (choiceeee == 0)
        {
            cout << "输入有误，请重新输入!" << endl;
            system("pause");
            fflush(stdin);
            continue;
        }
        switch (choiceeee)
        {
        case 1:system("cls");
            cout << "\n\t\t\t  注册\n\n";
            scenic.login();
            break;
        case 2:system("cls");
            cout << "\n\t\t\t\t登录\n";
            scenic.enter();
            break;
        case 3:system("cls");
            cout << "\n\t\t\t\t管理员模式\n";
            scenic.inside_function();
            break;
        default:cout << "输入有误，请重新输入你的选择:" << endl;
            break;
        }
    }
    return 0;
}
