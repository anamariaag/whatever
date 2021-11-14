#include <stdlib.h>
#include <stdio.h>
#include "gusanos.h"
#include "raylib.h"
#include "Lists.h"


struct bloque{
    Color color;
    Vector2 posicion;
    float alpha;
    float radio;
};

bloque* getBloque(List* list,int index) {
    Node *focusNode = list->head;//index 0
    for (int i = 0; i < index; i++) {
        focusNode = focusNode->next;
    }
    bloque *ptr = focusNode->value;
    return ptr;
}

Color getColor(List* gusano, int index){
    Node *focusNode = list->head;//index 0
    for (int i = 0; i < index; i++) {
        focusNode = focusNode->next;
    }
    bloque *ptr = focusNode->value;
    return ptr->color;
}

float getRadio(List* gusano,int index){
    Node *focusNode = list->head;//index 0
    for (int i = 0; i < index; i++) {
        focusNode = focusNode->next;
    }
    bloque *ptr = focusNode->value;
    return ptr->radio;
}

Vector2 getPosicion(List* gusano,int index){
    Node *focusNode = list->head;//index 0
    for (int i = 0; i < index; i++) {
        focusNode = focusNode->next;
    }
    bloque *ptr = focusNode->value;
    return ptr->posicion;
}

bloque* newBloque(Color color,int n){
    bloque* new=malloc(sizeof(bloque));
    new->color=color;
    new->alpha=1;
    new->posicion=(Vector2){ 100+5*n, 100 +5*n};
    new->radio=10;
    return new;
}

void updateListaP(List* posiciones,Vector2 *mouse){
    void *ptrPosicion=mouse;
    addElement(posiciones,ptrPosicion);
    removeLastElement(posiciones);
}

void updateGusano(List *gusano,List *posiciones){
    Node *focusGusano=gusano->list;
    Node *focusPosiciones = posiciones->head;
    bloque *focusBloque = focusGusano->value;
    Vector2 *focusPosicion = focusPosiciones->value;
    for(int i =0; i<gusano->size;i++){
        focusBloque->posicion=*focusPosicion;
        focusGusano=focusGusano->next;
        focusPosiciones=focusPosiciones->next;
        focusBloque=focusGusano->value;
        focusPosicion=focusPosiciones->value;
    }
}






