//
// Created by Ciro on 17/8/2023.
//
#include "listaSimple.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *newNodo(int valor) {
    Nodo * aux = NULL;
    aux= malloc(sizeof(Nodo));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->num=valor;
        aux->sig=NULL;
    }
    return aux;
}

Lista *newLista() {
    Lista * aux = NULL;
    aux= malloc(sizeof(Lista));
    if(aux==NULL){
        printf("ERROR al asignar memoria.\n");
        exit(-1);
    }else{
        aux->cabecera=NULL;
    }
    return aux;
}

void imprimir(Lista *lista) {
    if(lista->cabecera ==NULL){
        printf("La lista esta vacia.\n");
    }else{
        Nodo * aux =lista->cabecera;
        while(aux != NULL){
            printf("%d\t",aux->num);
            aux=aux->sig;
        }
    }
}

void insertar(Lista *lista, Nodo *nodo) {
    if(lista->cabecera == NULL){ //la lista esta vacia
        lista->cabecera= nodo;
        nodo->sig=NULL;
    }else{
        Nodo * aux = lista->cabecera;
        while(aux->sig != NULL){
            aux=aux->sig;
        }
        aux->sig=nodo;
        nodo->sig=NULL;
    }
}

void insertarOrdenado(Lista *lista, Nodo *nodo) {
    if(lista->cabecera==NULL){ //la lista esta vacia
        lista->cabecera=nodo;
        nodo->sig=NULL;
    } else{
        Nodo * ant =NULL;
        Nodo * act = lista->cabecera;
        while(act != NULL && nodo->num>act->num){
            ant=act;
            act= act->sig;
        }if(ant==NULL){ //insertar al principio
            nodo->sig=act;
            lista->cabecera=nodo;
        }else if(act == NULL){ //insertar al final
            nodo->sig=NULL;
            ant->sig=nodo;
        }else{ //insetar entre dos
            nodo->sig=act;
            ant->sig=nodo;
        }
    }
}

void eliminar(Lista *lista, int num) { //falta elemento no esta en la lista
    if(lista->cabecera == NULL){
        printf("La lista esta vacia.\n");
        exit(-1);
    } else{
        Nodo * act = lista->cabecera;
        Nodo * ant = NULL;
        if(lista->cabecera->num == num){ //primer elemento
            lista->cabecera=act->sig;
            free(act);
        }else{
            while(act->num != num){
                ant=act;
                act=act->sig;
            }if(act->sig == NULL){ //ultimo elemento
                ant->sig=NULL;
                free(act);
            }else{ //en el medio
                ant->sig = act->sig;
                free(act);
            }
        }
    }
}
//funcion que recibe como paramentro conjuntos de enteros (representados por listas ordenadas)
// y devuelve la resta del primero con el segundo(los elementos que SOLO aparecen en la primera)
Lista *resta(Lista *listaA, Lista *listaB) {
    Nodo * auxA= listaA->cabecera;
    Nodo * auxB =listaB->cabecera;
    Lista * listaResta=newLista();
    while (auxA != NULL){
        while (auxB != NULL && auxB->num <= auxA->num){
            if(auxB->num == auxA->num){
                auxA=auxA->sig;
            }
            auxB=auxB->sig;
        }
        if(auxB == NULL || auxA->num<auxB->num){
            insertar(listaResta, newNodo(auxA->num));
            auxA=auxA->sig;
        }
    }
    return listaResta;
}
