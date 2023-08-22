#include <stdio.h>
#include "listaSimple.h"

int main() {
    Lista * listaA =newLista();
    Lista * listaB = newLista();

    insertar(listaA, newNodo(0));
    insertar(listaA, newNodo(2));
    insertar(listaA, newNodo(3));
    insertar(listaA, newNodo(5));
    insertar(listaA, newNodo(7));

    insertar(listaB, newNodo(1));
    insertar(listaB, newNodo(2));
    insertar(listaB, newNodo(3));

    imprimir(listaA);
    printf("\n");
    imprimir(listaB);
    printf("\n");
    Lista * listaResta = resta(listaA,listaB);
    imprimir(listaResta);

    return 0;
}
