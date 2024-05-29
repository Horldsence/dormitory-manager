#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    USER user[M]; //定义结构体数组保存用户信息


    Register_system(); // 登录注册功能  系统管理员登录后sign = 1， 普通用户登录后 sign = 2，
    Load(user, &n); // 把用户信息加载到内存中
    readFile(); //
    if(sign == 1) // 进入系统管理员菜单
    {
        int select;
        FILE *fp;
        while(1)
        {
            Menu_admist();
            printf("请输入菜单选项：\n");
            scanf("%d", &select);
            switch(select)
            {
                case 1: // 批量创建用户
                    Creat_account(user, &n);break;
                case 2: // 批量删除用户
                    De_account(user, &n);break;
                case 3: //修改账号密码
                    Edit_accont(user, &n);break;
                case 4: //重置账号密码
                    PrAllAccount(user, &n);break;
                case 5://显示全部住宿信息 排序
                    view(); break;
                case 6://添加一条住宿信息 查 增
                    add(); break;
                case 7://修改一条住宿信息
                    edit(); break;
                case 8://删除一条住宿信息
                    delete(); break;
                case 9://根据姓名查找
                    find(1); break;
                case 10://根据学号查找
                    find(2); break;
                case 11://根据住宿号查找
                    find(3); break;
                case 0:
                    printf("成功退出系统，期待你的下次使用O(∩_ ∩)O, 祝你生活愉快！\n");
                    writeDataToFile();
                    exit(0);
                default:
                    printf("\n输入错误！无该菜单，输入任意键返回 *系统管理员功能菜单界面* ...\n");
                    scanf("%*c%*c");
                    break;
            }
        }

    }
    if(sign == 2) // 进入系统普通用户菜单
    {
        int select;
        FILE *fp;
        while(1)
        {
            Menu_user();
            printf("请输入菜单选项：\n");
            scanf("%d", &select);
            switch(select)
            {
                case 1:
                    Edit_accont(user, &n); //修改账号密码
                    break;
                case 2:
                    find(1); break;
                case 3:
                    find(2); break;
                case 4:
                    find(3); break;
                case 0:
                    printf("成功退出系统，期待你的下次使用O(∩_ ∩)O, 祝你生活愉快！\n");
                    writeDataToFile();
                    exit(0);
                default:
                    printf("\n输入错误！无该菜单，输入任意键返回 *系统普通用户功能菜单界面* ...\n");
                    scanf("%*c%*c");
                    break;
            }
        }
    }
}