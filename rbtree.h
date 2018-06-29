#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree
#include <stack>
#include <iostream>

#include "bstree.h"

using namespace std;

enum colors {
    RED, BLACK
};

// Nodos del arbol:

template <typename T>
class rbnode {
public:
    // Esta clase es para ser usada por otras clases.
    // Por eficiencia se hacen los atributos publicos.
    T key;
    rbnode<T> *p, *left, *right;
    enum colors color;

    // Constructor por omision.

    rbnode() {
        p = NULL;
        left = NULL;
        right = NULL;
        color = RED; //Rojo ya que un nodo siempre debe insertarse rojo
    };

    // Constructor por copia del nodo.

    rbnode(const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr) { //Se toma como original a obj y nil del original a objNil
        if (obj->left == objNil && obj->right == objNil) { //Si el original no tiene hijos
            parent->left = nilPtr;
            parent->right = nilPtr;
            //El copia tampoco tiene hijos
        } else { //El original tiene 1 o 2 hijos

            if ((obj->left != objNil) && (obj->right != objNil)) { //Si el original tiene los dos hijos
                parent->left = new rbnode<T>(obj->left->key); //Crea un nodo igual al hijo izquierdo del original
                parent->right = new rbnode<T>(obj->right->key); //Crea un nodo igual al hijo derecho del original
            } else if ((obj->left != objNil) && (obj->right == objNil)) { //Si el original tiene hijo izquierdo,pero no derecho
                parent->left = new rbnode<T>(obj->left->key); //Crea un nodo igual al hijo izquierdo del original
                parent->right = nilPtr;
            } else if ((obj->left == objNil) && (obj->right != objNil)) { //Si el original tiene hijo derecho,pero no izquierdo
                parent->left = nilPtr;
                parent->right = new rbnode<T>(obj->right->key); //Crea un nodo igual al hijo derecho del original
            }

        }
    }

    // Inicializacion de datos miembro.

    rbnode(const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL, rbnode<T> *z =
            NULL, enum colors c = RED) : key(k), p(w), left(y), right(z), color(c) {

    };

    ~rbnode() {

    }
};

// Arbol:

template <typename T>
class rbtree {
public:

    rbtree() {
        nil = new rbnode<T>(-12345); //Crea la hoja compartida
        nil->color = BLACK;
        root = nil; //La raiz apunta nil
    };
    // Constructor (crea un arbol vacio)

    rbtree(const rbtree<T>& obj) {
        this -> nil = new rbnode<T>(obj.nil->key); //Crea el nil del arbol copia igual al del arbol original
        this->nil->color = BLACK; //Asigna el color del nil copia igual al color del nil original
        this->root = this->nil; //Se crea el arbol copia vacio 

        copyRB(obj.getRoot(), obj.getNil()); //Copie el arbol

    };
    // Constructor copia

    ~rbtree() {
        if (this->root != nil) {
            borrarArbol(root);
        }
        delete nil;
    };
    // Destructor (borra el arbol)

    void inorderTreeWalk(rbnode<T>* x, stack<T> & pila) {
        if (x != nil) { //Si el arbol no esta vacio
            if (x->left != nil) {// Si existe hijo izquierdo
                inorderTreeWalk(x->left, pila); // se mete a la parte izquierda del arbol
            }
            pila.push(x->key); //mete los valores de forma IZQ-RAIZ-DER en la pila
            pila.push(x->color); //Mete el color del nodo luego de su llave

            if (x->right != nil) { //Si existe hijo derecho
                inorderTreeWalk(x->right, pila); //se mete a la parte derecha del arbol
            }
        }
    };
    // Efectua un recorrido en orden del subarbol cuya ra�z es apuntada
    // por x. En cada visita apila la llave de cada nodo y su color.
    // Es decir, cada vez que se llega a un nodo se ejecutan las 
    // instrucciones pila.push(x->key); y luego pila.push(colorDeX).
    // Para efectos de la tarea, si el color del nodo es rojo, 
    // ponga en la pila un 0, y si es negro, ponga un 1.
    // Si se hace correctamente, al finalizar el m�todo la pila deber�a 
    // contener las llaves de los nodos del sub�rbol (y su color) 
    // ordenadas de mayor a menor.

