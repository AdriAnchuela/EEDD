//
//  paquetes.h
//  EEDD
//
//  Created by Adrian Anchuela  on 14/10/22.
//

#ifndef PAQUETES_H
#define PAQUETES_H
using namespace std;

#include <iostream>

struct Coordenadas
{
    int grados;
    int minutos;
    int segundos;
};

struct Paquetes
{
    string identificacion;
    Coordenadas latitud;
    Coordenadas longitud;
    string nifC;

};

class Nodo
{
    private:
            Paquetes valor;
            Nodo *siguiente;
            friend class Cola;
            friend class Pila;
    public:
            Nodo (Paquetes p, Nodo *sig = NULL)
            {
            valor = p;
            siguiente = sig;

            }
};
typedef Nodo *pNodo;

class Cola
{
    public:
        Cola() : frente(NULL), fin(NULL) {}
        ~Cola();
        void encolar(Paquetes p);
        Paquetes desencolar();
        void recorrerCola();
        int lenCola();
        bool vacia();
    private:
        pNodo frente, fin;
    friend class Pila;
};


class Pila
{
    private:
        pNodo cima;
    public:
        Pila() : cima(NULL) {} //Constructor de la Pila
        ~Pila();
        void apilar(Paquetes p);
        Paquetes desapilar();
        int lenPila();
        bool vacia();
};


#endif /* paquetes_h */
