#ifndef NODO_H
#define NODO_H

template <class T>
class nodo
{
private:
    T dato;
    nodo<T> *siguiente;

public:
    T getDato()
    {
        return dato;
    }

    void setDato(T d)
    {
        dato = d;
    }

    nodo<T> *getSiguiente()
    {
        return siguiente;
    }

    void setSiguiente(nodo<T> *s)
    {
        this->siguiente = s;
    }
};

#endif //NODO_H
