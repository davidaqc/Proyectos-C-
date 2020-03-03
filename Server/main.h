#ifndef MAIN_H
#define MAIN_H

#include <string>
using namespace std;

/**
 * @brief Encargado de enviar mensajes al cliente mediante
 * sockets.
 *
 * @param mensaje Mensaje enviado al cliente
 */
void entro_mensaje(string mensaje);
/**
 * @brief Encargado de insertar nodos/vertice al grafo
 *
 * @param valor Vertice a insertar
 */
void insertar_nodo(string valor);
/**
 * @brief Muestra el grafo: vertices, aristas, pesos.
 *
 * @param a Vertices
 * @param b Aristas
 */
void mostrar_grafo(int a, int b);
/**
 * @brief Encargado de insertar aristas al grafo
 *
 * @param ambos_valores contiene el origen y destino del  arista
 */
void insertar_arista(string ambos_valores);
/**
 * @brief Encargado de generar el algorimo Dijkstra
 *
 * @param n Contiene los aristas y el peso
 * @param bb Contiene los vertices
 * @param a Origen
 * @param b Destino
 */
void generar_dijkstra(string n, string bb, int a, int b);

#endif // MAIN_H
