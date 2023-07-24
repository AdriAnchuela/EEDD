//
//  clases.h
//  PEEF
//
//  Created by Adrian Anchuela on 21/5/23.
//

#ifndef clases_h
#define clases_h

#include <iostream>
#include <map>
#include <iterator>


using namespace std;

// Coordenadas GPS Latitud y Longitud en formato grados, minutos y segundos
struct Coordenadas
{
    int grados;
    int minutos;
    int segundos;
};
std::ostream& operator<<(std::ostream &os, const Coordenadas &c) {
    os << "Grados: " << c.grados << ", Minutos: " << c.minutos << ", Segundos: " << c.segundos;
    return os;
}

//
struct Paquete {
    string ID;
    Coordenadas latitud;
    Coordenadas longitud;
    string niDestinatario;
    int numCP;
};
//ESTRUCTURA NODO Y LISTAS DOBLEMENTE ENLAZADAS PAQUETES
struct Nodo {
    public:
            int numeroCP;
            Nodo *derecho;
            Nodo *izquierdo;
            Paquete paq;
            friend class Lista;
            friend class CentralPaqueteria;
            
    public:
            Nodo(int numeroCP, Paquete p, Nodo *sig = NULL, Nodo *ant = NULL){
                paq = p;
                numeroCP = numeroCP;
                derecho = sig;
                izquierdo = ant;
                
            }

        };

typedef Nodo *pnodo;
struct InformeCP {
    int numCP;
    string localidad;
    int numPaquetes;
    double porcentaje;
};

struct CPInfo {
    int numCP;
    string localidad;
    int numPaquetes;
    double porcentaje; // El porcentaje de paquetes que contiene respecto al total en CAE.
};


class Lista{
    private:
        pnodo cabeza, actual, final;

    public:   
        Lista() {cabeza=actual=final=NULL; }
        ~Lista();
        void imprimirOrdenado();
        bool buscarPaquetePorID(string id);
        int obtenerTotalPaquetes();
        void insertarNodo(int numeroCP,char c, Paquete p); //insertamos un paquete en un CP
        bool borrarNodo(string ID); ///borramos un paqute de un CP cualquiera introduciendo su numero ID
        bool listaVacia();
        void recorrerLista(int n); // n es para el orden de recorrido normalmente 0 para ascendente;
        int lenLista();
        void ordenarPorID();
        void esSiguiente();
        void esAnterior();
        void esPrimero();
        void esUltimo();
        bool esActual();
        void sacarCP(int numero); 
        void cambiarCP(int ID, int numero,char c, Lista& lista); 
        Paquete valorActual();
        Paquete pasarCAEaCP();
        Paquete mostrarPaquete(string id);
        bool buscarPaquete(string ID);
        
};

struct CentralPaqueteria {
    int numCP;
    string localidad;
    Lista lista;
    int totalPaquetes();
};

//NODO Y ARBOL DE CENTRAL DE PAQUETERIA
struct nodo {
public:
    CentralPaqueteria CP;
    nodo *izquierdo;
    nodo *derecho;
    
    friend class ArbolABB;
    // Constructor:
    nodo(CentralPaqueteria CP , nodo *izq=NULL, nodo *der=NULL){
        CP = CP;
        CP.numCP = CP.numCP;
        izquierdo = izq;
        derecho = der;
    }
};

typedef nodo *anodo;

class ArbolABB {
 
    int contador, altura;
    
    public:
        anodo raiz, actual = NULL;
        ArbolABB() : raiz(NULL), actual(NULL) {}
        //~ArbolABB() { Podar(raiz); }
        void eliminarPaqueteCPDada2(anodo nodo, string id, int numero, bool& t);

        bool buscarPaquetePorID(anodo nodo, string id);
        void informarCPMasMenosPaquetes(anodo nodo, CPInfo& masPaquetes, CPInfo& menosPaquetes, int totalCAE);
        void preOrden(anodo nodo, int totalPaquetesCAE);
        void recorrerArbolDFS(anodo nodo);
        void recorrerArbolYMostrarCPs(anodo nodo);
        anodo buscarNodo(int numero);
        void mostrarPaquetesEnCP(int numCP);
        void Podar(nodo* &);
        void auxContador(nodo* );
        void auxAltura(nodo*, int);
        bool buscarNodoB (int numero);
        void insertarNodo (CentralPaqueteria cp);
        void borrarNodo (int dat);
        bool Vacio(nodo *r) { return r==NULL; }
        bool esHoja(nodo *r) { return !r->derecho && !r->izquierdo; }
        const int numeroNodos();
        const int alturaArbol();
        int getAlturaArbol(const int dat);
        bool insertarListaNodo(int numero, Paquete pa);
        void pasarCAEaCPdada(int numero, string s, Lista& lis);
        void borrarListaNodo(int numero, string id);
        void sacarlista(int numero);
        void asignarCP (Paquete p);
        void asignarCPdada (Paquete p, int numero);
        void eliminarPaqueteCPDada(anodo nodo, string id,int numero, bool t);
        void esRaiz() { actual = raiz; }
        void postOrden(anodo nodo);
        void preOrden(anodo nodo);
        void buscarPaqueteEnCP(anodo nodo, string id, bool t);
        pnodo sacarConcesionario (int numero);
        void eliminarElemento(int numero, string valor);
        void mudarPaquete(int numeroCP1, int numeroCP2, string id);
};

#endif
