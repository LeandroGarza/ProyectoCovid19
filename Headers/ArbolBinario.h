#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "NodoArbol.h"
#include<iostream>

using namespace std;

template <class T> class ArbolBinario {
protected:

    NodoArbol<T> *root;  //un puntero a un nodo de tipo arbol

public:
  ArbolBinario();

  void put(T dato); //insertar dato en arbol

  T search(T dato); //buscar dato por parametro y ver si existe


  void preorder();  //visita raiz, izquierdo y derecho

  void inorder();   //visita izquierdo, raiz y derecha

  void postorder(); //visita izquierda, derecha y raiz

  ~ArbolBinario();  //destructor

  int contarPorNivel(int n);

private:    //tambien lo podia declarar arriba en el otro private, pero siento + prolijo aca. Son privados recursivos

    T search(T dato, NodoArbol<T> *r);   //puede ser del mismo nombre ya que tienen parametros #. El 2do parametro permite hacer la busqueda de forma recursiva

    void put(T dato, NodoArbol<T> *r);

    void preorder(NodoArbol<T> *r);

    void inorder(NodoArbol<T> *r);

    void postorder(NodoArbol<T> *r);

    int contarPorNivel(NodoArbol<T> *r, int actual, int nivel);

};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinario<T>::ArbolBinario(){
    root = nullptr;     //si nuestra raiz es nulo, nuestro arbol es vacio
}

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T>  //metodo accesible de afuera de la clase (osea cuando instanciamos objeto)
T ArbolBinario<T>::search(T dato) {

  return search(dato, root);    //osea le mandamos el dato y por donde comenzar la busqueda. Este metodo termina cuando termine la funcion recursiva
}

template <class T>  //a este solo puede acceder por el metodo search de arriba
T ArbolBinario<T>::search(T dato, NodoArbol<T> *r){

    if(r == nullptr){   //si no existe le tiramos error
        throw 404;  //404 es valor no encontrado
    }
    if(r->getData() == dato && !r->getBuscado())
    {
        r->setBuscado(true);
        return r->getData();    // return dato es lo mismo
    }

    if(r->getData() > dato){    //si el q estoy parado > al q estoy buscando
        return search(dato, r->getLeft());  //ya que el de la izq es menor siempre. Asi q llamamos a la funcion con el mismo dato, pero en el lugar izq
    }
    else{
        return search(dato, r->getRight()); //si estoy parado < al q busco entonces voy a la derecha q es siempre mayor q la izq
    }

}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinario<T>::put(T dato){
        //root = put(dato, root);    //para insertar un dato, necesitamos buscar la posicion. Hizo profe no anda
        if(root != nullptr){
            put(dato,root);
        }
        else{
            root = new NodoArbol<T>(dato);
        }
}

template <class T>
void ArbolBinario<T>::put(T dato, NodoArbol<T> *r){

    /*if(r == nullptr){   //si la posicion en la que estoy es nula, osea no hay nada, es la que busco ya que ahi insertare mi dato
        return new NodoArbol<T>dato;
    }

    if(r->getData() == dato){
        throw 200;  //si el dato que estoy pasando es igual al que ya esta, entonces tiro error (ya que no aceptamos datos repetidos)
    }

    if(r->getData() > dato){    //el dato q estoy almacenando en el nodo que estoy parado es mayor al dato que estoy pasando por parametro
        r->setLeft(put(dato, r->getLeft()));   //osea el que quiero insertar, quizas deberia ir en el izq (quizas ya que si ya exite uno en la izq, no puedo)
    }
    else{
        r->setRight(put(dato, r->getRight()));  //como no pude en el izq, pruebo con el derecho. Si esta llena se pasa a un subnivel mas profundo
        //en el caso que se cumpla, ya sea este o el setLeft, te manda recursivamente al if(r == nullptr)
    }

    return r;*/

    T miDato = r->getData();

    if(dato >= miDato){
        if(r->getRight() != nullptr){
            put(dato, r->getRight());
        }
        else{
            auto *nuevo = new NodoArbol<T>(dato);
            r->setRight(nuevo);
        }
    }
    else{
        if (r->getLeft() != nullptr) {
            put(dato, r->getLeft());
        }
        else{
            auto *nuevo = new NodoArbol<T>(dato);
            r->setLeft(nuevo);
        }
    }
}

template <class T>
void ArbolBinario<T>::preorder(){
    preorder(root);
}

template <class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r){    //R - I - D

    if(r == nullptr){   //osea si el r que le pasamos por parametro es el numero, terminamos la funcion recursiva
        return; //con esto, las 3 lineas de abajo no se ejecutan
    }

    cout<< r->getData()<<" ";  //Para visitar un nodo, simplemente lo imprimimos. Imprimimos que dato almacena

    if(r->getLeft() != nullptr){
        preorder(r->getLeft());     //quiero q imprimas tod0 lo que esta a la izquierda del nodo actual
    }
    if(r->getRight() != nullptr){
        preorder(r->getRight());    //quiero q imprimas tod0 lo q esta a la derecha del nodo actual
    }
}

/**
 * Recorre un árbol en orden. Es para ver el arbol de manera ordenada
 */
// nivel 0                         5
//                                / \
// nivel 1                       3   8
//                              / \   \
// nivel 2                     2   4   9
//En este caso se ve:  2 - 3 - 4 - 5 - 8 - 9

template <class T>
void ArbolBinario<T>::inorder(){     //I - R - D
    inorder(root);
}

template <class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r){

    if(r == nullptr){   //osea si el r que le pasamos por parametro es el numero, terminamos la funcion recursiva
        return; //con esto, las 3 lineas de abajo no se ejecutan
    }

    //fijate que ahora vamos primero a la izq, luego raiz, luego derecha
    inorder(r->getLeft());     //quiero q imprimas tod0 lo que esta a la izquierda del nodo actual
    cout<< r->getData()<<" ";  //Para visitar un nodo, simplemente lo imprimimos. Imprimimos que dato almacena
    inorder(r->getRight());    //quiero q imprimas tod0 lo q esta a la derecha del nodo actual
}

/**
 * Recorre un árbol en postorden. Es para eliminar un arbol
 */
//                          5
//                         / \
//                        3   8
//                       / \   \
//                      2   4   9
//En este caso la eliminacion seria:  2 - 4 - 3 - 9 - 8 - 5

template <class T>
void ArbolBinario<T>::postorder(){   //I - D - R
    portorder(root);
}

template<class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r){

    if(r == nullptr){   //osea si el r que le pasamos por parametro es el numero, terminamos la funcion recursiva
        return; //con esto, las 3 lineas de abajo no se ejecutan
    }

    postorder(r->getLeft());     //quiero q imprimas tod0 lo que esta a la izquierda del nodo actual
    postorder(r->getRight());    //quiero q imprimas tod0 lo q esta a la derecha del nodo actual
    cout<< r->getData()<<endl;  //Para visitar un nodo, simplemente lo imprimimos. Imprimimos que dato almacena
}


template <class T>
int ArbolBinario<T>::contarPorNivel(int n){
    if(root != nullptr){
        return contarPorNivel(root,0,n);
    }
    else{
        return 0;
    }
}

template<class T>
int ArbolBinario<T>::contarPorNivel(NodoArbol<T> *r, int actual, int nivel){

    if(r == nullptr){
        return 0;
    }

    if(actual == nivel){
        return 1;
    }

    //int *suma = r->getLeft() + r->getRight();
    return contarPorNivel(r->getLeft() , actual+1, nivel);
    //return contarPorNivel(r->getRight(), actual+1, nivel);
}


#endif // ARBOLBINARIO_H
