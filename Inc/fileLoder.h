#ifndef FILELOADER_H
#define FILELOADER_H

#include "main.h"

void Load(USER user[],  int *nptr);
void readFile(char *DATA_FILE);
void Save(char *FILE_NAME, USER user[],  int n);
void createFile(char *FILE_NAME);
void lodeFileFromPath(char *FILE_NAME);

#endif