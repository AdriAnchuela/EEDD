//
//  metodos.cpp
//  PEEF
//
//  Created by Adrian Anchuela on 21/5/23.
//

#include <stdio.h>
#include "clases.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>  // Para la función time().




// Ahora puedes usar rand() para generar números aleatorios.


using namespace std;

//Insertar CP en el arbol
void ArbolABB::insertarNodo(CentralPaqueteria cp){
    int numero = cp.numCP;
    // Verifica si el número de CP ya existe en el árbol
    if (buscarNodo(numero)){
        
        // Si el número de CP ya existe, muestra un mensaje de error
        cout << "Error: ya existe un nodo con el número de CP " << numero << endl;
        return;
    }
        // Crea un nuevo nodo
    nodo *nuevo = new nodo(CentralPaqueteria(), NULL, NULL);
    
    nuevo->CP = cp;
    if(Vacio(raiz)){
        raiz = nuevo ;
        cout << "CP SE HA INGRESADO CORRECTAMENTE" <<endl;
    }else{
        nodo *p = raiz, *padre;
        
        while(!Vacio(p)){
            padre = p;
            if(numero < p->CP.numCP) p = p->izquierdo;
            else p = p->derecho;
        }
        if(numero < padre->CP.numCP) padre->izquierdo = nuevo;
        else padre->derecho = nuevo;
        cout << "CP SE HA INGRESADO CORRECTAMENTE" <<endl;
    }
}

//Borrar un nodo CP del arbol
void ArbolABB::borrarNodo(const int dat){
   nodo *padre = NULL;
   nodo *nodo;
   char aux;

   actual = raiz;
   while(!Vacio(actual)) {
       if(dat == actual->CP.numCP) {
           if(esHoja(actual)){
               if(padre){
                   if(padre->derecho == actual) padre->derecho = NULL;
                   else if(padre->izquierdo == actual) padre->izquierdo = NULL;
               }
               delete actual; // Borrar el nodo actual = NULL;
               cout << "EL CP SE HA BORRADO CORRECTAMENTE" << endl;
               actual = NULL;
               return;
           }
       else
           {
               padre = actual;
               if(actual->derecho)
               {
                   nodo = actual->derecho;
                   while(nodo->izquierdo) {
                       padre = nodo;
                       nodo = nodo->izquierdo; }
               }else
           {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                   padre = nodo;
                     nodo = nodo->derecho;
                  }
           }
               aux = actual->CP.numCP;
               actual->CP.numCP = nodo->CP.numCP;
               nodo->CP.numCP=aux;
               actual = nodo;
           }
       }
       else{
           padre = actual;
           if (dat > actual -> CP.numCP) actual = actual->derecho;
           else if (dat < actual-> CP.numCP) actual = actual-> izquierdo;
           }
       }
   }

void ArbolABB::postOrden(anodo nodo){
    if (nodo!= NULL)
    {
        postOrden (nodo ->izquierdo);
        postOrden (nodo -> derecho);
        
        cout << nodo-> CP.numCP << "-"<< nodo ->CP.localidad << ","<< " Numero paquetes dentro: " << nodo -> CP.lista.lenLista() << endl;
    }
}

void ArbolABB::preOrden(anodo nodo){
    if (nodo != NULL)
    {
        // Procesa el nodo actual primero
        cout << nodo-> CP.numCP << "-" << nodo-> CP.localidad << "," 
             << " Numero de paquetes dentro: " << nodo-> CP.lista.lenLista() << endl;

        // Luego recorre el subárbol izquierdo
        preOrden(nodo -> izquierdo);

        // Y finalmente recorre el subárbol derecho
        preOrden(nodo -> derecho);
    }
}

void ArbolABB::buscarPaqueteEnCP(anodo nodo, string id, bool t) {
    if (nodo!= NULL && t) {
        
       
        if (nodo -> CP.lista.buscarPaquete(id)) {
            cout << "El paquete " << id << " se encuentra en el CP numero: " << nodo -> CP.numCP << " "<< nodo->CP.localidad << endl;
            t = false;
        }
        
        buscarPaqueteEnCP (nodo ->izquierdo, id,t);

        buscarPaqueteEnCP(nodo -> derecho, id,t);
    }
}



int ArbolABB::getAlturaArbol(const int dat)
{
  int altura = 0;
  actual = raiz;

  while(!Vacio(actual)) {
     if(dat == actual->CP.numCP) return altura;
     else {
        altura++;
        if(dat > actual->CP.numCP) actual = actual->derecho;
        else if(dat < actual->CP.numCP) actual = actual->izquierdo;
     }
  }
  return -1; // No estÃ¡ en Ã¡rbol
}

