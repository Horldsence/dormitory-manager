//
// Created by PengHeng on 24-5-29.
//

#include "accountManager.h"
#include <conio.h>

/*
@brife 批量创建用户
*/
void creatAccount(USER user[],  int *nptr)
{
    int i = *nptr;
    printf("请输入待创建用户信息， 输入 0 表示结束添加！\n");
    printf("九位数数字账号 ---- 密码 ---- 学号 ---- 用户姓名：\n");
    while(1)
    {
        scanf("%s", &user[i].Accont);
        if(strcmp(user[i].Accont, "0") == 0)
        {
            break;
        }
        scanf("%s", &user[i].Password);
        scanf("%s", &user[i].ID);
        scanf("%s", &user[i].People_name);
        i++;
    }
    *nptr = i;
    Save("userInfoList.txt", user, *nptr); // //把数据保存到文本文件中
    printf("\n创建成功！！输入任意键返回 *系统管理员功能菜单界面*....... \n");
    scanf("%*c%*c");
}

/*
@brife 批量删除用户
*/
void removeAccount(USER user[],  int *nptr)
{
    int i, index;
    char account1[N];
    while(printf("\n输入待删除的账号, 注意：输入 0 表示结束输入\n"), scanf("%s", account1), strcmp(account1, "0") != 0)
    {
        index = FindByNum(user, *nptr,  account1);  //定位待删除用户信息在数组的下标
        if(index < 0)
        {
            printf("\n系统内%s账号不存在！！请重新输入\n" , account1);
        }else
        {

            Print_account(&user[index]);
            for(i = index; i < *nptr - 1; i++)
            {
                user[i] = user[i+1];
            }
            (*nptr)--;
            Save("userInfoList.txt", user, *nptr);
            printf("\n删除成功 o(*￣▽￣*)o\n ");
        }
    }
    printf("\n输入任意键返回 *系统管理员功能菜单界面*....... \n");
    scanf("%*c%*c");
}

/*
@brife 管理员和用户修改账号密码
*/
void editAccount(USER user[],  int *nptr)
{
    int i, index;
    char account1[N], password1[N], password2[N];
    if(sign == 1) //管理员修改密码
    {
        printf("请输入要重置密码或要查看密码的账号:\n");
        scanf("%s", account1);
    }else
    {
        if(sign == 2); // 用户修改密码
        strcpy(account1, ACCOUNT); // 将普通用户登录后的账号存入account1中
    }
    index =  FindByNum(user, *nptr, account1);
    if(index == -1)
    {
        printf("\n系统内无该账号信息！！\n");
        editAccount(user, nptr);
        return;
    }
    Print_account(&user[index]);
    while(1)
    {
        printf("\n请输入要更换的密码：\n");
        scanf("%s", password1);
        printf("请再次输入密码：\n");
        scanf("%s", password2);
        if(strcmp(password1, password2) == 0)
        {
            printf("\n密码修改成功 ^_~ \n");
            strcpy(user[index].Password, password2);
            break;
        }else
        {
            printf("\n输入的两次密码不同，请重新修改。＞﹏＜\n");
        }
    }
    Save("userInfoList.txt", user, *nptr);
    printf("\n输入任意键返回 *系统管理员功能菜单界面* ...\n");
    scanf("%*c%*c");
}

/*
 *@brife 重置用户密码
 */
void resetAccount(USER user[],  int *nptr)
{
    int i, index;
    char account1[N], password1[N], password2[N];
    printf("请输入要重置密码的账号:\n");
    scanf("%s", account1);
    index =  FindByNum(user, *nptr, account1);
    if(index == -1)
    {
        printf("\n系统内无该账号信息！！\n");
        resetAccount(user, nptr);
        return;
    }
    Print_account(&user[index]);
    while(1)
    {
        printf("\n请输入要重置的密码：\n");
        scanf("%s", password1);
        printf("请再次输入密码：\n");
        scanf("%s", password2);
        if(strcmp(password1, password2) == 0)
        {
            printf("\n密码重置成功 ^_~ \n");
            strcpy(user[index].Password, password2);
            break;
        }else
        {
            printf("\n输入的两次密码不同，请重新修改。＞﹏＜\n");
        }
    }
    Save("userInfoList.txt", user, *nptr);
    printf("\n输入任意键返回 *系统管理员功能菜单界面* ...\n");
    scanf("%*c%*c");
}

/*
@brife 查看当前馆内所有用户信息
*/
void PrAllAccount(USER user[],  int *nptr)
{
    int i;
    printf("\t\t  *所有用户信息*\n");
    printf("%-15s%-15s%-18s%-15s\n","用户账号:", "用户密码:", "用户身份证号:", "用户姓名:");
    for(i = 0; i < *nptr; i++)
    {
        printf("\n%-15s%-15s%-18s%-15s\n", user[i].Accont, user[i].Password, user[i].ID, user[i].People_name);
    }
    system("pause");
}

void Print_account(USER *sptr)
{
    printf("\n%s账号信息为：\n", sptr->Accont);
    printf("%-15s%-15s%-18s%-15s\n","用户账号:", "用户密码:", "用户身份证号:", "用户姓名:");
    printf("%-15s%-15s%-18s%-15s\n", sptr->Accont, sptr->Password, sptr->ID, sptr->People_name);
}

void get_password(char *pswd, unsigned maxlen) {
    int index = 0;
    char buff = '\0';

    while ((buff = getch()) != '\r') {
        if (buff == '\b' && index != 0) {
            index--;
            printf("\b \b");
        } else if (index < maxlen - 1 && buff != '\b') {
            pswd[index++] = buff;
            putchar('*');
        }
    }
    printf("\n");
    pswd[index] = '\0';
}