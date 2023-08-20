//
// Created by Ciro on 17/8/2023.
//

#ifndef EDYA_LISTASIMPLE_LISTASIMPLE_H
#define EDYA_LISTASIMPLE_LISTASIMPLE_H

typedef struct nodo{
    int num;
    struct nodo * sig;
}Nodo;

typedef struct lista{
    Nodo * cabecera;
}Lista;

Nodo * newNodo(int valor);
Lista * newLista();
void imprimir(Lista * lista);
void insertar(Lista * lista, Nodo * nodo);
void insertarOrdenado(Lista * lista, Nodo * nodo);
void eliminar(Lista * lista, int num);
Lista * resta(Lista * listaA, Lista * listaB);
#endif //EDYA_LISTASIMPLE_LISTASIMPLE_H
