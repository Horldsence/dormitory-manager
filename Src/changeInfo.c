#include "changeInfo.h"
#include "main.h"

//用户登录注册菜单函数
void Register_system()
{
    int select;
    Menu1();
    scanf("%d", &select);
    switch(select)
    {
    case 0:  //退出系统
        printf("\n成功退出系统！期待你的下次使用O(∩_ ∩)O ，祝你生活愉快！\n");
        exit(0);
    case 1: //登录账户
        User_enter();
        return;
    case 2://注册账号
        User_reg();
        return;
    default: //重新输入选项
        printf("\n输入错误，输入任意键返回 *系统用户登录注册界面* ...\n");
        scanf("%*c%*c");
        system("clear");
        Register_system();
        return;
    }
}

//系统用户登录注册界面
void Menu1()
{
    system("clear");
    printf("===============================================\n");
    printf("                                            \n");
    printf("            欢 迎 使 用 宿 舍 系 统             \n");
    printf("      该界面为：*系统用户登录注册界面*            \n");
    printf("     1: 登录  2：新用户注册  0: 退出系统         \n");
    printf("                                             \n");
    printf("===============================================\n");
    printf("请输入菜单项：\n");
}