//
// Created by moska on 27.12.2021.
//

#ifndef LR_1_FUN_H
#define LR_1_FUN_H

#include <stdio.h>
#include "stdlib.h"
#include<string.h>
struct cinema{
    char name[30];
    int session;
    int price;
    int v_number;
};

struct cinema* generate(struct cinema* c,int size);
void print_str(struct cinema* c);
void print_list(struct cinema* c,int num);
void rand_str(char* str,int len);
void cin_edit(struct cinema* c);
struct cinema* find_full_session(struct cinema* c,int size,int parameter);
void sort_with_interface(struct cinema* c,int size);
//FOR SORT
int cmp_name(const void * a, const void * b);
int cmp_session(const void * a, const void * b);
int cmp_price(const void * a, const void * b);
int cmp_v_number(const void * a, const void * b);
// END FOR SORT


#endif //LR_1_FUN_H
