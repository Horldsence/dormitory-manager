//
// Created by PengHeng on 24-5-29.
//

#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "main.h"

void creatAccount(USER user[],  int *nptr);
void removeAccount(USER user[],  int *nptr);
void editAccount(USER user[],  int *nptr);
void PrAllAccount(USER user[],  int *nptr);
void Print_account(USER *sptr);

#endif //ACCOUNTMANAGER_H
