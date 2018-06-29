#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>

using namespace std;
// Nodos del arbol:

template <typename T>
class node {
public:
    // Esta clase es usada por otras clases.
    // Para mayor eficiencia, los atributos se hacen publicos.
    T key;
    node<T> *p, *left, *right;

    // Constructor por omision

    node() {
        p = NULL;
        left = NULL;
        right = NULL;
    };

    // Constructor por copia. Copia el nodo y sus hijos.

    node(const node<T> * obj, node<T> * padre) { //Se toma como nodo orignal obj
        if (obj->left == NULL && obj->right == NULL) { //Si el original no tiene hijos
            padre->left = NULL;
            padre->right = NULL;
            //El copia tampoco tiene hijos
        } else { //El original tiene 1 o 2 hijos

            if ((obj->left != NULL) && (obj->right != NULL)) { //Si el original tiene los dos hijos
                padre->left = new node<T>(obj->left->key); //Crea un nodo igual al hijo izquierdo del original
                padre->right = new node<T>(obj->right->key); //Crea un nodo igual al hijo derecho del original
            } else if ((obj->left != NULL) && (obj->right == NULL)) { //Si el original tiene hijo izquierdo,pero no derecho
                padre->left = new node<T>(obj->left->key); //Crea un nodo igual al hijo izquierdo del original
                padre->right = NULL;
            } else if ((obj->left == NULL) && (obj->right != NULL)) { //Si el original tiene hijo derecho,pero no izquierdo
                padre->left = NULL;
                padre->right = new node<T>(obj->right->key); //Crea un nodo igual al hijo derecho del original
            }

        }
    }

    // Inicializacion de datos miembro

    node(const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL) : key(k), p(w), left(y), right(z) {
    };

    ~node() {
    }
};

// Arbol:

template <typename T>
class tree {
public:

    tree() {
        root = NULL; //La raiz apunta a nulo 
    }
    // Constructor. Crea un arbol vacio

    tree(const tree<T>& obj) {
        copy(this->root, obj.getRoot()); //Metodo privado
    }
    // Constructor copia

    ~tree() {
        if (this->root != NULL) {
            borrarArbol(root);
        }
    }
    // Destructor (borra el arbol)

    void inorderTreeWalk(node<T>* x, stack<T> & pila) {
        if (x != NULL) { //Si el arbol no esta vacio
            if (x->left != NULL) {// Si existe hijo izquierdo
                inorderTreeWalk(x->left, pila); // se mete a la parte izquierda del arbol
            }
            pila.push(x->key); //mete los valores de forma IZQ-RAIZ-DER en la pila

            if (x->right != NULL) { //Si existe hijo derecho
                inorderTreeWalk(x->right, pila); //se mete a la parte derecha del arbol
            }
        }
    }
    // Efectua un recorrido en orden del sub�rbol cuya raiz es apuntada
    // por x, guardando en cada visita la llave de cada nodo en la pila.
    // Es decir, cada vez que se llega a un nodo se hace
    // pila.push(x->key). Si se hace correctamente, al finalizar el 
    // metodo la pila debe contener las llaves de los nodos del 
    // subarbol ordenadas de mayor a menor.

    node<T>* treeSearch(const T& k) {
        node<T> *ptr = root;
        node<T>* llave = search(ptr, k); //Se usa search implementado como privado
        return llave;
    }
    // Busca la llave recursivamente; si la encuentra, devuelve un 
    // apuntador al nodo que la contiene, sino devuelve NULL

    node<T>* iterativeTreeSearch(const T& k) {
        node<T> *ptr = root; // se posiciona en la raiz
        while (ptr != NULL && k != ptr->key) {//mientras no se acabe el arbol y no se encuentre la llave

            if (k < ptr->key) {//si lo que busco es menor puede estar a la izquierda
                ptr = ptr->left;
            } else {//sino a la derecha
                ptr = ptr->right;
            }
        }
        return ptr;
    }
    // Lo mismo que en el anterior pero usando un procedimiento 
    // iterativo

    node<T>* treeMinimum() {
        node<T> *rt = root; //Se posiciona en la raiz del arbol
        node<T> *m = NULL;
        if (rt != NULL) { //Si el arbol no esta vacio
            m = minimo(rt); //Usa metodo minimo privado
        }
        return m;
    }
    // Devuelve el nodo que tiene la llave menor.
    // Si el arbol est� vacio devuelve NULL.

