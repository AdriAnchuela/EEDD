//
//  main_prueba.cpp
//  EEDD
//
//  Created by Adrian Anchuela  on 27/10/22.
//
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include <stdio.h>
#include "paquetes.h"


using namespace std;

#define N1 100
#define N2 10
#define N3 5

Coordenadas generador_latitud();
Coordenadas generador_longitud();
string generador_id();
string generador_dni();
int mayor (int ,int );
int elmayor(int, int , int ,int );

void pressEnterToContinue(){
    do {
        cout << '\n' << "Press a key to continue...";
    }
    while (cin.get() != '\n');
}

int main(){
    Cola colaIn, colaNO, colaNE, colaSO, colaSE, colaZRNO, colaZRNE, colaZRSO, colaZRSE;
    Pila pilaNO, pilaNE, pilaSO, pilaSE,pilaAUXNO, pilaAUXNE, pilaAUXSO, pilaAUXSE, pilaAUX2NO, pilaAUX2NE, pilaAUX2SO, pilaAUX2SE;
    
    Paquetes paq, paq1,paq2,paq3,paq4;
    
    string c1,c2;
    int i, paso = 0;
    int len_cola_max = 0, suma_colas=0;
    int len_cola2_max=0, suma_colas2=0;
    int len_pila_max=0, suma_pilas=0;
    int len_pilaNO =0, len_pilaNE = 0, len_pilaSO=0, len_pilaSE=0;
    int len_pilaAUXNO =0, len_pilaAUXNE = 0, len_pilaAUXSO=0, len_pilaAUXSE=0;
    
    int nNO=0, nNE=0, nSO=0, nSE=0, lencolaT=0;
    
    int n1 = 1, n2 =1, n3 =1, n4 =1;
    
    Paquetes paq_null = {"", NULL,NULL,NULL};
    
    srand(time(NULL));  //resetea los randoms para que sean valores totalmente aleatorios
    
    for (i=0; i<N1; i++){
        paq.identificacion = generador_id();
        paq.latitud = generador_latitud();
        paq.longitud = generador_longitud();
        paq.nifC = generador_dni();
        colaIn.encolar(paq);
    }
    
    
    while (suma_colas2 != N1){
        
        
        cout << endl;
        cout << "PASO DE EJECUCION::::::::::::. " << paso + 1  << endl;
        
        if (paso == 0){
            cout << "COLA INICIAL::::::::::::. " << endl;
            colaIn.recorrerCola();
            
            
            
            cout << endl;
        } //end paso 0
        
        if ( paso >=1 ){
            
            for (i=0; i<N2; i++){
                paq1 = colaIn.desencolar();
                if (paq1.latitud.minutos>=49 && paq1.longitud.minutos>=37){
                    colaNO.encolar(paq1);
                    nNO++;
                    lencolaT++;
                }
                else if (paq1.latitud.minutos>=49 && paq1.longitud.minutos<37){
                    colaNE.encolar(paq1);
                    nNE++;
                    lencolaT++;
                }
                else if (paq1.latitud.minutos<49 && paq1.longitud.minutos>=37){
                    colaSO.encolar(paq1);
                    nSO++;
                    lencolaT++;
                }
                else if (paq1.latitud.minutos<49 && paq1.longitud.minutos<37 && paq1.latitud.minutos!=0 && paq1.longitud.minutos !=0){
                    colaSE.encolar(paq1);
                    nSE++;
                    lencolaT++;
                }
            }
            
            cout << "El "<< (nNO*100)/lencolaT << "% de paquetes han ido al Noroeste"<< endl;
            cout << "El "<< (nNE*100)/lencolaT << "% de paquetes han ido al Noreste"<< endl;
            cout << "El "<< (nSO*100)/lencolaT << "% de paquetes han ido al Suroeste"<< endl;
            cout << "El "<< (nSE*100)/lencolaT << "% de paquetes han ido al Sureste"<< endl;
            cout << lencolaT << endl;
            
          /*  cout << nNO << endl;
            cout << nNE << endl;
            cout << nSO << endl;
            cout << nSE << endl;
            cout << lencolaT << endl;*/
            
            cout << endl;
            
            len_cola_max= elmayor(colaNO.lenCola(), colaNE.lenCola(), colaSO.lenCola(), colaSE.lenCola());
            suma_colas= colaNO.lenCola() + colaNE.lenCola() + colaSO.lenCola() + colaSE.lenCola();
            
            cout << "PAQUETES EN MUELLES::::::::::." << suma_colas << endl << endl;
            
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(35) << "MUELLE ZONA NO:" << "||" << setw(35) << "MUELLE ZONA NE:" << "||" << setw(35) << "MUELLE ZONA SO:" << "||" << setw(35) << "MUELLE ZONA SE:" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            
            for (i=0; i < len_cola_max; i++){
                if (i < colaNO.lenCola()){
                    paq1 = colaNO.desencolar();}
                else{
                    paq1 = paq_null;}
                
                if (i < colaNE.lenCola()){
                    paq2 = colaNE.desencolar();}
                else{
                    paq2 = paq_null;}
                
                if (i < colaSO.lenCola()){
                    paq3 = colaSO.desencolar();}
                else{
                    paq3 = paq_null;}
                
                if (i < colaSE.lenCola()){
                    paq4 = colaSE.desencolar();}
                else{
                    paq4 = paq_null;}
                
                
                
                cout << setw(7) << paq1.identificacion << "|" << setw(3) << paq1.latitud.grados << setw(3) << paq1.latitud.minutos << setw(2) << paq1.latitud.segundos << "|" << setw (3) << paq1.longitud.grados << setw (3) << paq1.longitud.minutos << setw (2) << paq1.longitud.segundos << "|" << setw (9) <<paq1.nifC << "||"
                << setw(7) << paq2.identificacion << "|" << setw(3) << paq2.latitud.grados << setw(3) << paq2.latitud.minutos << setw(2) << paq2.latitud.segundos << "|" << setw (3) << paq2.longitud.grados << setw (3) << paq2.longitud.minutos << setw (2) << paq2.longitud.segundos << "|" << setw (9) <<paq2.nifC << "||"
                << setw(7) << paq3.identificacion << "|" << setw(3) << paq3.latitud.grados << setw(3) << paq3.latitud.minutos << setw(2) << paq3.latitud.segundos << "|" << setw (3) << paq3.longitud.grados << setw (3) << paq3.longitud.minutos << setw (2) << paq3.longitud.segundos << "|" << setw (9) <<paq3.nifC << "||"
                << setw(7) << paq4.identificacion << "|" << setw(3) << paq4.latitud.grados << setw(3) << paq4.latitud.minutos << setw(2) << paq4.latitud.segundos << "|" << setw (3) << paq4.longitud.grados << setw (3) << paq4.longitud.minutos << setw (2) << paq4.longitud.segundos << "|" << setw (9) <<paq4.nifC <<  endl ;
                
                
                if (i <= colaNO.lenCola()){
                    if (paq1.identificacion != paq_null.identificacion){
                        colaNO.encolar(paq1);}
                }
                if (i <= colaNE.lenCola()){
                    if (paq2.identificacion != paq_null.identificacion){
                        colaNE.encolar(paq2);}
                }
                if (i <= colaSO.lenCola()){
                    if (paq3.identificacion != paq_null.identificacion){
                        colaSO.encolar(paq3);}
                }
                if (i <= colaSE.lenCola()){
                    if (paq4.identificacion != paq_null.identificacion){
                        colaSE.encolar(paq4);}
                }
            }
        } // end if paso 1 cola
        paso ++;
        pressEnterToContinue();
        
        if ( paso >=2 ){
                        
            if (colaNO.lenCola() >= N3){
                for (i=0; i < N3; i++){
                    paq1=colaNO.desencolar();
                    pilaNO.apilar(paq1);}}
            if (colaNE.lenCola() >= N3){
                for (i=0; i < N3; i++){
                    paq2=colaNE.desencolar();
                    pilaNE.apilar(paq2);}}
            if (colaSO.lenCola() >= N3){
                for (i=0; i < N3; i++){
                    paq3=colaSO.desencolar();
                    pilaSO.apilar(paq3);}}
            if (colaSE.lenCola() >= N3){
                for (i=0; i <N3; i++){
                    paq4=colaSE.desencolar();
                    pilaSE.apilar(paq4);}}
            
            cout << endl;
            
            len_pila_max = elmayor(pilaNO.lenPila(), pilaNE.lenPila(), pilaSO.lenPila(), pilaSE.lenPila());
            suma_pilas = pilaNO.lenPila() + pilaNE.lenPila() + pilaSO.lenPila() + pilaSE.lenPila();
            len_pilaNO = pilaNO.lenPila();
            len_pilaNE = pilaNE.lenPila();
            len_pilaSO = pilaSO.lenPila();
            len_pilaSE = pilaSE.lenPila();
            

            cout << "FURGONETAS EN MUELLES::::::::::." << suma_pilas << endl << endl;
            
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(12) << "FURGONETA " << n1 << " EN ZONA DE MUELLE NO:" << "||" << setw(12) << "FURGONETA "<< n2 <<" EN ZONA DE MUELLE NE:" << "||" << setw(12) << "FURGONETA "<<n3<<" EN ZONA DE MUELLE SO:" << "||" << setw(12) << "FURGONETA "<<n4 <<" EN ZONA DE MUELLE SE:" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        
            for (i=0; i < len_pila_max; i++){
                if (i < len_pilaNO){
                    paq1 = pilaNO.desapilar();}
                else{
                    paq1 = paq_null;}
                if (i < len_pilaNE){
                    paq2 = pilaNE.desapilar();}
                else{
                    paq2 = paq_null;}
                
                if (i < len_pilaSO){
                    paq3 = pilaSO.desapilar();}
                else{
                    paq3 = paq_null;}
                
                if (i < len_pilaSE){
                    paq4 = pilaSE.desapilar();}
                else{
                    paq4 = paq_null;}
                
                cout << setw(7) << paq1.identificacion << "|" << setw(3) << paq1.latitud.grados << setw(3) << paq1.latitud.minutos << setw(2) << paq1.latitud.segundos << "|" << setw (3) << paq1.longitud.grados << setw (3) << paq1.longitud.minutos << setw (2) << paq1.longitud.segundos << "|" << setw (9) <<paq1.nifC << "||"
                << setw(7) << paq2.identificacion << "|" << setw(3) << paq2.latitud.grados << setw(3) << paq2.latitud.minutos << setw(2) << paq2.latitud.segundos << "|" << setw (3) << paq2.longitud.grados << setw (3) << paq2.longitud.minutos << setw (2) << paq2.longitud.segundos << "|" << setw (9) <<paq2.nifC << "||"
                << setw(7) << paq3.identificacion << "|" << setw(3) << paq3.latitud.grados << setw(3) << paq3.latitud.minutos << setw(2) << paq3.latitud.segundos << "|" << setw (3) << paq3.longitud.grados << setw (3) << paq3.longitud.minutos << setw (2) << paq3.longitud.segundos << "|" << setw (9) <<paq3.nifC << "||"
                << setw(7) << paq4.identificacion << "|" << setw(3) << paq4.latitud.grados << setw(3) << paq4.latitud.minutos << setw(2) << paq4.latitud.segundos << "|" << setw (3) << paq4.longitud.grados << setw (3) << paq4.longitud.minutos << setw (2) << paq4.longitud.segundos << "|" << setw (9) <<paq4.nifC <<  endl ;
                
                if (i < len_pilaNO){
                    if (paq1.identificacion != paq_null.identificacion){
                        pilaAUXNO.apilar(paq1);}
                }
                if (i < len_pilaNE){
                    if (paq2.identificacion != paq_null.identificacion){
                        pilaAUXNE.apilar(paq2);}
                    
                }
                if (i < len_pilaSO){
                    if (paq3.identificacion != paq_null.identificacion){
                        pilaAUXSO.apilar(paq3);}
                }
                if (i < len_pilaSE){
                    if (paq4.identificacion != paq_null.identificacion){
                        pilaAUXSE.apilar(paq4);}
                }
            }
            
        }//end if paso 2 furgonetas muelles
        
        pressEnterToContinue();
        
        
        if (paso >=2 ){
            
            cout << endl;
            
            len_pila_max = elmayor(pilaAUXNO.lenPila(),pilaAUXNE.lenPila(),pilaAUXSO.lenPila(),pilaAUXSE.lenPila());
            suma_pilas = pilaAUXNO.lenPila() + pilaAUXNE.lenPila() + pilaAUXSO.lenPila() + pilaAUXSE.lenPila();
            len_pilaAUXNO = pilaAUXNO.lenPila();
            len_pilaAUXNE = pilaAUXNE.lenPila();
            len_pilaAUXSO = pilaAUXSO.lenPila();
            len_pilaAUXSE = pilaAUXSE.lenPila();
            
            cout << "FURGONETAS DE REPARTOOOOO::::::::::."<< suma_pilas << endl << endl;
            
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(19) << "FURGONETA " << n1 << " DE REPARTO NO:" << "||" << setw(19) << "FURGONETA " << n2 << " DE REPARTO NE:" << "||" << setw(19) << "FURGONETA " << n3 << " DE REPARTO SO:" << "||" << setw(19) << "FURGONETA " << n4 << " DE REPARTO SE:" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            
            
            for (i=0; i < len_pila_max; i++){
                if (i < len_pilaAUXNO){
                    paq1 = pilaAUXNO.desapilar();}
                else{
                    paq1 = paq_null;}
                if (i < len_pilaAUXNE){
                    paq2 = pilaAUXNE.desapilar();}
                else{
                    paq2 = paq_null;}
                
                if (i < len_pilaAUXSO){
                    paq3 = pilaAUXSO.desapilar();}
                else{
                    paq3 = paq_null;}
                
                if (i < len_pilaAUXSE){
                    paq4 = pilaAUXSE.desapilar();}
                else{
                    paq4 = paq_null;}
                
                cout << setw(7) << paq1.identificacion << "|" << setw(3) << paq1.latitud.grados << setw(3) << paq1.latitud.minutos << setw(2) << paq1.latitud.segundos << "|" << setw (3) << paq1.longitud.grados << setw (3) << paq1.longitud.minutos << setw (2) << paq1.longitud.segundos << "|" << setw (9) <<paq1.nifC << "||"
                << setw(7) << paq2.identificacion << "|" << setw(3) << paq2.latitud.grados << setw(3) << paq2.latitud.minutos << setw(2) << paq2.latitud.segundos << "|" << setw (3) << paq2.longitud.grados << setw (3) << paq2.longitud.minutos << setw (2) << paq2.longitud.segundos << "|" << setw (9) <<paq2.nifC << "||"
                << setw(7) << paq3.identificacion << "|" << setw(3) << paq3.latitud.grados << setw(3) << paq3.latitud.minutos << setw(2) << paq3.latitud.segundos << "|" << setw (3) << paq3.longitud.grados << setw (3) << paq3.longitud.minutos << setw (2) << paq3.longitud.segundos << "|" << setw (9) <<paq3.nifC << "||"
                << setw(7) << paq4.identificacion << "|" << setw(3) << paq4.latitud.grados << setw(3) << paq4.latitud.minutos << setw(2) << paq4.latitud.segundos << "|" << setw (3) << paq4.longitud.grados << setw (3) << paq4.longitud.minutos << setw (2) << paq4.longitud.segundos << "|" << setw (9) <<paq4.nifC <<  endl ;
                
                if (i < len_pilaAUXNO){
                    if (paq1.identificacion != paq_null.identificacion){
                        colaZRNO.encolar(paq1);;}
                }
                if (i < len_pilaAUXNE){
                    if (paq2.identificacion != paq_null.identificacion){
                        colaZRNE.encolar(paq2);;}
                    
                }
                if (i < len_pilaAUXSO){
                    if (paq3.identificacion != paq_null.identificacion){
                        colaZRSO.encolar(paq3);;}
                }
                if (i < len_pilaAUXSE){
                    if (paq4.identificacion != paq_null.identificacion){
                        colaZRSE.encolar(paq4);;}
                }

            }
            if (len_pilaAUXNO >= 5){
                n1++;
            }
            if (len_pilaAUXNE >= 5){
                n2++;
            }
            if (len_pilaAUXSO >= 5){
                n3++;
            }
            if (len_pilaAUXSE >= 5){
                n4++;
            }
        } //end paso 2 furgoetas de reparto

        pressEnterToContinue();
        
        if (paso >=2 ){
            
            cout << endl;

            
            len_cola2_max= elmayor(colaZRNO.lenCola(), colaZRNE.lenCola(), colaZRSO.lenCola(), colaZRSE.lenCola());
            suma_colas2= colaZRNO.lenCola() + colaZRNE.lenCola() + colaZRSO.lenCola() + colaZRSE.lenCola();
            
            cout << "ZONA DE REPARTO FINAL::::::::::." << suma_colas2 << endl << endl;
            
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(35) << "ZONA DE REPARTO NO:" << "||" << setw(35) << "ZONA DE REPARTO NE:" << "||" << setw(35) << "ZONA DE REPARTO SO:" << "||" << setw(35) << "ZONA DE REPARTO SE:" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << "||"
            << setw(7) << "ID" << "|" << setw(8) << "LATITUD" << "|" << setw (8) << "LONGITUD" << "|" << setw (9) <<"NIF DESTI" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
          
            
            for (i=0; i < len_cola2_max; i++){
                if (i < colaZRNO.lenCola()){
                    paq1 = colaZRNO.desencolar();}
                else{
                    paq1 = paq_null;}
                
                if (i < colaZRNE.lenCola()){
                    paq2 = colaZRNE.desencolar();}
                else{
                    paq2 = paq_null;}
                
                if (i < colaZRSO.lenCola()){
                    paq3 = colaZRSO.desencolar();}
                else{
                    paq3 = paq_null;}
                
                if (i < colaZRSE.lenCola()){
                    paq4 = colaZRSE.desencolar();}
                else{
                    paq4 = paq_null;}
                
                cout << setw(7) << paq1.identificacion << "|" << setw(3) << paq1.latitud.grados << setw(3) << paq1.latitud.minutos << setw(2) << paq1.latitud.segundos << "|" << setw (3) << paq1.longitud.grados << setw (3) << paq1.longitud.minutos << setw (2) << paq1.longitud.segundos << "|" << setw (9) <<paq1.nifC << "||"
                << setw(7) << paq2.identificacion << "|" << setw(3) << paq2.latitud.grados << setw(3) << paq2.latitud.minutos << setw(2) << paq2.latitud.segundos << "|" << setw (3) << paq2.longitud.grados << setw (3) << paq2.longitud.minutos << setw (2) << paq2.longitud.segundos << "|" << setw (9) <<paq2.nifC << "||"
                << setw(7) << paq3.identificacion << "|" << setw(3) << paq3.latitud.grados << setw(3) << paq3.latitud.minutos << setw(2) << paq3.latitud.segundos << "|" << setw (3) << paq3.longitud.grados << setw (3) << paq3.longitud.minutos << setw (2) << paq3.longitud.segundos << "|" << setw (9) <<paq3.nifC << "||"
                << setw(7) << paq4.identificacion << "|" << setw(3) << paq4.latitud.grados << setw(3) << paq4.latitud.minutos << setw(2) << paq4.latitud.segundos << "|" << setw (3) << paq4.longitud.grados << setw (3) << paq4.longitud.minutos << setw (2) << paq4.longitud.segundos << "|" << setw (9) <<paq4.nifC <<  endl ;
                
                
                if (i <= colaZRNO.lenCola()){
                    if (paq1.identificacion != paq_null.identificacion){
                        colaZRNO.encolar(paq1);}
                }
                if (i <= colaZRNE.lenCola()){
                    if (paq2.identificacion != paq_null.identificacion){
                        colaZRNE.encolar(paq2);}
                }
                if (i <= colaZRSO.lenCola()){
                    if (paq3.identificacion != paq_null.identificacion){
                        colaZRSO.encolar(paq3);}
                }
                if (i <= colaZRSE.lenCola()){
                    if (paq4.identificacion != paq_null.identificacion){
                        colaZRSE.encolar(paq4);}
                }
            }
        }//end paso 2 zonas finales
        pressEnterToContinue();
        
        cout << endl;
        
        cout << "COLA INICIAL::::::::::::. " << endl;
        
        colaIn.recorrerCola();
        
        cout << endl;
        
        pressEnterToContinue();
    }//end while
    
    /*
     
     */
    /*
     
     
     cout << "COLA DESENCOLADA NO::::::::::::. " << endl;
     colaNO.recorrerCola();
     cout << "COLA DESENCOLADA NE::::::::::::. " << endl;
     colaNE.recorrerCola();
     cout << "COLA DESENCOLADA SO::::::::::::. " << endl;
     colaSO.recorrerCola();
     cout << "COLA DESENCOLADA SE::::::::::::. " << endl;
     colaSE.recorrerCola();
     */
    return 0;
    
    
}
