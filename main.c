#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "Fun.h"
///1)	Ввод массива структур;
///2)	Вывод на экран массива структур;
///3)	Изменение заданной структуры;
///4)	Поиск в массиве структур по заданному параметру(одному любому);
///5)	Сортировка массива структур по заданному параметру;
//6)	Поиск в массиве структур по заданному параметру (по всем параметрам);
//7)	Удаление структуры из массива по заданному параметру(всем);
//8)	Поиск в массиве структур по частичному совпадению заданного параметра.
//  Структура «Кинотеатр»: название кинофильма, сеанс, стоимость билета, количество зрителей

int main() {
    setbuf(stdout, 0);
    srand(time(NULL));
    struct cinema *c_list=NULL;
    int kol_vo=0;
    printf("Vvedi kolichestvo struktur \n");
    scanf_s("%d",&kol_vo);
    c_list=generate(c_list,kol_vo);
    print_list(c_list,kol_vo);
    sort_with_interface(c_list,kol_vo);
    print_list(c_list,kol_vo);
    return 0;
}
