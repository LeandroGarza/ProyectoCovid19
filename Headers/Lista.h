#ifndef PROYECTOCOVID19_LISTA_H
#define PROYECTOCOVID19_LISTA_H

#include "nodo.h"
#include<iostream>

using namespace std;

template<class T>
        class lista{

        private:
            nodo<T> *inicio;

        public:
            lista();
            lista(const lista<T> &li);

            ~lista();
            bool esVacia();
            int getTamanio();
            void insertar(int, T);
            void insertarPrimero(T);
            void insertarUltimo(T);
            void remover(int);
            T getDato(int);
            void reemplazar(int, T);
            void vaciar();
            void imprimir();

            void agregar(int, T);
            void fnInvierte(lista<T> *lis);
            void borrar(int);

            void insertAfter2(int ,int ,int);

        };

template<class T>
lista<T>::lista(){

    inicio = nullptr;
}

template<class T>
lista<T>::lista(const lista<T> &li){

    inicio = li.inicio;
}

template<class T>
lista<T>::~lista(){
    vaciar();
    delete inicio;
}

template<class T>
bool lista<T>::esVacia(){

    return inicio == nullptr;
}

template<class T>
lista<T>::getTamanio(){

    nodo<T> *aux = inicio;
    int tam = 0;

    while(aux != nullptr){
        aux = aux -> getSiguiente();
        tam++;
    }

    return tam;
}

template<class T>
void lista<T>::insertar(int pos, T dato){

    nodo<T> *aux = inicio;

    nodo<T> *nuevo = new nodo<T>;
    nuevo ->setDato(dato);

    int posActual = 0;

    if(pos == 0){
        nuevo -> setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while(aux != nullptr && posActual < pos-1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if(aux == nullptr){
        throw 400;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);
}

template<class T>
void lista<T>::insertarPrimero(T dato){

    insertar(0, dato);
}

template<class T>
void lista<T>::insertarUltimo(T dato){

    insertar(getTamanio(),dato);
}

template<class T>   //elimina el nodo que vos le digas ya que vos le decis la posicion a eliminar
void lista<T>::remover(int pos){
    nodo<T> *aux = inicio, *aBorrar;
    int posActual = 0;

    if(pos == 0){
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }

    while(aux != nullptr && posActual < pos-1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if(aux == nullptr){
        throw 400;
    }

    aBorrar = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());

    delete aBorrar;

}

template<class T>
T lista<T>::getDato(int pos){
    nodo<T> *aux = inicio;
    int posActual = 0;

    while(aux != nullptr && posActual < pos){
        aux = aux->getSiguiente();
        posActual++;
    }

    if(aux == nullptr){
        throw 400;
    }

    return aux->getDato();
}

template<class T>
void lista<T>::reemplazar(int pos, T dato){

    nodo<T> *aux = inicio;
    int posActual = 0;

    while(aux != nullptr && posActual < pos){
        aux = aux->getSiguiente();
        posActual++;
    }

    if(aux == nullptr){
        throw 400;
        aux->setDato(dato);
    }
}

template<class T>
void lista<T>::vaciar(){
    nodo<T> *aux = inicio, *aBorrar;

    while(aux != nullptr){
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }

    inicio = nullptr;
}

template<class T>   //imprime la lista que creamos
void lista<T>::imprimir(){

    nodo<T> *aux = inicio;

    while(aux != nullptr){
        cout<<aux->getDato()<<" ->";
        aux = aux->getSiguiente();
    }
}

template<class T>
void lista<T>::agregar(int pos, T dato){

    int tam;

    tam = getTamanio();

    if(pos == 1){
        insertarPrimero(dato);
    }

    if(pos == 2){
        insertar(tam/2,dato);
    }

    if(pos == 3){
        insertar(tam,dato);
    }
}

template<class T>
void lista<T>::borrar(int posi){

    int tam = getTamanio();

    if(posi > tam-1){
                cout<<"La lista no tiene "<<posi<<" elementos, ingrese un valor valido"<<endl;
    }
    else{
        remover(posi);
        imprimir();

    }
}

template<class T>
lista<T> *enlazadas(lista<T> &lis1, lista<T> &lis2) {
    lista<T> *lista3 = new lista<T>();

    for(int i = 0; i < lis1.getTamanio(); i++)
        lista3->insertarUltimo(lis1.getDato(i));
    for(int i = 0; i < lis2.getTamanio(); i++)
        lista3->insertarUltimo(lis2.getDato(i));

    return lista3;
}

template<class T>
void lista<T>::insertAfter2(int oldValue, int n, int newValue){

    for(int i = 0 ; i < getTamanio() ; i++){
        if(getDato(i) == oldValue){
            reemplazar(n+i,newValue);
            break;
        }
    }
}

#endif //PROYECTOCOVID19_LISTA_H