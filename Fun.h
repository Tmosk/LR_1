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
struct cinema *find_by_fullname(struct cinema *list, int size, const char* parameter);
struct cinema* find_by_session(struct cinema* list,int size,int parameter);
struct cinema* find_by_price(struct cinema *list, int size, int parameter);
struct cinema* find_by_vnumber(struct cinema *list, int size, int parameter);
struct cinema* find_with_interface(struct cinema *list, int size);
void sort_with_interface(struct cinema* list,int size);
void delete_element_by_name(struct cinema *list, int *size, const char* parameter);
void delete_element_by_session(struct cinema *list, int *size, int parameter);
void delete_element_by_prise(struct cinema *list, int *size, int parameter);
void delete_element_by_vnumber(struct cinema *list, int *size, int parameter);
void delete_element_with_interface(struct cinema *list, int *size);
void delete_element(struct cinema *list, int *size, struct cinema *element);
int cmp_name(const void * a, const void * b);
int cmp_session(const void * a, const void * b);
int cmp_price(const void * a, const void * b);
int cmp_v_number(const void * a, const void * b);


#endif //LR_1_FUN_H
