#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashEntry.h"

template <class K, class T>
class HashMap
{
private:
  HashEntry<K, T> **tabla;
  unsigned int tamanio;

  static unsigned int hashFunc(K clave);

  unsigned int (*hashFuncP)(K clave);

public:
  explicit HashMap(unsigned int k);

  T get(K clave);

  void put(K clave, T valor);

  ~HashMap();

  void print();

  void set(K clave, T valor);

};

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int k)
{
  tamanio = k;
  tabla = new HashEntry<K, T> *[tamanio];
  for (int i = 0; i < tamanio; i++)
  {
    tabla[i] = NULL;
  }
  hashFuncP = hashFunc;
}

template <class K, class T>
HashMap<K, T>::~HashMap()
{
  for (int i = 0; i < tamanio; i++)
  {
    if (tabla[i] != NULL)
    {
      delete tabla[i];
    }
  }
}

template <class K, class T>
T HashMap<K, T>::get(K clave)
{
  unsigned int pos = hashFuncP(clave) % tamanio;
  if (tabla[pos] == NULL)
  {
    throw 404;
  }
  if(tabla[pos]->getClave() == clave){
    return tabla[pos]->getValor();
  }else{
    int i = 0;
    while (i < 15)
    {
        if(tabla[pos]->getClave() == clave)
        {
            return tabla[pos]->getValor();
        }
      pos += 4 + i;
      if(pos > tamanio){
        pos = 0;
        i++;
      }
    }

  }
}

template <class K, class T>
void HashMap<K, T>::set(K clave, T valor)
{
  unsigned int pos = hashFuncP(clave) % tamanio;
  if (tabla[pos] == NULL)
  {
    throw 404;
  }
  if(tabla[pos]->getClave() == clave){
    tabla[pos]->setValor(valor);
  }else{
    int i = 0;
    while (i < 15)
    {
      if(tabla[pos]->getClave() == clave){
        tabla[pos]->setValor(valor);
      }
      pos += 4 + i;
      if(pos > tamanio){
        pos = 0;
        i++;
      }

    }
  }
}


template <class K, class T>
void HashMap<K, T>::put(K clave, T valor)
{
  unsigned int pos = hashFuncP(clave) % tamanio;

  int i = 0;
  while (tabla[pos] != NULL)
  {

    pos += 4 + i;
    if(pos > tamanio){
      pos = 0;
      i++;
    }
  }
  tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una fila en la tabla HASH
}


template <class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave)
{
    if(clave == "Tierra del Fuego"){
      return 17;
    }
    else if(clave == "Misiones"){
      return 23;
    }
    int hash = 0;
    for(int i = 0; i < clave.length(); ++i){
        hash += (clave[i]);
    }
    hash += clave.size() + clave[0];
    return hash;
}

#endif // HASHMAP_H
