/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Roberto Vargas <robertovargasrojas97@gmail.com>
 *
 * Created on 22 de abril de 2018, 07:27 PM
 */

#include <cstdlib>
#include <stack>
#include <iostream>
#include<time.h>
#include <random>

using namespace std;

#include "llist.h"
#include "bstree.h"
#include "rbtree.h"
#include "hasht.h" 

/*
 * 
 */


bool si_No(node<int> *nodo) {
    bool si = false;
    if (nodo == NULL) {
        cout << "No existe un " << nodo->key << " en el arbol" << endl;
    } else {
        cout << "El " << nodo->key << " fue encontrado" << endl;
        si = true;
    }
    return si;
}

int main(int argc, char** argv) {
    /*
        llist <int> lista;
        llnode<int> *nodo = new llnode<int>;

        for (int i = 0; i <= 100; i++) {
            lista.listInsert(new llnode <int> (i));
        }


        cout << "Lista" << endl;
        lista.imprimirLista();
        cout << endl;

        cout << "Copia de lista" << endl;
        llist <int> lista1(lista);
       lista1.imprimirLista();
        cout << endl;


        cout << "Buscar y Borrar" << endl;
        nodo = lista.listSearch(1);
        cout << "Se encontro y se borro un " << nodo->key << endl;
        lista.listDelete(nodo);

        nodo = lista.listSearch(3);
        cout << "Se encontro y se borro un " << nodo->key << endl;
        lista.listDelete(nodo);

        nodo = lista.listSearch(4);
        cout << "Se encontro y se borro un " << nodo->key << endl;
        lista.listDelete(nodo);

        nodo = lista.listSearch(5);
        cout << "Se encontro y se borro un " << nodo->key << endl;
        lista.listDelete(nodo);

        nodo = lista.listSearch(0);
        cout << "Se encontro y se borro un " << nodo->key << endl;
        lista.listDelete(nodo);

        cout << "lista luego de borrar" << endl;
       lista.imprimirLista();

        cout << endl;
        // lista.SA();
        cout << endl;
        cout << endl;

        cout << "Copia de lista" << endl;
       lista1.imprimirLista();
     */
    /*
        bool borrar = false;
        int nElemntos = 0;
        cout << "Ingrese la cantidad de elementos" << endl;
        cin >> nElemntos;
        stack <int> pila;
        tree <int> arbol;
        for (int i = 0; i <= nElemntos; i++) {
            arbol.treeInsert(new node <int> (i));
        }

        arbol.inorderTreeWalk(arbol.getRoot(), pila);

        for (int i = 0; i <= nElemntos; i++) {
            cout << pila.top() << " ";
            pila.pop();
        }

        cout << endl << endl;
        cout << "Busqueda en arbol" << endl;



        node<int> *nodo = arbol.treeSearch(6);
        node<int> *b;

        borrar = si_No(nodo);
        if (borrar == true) {
            b = arbol.treeDelete(nodo);
            cout << "Se borro el  " << b->key << endl;
        } else {
            cout << "El nodo con " << "6" << " No existe en el arbol" << endl;
        }

        nodo = arbol.iterativeTreeSearch(14);
        b = arbol.treeSuccessor(nodo);
        if (b != NULL) {
            cout << "El sucesor de " << nodo->key << " es " << b->key << endl;
        } else {
            cout << "No existe";
        }
    
        nodo = arbol.iterativeTreeSearch(1);
        borrar = si_No(nodo);
        if (borrar == true) {
            b = arbol.treeDelete(nodo);
            cout << "Se borro el  " << b->key << endl;
        } else {
            cout << "El nodo con " << nodo->key << " No existe en el arbol" << endl;
        }

        nodo = arbol.iterativeTreeSearch(50);

        //if (nodo != NULL) {
            arbol.treeDelete(nodo);
       // } else {
            cout << "El nodo con " << "50" << " No existe en el arbol" << endl;
       // }

        nodo = arbol.iterativeTreeSearch(3);
        borrar = si_No(nodo);
        if (borrar == true) {
            b = arbol.treeDelete(nodo);
            cout << "Se borro el  " << b->key << endl;
        } else {
            cout << "El nodo con " << "3 " << " No existe en el arbol" << endl;
        }

        nodo = arbol.treeMaximum();
        cout << "El maximo es " << nodo->key << endl;

        nodo = arbol.treeMinimum();
        cout << "El minimo es " << nodo->key << endl;
  
     */

    /*
        //-----------------------------------INICIA PRUEBA DE LISTA--------------------------------------//
        llist <int> lista;
        llist <int> lista2;
        llnode<int> *nodo;

        int nElemntos = 0;
        cout << "Ingrese la cantidad de elementos" << endl;
        cin >> nElemntos;
        int numero = 0;

        int busquedas_realizadas = 0;
        int bE = 0, bF = 0;
        double tiempo = 0, t1 = 0, t2 = 0;

        random_device rd;
        mt19937 gen(rd());
        srand(time(NULL));
        uniform_real_distribution<> distribution(0, 2000000);

        
                cout << "Agregados aleatoriamente" << endl;
                for (int i = 0; i < nElemntos; i++) {
                    numero = distribution(gen);
                    lista.listInsert(new llnode <int> (numero));
                }
                cout << endl << endl;

                srand(time(NULL));
                cout << "Para buscar en list creada aleatoriamente" << endl;
                while (tiempo <= 10) {
                    numero = (rand()*50) % 2000000;
                    t1 = clock();
                    nodo = lista.listSearch(numero);
                    t2 = clock();
                    tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

                    if (nodo != NULL) {
                        bE++;
                    } else {
                        bF++;
                    }
                    busquedas_realizadas++;
                }

                cout << "Hay " << bE << " busquedas efectivas" << endl;
                cout << "Hay " << bF << " busquedas fallidas" << endl;
                cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;
     
     */

    /*
            cout << "Agregados en orden" << endl;
            for (int i = 0; i < nElemntos; i++) {
                lista2.listInsert(new llnode <int> (i));
            }

            cout << "Para buscar en lista creada en orden" << endl;
            while (tiempo <= 10) {
                numero = (rand()*50) % 2000000;
                t1 = clock();
                nodo = lista2.listSearch(numero);
                t2 = clock();
                tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

                if (nodo != NULL) {
                    bE++;
                } else {
                    bF++;
                }
                busquedas_realizadas++;
            }

            cout << "Hay " << bE << " busquedas efectivas" << endl;
            cout << "Hay " << bF << " busquedas fallidas" << endl;
            cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;

     */

    /*
        //-----------------------------------INICIA PRUEBA DE ARBOL-------------------------------------//

        int nElemntos = 0;
        cout << "Ingrese la cantidad de elementos" << endl;
        cin >> nElemntos;
        stack <int> pila;
        tree <int> arbol;
        node <int> *nodo;

        int numero = 0;
        int busquedas_realizadas = 0;
        int bE = 0, bF = 0;
        double tiempo = 0, t1 = 0, t2 = 0;

        random_device rd;
        mt19937 gen(rd());
        srand(time(NULL));
        uniform_real_distribution<> distribution(0, 2000000);


        cout << "Agregados secuencial" << endl;
        for (int i = 0; i < nElemntos; i++) {
            arbol.agregarSecuencial(new node <int> (i));
            //cout << i << endl;
        }
        cout << endl << endl;

        srand(time(NULL));
        cout << "Para buscar en arbol creado secuencialmente" << endl;
        while (tiempo <= 10) {
            numero = (rand()*61) % 2000000;
            t1 = clock();
            nodo = arbol.iterativeTreeSearch(numero);
            t2 = clock();
            tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

            if (nodo != NULL) {
                bE++;
            } else {
                bF++;
            }
            busquedas_realizadas++;
        }

        cout << "Hay " << bE << " busquedas efectivas" << endl;
        cout << "Hay " << bF << " busquedas fallidas" << endl;
        cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;


     */
    /*
       cout << "Agregados aleatoriamente" << endl;
       for (int i = 0; i < nElemntos; i++) {
           numero = distribution(gen);
           arbol.treeInsert(new node <int> (numero));
       }
       cout << endl << endl;

       srand(time(NULL));
       cout << "Para buscar en arbol creado aleatoriamente" << endl;
       while (tiempo <= 10) {
           numero = (rand()*50) % 2000000;
           t1 = clock();
           nodo = arbol.treeSearch(numero);
           t2 = clock();
           tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

           if (nodo != NULL) {
               bE++;
           } else {
               bF++;
           }
           busquedas_realizadas++;
       }

       cout << "Hay " << bE << " busquedas efectivas" << endl;
       cout << "Hay " << bF << " busquedas fallidas" << endl;
       cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;
     */


/*
    //-----------------------------------INICIA PRUEBA DE ARBOL ROJI-NEGRO-------------------------------------//
    int nElemntos = 0;
    cout << "Ingrese la cantidad de elementos" << endl;
    cin >> nElemntos;
    stack <int> pila;
    rbtree <int> arbolRB;
    rbnode <int> *nodo;

    int numero = 0;
    int busquedas_realizadas = 0;
    int bE = 0, bF = 0;
    double tiempo = 0, t1 = 0, t2 = 0;

    random_device rd;
    mt19937 gen(rd());
    srand(time(NULL));
    uniform_real_distribution<> distribution(0, 2000000);
*/

    /*
        cout << "Agregados aleatoriamente" << endl;
        for (int i = 0; i < nElemntos; i++) {
            numero = distribution(gen);
            arbolRB.treeInsert(new rbnode <int> (numero));
            //cout << "Se inserto un " << numero << endl;

        }
        cout << endl << endl;

        srand(time(NULL));
        cout << "Para buscar en arbol creado aleatoriamente" << endl;
        while (tiempo <= 10) {
            numero = (rand()*50) % 2000000;
            t1 = clock();
            nodo = arbolRB.iterativeTreeSearch(numero);
            t2 = clock();
            tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

            if (nodo != NULL) {
                bE++;
            } else {
                bF++;
            }
            busquedas_realizadas++;
        }

        cout << "Hay " << bE << " busquedas efectivas" << endl;
        cout << "Hay " << bF << " busquedas fallidas" << endl;
        cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;


     */



    /*
        cout << "Agregados secuencial" << endl;
        for (int i = 0; i < nElemntos; i++) {
            arbolRB.treeInsert(new rbnode <int> (i));

        }
        cout << endl << endl;

        srand(time(NULL));
        cout << "Para buscar en arbol creado secuencialmente" << endl;
        while (tiempo <= 10) {
            numero = (rand()*50) % 2000000;
            t1 = clock();
            nodo = arbolRB.iterativeTreeSearch(numero);
            t2 = clock();
            tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

            if (nodo != NULL) {
                bE++;
            } else {
                bF++;
            }
            busquedas_realizadas++;
        }

        cout << "Hay " << bE << " busquedas efectivas" << endl;
        cout << "Hay " << bF << " busquedas fallidas" << endl;
        cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;

     */

    /*
    
        for (int i = 1; i <= nElemntos; i++) {
            arbolRB.treeInsert(new rbnode <int> (i));
        }

        arbolRB .inorderTreeWalk(arbolRB.getRoot(), pila);
        int a = pila.size();

        for (int i = 0; i < a; i++) {
            cout << "Color: ";
            if (pila.top() == 0) {
                cout << "RED  ,";
            } else if (pila.top() == 1) {
                cout << "BLACK,";
            }

            pila.pop();
            cout << " Llave: ";
            cout << pila.top();
            pila.pop();
            cout << " " << endl;
            i++;

        }
        cout << endl;
        cout << endl;


        cout << "Copia del arbol" << endl;
        rbtree <int> arbolRBCopia(arbolRB);

        arbolRBCopia .inorderTreeWalk(arbolRBCopia .getRoot(), pila);
        a = pila.size();

        for (int i = 0; i < a; i++) {
            cout << "Color: ";
            if (pila.top() == 0) {
                cout << "RED  ,";
            } else if (pila.top() == 1) {
                cout << "BLACK,";
            }

            pila.pop();
            cout << " Llave: ";
            cout << pila.top();
            pila.pop();
            cout << " " << endl;
            i++;
        }
     */


    /*
        //-----------------------------------INICIA PRUEBA DE HASH------------------------------------//
        int nElemntos = 0;
        cout << "Ingrese la cantidad de elementos de la tabla" << endl;
        cin >> nElemntos;
        hasht <int> tablita(nElemntos);
        int * ptr = NULL;
        int nItems = 0;
        cout << "Ingrese cuantos elementos desea agregar" << endl;
        cin >> nItems;


        int numero = 0;
        int busquedas_realizadas = 0;
        int bE = 0, bF = 0;
        double tiempo = 0, t1 = 0, t2 = 0;

        random_device rd;
        mt19937 gen(rd());
        srand(time(NULL));
        uniform_real_distribution<> distribution(0, 2000000);



        cout << "Agregados aleatoriamente" << endl;
        for (int i = 0; i < nElemntos; i++) {
            numero = distribution(gen);
            tablita.insert(numero);
        }
        cout << endl << endl;


        srand(time(NULL));
        cout << "Para buscar en arbol creado aleatoriamente" << endl;
        while (tiempo <= 10) {
            numero = (rand()*50) % 2000000;
            t1 = clock();
            ptr = tablita.search(numero);
            t2 = clock();
            tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

            if (ptr != NULL) {
                bE++;
            } else {
                bF++;
            }
            busquedas_realizadas++;
        }

        cout << "Hay " << bE << " busquedas efectivas" << endl;
        cout << "Hay " << bF << " busquedas fallidas" << endl;
        cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;
     */


    /*
        cout << "Agregados secuencial" << endl;
        for (int i = 0; i < nElemntos; i++) {
            tablita.insert(i);

        }
        cout << endl << endl;

        srand(time(NULL));
        cout << "Para buscar en arbol creado secuencialmente" << endl;
        while (tiempo <= 10) {
            numero = (rand()*50) % 2000000;
            // cout << numero << endl;
            t1 = clock();
            ptr = tablita.search(numero);
            t2 = clock();
            tiempo = tiempo + ((double(t2 - t1) / CLOCKS_PER_SEC));

            if (ptr != NULL) {
                bE++;
            } else {
                bF++;
            }
            busquedas_realizadas++;
        }

        cout << "Hay " << bE << " busquedas efectivas" << endl;
        cout << "Hay " << bF << " busquedas fallidas" << endl;
        cout << "Hay " << busquedas_realizadas << " busquedas en total en " << tiempo << " seg" << endl;


     */




    /*
    tablita.Imprimir();
    int * k = tablita.search(5);
    cout << endl;
    cout << endl;

    if (k != NULL) {
        cout << "Se encontro un " << *k;
    }
    cout << endl;
    cout << endl;

    k = tablita.search(9);
    if (k != NULL) {
        cout << "Se encontro un " << *k;
    } else {
        cout << "No se encontro un " << 9;
    }
    cout << endl;
    cout << endl;


    cout << "Copia de tabla" << endl;
    hasht <int> tablitaCopia(tablita);
    tablitaCopia.Imprimir();
     */
    return 0;
}

