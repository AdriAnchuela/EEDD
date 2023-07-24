//
//  main.cpp
//  PEEF
//
//  Created by Adrian Anchuela on 21/5/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "clases.h"
#include "metodos.cpp"
#include <ctime>


using namespace std;

// Constantes
const int N1 = 8;       // Número de centrales de paquetería
const int N2 = 100;     // Número de paquetes generados aleatoriamente
const int N3 = 12;      // Número de paquetes enviados a las CP en cada paso de ejecución
const int N4 = 6 * N3;  // Número de paquetes enviados a las CP al finalizar el periodo de tiempo evaluado

//Coordenadas generador_latitud();
//Coordenadas generador_longitud();
string generador_dni();
//string generador_id();

string localidades[] = {"Alcala","Mejorada","Arganda","Morata", "Los Santos","Pezuela", "Orusco", "Valdaracete"};

void menu1()
{
        cout << "\nMenu:\n";
        cout << "1. Insertar una CP de forma manual\n";
        cout << "2. Borrar una CP\n";
        cout << "3. Mostrar paquetes de una CP dada en orden ascendente\n";
        cout << "4. Recorrer nodos del árbol en Pre-Orden\n";
        cout << "5. Informar de la CP con más y menos paquetes\n";
        cout << "6. Buscar un paquete concreto por su ID\n";
        cout << "7. Extraer un paquete concreto de una CP dada\n";
        cout << "8. Llevar un paquete del CAE a una CP concreta\n";
        cout << "9. Llevar un paquete de una CP a otra\n";
        cout << "10. Mostrar paquetes en el CAE en orden descendente\n";
        cout << "11. Continuar con la distribución de paquetes\n";
        cout << "0. Salir del programa\n";
        cout << "Introduce tu opción: ";
}
void pressEnterToContinue(){
    do {
        cout << '\n' << "Press a key to continue...";
    }
    while (cin.get() != '\n');
}

