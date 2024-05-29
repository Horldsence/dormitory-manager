// Contents: Include file for the main program
#ifndef MAIN_H
#define MAIN_H

#include "changeInfo.h"
#include "studentDelet.h"
#include "fileLoder.h"
#include "studentFinder.h"
#include "outputManager.h"
#include "inputManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // 调用isdigit函数检查注册账号是否为存数字账号
#define N 20   //宏定义
#define M 10000 //宏定义，用于用户信息结构体数组

#define MAX_SIZE 100
#define DORM_MAX_NUM 6 // 一个宿舍最多住多少人
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
p_node_dormitory headDormitory;

//定义 3 个指针数组，分别按照关键字学号、姓名和宿舍号顺序存储住宿信息的结点地址。
dormitory *arrayDormID[MAX_SIZE], *arrayStudentID[MAX_SIZE], *arrayName[MAX_SIZE];
int countRecord;

int sign = 0;// 区分用户标识符， 1： 系统管理员，  2：普通用户
char ACCOUNT[N]; // 用于保存普通用户登录后的账号

#endif // !MAIN_H