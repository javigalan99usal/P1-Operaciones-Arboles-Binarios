#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"
#include "cola.h"

//
// Reserva de memoria para un nuevo nodo de árbol binario
//
Arbol creaNodo(tipoInfo info)
{
  NodoArbol *nuevo;

  //   nuevo =(NodoArbol *)calloc(1, sizeof(NodoArbol));
  if ((nuevo = (NodoArbol *)malloc(sizeof(NodoArbol))) == NULL)
    return NULL;
  else
  {
    nuevo->info = info;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
  }
}

//
// Recorrido en amplitud o por niveles: necesita una cola de punteros a nodos de árbol binario!!!
//

void amplitud(Arbol raiz)
{
  Cola c;
  NodoArbol *nodo;
  colaCreaVacia(&c);
  nodo = raiz;
  if (raiz != NULL)
    colaInserta(nodo, &c);
  while (!colaVacia(&c))
  {
    nodo = (Arbol)colaSuprime(&c);
    printf(" %c ", nodo->info);
    if (nodo->izq != NULL)
      colaInserta(nodo->izq, &c);
    if (nodo->der != NULL)
      colaInserta(nodo->der, &c);
  }
}
//
// Recorridos en profundidad "recursivos"
//
void preOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    printf("%c ", raiz->info);
    preOrden(raiz->izq);
    preOrden(raiz->der);
  }
}
void enOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    enOrden(raiz->izq);
    printf("%c ", raiz->info);
    enOrden(raiz->der);
  }
}
void postOrden(Arbol raiz)
{
  if (raiz != NULL)
  {
    postOrden(raiz->izq);
    postOrden(raiz->der);
    printf("%c ", raiz->info);
  }
}
//
// Altura de un árbol binario
//
int altura(Arbol raiz)
{
  int altIzq, altDer; // alturas de los subárboles izquierdo y derecho
  if (raiz == NULL)
    return -1;
  else
  {
    altIzq = altura(raiz->izq);
    altDer = altura(raiz->der);
    if (altIzq > altDer)
      return altIzq + 1;
    else
      return altDer + 1;
  }
}
//
// Número de nodos de un árbol binario
//
int numNodos(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else
    return 1 + numNodos(raiz->izq) + numNodos(raiz->der);
}
//
// Anulación de un árbol binario
//
Arbol anula(Arbol raiz)
{
  if (raiz != NULL)
  {
    anula(raiz->izq);
    anula(raiz->der);
    free(raiz);
  }
  return NULL;
}
//
// Sustitución de un valor por otro en un árbol binario
//
int sustituye(Arbol raiz, tipoInfo x, tipoInfo y)
{
  if (raiz != NULL)
  {
    if (raiz->info == x)
    {
      raiz->info = y;
      return 1 + sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
    }
    else
    {
      return 0 + sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
    }
  }
  else
  {
    return 0;
  }
}
//
// Número de nodos hoja de un árbol binario
//
int numNodosHoja(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else if (raiz->izq == NULL && raiz->der == NULL)
    return 1;
  else
    return numNodosHoja(raiz->izq) + numNodosHoja(raiz->der);
}
//
// Número de nodos internos de un árbol binario
//
int numNodosInternos(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else if (raiz->izq == NULL && raiz->der == NULL)
    return 0;
  else
    return 1 + numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);
}
//
// Número de nodos con un solo hijo de un árbol binario
//
int numHijoUnico(Arbol raiz)
{
  if (raiz == NULL)
    return 0;
  else if (raiz->izq == NULL && raiz->der != NULL)
    return 1 + numHijoUnico(raiz->der);
  else if (raiz->izq != NULL && raiz->der == NULL)
    return 1 + numHijoUnico(raiz->izq);
  else
    return numHijoUnico(raiz->izq) + numHijoUnico(raiz->der);
}
//
// Búsqueda del nodo con el valor máximo de un árbol binario sin ordenar
//
Arbol buscarMax(Arbol raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  else
  {
    Arbol ar_izq = buscarMax(raiz->izq);
    Arbol ar_der = buscarMax(raiz->der);
    if (ar_izq == NULL && ar_der == NULL) // Si no tiene hijos
    {
      return raiz;
    }
    if (ar_izq != NULL && ar_der == NULL) // Si solo tiene hijo izquierdo
    {
      if (ar_izq->info > raiz->info)
      {
        return ar_izq;
      }
      else
      {
        return raiz;
      }
    }
    if (ar_der != NULL && ar_izq == NULL) // Si solo tiene hijo derecho
    {
      if (ar_der->info > raiz->info)
      {
        return ar_der;
      }
      else
      {
        return raiz;
      }
    }
    if (ar_izq->info > ar_der->info) // Si tiene dos hijos y el izquierdo es mayor que el derecho
    {
      if (ar_izq->info > raiz->info)
      {
        return ar_izq;
      }
      else
      {
        return raiz;
      }
    }
    else // Si tiene dos hijos y el derecho es menor que el izquierdo
    {
      if (ar_der->info > raiz->info)
      {
        return ar_der;
      }
      else
      {
        return raiz;
      }
    }
  }
}
//
// Búsqueda del nodo con el valor mínimo de un árbol binario sin ordenar
//
Arbol buscarMin(Arbol raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  else
  {
    Arbol ar_izq = buscarMin(raiz->izq);
    Arbol ar_der = buscarMin(raiz->der);
    if (ar_izq == NULL && ar_der == NULL) // Si no tiene hijos
    {
      return raiz;
    }
    if (ar_izq != NULL && ar_der == NULL) // Si solo tiene hijo izquierdo
    {
      if (ar_izq->info < raiz->info)
      {
        return ar_izq;
      }
      else
      {
        return raiz;
      }
    }
    if (ar_der != NULL && ar_izq == NULL) // Si solo tiene hijo derecho
    {
      if (ar_der->info < raiz->info)
      {
        return ar_der;
      }
      else
      {
        return raiz;
      }
    }
    if (ar_izq->info < ar_der->info) // Si tiene dos hijos y el izquierdo es menor que el derecho
    {
      if (ar_izq->info < raiz->info)
      {
        return ar_izq;
      }
      else
      {
        return raiz;
      }
    }
    else // Si tiene dos hijos y el derecho es menor que el izquierdo
    {
      if (ar_der->info < raiz->info)
      {
        return ar_der;
      }
      else
      {
        return raiz;
      }
    }
  }
}