int main() {
    srand(time(NULL));
    ArbolABB a;
    Lista CAE;
    int secuencia = 1;
    
    for (int i=0; i<N1; i++)//Crea las 8 centrales de paqueteria y las muestra por pantalla
        {
            CentralPaqueteria cp;
            cp.numCP = i+1;
            cp.localidad = localidades[i];
            a.insertarNodo(cp);
            
        }
    
    for (int i=0; i<N2; i++)
        {
            // Seleccionamos aleatoriamente uno de los numCp generados en el paso anterior
            Paquete p;
            p.numCP=0;
            p.ID = generador_id(secuencia);
            p.niDestinatario = generador_dni();
            p.latitud = generador_latitud();
            p.longitud = generador_longitud();
            CAE.insertarNodo(0, 'f', p);
        }
    
    CAE.recorrerLista(0); // recorre lista inicial
    
    int paso = 0;
    int r = N4;
    while (r!=0){
        cout << endl;
        cout << "DIAS (EJECUCIONES)::::::::::::. " << paso + 1  << endl;
        
        int w = N3;
        
        while (w!=0) {
            a.asignarCP(CAE.pasarCAEaCP());
            w--;
        }
        
        cout << "PAQUETES QUE QUEDAN EN CAE" << endl;
        CAE.recorrerLista(0); //se pone en 0 para el orden nada mas ASCENDENTE
        paso++;
        r=r-N3;
        pressEnterToContinue();
    }
         
    
    int op;
    system("color 0b");
    
    
    do {
        menu1(); cin >> op;
            
            switch (op)
            {
                case 1:{
                    int numero;
                    string local;
                    CentralPaqueteria cp;
                    cout <<endl;
                    cout << "Has elegido la opcion 1" << endl;
                    cout <<"Numero de CP deseado(Numero de tres cifras): "; // Insertar una CP de forma manual
                    cin >> numero; //Asigno el número de CP manual
                    cout <<"Escribe la localidad: ";
                    cin >> local;
                    
                    cp.numCP = numero;
                    cp.localidad = local;
                    
                    a.insertarNodo(cp);
                    cout << endl;
                    
                    break;
                }
                case 2:{
                    int numero;
                    cout <<endl;
                    cout << "Has elegido la opcion 2" << endl;
                    cout << "Lista de centrales disponibles: (postOrden)"<<endl;
                    cout <<endl;
                    a.postOrden(a.raiz);
                    cout <<endl;
                    cout << "Codigo de la central que desea eliminar: "; //Busco la central por su código
                    cin >> numero;
                    a.borrarNodo(numero);
                    cout << endl;
                    break;
                }
                case 3:{
                    int numCP;
                    cout << endl;
                    cout << "Has elegido la opción 3" << endl;

                    // Mostrar los códigos y localidades de todas las CPs
                    cout << "Lista de centrales disponibles:" << endl;
                    a.recorrerArbolDFS(a.raiz);

                    cout << "Ingresa el número de CP que deseas consultar: ";
                    cin >> numCP;

                    // Mostrar los paquetes en la CP seleccionada
                    a.mostrarPaquetesEnCP(numCP);
                     break;
                }
                case 4: {
                    cout << endl;
                    cout << "Has elegido la opción 4" << endl;
                    
                    // Obtiene el total de paquetes en el CAE
                    int totalPaquetesCAE = CAE.obtenerTotalPaquetes(); 

                    // Recorre el árbol en Pre-Orden y muestra la información de cada CP
                    a.preOrden(a.raiz, totalPaquetesCAE);
                    break;
                }
                case 5: {
                    cout << endl;
                    cout << "Has elegido la opción 5" << endl;

                    CPInfo masPaquetes;
                    masPaquetes.numPaquetes = INT_MIN;
                    CPInfo menosPaquetes;
                    menosPaquetes.numPaquetes = INT_MAX;

                    int totalCAE = CAE.obtenerTotalPaquetes();

                    a.informarCPMasMenosPaquetes(a.raiz, masPaquetes, menosPaquetes, totalCAE);

                    cout << "CP con más paquetes:\n";
                    cout << "CP: " << masPaquetes.numCP << ", Localidad: " << masPaquetes.localidad << ", Número de Paquetes: " << masPaquetes.numPaquetes << ", Porcentaje: " << masPaquetes.porcentaje << "%\n";

                    cout << "\nCP con menos paquetes:\n";
                    cout << "CP: " << menosPaquetes.numCP << ", Localidad: " << menosPaquetes.localidad << ", Número de Paquetes: " << menosPaquetes.numPaquetes << ", Porcentaje: " << menosPaquetes.porcentaje << "%\n";

                    break;
                }
                case 6: {
                    string id;
                    cout << "\nPor favor, introduce el ID del paquete que deseas buscar: ";
                    cin >> id;

                    // Buscar el paquete en el CAE
                    if(CAE.buscarPaquetePorID(id))
                        cout << "El paquete con ID " << id << " se encuentra en el Centro de Almacenamiento (CAE).\n";
                    else if(a.buscarPaquetePorID(a.raiz, id)) // Buscar el paquete en las CP
                        cout << "El paquete con ID " << id << " se encuentra en una Central de Paqueteria (CP).\n";
                    else
                        cout << "No se encontró ningún paquete con el ID " << id << ".\n";
                    break;
                }
                case 7:{
                    string id;
                    int numCP;
                    bool encontrado = false;
                    a.recorrerArbolDFS(a.raiz);
                    cout << "Ingresa el número de CP de donde quieres eliminar el paquete: ";
                    cin >> numCP;
                    a.mostrarPaquetesEnCP(numCP);
                    cout << "Ingresa el ID del paquete que quieres eliminar: ";
                    cin >> id;

                    // Borrar el paquete con el ID especificado
                    a.eliminarPaqueteCPDada2(a.raiz, id, numCP, encontrado);

                    if (encontrado) {
                        cout << "El paquete con el ID " << id << " ha sido eliminado de la CP " << numCP << ".\n";
                    } else {
                        cout << "No se encontró el paquete con el ID " << id << " en la CP " << numCP << ".\n";
                    }
                    break;
                }
                case 8:{
                    string id;
                    int numero;
                    cout << endl;
                    cout << "Has elegido la opcion 8" << endl;
                    cout <<endl;
                    cout << "Paquetes que aun quedan en la CAE" << endl;
                    cout << endl;
                    CAE.recorrerLista(0); // recordar el 0 es solo para orden de busqueda
                    cout << endl;
                    cout << "ID de Paquete que se quiere mover: ";
                    cin >> id;
                    a.recorrerArbolDFS(a.raiz);
                    cout << "Numero de CP al cual se movera el Paquete: ";
                    cin >> numero;
                    a.pasarCAEaCPdada(numero, id, CAE);
                    cout << endl;
                    break;
                }

                case 9: {
                    int numCP1, numCP2;
                    string id;
                    cout << "Has elegido la opcion 9" << endl;
                    a.recorrerArbolDFS(a.raiz);
                    cout << "Numero de CP desde el cual se movera el Paquete: ";
                    cin >> numCP1;
                    a.mostrarPaquetesEnCP(numCP1);
                    cout << "ID del paquete a pasar: ";
                    cin >> id;
                    cout << "Numero de CP al cual se movera el Paquete: ";
                    cin >> numCP2;
                    cout << endl;
                    a.mudarPaquete(numCP1, numCP2, id);
                    break;
                }
                case 10:{
                    cout << "\nListando paquetes en orden descendente por ID...\n";
                    a.actual->CP.lista.imprimirOrdenado();
                    break;
                }
                case 11: {
                    cout << "Has elegido la opcion 11" << endl;
                    
                    // En cada paso, se distribuirán N3 paquetes del CAE a las CPs
                    int w = N3;

                    while (w != 0 && !CAE.listaVacia()) {  
                        a.asignarCP(CAE.pasarCAEaCP());
                        w--;
                    }

                    cout << "PAQUETES QUE QUEDAN EN CAE" << endl;
                    CAE.recorrerLista(0);  // muestra los paquetes restantes en el CAE
                    break;
                }
                case 0:{
                    cout << "Has elegido la opcion 0" << endl;
                    cout << "PROGRAMA FINALIZADO" << endl;
 
                    break;}
            }
        cout<<endl<<endl;
        system("pause");  system("cls");

        }while(op!=0);
    
    system("pause");
    
            return 0;
}