#ifndef PROYECTOCOVID19_PILA_H
#define PROYECTOCOVID19_PILA_H

#include "nodo.h"

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
        class Pila {

        private:
            nodo<T> *tope;
        public:
            Pila();

            ~Pila();

            void push(T dato);

            T pop();

            bool esVacia();
        };


/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T>
Pila<T>::Pila() {
    tope = nullptr;
}



template<class T>
Pila<T>::~Pila() {
    nodo<T> *aux = tope;
    while(aux != nullptr) {
        tope = aux->getSiguiente();
        delete aux;
        aux = tope;
    }
    delete tope;
}

template<class T>
void Pila<T>::push(T dato) {
    nodo<T> *nuevo;
    nuevo = new nodo<T>;

    nuevo->setSiguiente(tope);
    nuevo->setDato(dato);

    tope = nuevo;
}



template<class T>
T Pila<T>::pop() {

    if(tope == nullptr)
        throw 1;

        T dato = tope->getDato();
        nodo<T> *aBorrar = tope;
        tope = tope->getSiguiente();

        delete aBorrar;
        return dato;
}

template<class T>
bool Pila<T>::esVacia() {
    return (tope == nullptr);
}

#endif //PROYECTOCOVID19_PILA_H
