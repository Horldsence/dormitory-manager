#include "studentFinder.h"
/*
 @brief 下列函数是排序函数，功能是根据宿舍号进行排序，排序时住宿信息链表并不改变，只是把宿舍指针数组中的内容根据指针所指的结点的宿舍号大小进行排序。
*/
void sortWithDormID()
{
    int i, j, k;
    dormitory *tmp;
    for(i = 0; i < countRecord - 1; i++)
    {
        k = i;
        for(j = i + 1; j < countRecord; j++)
            if(strcmp(arrayDormID[j]->dormID, arrayDormID[k]->dormID) < 0)
                k = j;
        if(k != i)
        {
            tmp = arrayDormID[i];
            arrayDormID[i] = arrayDormID[k];
            arrayDormID[k] = tmp;
        }mao
    }
}

/*
 @brief 下列函数是排序函数，功能是根据学号进行排序，排序时住宿信息链表并不改变，只是把学号指针数组中的内容根据指针所指的结点的学号大小进行排序
*/
void sortWithStudentID()
{
    int i, j, k;
    dormitory *tmp;
    for(i = 0; i < countRecord - 1; i++)
    {
        k = i;
        for(j = i + 1; j < countRecord; j++)
            if(strcmp(arrayStudentID[j]->studentID, arrayStudentID[k]->studentID) < 0)
                k = j;
        if(k != i)
        {
            tmp = arrayStudentID[i];
            arrayStudentID[i] = arrayStudentID[k];
            arrayStudentID[k] = tmp;
        }
    }
}

/*
@brife 下列函数是排序函数，功能是根据姓名进行排序，排序时住宿信息链表并不改变，只是把姓名指针数组中的内容根据指针所指的结点的姓名大小进行排序。
*/
void sortWithName()
{
    int i, j, k;
    dormitory *tmp;
    for(i = 0; i < countRecord - 1; i++)
    {
        k = i;
        for(j = i + 1; j < countRecord; j++)
            if(strcmp(arrayName[j]->Name, arrayName[k]->Name) < 0)
                k = j;
        if(k != i)
        {
            tmp = arrayName[i];
            arrayName[i] = arrayName[k];
            arrayName[k] = tmp;
        }
    }
}

/*
@brife 下列函数是根据姓名查找函数，功能是采用二分查找法在姓名指针数组中查找结点。
*/
void searchWithName(char *key)
{
    int low, high, mid, i, matchCount; //matchCount 为匹配记录数目
    low = 0;
    high = countRecord - 1;
    matchCount = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(arrayName[mid]->Name, key) == 0)
        {
            PrintTitle();
            i = mid - 1;
            while(i >= low)
            {
                if(strcmp(arrayName[i]->Name, key) == 0)
                    i--;
                else
                    break;
            }
            low = i + 1; //low 此时为匹配的第一条记录下标
            i = mid;
            while(i <= high)
            {
                if(strcmp(arrayName[i]->Name, key) == 0)
                    i++;
                else
                    break;
            }
            high = i - 1; //high 此时为匹配的最后一条记录下标
            matchCount = high - low + 1;
            adaptive_progress_bar(1);
            for(i = low; i <=high; i++)
                PrintDormitory(*arrayName[i]);
            printf("\n共找到%d条数据( ’ω’ )\n", matchCount);
            system("pause");
            return;
        }
        else if(strcmp(arrayName[mid]->Name, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    adaptive_progress_bar(1);
    printf("\n没有找到( ∵ )\n");
    system("pause");
}
/*
@brife 下列函数是根据学号查找函数，功能是采用二分查找法在学号指针数组中查找结点。
*/
void searchWithStudentID(char *key)
{
    int low, high, mid;
    low = 0;
    high = countRecord - 1;
    adaptive_progress_bar(1);
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(arrayStudentID[mid]->studentID, key) == 0)
        {
            PrintTitle();
            PrintDormitory(*arrayStudentID[mid]);
            printf("\n找到1条数据( ’ω’ )\n");
            system("pause");
            return;
        }
        else if(strcmp(arrayStudentID[mid]->studentID, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\n没有找到( ∵ )\n");
    system("pause");
}
//下列函数是根据宿舍号查找函数，功能是采用二分查找法在宿舍指针数组中查找结点。A
void searchWithDormID(char *key)
{
    int low, high, mid, i, matchCount; //matchCount 为匹配记录数目
    low = 0;
    high = countRecord - 1;
    matchCount = 0;
    adaptive_progress_bar(1);
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(arrayDormID[mid]->dormID, key) == 0)
        {
            PrintTitle();
            i = mid - 1;
            while(i >= low)
            {
                if(strcmp(arrayDormID[i]->dormID, key) == 0)
                    i--;
                else
                    break;
            }
            low = i + 1; //low 此时为匹配的第一条记录下标
            i = mid;
            while(i <= high)
            {
                if(strcmp(arrayDormID[i]->dormID, key) == 0)
                    i++;
                else
                    break;
            }
            high = i - 1; //high 此时为匹配的最后一条记录下标
            matchCount = high - low + 1;
            for(i = low; i <=high; i++)
                PrintDormitory(*arrayDormID[i]);
            printf("\n共找到%d条数据( ’ω’ )\n", matchCount);
            getchar();
            return;
        }
        else if(strcmp(arrayDormID[mid]->dormID, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\n没有找到( ∵ )\n");
    system("pause");
}

// 定位待删除账号的位置
int FindByNum(USER user[],  int n, char *str)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(strcmp(user[i].Accont, str) == 0)
        {
            return i;	//返回待删除用户信息在数组的下标
        }
    }
    return -1;
}
/*
@brife 下列函数是显示住宿信息的函数，功能是把目前住宿信息链表中的所有结点内容显示出来。首先按照链表顺序显示链表内容（宿舍号、学号、姓名），然后分别按照姓名、学号、宿舍号为关键字排序后显示住宿信息（宿舍号、学号、姓名）。
*/
void view()
{
    int count = 0;
    p_node_dormitory pNodeDormitory;
    pNodeDormitory = headDormitory;
    adaptive_progress_bar(1);
    PrintTitle();
    while(pNodeDormitory != NULL)
    {
        PrintDormitory(pNodeDormitory->data);
        pNodeDormitory = pNodeDormitory->next;
        count++;
    }
    printf("共有%d条数据\n", count);
    printf("\n\n通过名字排序\n");
    PrintTitle();
    for(count = 0; count < countRecord; count++)
    {
        PrintDormitory(*arrayName[count]);
    }
    printf("\n\n通过学号排序\n");
    PrintTitle();
    for(count = 0; count < countRecord; count++)
    {
        PrintDormitory(*arrayStudentID[count]);
    }
    printf("\n\n通过宿舍号排序\n");
    PrintTitle();
    for(count = 0; count < countRecord; count++)
    {
        PrintDormitory(*arrayDormID[count]);
    }
    system("pause");
}
/*
@brife 下列函数是查找函数，进入查找函数后再次进行选择查找的方式。
*/
void find(int type)
{
    char *typeName = NULL;
    switch(type)
    {
    case 1:
        typeName="学生名字"; break;
    case 2:
        typeName="学号"; break;
    case 3:
        typeName="宿舍号"; break;
    }
    char key[10];
    printf("\n请输入要查找的%s：", typeName);
    scanf("%s", key);
    switch(type)
    {
    case 1:
        searchWithName(key); break;
    case 2:
        searchWithStudentID(key); break;
    case 3:
        searchWithDormID(key); break;
    }
}