const int ArbolABB::numeroNodos()
{
  contador = 0;

  auxContador(raiz); // FUnciÃ³n auxiliar
  return contador;
}

void ArbolABB::auxContador(nodo *nodo)
{
  contador++;  // Otro nodo
  // Continuar recorrido
  if(nodo->izquierdo) auxContador(nodo->izquierdo);
  if(nodo->derecho)   auxContador(nodo->derecho);
}

const int ArbolABB::alturaArbol()
{
  altura = 0;

  auxAltura(raiz, 0); // FunciÃ³n auxiliar
  return altura;
}

void ArbolABB::auxAltura(nodo *nodo, int a)
{
  // Recorrido postorden
  if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
  if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
  // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
  // Ã¡rbol, actualizamos la altura actual del Ã¡rbol
  if(esHoja(nodo) && a > altura) altura = a;
}

bool Lista::listaVacia()
{
    return cabeza == NULL;
}

// Booleano que nos dice si existe un nodo CP en el arbol
bool ArbolABB::buscarNodoB(int numero){
    nodo *p = raiz;
    while(!Vacio(p)){
        if(numero == p->CP.numCP){
            // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
            actual = p;
            return true;
        }
        else if(numero < p->CP.numCP) p = p->izquierdo;
        else p = p->derecho;
    }
    
    // Devuelve false si no se ha encontrado el nodo
    return false;
}

void ArbolABB::sacarlista (int numero){
    bool t = true;
    if (buscarNodo(numero)){
        nodo *p = raiz;
        while(t){
            if(numero == p->CP.numCP){
                // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                actual = p;
                actual -> CP.lista.recorrerLista(0);
                t = false;
            }
            else if(numero < p->CP.numCP) p = p->izquierdo;
            else p = p->derecho;
            
            
        }
        
    }
}

//metodo para inserta una lista en un CP dado
nodo* ArbolABB::buscarNodo(int numero){
    nodo* p = raiz;
    while(p != NULL) {
        if(numero == p->CP.numCP) {
            return p; // Se encuentra el nodo y se retorna
        }
        else if(numero < p->CP.numCP) {
            p = p->izquierdo;
        }
        else {
            p = p->derecho;
        }
    }
    return NULL; // No se encuentra el nodo y se retorna NULL
}



void ArbolABB::pasarCAEaCPdada(int numero, string id, Lista& lis){
    bool t = true;
    if (buscarNodo(numero)){
        nodo *p = raiz;
        while (t){
            if(numero == p->CP.numCP){
                // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                actual = p;
                actual -> CP.lista.insertarNodo(numero, 'f', lis.mostrarPaquete(id));
                lis.borrarNodo(id);
                cout << "Se ha cambiado correctamente " << endl;
                t = false;
            }
            else if(numero < p->CP.numCP) p = p->izquierdo;
            else p = p->derecho;
        }
    }
}

void ArbolABB::borrarListaNodo(int numero, string id){
    bool t = true;
    if (buscarNodo(numero)){
        nodo *p = raiz;
        while (t){
            if(numero == p->CP.numCP){
                // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                actual = p;
                actual -> CP.lista.borrarNodo(id);
                t = false;
            }
            else if(numero < p->CP.numCP) p = p->izquierdo;
            else p = p->derecho;
        }
    }
}

