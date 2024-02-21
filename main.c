#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cola.h"
#include "arbol.h"

// Función principal para probar las funciones de árbol.h (RECORRIDOS EN ÁRBOLES BINARIOS)

int main(void)
{
  Arbol varArbol;

  printf("\n EJERCICIO 1, RECORRIDOS:\n");

  /* Creación árbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq = creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq = creaNodo('D');
  varArbol->izq->der = creaNodo('E');
  varArbol->der->izq = creaNodo('F');
  varArbol->der->der = creaNodo('G');

  /* Aplicación de recorridos al árbol ejemplo */

  printf("\tRecorrido en PRE_ORDEN: ");
  preOrden(varArbol);
  printf("\n");
  printf("\tRecorrido en ORDEN: ");
  enOrden(varArbol);
  printf("\n");
  printf("\tRecorrido en POST_ORDEN: ");
  postOrden(varArbol);
  printf("\n");
  printf("\tRecorrido en AMPLITUD: ");
  amplitud(varArbol);
  printf("\n");

  /* Comenzar a implementar y probar las funciones del ejercicio 2 ... y segunda parte del ejercicio 3 */

  printf("\n EJERCICIO 2, OPERACIONES:\n");

  printf("\tAltura del arbol: ");
  int alt = altura(varArbol);
  printf("%d\n", alt);

  printf("\tNumero de nodos: ");
  int numNod = numNodos(varArbol);
  printf("%d\n", numNod);

  printf("\tOperación ANULA: ");
  varArbol = anula(varArbol);
  if (varArbol == NULL)
    printf("Árbol anulado\n");

  /* Creación árbol ejemplo de las transparencias de recorridos */
  varArbol = creaNodo('A');
  varArbol->izq = creaNodo('B');
  varArbol->der = creaNodo('C');
  varArbol->izq->izq = creaNodo('D');
  varArbol->izq->der = creaNodo('E');
  varArbol->der->izq = creaNodo('F');
  varArbol->der->der = NULL;

  printf("\tOperación SUSTITUYE 'E' por 'B': ");
  int num_sust = sustituye(varArbol, 'E', 'B');
  printf("%d\n", num_sust);

  printf("\tOperación SUSTITUYE 'B' por 'W': ");
  num_sust = sustituye(varArbol, 'B', 'W');
  printf("%d\n", num_sust);

  printf("\tNumero de hojas: ");
  int num_hoj = numNodosHoja(varArbol);
  printf("%d\n", num_hoj);

  printf("\tNumero de nodos internos: ");
  int num_int = numNodosInternos(varArbol);
  printf("%d\n", num_int);

  printf("\tNumero de nodos con un solo hijo: ");
  int num_hijo = numHijoUnico(varArbol);
  printf("%d\n", num_hijo);
  
  printf("\tOperación BUSCAR MIN: ");
  Arbol min = buscarMin(varArbol);
  printf("%c\n", min->info);

  printf("\tOperación BUSCAR MAX: ");
  Arbol max = buscarMax(varArbol);
  printf("%c\n", max->info);

  printf("\tOperación SIMILAR: ");

  printf("\tOperación EQUIVALENTE: ");

  printf("\tOperación ESPECULAR: ");

  return 0;
}
