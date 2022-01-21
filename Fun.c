//
// Created by moska on 27.12.2021.
//

#include "Fun.h"
//Generate array of cinema; requires  pointer to first element
struct cinema* generate(struct cinema* c,int size) {
    c=(struct cinema*)malloc(sizeof(struct cinema)*size);
    printf("Enter data in format:\tNAME\tSESSION \tPRICE\tV_NUMBER\n (0 to random)\n");
    getc(stdin);
    for (int i = 0; i < size; ++i) {
        fgets(c[i].name, 30 * sizeof(char), stdin);
        if(c[i].name[0]=='0'){
            rand_str(c[i].name,10);
            c[i].session=rand()%5+1;
            c[i].price=rand()%500;
            c[i].v_number=rand()%200;
        }
        else{
            scanf_s("%d",&c[i].session);
            scanf_s("%d",&c[i].price);
            scanf_s("%d",&c[i].v_number);
            scanf_s("%c");
        }
        printf("next\n");
    }
    return c;
}
//Generate random string at the specified address
void rand_str(char *str, int len) {
    int i;
    for (i= 0; i < len; ++i) {
        str[i]=rand()%26+97;
    }
    str[i]='\0';
}
//Print all cinema fields
void print_str(struct cinema *c) {
    printf("NAME:\t\t%s\n",c->name);
    printf("SESSION:\t%d\n",c->session);
    printf("PRICE:\t\t%d\n",c->price);
    printf("V_NUMBER:\t%d\n",c->v_number);
}
//Print all array of cinema
void print_list(struct cinema *c, int num) {
    for (int i = 0; i < num; ++i) {
        print_str(&c[i]);
        printf("\n");
    }
}
//Allows to edit all fields
void cin_edit(struct cinema *c) {
    printf("Enter new data in format:\tNAME\tSESSION\tPRICE\tV_NUMBER\n (0 to random)\n");
    fgets(c->name, 30 * sizeof(char), stdin);
    if(c->name[0]=='0'){
        rand_str(c->name,10);
        c->session=rand()%5+1;
        c->price=rand()%500;
        c->v_number=rand()%200;
    }
    else{
        scanf_s("%d",&c->session);
        scanf_s("%d",&c->price);
        scanf_s("%d",&c->v_number);
    }
}
//Return address of cinema with same name value
struct cinema *find_by_fullname(struct cinema *c, int size, const char* parameter) {
    for (int i = 0; i < size; ++i) {
        int j=0,flag=0;
        while (c[i].name[j]!='\n'){
            if((c[i].name[j]!=parameter[j])){
                flag=1;
                break;
            }
            j++;
        }
        if(flag==0){
            return (c+i);
        }
    }
    return NULL;
}
//Return address of cinema with same session value
struct cinema *find_by_session(struct cinema *c, int size, int parameter) {
    for (int i = 0; i < size; ++i) {
        if(c[i].session==parameter){
            return (c+i);
        }
    }
    return NULL;
}
//Return address of cinema with same price value
struct cinema *find_by_price(struct cinema *c, int size, int parameter) {
    for (int i = 0; i < size; ++i) {
        if(c[i].price==parameter){
            return (c+i);
        }
    }
    return NULL;
}
//Return address of cinema with same vnumber value
struct cinema *find_by_vnumber(struct cinema *c, int size, int parameter) {
    for (int i = 0; i < size; ++i) {
        if(c[i].v_number==parameter){
            return (c+i);
        }
    }
    return NULL;
}
//Allows sorting array of structs with user interface
void sort_with_interface(struct cinema *c, int size) {
    printf("Chose sort parameter:\n1)\tNAME\n2)\tSESSION\n3)\tPRICE\n4)\tV_NUMBER\n");
    int sort_form;
    scanf_s("%d",&sort_form);
    switch (sort_form) {
        case 1:
            qsort(c,size, sizeof(struct cinema),cmp_name);
            break;
        case 2:
            qsort(c,size, sizeof(struct cinema),cmp_session);
            break;
        case 3:
            qsort(c,size, sizeof(struct cinema),cmp_price);
            break;
        case 4:
            qsort(c,size, sizeof(struct cinema),cmp_v_number);
            break;
        default:
            printf("\n\n\t\tERROR\n\n");
    }
}
//Compare by name
int cmp_name(const void *a, const void *b) {return strcmp((*((struct cinema*)a)).name,(*((struct cinema*)b)).name);}
//Compare by session
int cmp_session(const void *a, const void *b) {return ((*((struct cinema*)a)).session-(*((struct cinema*)b)).session);}
//Compare by price
int cmp_price(const void *a, const void *b) {return ((*((struct cinema*)a)).price-(*((struct cinema*)b)).price);}
//Compare by v_number
int cmp_v_number(const void *a, const void *b) {return ((*((struct cinema*)a)).v_number-(*((struct cinema*)b)).v_number);}

//Return address of cinema founded using user interface
struct cinema *find_with_interface(struct cinema *list, int size) {
    printf("Chose search parameter:\n1)\tNAME\n2)\tSESSION\n3)\tPRICE\n4)\tV_NUMBER\n");
    int sort_form;
    scanf_s("%d",&sort_form);
    char arr[30];
    int parameter;
    if(sort_form==1){
        printf("Enter name:\n");
        scanf_s("%d");
        fgets(arr, 30 * sizeof(char), stdin);
    } else{
        printf("Enter parameter: ");
        scanf_s("%d",&parameter);
    }
    switch (sort_form) {
        case 1:
            return find_by_fullname(list,size,arr);
        case 2:
            return find_by_session(list,size,parameter);
        case 3:
            return find_by_price(list,size,parameter);
        case 4:
            return find_by_vnumber(list,size,parameter);
        default:
            return NULL;
    }
}

void delete_element_by_name(struct cinema *list, int *size, const char *parameter) {
    delete_element(list,size, find_by_fullname(list,*size,parameter));
}

void delete_element_by_session(struct cinema *list, int *size, int parameter) {
    delete_element(list,size, find_by_session(list,*size,parameter));
}

void delete_element_by_prise(struct cinema *list, int *size, int parameter) {
    delete_element(list,size, find_by_price(list,*size,parameter));
}

void delete_element_by_vnumber(struct cinema *list, int *size, int parameter) {
    delete_element(list,size, find_by_vnumber(list,*size,parameter));
}

void delete_element_with_interface(struct cinema *list, int *size) {
    delete_element(list,size, find_with_interface(list,*size));
}

void delete_element(struct cinema *list, int *size, struct cinema *element) {
    do{
        *element= *(element+1);
        ++element;
    }
    while (element!=&(list[*size-1]));
    *size=*size-1;
}