// Metodo automatico para pasar de CAE a CP
void ArbolABB::asignarCP (Paquete pa){
    int numero;
    if (pa.numCP== 0){
        
        if (pa.latitud.minutos>=27 && pa.longitud.minutos >=14){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Alcala" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
            
        }else if (pa.latitud.minutos>= 20 && pa.longitud.minutos>=14 ){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Mejorada" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
        }else if (pa.latitud.minutos>=13 && pa.longitud.minutos>=14){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Arganda" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
        }else if (pa.latitud.minutos>=6 && pa.longitud.minutos>=14){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Morata" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
        }else if (pa.latitud.minutos>=27 && pa.longitud.minutos >=5){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Los Santos" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
            
        }else if (pa.latitud.minutos>= 20 && pa.longitud.minutos>=5 ){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Pezuela" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho; 
            }
        }else if (pa.latitud.minutos>=13 && pa.longitud.minutos>=5){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Orusco" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
        }else if (pa.latitud.minutos>=6 && pa.longitud.minutos>=5){
            bool t = true;
            nodo *p = raiz;
            while (t){
                if("Valdaracete" == p->CP.localidad){
                    // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                    actual = p;
                    numero = actual -> CP.numCP;
                    pa.numCP = numero;
                    insertarListaNodo(numero, pa);
                    t = false;
                }
                else if(numero < p->CP.numCP) p = p->izquierdo;
                else p = p->derecho;
            }
        }
    }
    else{
        cout << "YA TIENE CP ASIGNADO" << endl;
    }
}
bool ArbolABB::insertarListaNodo(int numero, Paquete pa){
    bool t = true;
    if (buscarNodo(numero)){
        nodo *p = raiz;
        while (t){
            if(numero == p->CP.numCP){
                // Si se encuentra el nodo, actualiza el puntero "actual" y devuelve true
                actual = p;
                actual -> CP.lista.insertarNodo(numero, 'f', pa);
                t = false;
            }
            else if(numero < p->CP.numCP) p = p->izquierdo;
            else p = p->derecho;
        }
    }
    return t; // devolver el estado de la operación de inserción
}


//sirve para la funcion 7 que nos dan un numero id de paquete y un numero de CP
void ArbolABB::asignarCPdada (Paquete pa, int numero){
    nodo *p = raiz;
    bool t = true;
    if (pa.numCP== 0){
        while (t)
        if (numero == p -> CP.numCP ){
            pa.numCP = numero;
            insertarListaNodo(numero, pa);
            t = false;
        }else if(numero < p->CP.numCP) p = p->izquierdo;
        else p = p->derecho;
        }
    
    else{
        cout << "YA TIENE CP ASIGNADO" << endl;
    }
}

void ArbolABB::mudarPaquete(int numeroCP1, int numeroCP2, string id){
    nodo *p = buscarNodo(numeroCP1);
    if (p == NULL) {
        cout << "No se encontró la CP " << numeroCP1 << ".\n";
        return;
    }
    
    Paquete pa = p -> CP.lista.mostrarPaquete(id);
    if(pa.ID != id) {
        cout << "No se encontró el paquete con el ID " << id << " en la CP " << numeroCP1 << ".\n";
        return;
    }

    if (!p -> CP.lista.borrarNodo(id)) {
        cout << "No se pudo eliminar el paquete con el ID " << id << " de la CP " << numeroCP1 << ".\n";
        return;
    }

    if (!insertarListaNodo(numeroCP2, pa)) {
        cout << "No se pudo insertar el paquete en la CP " << numeroCP2 << ".\n";
        return;
    }

    cout << "El paquete con el ID " << id << " se ha movido de la CP " << numeroCP1 << " a la CP " << numeroCP2 << ".\n";
}

// Buscar un nodo (CP) en el árbol por su número de CP

const int ASCENDENTE=0;
// Mostrar todos los paquetes en una CP dada, ordenados por ID
void ArbolABB::mostrarPaquetesEnCP(int numCP) {
    // Encontrar el nodo con el número de CP dado
    anodo nodoCP = buscarNodo(numCP);
    
    if (nodoCP != NULL) {
        // Ordenar los paquetes por ID
        nodoCP->CP.lista.ordenarPorID();
        
        // Mostrar los paquetes
        nodoCP->CP.lista.recorrerLista(ASCENDENTE);
    } else {
        cout << "No se encontró una CP con el número " << numCP << endl;
    }
}

