#include "outputManager.h"

/*
@brife 下列函数是写入文件，功能是把住宿信息链表中的内容保存到数据文件中。添加、修改、删除链表的函数完成操作后，只是链表的内容改变了，并没有把修改后的内容写入到数据文件中， 只有调用下列函数，修改后的内容才写入数据文件中。D
*/
void writeDataToFile(char *DATA_FILE)
{
    FILE *fp;
    p_node_dormitory pNodeDormitory;
    int count = 0;
    if((fp = fopen(DATA_FILE, "wb+")) == NULL)
    {
        printf("保存失败!\n");
        system("pause");
        return;
    }
    pNodeDormitory = headDormitory;
    while(pNodeDormitory != NULL)
    {
        if(fwrite(&pNodeDormitory->data, sizeof(dormitory), 1, fp) != 1)
            printf("文件写入失败!\n");
        pNodeDormitory = pNodeDormitory->next;
        count++;
    }
    fclose(fp);
    printf("成功写入%d条数据!\n", count);
    getchar();
}

void saveFile()
{
    char massage[] = "是否另存为修改？";
    char choices[MAX_OPTIONS][BUFFER_SIZE] = {
        "是",
        "否"
    };
    int choice = displayMenu(massage, choices, 2);
    if(choice == 1)
    {
        printf("请输入保存文件名：");
        char DATA_FILE[20];
        scanf("%s", DATA_FILE);
        writeDataToFile(DATA_FILE);
    }
    else
    {
        return;
    }

}