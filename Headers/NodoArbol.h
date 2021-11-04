#ifndef U05_ARBOL_ARBOL_NODOARBOL_H_
#define U05_ARBOL_ARBOL_NODOARBOL_H_

template <class T> class NodoArbol {
private:
  T data;   //el dato que vamos a almacenar
  NodoArbol *left, *right;  //apuntan a cada lado del nodo
  bool buscado;

public:
  NodoArbol(){  //constructor para inicializar el izq y derecho a nulo
      left = nullptr;
      right = nullptr;
  }

  NodoArbol(T d){   //acepta un parametro para inicializar tanto el dato como el izq y der
      data = d;
      buscado = false;
      left = nullptr;
      right = nullptr;
  }
  
  bool getBuscado() const{
    return buscado;
  }

  void setBuscado(bool b){
    buscado = b;
  }

  T getData() const{    //devuelve el valor que el nodo almacena
      return data;
  }


  void setData(T d){    //escribe el valor que el nodo almacena
      this->data = d;
  }

  NodoArbol *getRight() const{  //devuelve el nodo der
      return right;
  }

  void setRight(NodoArbol *r){  //escribe el nodo der
      this->right = r;    //setear la direccion de memoria del nodo derecho. Recibe la direccion de memoria de un nodo r
  }

  NodoArbol *getLeft() const{   //devuelve el nodo izq
      return left;
  }

  void setLeft(NodoArbol *l){   //escribe el nodo der
      this->left = l;
  }
};

#endif // U05_ARBOL_ARBOL_NODOARBOL_H_