    node<T>* treeMaximum() {
        node<T> *maximo = root;

        if (maximo != NULL) { //Si el arbol no esta vacio
            while (maximo->right != NULL) {
                maximo = maximo->right;
            }
        }
        return maximo;
    }
    // Devuelve el nodo que tiene la llave mayor.
    // Si el arbol esta vacio devuelve NULL.

    node<T>* treeSuccessor(const node<T>* x) {
        node<T> *y = NULL;

        if (x != NULL) {
            if (x->right != NULL) {
                return minimo(x->right);
            }
            node<T> *y = x->p;

            while ((y != NULL) && (x == y->right)) {
                x = y;
                y = y->p;
            }
        }
        return y;
    }
    // Devuelve el nodo cuya llave es la que le sigue a la
    // del nodo x. Si no existe tal nodo devuelve NULL.

    void treeInsert(node<T>* z) {
        node<T> *y = NULL;
        node <T> *x = this->root;

        while (x != NULL) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->p = y;
        if (y == NULL) {
            this->root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

    }
    // Inserta el nodo z en la posicion que le corresponde en el arbol.

    node<T>* treeDelete(node<T>* z) {
        node<T> *temp;

        if (z != NULL) {
            if (z->left == NULL) {
                transplant(root, z, z->right);

            } else {
                if (z->right == NULL) {
                    transplant(root, z, z->left);

                } else {
                    temp = minimo(z->right);
                    if (temp->p != z) {
                        transplant(root, temp, temp->right);
                        temp->right = z->right;
                        temp->right->p = temp;
                    }
                    transplant(root, z, temp);
                    temp->left = z->left;
                    temp->left->p = temp;
                }
            }
        }
        return z;
    }
    // Saca del arbol la llave contenida en el nodo apuntado por z.
    // Devuelve la direccion del nodo eliminado para que se pueda 
    // disponer de ella.

    node<T> * getRoot() const {
        return this->root;
    };
    // Devuelve la raiz del arbol. (Para efectos de revisi�n de la tarea).

    void agregarSecuencial(node<T>* z) { //Metodo que agrega en el arbol elementos secuencialmente

        if (this->root == NULL) { //Si el arbol esta vacio
            this->root = z; //Conecta la raiz con el nodo nuevo
            this->root->left = NULL; // el hijo izquierdo es nulo ya que solo agrega a la derecha
            ultimoAgregado = z; //Coloca al ultimoAgregado en el nodo nuevo
        } else {
            ultimoAgregado->right = z; //Conecta al nodo nuevo con el ultimo agregado como hijo derecho
            ultimoAgregado->left = NULL; // el hijo izquierdo es nulo ya que solo agrega a la derecha
            z->p = ultimoAgregado; //Hace al ultimo agregado anteriormente papa del nodo nuevo
            ultimoAgregado = z; //Pone como ultimoAgregado al nodo nuevo
        }
    }
    // Inserta el nodo z en la posicion que le corresponde en el arbol creado secuencialmente.





private:
    node<T> *root; // root of the Tree
    node<T> *ultimoAgregado = NULL; //Se utiliza para agregar cuando el arbol es secuencial

    void copy(node<T>* &nuevo, node <T>* orig) {
        if (orig == NULL) {
            nuevo = NULL;
        } else {
            nuevo = new node<T>;
            nuevo->key = orig->key;
            copy(nuevo->left, orig->left);
            copy(nuevo->right, orig->right);

            if (nuevo->left != NULL) {
                nuevo->left->p = nuevo;
            }
            if (nuevo->right != NULL) {
                nuevo->right->p = nuevo;
            }
        }
    }

    node<T>* search(node<T> *root, T k) {
        if ((root == NULL) || (root->key == k)) {//si la raiz esta en nulo o tiene la llave
            return root;
        } else {
            if (root->key > k) {
                return search(root->left, k);
            } else {
                if (root->key < k) {
                    return search(root->right, k);
                }
            }
        }
    }

    node<T>* minimo(node<T> *x) {
        while (x->left != NULL) { //Mientras no se llegue al elemento mas pequeño del arbol
            x = x->left; //Camine a la izquierda
        }
        return x;
    }

    void transplant(node<T> *root, node<T> *u, node<T> *v) {
        if (u->p == NULL) {
            this->root = v;
        } else if (u == u-> p-> left) {
            u->p->left = v;
        } else {
            u->p->right = v;
        }
        if (v != NULL) {
            v->p = u->p;
        }
    }

    void borrarArbol(node<T> *rt) {
        if (rt->left != NULL) {
            borrarArbol(rt->left);
        }
        if (rt->right != NULL) {
            borrarArbol(rt->right);
        }
        delete rt;
    }


};
#endif // BINARY_SEARCH_Tree
