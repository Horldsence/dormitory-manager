// Contents: Include file for the main program
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h> // 调用isdigit函数检查注册账号是否为存数字账号

#define N 20   //宏定义
#define M 10000 //宏定义，用于用户信息结构体数组

#define MAX_SIZE 100
#define DORM_MAX_NUM 6 // 一个宿舍最多住多少人

#define MENU_WIDTH 42
#define MAX_OPTIONS 10
#define BUFFER_SIZE 100
//定义住宿信息结构体。
typedef struct dormitory
{
    char dormID[10];
    char studentID[15];
    char sex[10]; // 0:男生，1：女生
    char Name[10];
    char phonenumber[13];
    char vip[3];
} dormitory;
//定义结构体存储系统用户信息
typedef struct userinfo
{
    char Accont[N]; //账号
    char Password[N];//密码
    char ID[N]; //学号
    char People_name[N];//用户姓名
}USER;
//定义住宿信息链表结点，包括 dormitory 型的数据域和指向下一个结点的指针域。
typedef struct node_dormitory
{
    dormitory data;
    struct node_dormitory *next;
} node_dormitory, *p_node_dormitory;

//定义住宿信息链表的头指针为全局变量。
extern p_node_dormitory headDormitory;
//定义 3 个指针数组，分别按照关键字学号、姓名和宿舍号顺序存储住宿信息的结点地址。
extern dormitory *arrayDormID[MAX_SIZE], *arrayStudentID[MAX_SIZE], *arrayName[MAX_SIZE];
extern int countRecord;
// 区分用户标识符， 1： 系统管理员，  2：普通用户
extern int sign;
// 用于保存普通用户登录后的账号
extern char ACCOUNT[N];


void Register_system(); // 注册账户
void User_enter();// 系统用户登录函数
void User_reg();// 系统用户注册

void Menu1();// 系统用户登录注册界面
void Menu2();//系统用户注册界面
void Menu3();//用户登录注册界面
void Menu_admist();// 管理员菜单界面
void Menu_user();// 用户菜单界面

int displayMenu(const char* message, const char options[][BUFFER_SIZE], int optionCount);
void printCentered(const char* text, int width);

void PrintTitle();// 打印表头
void PrintDormitory(dormitory p); // 打印住宿信息

void draw_progress_bar(int percentage);// 进度条
void adaptive_progress_bar(int total_time);// 自适应进度条

#include "changeInfo.h"
#include "studentDelet.h"
#include "fileLoder.h"
#include "studentFinder.h"
#include "outputManager.h"
#include "inputManager.h"
#include "accountManager.h"

extern p_node_dormitory headDormitory;
extern dormitory *arrayDormID[MAX_SIZE], *arrayStudentID[MAX_SIZE], *arrayName[MAX_SIZE];
extern int countRecord;
extern int sign;
extern char ACCOUNT[N];

#endif // !MAIN_H