#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

using namespace std;

// Nodos de la lista:

template <typename T>
class llnode {
public:
    // Esta clase es para ser usada por otras clases.
    // Por eficiencia los atributos se dejan publicos.
    T key;
    llnode<T> *prev, *next;
    //enum colors color;

    // Constructor por omision

    llnode() {
        prev = NULL; //Inicializa el nodo sin nodo anterior
        next = NULL; //Inicializa el nodo sin nodo siguiente
    };

    // Inicializacion de los datos miembro.

    llnode(const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL) : key(k), prev(w), next(y) {
    };

    ~llnode() {
    }
};

// Lista enlazada con nodo centinela:

template <typename T>
class llist {
public:

    llist() {
        nil = new llnode <T> (-1515151515); //Crea el nodo centinela
        nil->next = nil; //Se liga el nodo centinela con el mismo como siguiente
        nil->prev = nil; //Se liga el nodo centienela con el mismo como anterior
    }
    // Constructor (crea una lista vacia)

    llist(const llist<T>& obj) {
        llnode<T> *p = obj.nil->next; //Apunta al inicio de la lista original
        nil = new llnode <T> (obj.nil->key); //Crea la copia de nodo Centinela original
        //Se conecta a nil con el mismo
        nil->next = nil;
        nil->prev = nil;
        //Puntero al altimo nodo agregado
        llnode<T> *ultimoC = nil;

        if (p != obj.nil) { //Si a lista no esta vacia
            ultimoC = new llnode <T> (p->key); //Crea la copia del primer nodo de la lista orginal
            listInsert(ultimoC); //Agrega el nodo nuevo a la lista copia
            p = p->next; //Camino sobre la lista original

            while (p != obj.nil) { //Mientras no se acabe la lista original
                ultimoC = new llnode <T> (p->key); //Copia del nodo al que apunta p
                listInsert(ultimoC); //Agrega el nodo nuevo a la lista copia
                p = p -> next; //Camino sobre la lista original
                ultimoC = ultimoC->next; //Camino sobre la lista copia
            }
        }
    }
    // Constructor copia

    ~llist() {
        llnode<T> *destructor = nil->next; //Se coloca al inicio de la lista
        llnode<T> *destructorDos = destructor; // Se coloca a la par del nodo a borrar para no perder la referencia y seguir borrando

        while (destructor != nil) { //Mintras la lista no se acabe
            destructorDos = destructor->next; //Se mueve al nodo siguiente del que sera borrado para conservar la referencia
            delete destructor; //Borra el nodo donde estoy
            destructor = destructorDos; //Se  mueve al siguiente nodo a borrar
        }
        delete nil;
    }
    // Destructor (borra la lista)

    llnode<T>* listSearch(const T& k) {
        llnode<T> *buscador = nil->next; //Se coloca al inicio de la lista

        while ((buscador != nil) && (buscador->key != k)) {//Mientras la lista no se acabe y no se encuentre el elemento
            buscador = buscador->next; //Camine en la lista
        }

        if (buscador == nil) { //No se encontro el elemento
            return NULL;
        } else { //Si se encontro el elemento
            return buscador;
        }
    }
    // Busca la llave iterativamente. Si la encuentra, devuelve un 
    // apuntador al nodo que la contiene; sino devuelve NULL.

    void listInsert(llnode<T>* x) { //Inserta al final
        x->next = nil; //El siguiente del nuevo nodo(x) es nil
        x->prev = nil->prev; // El anterior del nuevo nodo(x) es el ultimo agregado antes que el
        nil->prev->next = x; //El siguiente del anterior de nil es el nuevo nodo(x)
        nil->prev = x; //El anterior de nil es el nuevo nodo(x) que queda al final de la lista

    };
    // Inserta el nodo x en la lista.

    llnode<T>* listDelete(llnode<T>* x) { //Se asume que el nodo ya fue buscado anteriormente ya que se recibe un puntero al nodo a borrar
        if (x == nil) { //Si el nodo no fue encontrado
            return NULL;
        } else { //Si el nodo si fue encontrado

            x->next->prev = x->prev; //Conecta el anterior del siguiente con el anterior de x
            x->prev->next = x->next; //Conecta el siguiente del anterior con el siguiente de x
            return x; //Devuelve un puntero a x
        }
    };
    // Saca de la lista la llave contenida en el nodo apuntado por x.
    // Devuelve la direccion del nodo eliminado para que se pueda 
    // disponer de el.

    llnode<T> * getNil() const {
        return this->nil;
    };
    // Devuelve el nodo centinela. (Para efectos de revision de la tarea).


    //EXTRA PARA PROBAR EN EL MAIN//

    void SA() {
        llnode<T> * p = nil->next;
        while (p != nil) {

            cout << "Hay un " << p->key << endl;
            if (p->next == nil) {
                cout << "El siguiente de " << p->key << " es nil" << endl;

            } else {
                cout << "El siguiente de " << p->key << " es " << p->next->key << endl;
            }

            if (p->prev == nil) {
                cout << "El anterior de " << p->key << " es nil" << endl;

            } else {
                cout << "El anterior de " << p->key << " es " << p->prev->key << endl;

            }
            p = p->next;
            cout << endl;
        }

    }

    void imprimirLista() {
        llnode<T> *p = nil->next;
        cout << "{ ";
        while (p != nil) {
            cout << p->key;
            if (p->next != nil) {
                cout << " , ";
            }
            p = p->next;
        }
        cout << " }" << endl;
    }

private:
    llnode<T> *nil; // nodo centinela

};

#endif // LINKED_LIST_llist