void ArbolABB::recorrerArbolYMostrarCPs(anodo nodo) {
    if(nodo != NULL) {
        recorrerArbolYMostrarCPs(nodo->izquierdo);
        cout << "CP: " << nodo->CP.numCP << " Localidad: " << nodo->CP.localidad << endl;
        recorrerArbolYMostrarCPs(nodo->derecho);
    }
}
void ArbolABB::recorrerArbolDFS(anodo nodo) {
    if (nodo != NULL) {
        recorrerArbolDFS(nodo->izquierdo);
        cout << "CP " << nodo->CP.numCP << " - " << nodo->CP.localidad << endl;
        recorrerArbolDFS(nodo->derecho);
    }
}
void mostrarInformacionCPCAE(CentralPaqueteria cp, int totalPaquetesCAE) {
    int numPaquetesCP = cp.lista.lenLista();
    float porcentajePaquetes = static_cast<float>(numPaquetesCP) / totalPaquetesCAE * 100.0;

    cout << "CP " << cp.numCP << " - " << cp.localidad << endl;

    cout << "Número de paquetes en la CP: " << numPaquetesCP << endl;
    cout << "Porcentaje de paquetes en la CP respecto al total de la CAE: " << porcentajePaquetes << "%" << endl;
}
void ArbolABB::preOrden(anodo nodo, int totalPaquetesCAE) {
    if(nodo != NULL) {
        float porcentaje = (nodo->CP.totalPaquetes() / (float) totalPaquetesCAE) * 100;
        cout << "Número de CP: " << nodo->CP.numCP << endl;
        cout << "Localidad: " << nodo->CP.localidad << endl;
        cout << "Número de paquetes en la pila: " << nodo->CP.totalPaquetes() << endl;
        cout << "Porcentaje de paquetes frente al total de la CAE: " << porcentaje << "%" << endl;

        preOrden(nodo->izquierdo, totalPaquetesCAE);
        preOrden(nodo->derecho, totalPaquetesCAE);
    }
}

void ArbolABB::informarCPMasMenosPaquetes(anodo nodo, CPInfo& masPaquetes, CPInfo& menosPaquetes, int totalCAE) {
    if (nodo) {
        informarCPMasMenosPaquetes(nodo->izquierdo, masPaquetes, menosPaquetes, totalCAE);

        int numPaquetesCP = nodo->CP.lista.obtenerTotalPaquetes();

        if (numPaquetesCP > masPaquetes.numPaquetes) {
            masPaquetes.numCP = nodo->CP.numCP;
            masPaquetes.localidad = nodo->CP.localidad;
            masPaquetes.numPaquetes = numPaquetesCP;
            masPaquetes.porcentaje = (double)numPaquetesCP / totalCAE * 100;
        }

        if (numPaquetesCP < menosPaquetes.numPaquetes) {
            menosPaquetes.numCP = nodo->CP.numCP;
            menosPaquetes.localidad = nodo->CP.localidad;
            menosPaquetes.numPaquetes = numPaquetesCP;
            menosPaquetes.porcentaje = (double)numPaquetesCP / totalCAE * 100;
        }

        informarCPMasMenosPaquetes(nodo->derecho, masPaquetes, menosPaquetes, totalCAE);
    }
}

bool ArbolABB::buscarPaquetePorID(anodo nodo, string id) {
    if(nodo != NULL) {
        if(nodo->CP.lista.buscarPaquetePorID(id))
            return true;
        
        // Buscar en el nodo izquierdo
        if(buscarPaquetePorID(nodo->izquierdo, id))
            return true;

        // Buscar en el nodo derecho
        if(buscarPaquetePorID(nodo->derecho, id))
            return true;
    }
    // Si el nodo es nulo, no se encontró el paquete
    return false;
}
void ArbolABB::eliminarPaqueteCPDada2(anodo nodo, string id, int numero, bool& t) {
    if (nodo == NULL) {
        return;
    }

    if (nodo->CP.numCP == numero) {
        // Solo establece t en verdadero si se eliminó un nodo.
        t = nodo->CP.lista.borrarNodo(id);
    }

    if (t) {
        return;
    }

    eliminarPaqueteCPDada2(nodo->izquierdo, id, numero, t);
    eliminarPaqueteCPDada2(nodo->derecho, id, numero, t);
}





//---------------------------------------------------------//
//---------------------------------------------------------//
//--------------------LISTAS-------------------------------//
//---------------------------------------------------------//
//---------------------------------------------------------//


const int DESCENDENTE=1;

Lista::~Lista()
{
    pnodo aux;
    esPrimero();
    while(cabeza)
    {
    aux = cabeza;
    cabeza = cabeza->derecho;
        delete aux;
    }
    cabeza=NULL;
    actual=NULL;
    final=NULL;
}

void Lista::esSiguiente()
{
    if(actual) actual = actual->derecho; }

void Lista::esAnterior()
{
    if(actual) actual = actual->izquierdo;

}

void Lista::esPrimero() {
    actual=cabeza;
}

void Lista::esUltimo()
{
    actual=final;
}

bool Lista::esActual()
{
    return actual != NULL;
}

Paquete paqueteVacio = {"",0,0,0,0};


