#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "Lists.h"


struct node{
    void* value;
    struct node *next;
};

struct list{
    Node* head;
    int size;
};

List *newList(){//regresa el primer nodo de una lista
    List *newHead= malloc(sizeof(List));
    newHead->size=0;
    newHead->head=NULL;
    return newHead;
}

void addElement(List *list,void* value){
    Node *new =malloc(sizeof (Node));
    new->value=value;
    new->next=list->head;
    list->head=new;
    list->size++;
}

void removeLastElement(List *list){
    Node *focusNode=list->head;
    for(int i=0;i<(list->size)-1;i++){
        focusNode=focusNode->next;
    }
    Node* elementDelete=focusNode->next;
    focusNode->next=NULL;
    free(elementDelete);
}
