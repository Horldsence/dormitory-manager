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
        }
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
            for(i = low; i <=high; i++)
                PrintDormitory(*arrayName[i]);
            printf("\n共找到%d条数据\n", matchCount);
            getchar();
            return;
        }
        else if(strcmp(arrayName[mid]->Name, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\n404 没有找到");
    getchar();
}
/*
@brife 下列函数是根据学号查找函数，功能是采用二分查找法在学号指针数组中查找结点。
*/
void searchWithStudentID(char *key)
{
    int low, high, mid;
    low = 0;
    high = countRecord - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(arrayStudentID[mid]->studentID, key) == 0)
        {
            PrintTitle();
            PrintDormitory(*arrayStudentID[mid]);
            printf("\n找到1条数据\n");
            getchar();
            return;
        }
        else if(strcmp(arrayStudentID[mid]->studentID, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\n404 没有找到");
    getchar();
}
//下列函数是根据宿舍号查找函数，功能是采用二分查找法在宿舍指针数组中查找结点。A
void searchWithDormID(char *key)
{
    int low, high, mid, i, matchCount; //matchCount 为匹配记录数目
    low = 0;
    high = countRecord - 1;
    matchCount = 0;
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
            printf("\n共找到%d条数据!\n", matchCount);
            getchar();
            return;
        }
        else if(strcmp(arrayDormID[mid]->dormID, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\n404 没有找到");
    getchar();
}