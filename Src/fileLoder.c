#include "fileLoder.h"

//把文本文件中用户信息加载到内存中
void Load(USER user[],  int *nptr)
{
    FILE *fp;
    int i = 0;

    if((fp = fopen("userInfoList.txt", "r")) == NULL)
    {
        *nptr = 0;
        system("cls");
        printf("打开用户文件失败qwq\n");
        char message[] = "未在程序目录下找到文件，是否导入或者创建？";
        char choice[][10]={
            "导入",
            "创建",
            "退出"
        };
        int ch = displayMenu(message, choice, 3);
        if(ch == 1)
        {
            char path[100];
            printf("请输入文件绝对路径：");
            scanf("%s", path);
            if((fp = fopen(path, "r")) == NULL)
            {
                printf("获取文件失败\n");
                printf("即将退出 *学生宿舍管理系统* \n");
                system("pause");
                exit(0);
            }
        }
        else if(ch == 2)
        {
            createFile("userInfoList.txt");
            fp = fopen("userInfoList.txt", "r");
        }
        else
        {
            printf("即将退出 *学生宿舍管理系统* \n");
            system("pause");
            exit(0);
        }
    }
    while(fscanf(fp,  "%s %s %s %s",  user[i].Accont, user[i].Password, user[i].ID, user[i].People_name) != EOF)
    {
        i++;
    }
    *nptr = i ; //  *nPtr记录文件中当前用户人数
    fclose(fp);
}

/*
 @brief 下列函数是读入文件的函数，把事先保存在数据文件中的住宿信息读入到内存中，创建住宿信息组成的单链表，同时把链表结点的地址保存到住宿号指针数组、学号指针数组和姓名指针数组中。DORM_MAX_NUM 定义了一个宿舍最多住多少人，MAX_SIZE 定义了住宿信息链表的最大长度。
*/
void readFile(char *DATA_FILE)
{
    FILE *fp;
    p_node_dormitory pNodeDormitory;
    int size;
    countRecord = 0;
    fp = fopen(DATA_FILE, "rb");
    fseek(fp, 0, 2); //得到文件大小
    size = ftell(fp);
    rewind(fp);
    while(size != 0)
    {
        size -= sizeof(struct dormitory);
        pNodeDormitory = (p_node_dormitory)malloc(sizeof(node_dormitory));
        if(fread(&pNodeDormitory->data, sizeof(struct dormitory), 1, fp) != 1)
            exit(0);
        pNodeDormitory->next = headDormitory;
        headDormitory = pNodeDormitory;
        arrayDormID[countRecord] = &headDormitory->data;
        arrayStudentID[countRecord] = &headDormitory->data;
        arrayName[countRecord] = &headDormitory->data;
        countRecord++;
    }
    fclose(fp);
    sortWithDormID();
    sortWithStudentID();
    sortWithName();
    printf("获取到%d条数据!\n", countRecord);
}

/*
@brife 把数据保存到文本文件中
*/
void Save(char *FILE_NAME, USER user[],  int n)
{
    int i;
    FILE *fp;
    if((fp = fopen(FILE_NAME, "w")) == NULL)
    {
        printf("can not open this file!!");
        exit(0);
    }
    for(i = 0; i < n; i++)
    {
        fprintf(fp, "%s %s %s %s\n",  user[i].Accont, user[i].Password, user[i].ID, user[i].People_name);
    }
    fclose(fp);
}

void createFile(char *FILE_NAME)
{
    int choice;
    const char* message = "未找到文件，是否创建一个？";
    const char* options[] = {
        "是",
        "否"
    };
    choice = displayMenu(message, options, 2);
    if(choice == 1)
    {
        FILE *file;
        if((file = fopen(FILE_NAME, "w")) == NULL)
        {
            printf("创建文件失败\n");
            printf("即将退出 *学生宿舍管理系统* \n");
            system("pause");
            exit(0);
        }
    }
}
