//
//  metodos.cpp
//  EEDD
//
//  Created by Adrian Anchuela  on 14/10/22.
//

#include <stdio.h>
#include "paquetes.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Destructor de la Pila
Pila::~Pila()
{
    while(cima)desapilar();
}


//Meter elemento en la Pila
void Pila::apilar(Paquetes p)
{
    pNodo nuevo;                //Var aux para manipular el nuevo nodo
                                //Se crea un nodo nuevo
    nuevo = new Nodo(p, cima);
                                //El comienzo de la pila es el nuevo nodo
    cima = nuevo;
}

//Sacar elemento de la Pila
Paquetes Pila::desapilar()
{
    pNodo nodo;                     //Var aux para manipular el nodo
                                    //Var aux para el retorno del valor del nodo
    Paquetes v,vaux={"",0,0,0};
    if(!cima) return vaux;          // Si no hay nodos en la pila se devuelve 0
                                    // Nodo apunta al primer elemento de la pila
        nodo = cima;
                                    //Se asigna a pila toda la pila menos el primer elemento
        cima= nodo->siguiente;
                                    //Se guarda el retorno del valor del nodo
        v = nodo->valor;
                                    //Se borra el nodo
    delete nodo;
    return v;
}


int Pila::lenPila(){
    pNodo actual;
    int longitud = 0;

    actual = cima;
    while (actual != NULL){
        longitud++;
        actual = actual -> siguiente;
    }
    return longitud;
}

bool Pila::vacia(){
    if(cima){
        return true;
    }
    else{
        return false;
    }
}

//Destructor
Cola::~Cola()
{
    while(frente) desencolar();
}
//Añadir elemento en la cola

void Cola::encolar(Paquetes p)

    { pNodo nuevo;
    nuevo = new Nodo(p);                // Se crea un nodo nuevo
                                        // Si cola no vacÌa, se aÒade el nuevo a continuaciÛn de ultimo
    if(fin) fin->siguiente = nuevo;
                                        //El ˙ltimo elemento de la cola es el nuevo nodo
    fin= nuevo;
                                        // Si frente es NULL, la cola est· vacÌa y el nuevo nodo pasa a ser el primero
    if(!frente) frente = nuevo;
}

//Leer elemento de la cola
Paquetes Cola::desencolar()
{
    pNodo nodo;                         //Var aux para manipular nodo
    Paquetes p , vaux={"",0,0,0};    //Var aux para retorno del valor
                                        // Nodo apunta al primer elemento de la pila
    nodo = frente;
    if(!nodo) return vaux;              // Si no hay nodos en la pila se devuelve 0
                                        //Se asigna a frente la direcciÛn del segundo nodo
    frente = nodo->siguiente;
                                        //Se guarda el valor de retorno
    p = nodo->valor;
    delete nodo;                        // Se borra el nodo
                                        // Si cola vacÌa, ultimo debe ser NULL tambiÈn
    if(!frente) fin = NULL;
    return p;
}

void Cola::recorrerCola()
{
        pNodo actual;
        actual = frente;
        while (actual != NULL){
            cout << setw(7) << actual -> valor.identificacion << "|" << setw(3) << actual -> valor.latitud.grados << setw(3) << actual -> valor.latitud.minutos << setw(2) << actual -> valor.latitud.segundos << "|" << setw (3) << actual -> valor.longitud.grados << setw (3) << actual -> valor.longitud.minutos << setw (2) << actual -> valor.longitud.segundos << "|" << setw (9) << actual -> valor.nifC << endl;
            actual = actual -> siguiente;
        }

}
int Cola::lenCola(){
    pNodo actual;
    int longitud = 0;

    actual = frente;
    while (actual != NULL){
        longitud++;
        actual = actual -> siguiente;
    }
    return longitud;
}

bool Cola::vacia()
{
    return frente == NULL;
}

int mayor (int x, int y)
{
    int resultado;
    if (x>y){
        resultado = x;}
    else if (x==y) {
            resultado = x;
    }
    else{
        resultado = y;
    }
    return resultado;
}
int elmayor (int a, int b, int c, int d){

    return (mayor(mayor(mayor(a,b),c),d));
}

int paquetes_creados = 1;
int n1=0, n2 =0, n3=0, n4=0;


string generador_id(void){

    int inicio, fin, i;
    string ide;
    string letra[] = {"A", "B", "C", "D", "E", "F", "G", "H"};
    
    inicio = 10 + rand() % (100-10);
    i = rand() % 8;
    fin = 1001 + paquetes_creados;
    n1 = paquetes_creados;
    
    if( n1 >= 10){
        n1 = paquetes_creados%10;
        if (n1 ==0){
            n2++;}
    }
    if( n2 ==10){
        n2 =0;
        n3 ++;
    }
    if (n3 ==10){
        n3=0;
        n4++;
    }
    
    //ide = to_string(inicio) + letra[i] + to_string(fin);
    ide = to_string(inicio) + letra[i] + to_string(n4) + to_string(n3) + to_string(n2) +to_string(n1);
    
    paquetes_creados +=1;

    return ide;
}




Coordenadas generador_latitud(void){

    int grados, minutos, segundos;
    Coordenadas latitud;
    
    latitud.grados= grados = 40;
    latitud.minutos= minutos = 46 + rand() % (52-46);
    latitud.segundos= segundos = 5 + rand() % (7-5);

    return latitud;
}

Coordenadas generador_longitud(void){

    int grados, minutos, segundos;
    Coordenadas longitud;
    
    longitud.grados= grados = -3;
    longitud.minutos= minutos = 32 + rand () % (42-32);
    longitud.segundos= segundos = 1 + rand () % (3-1);
    
    return longitud;
}



char letraDNI(unsigned int dni)
{
    return "TRWAGMYFPDXBNJZSQVHLCKE"[dni % 23];
}

string generador_dni(void){
    
    int n;
    char letra;
    string dni;
    
    n = 10000000 + rand () % (100000000-10000000);
    letra = letraDNI(n);
    
    dni = to_string(n) + letra;
    
    return dni;
    
}

