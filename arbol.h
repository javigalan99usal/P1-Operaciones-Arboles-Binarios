#ifndef __ARBOL_H
#define __ARBOL_H

/*      Definiciones para un Arbol binario. Un Arbol es un puntero a un NodoArbol
        - Cada nodo contiene:
                + info (un char)
                + izq (puntero a un tiponodo)
                + der (puntero a un tiponodo)
*/

typedef char tipoInfo;

typedef struct NodoArbol{
        tipoInfo info;
        struct NodoArbol *izq, *der;
} NodoArbol;

typedef NodoArbol *Arbol;

Arbol creaNodo(tipoInfo info);

void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitud(Arbol raiz);

int altura(Arbol raiz);
int numNodos(Arbol raiz);
Arbol anula(Arbol raiz);
int sustituye(Arbol raiz, tipoInfo x, tipoInfo y);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);
int similares(Arbol r1, Arbol r2);
int equivalentes(Arbol r1, Arbol r2);
Arbol especular(Arbol raiz);
#endif
