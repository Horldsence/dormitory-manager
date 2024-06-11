#include "changeInfo.h"

//下列函数是添加住宿信息的函数，功能是在住宿信息链表的表头插入一个新的结点，并把该
//结点的地址分别添加到宿舍号指针数组、姓名指针数组和学号指针数组的末尾，然后把宿舍号指
//针数组、姓名指针数组和学号指针数组分别排序。B
void add()
{
    char dormID[10];
    char studentID[15];
    char name[10];
    char sex[10];
    char phonenumber[15];
    char vip[10];
    printf("\n 宿舍号： ");
    scanf("%s", dormID);
    printf("\n 学号： ");
    scanf("%s", studentID);
    printf("\n 名字： ");
    scanf("%s", name);
    printf("\n 性别（0：男，1：女）： ");
    scanf("%s", sex);
    printf("\n 电话号码： ");
    scanf("%s", phonenumber);
    printf("\n 寝室长： ");
    scanf("%s", vip);

    // 校验宿舍是否住满，男女不能混住
    if (checkoutDormNumAndSex(dormID, sex) == -1) return;

    int i, j, k;
    p_node_dormitory pNodeDormitory;
    pNodeDormitory = (p_node_dormitory)malloc(sizeof(node_dormitory));


    strcpy(pNodeDormitory->data.dormID, dormID);
    strcpy(pNodeDormitory->data.studentID, studentID);
    strcpy(pNodeDormitory->data.Name, name);
    strcpy(pNodeDormitory->data.sex, sex);
    strcpy(pNodeDormitory->data.phonenumber, phonenumber);
    strcpy(pNodeDormitory->data.vip, vip);

    if(headDormitory == NULL)
    {
        headDormitory = pNodeDormitory;
        pNodeDormitory->next = NULL;
    }
    else
    {
        pNodeDormitory->next = headDormitory;
        headDormitory = pNodeDormitory;
    }
    //添加一条记录后重新排序住宿号指针数组
    for(i = 0; i < countRecord; i++)
    {
        if(strcmp(arrayDormID[i]->dormID, &headDormitory->data.dormID) > 0)
            break;
    }
    for(j = countRecord; j > i; j--)
        arrayDormID[j] = arrayDormID[j - 1];
    arrayDormID[i] = &headDormitory->data;
    //添加一条记录后重新排序学号指针数组
    for(i = 0; i < countRecord; i++)
    {
        if(strcmp(arrayStudentID[i]->studentID, &headDormitory->data.studentID) > 0)
            break;
    }
    for(j = countRecord; j > i; j--)
        arrayStudentID[j] = arrayStudentID[j - 1];
    arrayStudentID[i] = &headDormitory->data;
    //添加一条记录后重新排序姓名指针数组
    for(i = 0; i < countRecord; i++)
    {
        if(strcmp(arrayName[i]->Name, &headDormitory->data.Name) > 0)
            break;
    }
    for(j = countRecord; j > i; j--)
        arrayName[j] = arrayName[j - 1];
    arrayName[i] = &headDormitory->data;
    countRecord++;
    adaptive_progress_bar(1);
    PrintTitle();
    PrintDormitory(pNodeDormitory->data);
    printf("\n添加成功!\n");
    system("pause");
}

/*
@brife 下列函数是修改住宿信息函数，首先根据输入的学号找到要修改的住宿信息结点，然后修改该结点的数据域（宿舍号、学号、姓名）。
*/
void edit()
{
    p_node_dormitory pNodeDormitory;
    char sID[10];
    pNodeDormitory = headDormitory;
    printf("\n请输入你想编辑的学号");
    printf("\n学号： ");
    scanf("%s", sID);
    while(pNodeDormitory != NULL)
    {
        if(strcmp(pNodeDormitory->data.studentID, sID) == 0)
        {
            PrintTitle();
            PrintDormitory(pNodeDormitory->data);
            printf("\n 编辑学号： ");
            scanf("%s", pNodeDormitory->data.studentID);
            printf("\n 编辑宿舍号： ");
            scanf("%s", pNodeDormitory->data.dormID);
            printf("\n 编辑名字： ");
            scanf("%s", pNodeDormitory->data.Name);
            printf("\n 编辑性别（0：男，1：女）： ");
            scanf("%s", pNodeDormitory->data.sex);
            printf("\n\n\n");
            adaptive_progress_bar(1);
            PrintTitle();
            PrintDormitory(pNodeDormitory->data);
            printf("\n学号%s已编辑成功!", pNodeDormitory->data.studentID);
            getchar();
            return;
        }
        pNodeDormitory = pNodeDormitory->next;
    }
    printf("\nERROR 找不到对应的学生");
    getchar();
}

// 通过宿舍号查询到对应的信息  -1代表失败  0 代表添加成功 A
int checkoutDormNumAndSex(char *key, char *sex)
{
    // 男女不能混住
    int low, high, mid, index, matchCount; //matchCount 为匹配记录数目
    low = 0;
    high = countRecord - 1;
    matchCount = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(arrayDormID[mid]->dormID, key) == 0)
        {
            index = mid - 1;
            while(index >= low)
            {
                if(strcmp(arrayDormID[index]->dormID, key) == 0)
                    index--;
                else
                    break;
            }
            low = index + 1; //low 此时为匹配的第一条记录下标
            index = mid;
            while(index <= high)
            {
                if(strcmp(arrayDormID[index]->dormID, key) == 0)
                    index++;
                else
                    break;
            }
            high = index - 1; //high 此时为匹配的最后一条记录下标
            matchCount = high - low + 1;
            if (matchCount == DORM_MAX_NUM) {
                printf("\n添加失败😭\n");
                printf("\n%s号宿舍只能住%d个人，目前已经住满！\n", key, DORM_MAX_NUM);
                getchar();
                return -1;
            }
            for(index = low; index <=high; index++) {
                if (strcmp(arrayDormID[index]->sex, sex) != 0) {
                    printf("\n添加失败😭\n");
                    if (strcmp(arrayDormID[index]->sex, "0") == 0) {
                        printf("\n%s号宿舍是男宿舍不能住女生\n", key);
                    } else {
                        printf("\n%s号宿舍是女宿舍不能住男生\n", key);
                    }

                    getchar();
                    return -1;
                } else {
                    low = 1;
                    high = 0;
                }
            }
        }
        else if(strcmp(arrayDormID[mid]->dormID, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;

}