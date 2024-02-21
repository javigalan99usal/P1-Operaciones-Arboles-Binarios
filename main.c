#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cola.h"
#include "arbol.h"

// Función principal para probar las funciones de árbol.h (RECORRIDOS EN ÁRBOLES BINARIOS)

int main(void)
{
  Arbol varArbol, varSimilar, varNoSimilar, varEquivalente, varNoEquivalente, varEspecular;

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
  varArbol->der->der = creaNodo('G');

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

  /* Creación de árbol similar */
  varSimilar = creaNodo('A');
  varSimilar->izq = creaNodo('D');
  varSimilar->der = creaNodo('C');
  varSimilar->izq->izq = creaNodo('D');
  varSimilar->izq->der = creaNodo('N');
  varSimilar->der->izq = creaNodo('F');
  varSimilar->der->der = creaNodo('G');

  /* Creación de árbol no similar */
  varNoSimilar = creaNodo('A');
  varNoSimilar->izq = creaNodo('Z');
  varNoSimilar->der = creaNodo('C');
  varNoSimilar->izq->izq = creaNodo('G');
  varNoSimilar->izq->der = creaNodo('W');
  varNoSimilar->der->der = creaNodo('D');

  printf("\tOperación SIMILAR: ");
  int sim = similares(varArbol, varSimilar);
  int no_sim = similares(varArbol, varNoSimilar);

  if (sim)
  {
    printf("Arbol y ArbolSimilar -> Son similares\t");
  }
  else
  {
    printf("Arbol y ArbolSimilar -> NO son similares  ERROR\t");
  }
  if (!no_sim)
  {
    printf("Arbol y ArbolNoSimilar -> No son similares\n");
  }
  else
  {
    printf("Arbol y ArbolNoSimilar -> Son similares  ERROR\n");
  }

  /* Creación de árbol equivalente */
  varEquivalente = creaNodo('A');
  varEquivalente->izq = creaNodo('W');
  varEquivalente->der = creaNodo('C');
  varEquivalente->izq->izq = creaNodo('D');
  varEquivalente->izq->der = creaNodo('W');
  varEquivalente->der->izq = creaNodo('F');
  varEquivalente->der->der = creaNodo('G');

  /* Creación de árbol no equivalente */
  varNoEquivalente = creaNodo('A');
  varNoEquivalente->izq = creaNodo('W');
  varNoEquivalente->der = creaNodo('F');
  varNoEquivalente->izq->izq = creaNodo('D');
  varNoEquivalente->izq->der = creaNodo('W');
  varNoEquivalente->der->izq = creaNodo('F');
  varNoEquivalente->der->der = creaNodo('G');

  printf("\tOperación EQUIVALENTE: ");
  int eq = equivalentes(varArbol, varEquivalente);
  int no_eq = equivalentes(varArbol, varNoEquivalente);

  if (eq)
  {
    printf("Arbol y ArbolEquivalente -> Son equivalentes\t");
  }
  else
  {
    printf("Arbol y ArbolEquivalente -> NO son equivalentes  ERROR\t");
  }
  if (!no_eq)
  {
    printf("Arbol y ArbolNoEquivalente -> No son equivalentes\n");
  }
  else
  {
    printf("Arbol y ArbolNoEquivalente -> Son Equivalentes  ERROR\n");
  }

  printf("\tOperación ESPECULAR: ");
  varEspecular = especular(varArbol);
  printf("Arbol especular creado\n");

  printf("\t -Recorrido en PRE-ORDEN del arbol especular: ");
  preOrden(varEspecular);
  printf("\n");
  printf("\t -Recorrido en ORDEN del arbol especular: ");
  enOrden(varEspecular);
  printf("\n");
  printf("\t -Recorrido en POST-ORDEN del arbol especular: ");
  postOrden(varEspecular);
  printf("\n");
  printf("\t -Recorrido en AMPLITUD del arbol especular: ");
  amplitud(varEspecular);
  printf("\n");

  return 0;
}