    rbnode<T>* treeSearch(const T& k) {
        rbnode<T> *ptr = root;
        rbnode<T>* llave = search(ptr, k); //Se usa search implementado como privado

        if (llave == this->nil) {
            llave = NULL;
        }

        return llave;
    };
    // Busca la llave recursivamente, si la encuentra devuelve un 
    // puntero al nodo que la contiene, sino devuelve NULL.

    rbnode<T>* iterativeTreeSearch(const T& k) {
        rbnode<T> *ptr = root; // se posiciona en la raiz

        while (ptr != nil && k != ptr->key) {//mientras no se acabe el arbol y no se encuentre la llave

            if (k < ptr->key) {//si lo que busco es menor puede estar a la izquierda
                ptr = ptr->left;
            } else {//sino a la derecha
                ptr = ptr->right;
            }
        }

        if (ptr == nil) { //Si no se encontro el elemento
            ptr = NULL;
        }

        return ptr; //Si no se encuentra se devuelve nil que es lo mismo que null

    };
    // Igual que en el anterior pero usa un procedimiento iterativo.

    rbnode<T>* treeMinimum() {
        rbnode<T> *minimo = root; //Se posiciona en la raiz del arbol
        if (minimo != nil) {
            while (minimo->left != nil) { //Mientras no se llegue al elemento mas pequeño del arbol
                minimo = minimo->left; //Camine a la izquierda
            }
        } else {
            minimo = NULL;
        }
        return minimo;
    };
    // Devuelve el nodo con la llave menor.
    // Si el arbol esta vacio devuelve NULL.

    rbnode<T>* treeMaximum() {
        rbnode<T> *maximo = root;
        if (maximo != nil) {
            while (maximo->right != nil) {
                maximo = maximo->right;
            }
        }
        else{
            maximo = NULL;
        }
        return maximo;
    };
    // Devuelve el nodo con la llave mayor.
    // Si el arbol esta vacio devuelve NULL.

    rbnode<T>* treeSuccessor(const rbnode<T>* x) {
        rbnode<T> *y = nil;

        if (x != nil) {
            if (x->right != nil) {
                return minimo(x->right);
            }
            rbnode<T> *y = x->p;

            while ((y != nil) && (x == y->right)) {
                x = y;
                y = y->p;
            }
        }
        return y;
    };
    // Devuelve el nodo cuya llave es la siguiente mas grande que 
    // la del nodo x. Si no existe tal nodo devuelve NULL.

