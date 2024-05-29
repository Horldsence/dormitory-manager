#ifndef STUDENTFINDER_H
#define STUDENTFINDER_H

#include "main.h"

void sortWithDormID();
void sortWithStudentID();
void sortWithName();
void searchWithName(char *key);
void searchWithStudentID(char *key);
void searchWithDormID(char *key);
int FindByNum(USER user[],  int n, char *str);

#endif // !STUDENTFINDER_H