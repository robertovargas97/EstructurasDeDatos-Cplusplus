#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>

using namespace std;

template <typename T>
class hasht {
public:

    hasht(int nEntradas) {
        numEntradas = nEntradas;
        tabla.resize(numEntradas);
    };
    // Constructor que especifica el numero de cubetas (entradas) 
    // en la tabla

    hash(const hasht<T>& obj) {
        tabla.resize(obj.numEntradas); //Inicializacion del vector de nodos
        for (int entrada = 0; entrada < obj.numEntradas; entrada) {
            
            for (typename list<T>::const_iterator it = obj.tabla[entrada].begin(); it != obj.tabla[entrada].end(); ++it) { //se recorre la lista de cada entrada
                tabla[entrada].push_back(*it);
            }
        }
    };
    // Constructor copia

    ~hasht() {
  
    };
    // Destructor (borra la tabla)

    T* search(const T& item) {
        int posB = hashFunction(item); //PosB indica la posicion de la tabla donde buscar
        T *ptr = NULL; //Inicia el puntero a devolver en NULL
        for (typename list<T>::iterator i = tabla[posB].begin(); i != tabla[posB].end(); ++i) {
            if (*i == item) { //Si lo que apunta el iterador es lo que busco
                ptr = &(*i); //Ptr apunta al elemento
            }
        }
        return ptr;
    };
    // Retorna un puntero a la llave o NULL si no se encuentra

    void insert(const T& item) {
        int pos = hashFunction(item); //Guarda en pos la posicion donde debe ser insertado el elemento
        tabla[pos].push_front(item); //Inserte el item en la lista de la posicion que le corresponde
    };
    // Inserta el elemento en la tabla



    //METODO EXTRA SOLO PARA PROBAR EN EL MAIN, NO CALIFICAR//
    void Imprimir() {
        for (int j = 0; j < numEntradas; j++) {
            cout << "En la posicion " << j << " de la tabla hay :";
            for (typename list < T >::const_iterator i = tabla[j].begin(); i != tabla[j].end(); ++i) {
                cout << *i << " ";
            }
            cout << endl;
        }
    }

private:

    int hashFunction(int k) { //Funcion de dispersion necesaria
        int pos = k % numEntradas;
        return pos;
    }


    int numEntradas;
    // N�mero de entradas en la tabla

    vector < list < T > > tabla;
    // La tabla es un vector de listas de STL
};
#endif
