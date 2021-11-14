//
// Created by Ana Maria on 13/11/2021.
//

#ifndef WHATEVER_GUSANOS_H
#define WHATEVER_GUSANOS_H

typedef struct bloque bloque;

bloque* getBloque(List* list,int index);
Color getColor(List* gusano, int index);
float getRadio(List* gusano,int index);
Vector2 getPosicion(List* gusano,int index);


bloque* newBloque(Color color,int n);

void updateListaP(List* posiciones, Vector2* mouse);
void updateGusano(List *gusano,List* posiciones);


#endif //WHATEVER_GUSANOS_H
