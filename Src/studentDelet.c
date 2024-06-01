#include "studentDelet.h"
/*
@brife 下列函数是删除住宿信息的函数，功能是根据学号查找到要删除的结点，在信息链表中删除该结点，同时把宿舍号指针数组、姓名指针数组和学号指针数组中与该结点相关的指针域置为空。
*/
void delete()
{
    p_node_dormitory pNodeDormitory, p1;
    char sID[10];
    int i, j;
    p1 = headDormitory;
    printf("\n请输入要删除的学号：");
    scanf("%s", sID);
    if(strcmp(p1->data.studentID, sID) == 0)
    {
        headDormitory = p1->next;
        pNodeDormitory = p1;
    }
    else
    {
        pNodeDormitory = p1->next;
        while(pNodeDormitory != NULL)
        {
            if(strcmp(pNodeDormitory->data.studentID, sID) == 0)
            {
                p1->next = pNodeDormitory->next;
                break;
            }
            p1 = pNodeDormitory;
            pNodeDormitory = pNodeDormitory->next;
        }
    }
    adaptive_progress_bar(1);
    if(pNodeDormitory)
    {
        //删除一条记录后重新排序住宿号指针数组
        for(i = 0; i < countRecord; i++)
            if(arrayDormID[i] == &pNodeDormitory->data)
                break;
        for(j = i; j < countRecord - 1; j++)
            arrayDormID[j] = arrayDormID[j + 1];
        //删除一条记录后重新排序学号指针数组
        for(i = 0; i < countRecord; i++)
            if(arrayStudentID[i] == &pNodeDormitory->data)
                break;
        for(j = i; j < countRecord - 1; j++)
            arrayStudentID[j] = arrayStudentID[j + 1];
        //删除一条记录后重新排序姓名指针数组
        for(i = 0; i < countRecord; i++)
            if(arrayName[i] == &pNodeDormitory->data)
                break;
        for(j = i; j < countRecord - 1; j++)
            arrayName[j] = arrayName[j + 1];
        free(pNodeDormitory);
        countRecord--;
        printf("\n学号%s已删除", sID);
    }
    else
        printf("\n404 没有该学生");
    getchar();
}