    void treeInsert(rbnode<T>* z) { //aux es y, actual es x.
        rbnode<T> *y = nil;
        rbnode <T> *x = this->root;

        while (x != nil) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->p = y;
        if (y == nil) {
            this->root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = nil;
        z->right = nil;
        z->color = RED;

        RB_insert_FixUp(z);

    };
    // Inserta el nodo z en la posicion que le corresponde en el arbol.

    rbnode<T> * getRoot() const {
        return this->root;
    };

    // Devuelve la raiz del arbol. (Para efectos de revision de la tarea).

    rbnode<T> * getNil() const {
        return this->nil;
    };
    // Devuelve T.nil. (Para efectos de revision de la tarea).

private:

    rbnode<T> *root; // raiz del arbol
    rbnode<T> *nil; // nodo nil (hoja) del arbol

    //---------METODOS USADOS EN EL CONSTRUCTOR POR COPIA DE ARBOL------------//

    void copyInsert(rbnode<T>* z) { //Se usara para insertar un nodo en el constructor por copia
        rbnode<T> *y = nil;
        rbnode <T> *x = this->root;

        while (x != nil) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->p = y;
        if (y == nil) {
            this->root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        z->left = nil;
        z->right = nil;
    }

    void copyRB(rbnode<T>* orig, rbnode<T>* origNil) { //Debe llamarse con  obj.getRoot y obj.getNil 
        if (orig != origNil) {
            rbnode<T> * nuevo = new rbnode<T>(orig->key); //Crea el nodo nuevo
            nuevo->color = orig->color; //Asigna el color original al nodo nuevo
            copyInsert(nuevo); //Inserta el nodo en el arbol copia
            copyRB(orig->left, origNil);
            copyRB(orig->right, origNil);
        }
    };
    //------------------------------------------------------------------------//


    //----------METODO USADO EN EL DESTRUCTOR DEL ARBOL-----------------------//

    void borrarArbol(rbnode<T> *rt) {
        if (rt->left != nil) {
            borrarArbol(rt->left);
        }
        if (rt->right != nil) {
            borrarArbol(rt->right);
        }
        delete rt;
    }
    //------------------------------------------------------------------------//


    //----------METODO USADO EN EL SUCESOR DE NODO----------------------------//

    rbnode<T>* minimo(rbnode<T> *x) {
        while (x->left != NULL) { //Mientras no se llegue al elemento mas pequeño del arbol
            x = x->left; //Camine a la izquierda
        }
        return x;
    }

    //------------------------------------------------------------------------//


    //----------METODO USADO EN EL BUSCAR DE ARBOL----------------------------//

    rbnode<T>* search(rbnode<T> *root, T k) {
        if ((root == nil) || (root->key == k)) {//si la raiz esta en nulo o tiene la llave
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

    //------------------------------------------------------------------------//


    //----------METODOS USADAS EN EL INSERTAR DE ARBOL------------------------//

    void leftRotate(rbnode<T>* x) {
        rbnode<T>* y = x->right;
        x->right = y->left;

        if (y->left != nil) {
            y->left->p = x;
        }
        y->p = x->p;
        if (x->p == nil) {
            this->root = y;
        } else if (x == x->p->left) {
            x->p->left = y;
        } else {
            x->p->right = y;
        }
        y->left = x;
        x->p = y;
    }

    void rightRotate(rbnode<T>* x) {
        rbnode<T>* y = x->left;
        x->left = y->right;

        if (y->right != nil) {
            y->right->p = x;
        }
        y->p = x->p;
        if (x->p == nil) {
            this->root = y;
        } else if (x == x->p->right) {
            x->p->right = y;
        } else {
            x->p->left = y;
        }
        y->right = x;
        x->p = y;
    }

    void RB_insert_FixUp(rbnode<T>* z) {
        while (z->p->color == RED) {
            if (z->p == z->p->p->left) {
                rbnode<T>* y = z->p->p->right;
                if (y->color == RED) {
                    z->p->color = BLACK; //Caso 1
                    y->color = BLACK; //Caso 1
                    z->p->p->color = RED; //Caso 1
                    z = z->p->p; //Caso 1
                } else {
                    if (z == z->p->right) {
                        z = z->p; //Caso 2
                        leftRotate(z); //Caso 2
                    }
                    z->p->color = BLACK; //Caso 3
                    z->p->p->color = RED; //Caso 3
                    rightRotate(z->p->p); //Caso 3
                }
            } else {

                rbnode<T>* y = z->p->p->left;

                if (y->color == RED) {
                    z->p->color = BLACK;
                    y->color = BLACK;
                    z->p->p->color = RED;
                    z = z->p->p;
                } else {
                    if (z == z->p->left) {
                        z = z->p;
                        rightRotate(z);
                    }
                    z->p->color = BLACK;
                    z->p->p->color = RED;
                    leftRotate(z->p->p);
                }
            }
        }
        this->root->color = BLACK;
    }

};

#endif // RED_BLACK_rbtree
