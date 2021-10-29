cmake_minimum_required(VERSION 3.20)
project(ProyectoCovid19)

set(CMAKE_CXX_STANDARD 14)

include_directories("cosas juan/Arbol")
include_directories("cosas juan/Hash")
include_directories(Headers)

add_executable(ProyectoCovid19
        "cosas juan/Arbol/ArbolBinario.h"
        "cosas juan/Arbol/NodoArbol.h"
        "cosas juan/Hash/HashEntry.h"
        "cosas juan/Hash/HashMap.h"
        "cosas juan/main.cpp"
        Headers/ArbolBinario.h
        Headers/HashEntry.h
        Headers/HashMap.h
        Headers/Lista.h
        Headers/nodo.h
        Headers/NodoArbol.h
        Headers/pila.h
        Headers/provincias.h
        main.cpp)
