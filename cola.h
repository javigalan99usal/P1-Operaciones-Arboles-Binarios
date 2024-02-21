#include "arbol.h"
#include <stdbool.h>

#ifndef COLA_H
#define COLA_H

/* ============== Implementación de un TAD cola con memoria dinámica ============== */

/* ================ MODIFICADO PARA TRABAJAR CON ÁRBOLES BINARIOS ================= */

// Definición del tipo de dato para los nodos de la cola
typedef struct NodoCola {
    NodoArbol* dato;
    struct NodoCola* siguiente;
} NodoCola;

// Definición del tipo de dato Cola
typedef struct {
    NodoCola* frente;
    NodoCola* final;
} Cola;

// Prototipos de funciones
void colaCreaVacia(Cola *cola); // Inicia o crea la pila como una cola vacía sin ningún elemento
bool colaVacia(Cola *cola); // Devuelve verdadero si la cola está vacía y falso en caso contrario
void colaInserta(NodoArbol* x, Cola *cola); // Inserta un elemento al final de la cola
NodoArbol* colaSuprime(Cola *cola); // Suprime el elemento que está al inicio de la cola y devuelve su valor

#endif