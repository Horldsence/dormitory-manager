#ifndef STUDENTFINDER_H
#define STUDENTFINDER_H

#include "main.h"

void sortWithDormID();//按宿舍号排序
void sortWithStudentID();//按学号排序
void sortWithName();//按姓名排序
void searchWithName(char *key);//按姓名查找
void searchWithStudentID(char *key);//按学号查找
void searchWithDormID(char *key);//按宿舍号查找
int FindByNum(USER user[],  int n, char *str);//定位待删除账号的位置
void find(int type);//查找
void view();//查看所有学生信息

#endif // !STUDENTFINDER_H