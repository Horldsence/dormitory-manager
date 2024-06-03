#ifndef FILELOADER_H
#define FILELOADER_H

#include "main.h"

void Load(USER user[],  int *nptr); // 账户文件读取
void readFile(char *DATA_FILE); // 学生文件读取
void Save(char *FILE_NAME, USER user[],  int n); // 账户文件保存
void createFile(char *FILE_NAME); // 创建数据文件
void lodeFileFromPath(char *FILE_NAME); // 从路径加载文件

#endif