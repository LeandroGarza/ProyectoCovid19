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

  HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

  T get(K clave);

  void put(K clave, T valor);

  void remove(K clave);

  ~HashMap();

  void add(K clave, T valor);

  void set(K clave, T valor);

  bool esVacio();

  void print();
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
HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K))
{
  tamanio = k;
  tabla = new HashEntry<K, T> *[tamanio];
  for (int i = 0; i < tamanio; i++)
  {
    tabla[i] = NULL;
  }
  hashFuncP = fp;
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
    while (i < 10)
    {
      pos += 4 + i;
      if(pos > tamanio){
        pos = 0;
        i++;
      }
      if(tabla[pos]->getClave() == clave){
        return tabla[pos]->getValor();
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
    while (i < 10)
    {
      pos += 4 + i;
      if(pos > tamanio){
        pos = 0;
        i++;
      }
      if(tabla[pos]->getClave() == clave){
        tabla[pos]->setValor(valor);
      }
    }
  }
}


template <class K, class T>
void HashMap<K, T>::put(K clave, T valor)
{
  unsigned int pos = hashFuncP(clave) % tamanio;

  while (tabla[pos] != NULL)
  {
    int i = 0;
    pos += 4 + i;
    if(pos > tamanio){
      pos = 0;
      i++;
    }
  }
  tabla[pos] = new HashEntry<K, T>(clave, valor); //Corresponde a una fila en la tabla HASH
}

template <class K, class T>
void HashMap<K, T>::remove(K clave) {}

template <class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave)
{
  return (unsigned int)clave;
}

#endif // HASHMAP_H