// Insertamos un paquete en un CP, hay que elegir el orden f o p (final o principio)
void Lista::insertarNodo(int v,char c,Paquete p) {
    pnodo aux;
    char tipoInsercion; tipoInsercion=c;
    if (listaVacia())
    { aux = new Nodo(v, p, NULL,NULL);
        final=cabeza= aux;
    }else if (tipoInsercion=='f'){ //Insercion por el final
        aux= new Nodo(v, p, NULL,NULL);
        aux-> izquierdo = final;
        final->derecho=aux;
        final=aux;
    }
    else if (tipoInsercion=='p') {//Inserción por el principio
        aux= new Nodo(v, p, NULL,NULL);
        aux->derecho=cabeza;
        cabeza->izquierdo=aux;
        cabeza=aux;
    }
}

// Borramos un paquetes de un CP insertanod su ID
bool Lista::borrarNodo(string ID) {
    pnodo anterior = NULL;
    actual = cabeza;

    // Encontrar el nodo con el ID especificado.
    while (actual != NULL && actual->paq.ID != ID) {
        anterior = actual;
        actual = actual->derecho;
    }

    // Si no se encontró el nodo, retorna falso.
    if (actual == NULL) {
        return false;
    }

    // Si se encontró el nodo, entonces lo elimina de la lista.
    if (actual == cabeza) {
        // Es el primer nodo.
        cabeza = actual->derecho;
    } else {
        // No es el primer nodo.
        anterior->derecho = actual->derecho;
        if (actual == final) {
            final = anterior;
        }
    }

    delete actual;

    // Retorna verdadero, ya que se eliminó un nodo.
    return true;
}


//Esta funcion pasa automaticamnete un paquete del CAE al CP segun sus coordenadas
Paquete Lista::pasarCAEaCP(){
    Paquete p;
    string id;
    bool t = true;
    pnodo aux;
    if (!listaVacia()) {
        esPrimero();
        aux = cabeza;
        while (t) {
            p = aux -> paq;
            id = aux -> paq.ID;
            aux = aux ->derecho;
            borrarNodo(id);
            t = false;
        }
    }
    return p;
}
//esta funcion busca un paquete en una Lista
bool Lista::buscarPaquete(string numero){
    Paquete p;
    string id;
    bool t = true;
    bool f = false;
    pnodo aux;
    esPrimero();
    aux = cabeza;
    while (aux) {
       
        if (!listaVacia() & numero == aux -> paq.ID) {
            f = true;
                aux = aux ->derecho;
                t = false;
        }else {
            aux = aux -> derecho;
        }
    }
    return f;
}


Paquete Lista::mostrarPaquete(string id) {
  Paquete p;
  bool encontrado = false;
  pnodo aux = cabeza;

  // Recorremos la lista hasta encontrar el paquete con el ID especificado
  // o hasta llegar al final de la lista
  while (aux != nullptr && !encontrado) {
    if (aux->paq.ID == id) {
      encontrado = true;
      p.numCP = aux->paq.numCP;
      p.latitud = aux->paq.latitud;
      p.ID = aux->paq.ID;
      p.longitud = aux->paq.longitud;
      p.niDestinatario = aux->paq.niDestinatario;
    }
    aux = aux->derecho;
  }

  return p;
}


//Recorremos CP y sacamos su contenido por pantalla
void Lista::recorrerLista(int numero){
    pnodo aux;
    if (numero == ASCENDENTE) {
        esPrimero();
        aux = cabeza;
        while (aux) {
            cout << aux -> numeroCP <<"-"<< aux -> paq.numCP <<"-"<< aux -> paq.ID<<"-"<<  aux->paq.niDestinatario <<"-"<<  aux->paq.latitud.grados << aux->paq.latitud.minutos << aux->paq.latitud.segundos <<"-"<< aux->paq.longitud.grados << aux->paq.longitud.minutos << aux->paq.longitud.segundos <<endl;
            aux = aux ->derecho;
        }
    }
    else {
        esUltimo();
        aux = final;
        while(aux)  {
        } cout << aux -> numeroCP <<"-"<< aux -> paq.numCP <<"-"<< aux -> paq.ID<<"-"<<  aux->paq.niDestinatario <<"-"<< aux->paq.latitud.grados << aux->paq.latitud.minutos << aux->paq.latitud.segundos <<"-"<< aux->paq.longitud.grados << aux->paq.longitud.minutos << aux->paq.longitud.segundos <<endl;
           aux = aux->izquierdo;
    }
    cout << endl;
}



//Longitud de lista de un CP
int Lista::lenLista(){
    pnodo aux;
    aux = cabeza;
    int i = 0;
    while (aux) {
        aux = aux ->derecho;
        i++;
    }
    return i;
    
}

