//
// Created by Ana Maria on 13/11/2021.
//

#ifndef WHATEVER_LISTS_H
#define WHATEVER_LISTS_H

typedef struct node Node;
typedef struct list List;


List *newList();
void addElement(List *list,void* value);
void removeLastElement(List *list);

#endif //WHATEVER_LISTS_H