void Lista::ordenarPorID() {
    // Algoritmo de ordenamiento por burbuja
    bool intercambio;
    do {
        intercambio = false;
        pnodo actual = cabeza;
        while (actual != NULL && actual->derecho != NULL) {
            if (actual->paq.ID > actual->derecho->paq.ID) {
                // Intercambiamos los paquetes
                Paquete temp = actual->paq;
                actual->paq = actual->derecho->paq;
                actual->derecho->paq = temp;

                intercambio = true;
            }
            actual = actual->derecho;
        }
    } while (intercambio);  // Si no hubo intercambios en la última pasada, la lista ya está ordenada
}

int Lista::obtenerTotalPaquetes() {
    int total = 0;
    pnodo aux = cabeza;
    while(aux != NULL) {
        total++;
        aux = aux->derecho;
    }
    return total;
}

int CentralPaqueteria::totalPaquetes() {
    return this->lista.obtenerTotalPaquetes();
}

// Para Lista
bool Lista::buscarPaquetePorID(string id) {
    pnodo p = cabeza;
    while(p != NULL) {
        if(p->paq.ID == id) {
            cout << "Paquete encontrado con ID: " << p->paq.ID << "\n";
            cout << "Número de CP: " << p->paq.numCP << "\n";
            cout << "DNI del destinatario: " << p->paq.niDestinatario << "\n";
            cout << "Latitud: " << p->paq.latitud << "\n";
            cout << "Longitud: " << p->paq.longitud << "\n";
            return true;
        }
        p = p->derecho;
    }
    return false;
}

void Lista::imprimirOrdenado() {
    std::multimap<std::string, Paquete> map;
    pnodo temp = cabeza;

    while(temp != nullptr){
        map.insert(std::make_pair(temp->paq.ID, temp->paq));
        temp = temp->derecho;
    }

    for(auto it = map.rbegin(); it != map.rend(); ++it){
        std::cout << "ID: " << it->first << "\n";
        std::cout << "DNI Destinatario: " << it->second.niDestinatario << "\n";
        std::cout << "Número de CP: " << it->second.numCP << "\n";
        std::cout << "Latitud - Grados: " << it->second.latitud.grados << ", Minutos: " << it->second.latitud.minutos << ", Segundos: " << it->second.latitud.segundos << "\n";
        std::cout << "Longitud - Grados: " << it->second.longitud.grados << ", Minutos: " << it->second.longitud.minutos << ", Segundos: " << it->second.longitud.segundos << "\n";
    }
}




//---------------------------------------------------------//
//---------------------------------------------------------//
//--------Generadores ID Latitud y Longitud----------------//
//---------------------------------------------------------//
//---------------------------------------------------------//

int secuencia = 1;

std::string generador_id(int& secuencia) {
    
    // Generar dos dígitos aleatorios.
    int digitos = rand() % 100; // Esto generará un número aleatorio entre 0 y 99.

    // Generar una letra aleatoria.
    char letra = 'A' + rand() % 26; // Esto generará un carácter aleatorio entre 'A' y 'Z'.

    // Construir el ID.
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << digitos;  // Asegura que siempre sean dos dígitos.
    oss << letra;
    oss << std::setw(4) << std::setfill('0') << secuencia;  // Asegura que siempre sean cuatro dígitos.

    // Incrementa la secuencia para el próximo ID.
    secuencia++;

    return oss.str();
}

char letraDNI(int dni) {
    string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letras[dni % 23];
}

string generador_dni() {
    
    int numeroDNI = rand() % 100000000;  // Genera un número aleatorio de 8 cifras.
    char letra = letraDNI(numeroDNI);  // Calcula la letra correspondiente.
    stringstream ss;
    ss << setfill('0') << setw(8) << numeroDNI;  // Asegura que siempre sean 8 dígitos.
    return ss.str() + letra;
}


Coordenadas generador_latitud(void){
    
    int grados, minutos, segundos;
    Coordenadas latitud;

    latitud.grados= grados = 40;
    latitud.minutos= minutos = 6 + rand() % (35-6);
    latitud.segundos= segundos = 0;

    return latitud;
}

Coordenadas generador_longitud(void){
    
    int grados, minutos, segundos;
    Coordenadas longitud;

    longitud.grados= grados = -3;
    longitud.minutos= minutos = 5 + rand () % (35-5);
    longitud.segundos= segundos =30;

    return longitud;
}
