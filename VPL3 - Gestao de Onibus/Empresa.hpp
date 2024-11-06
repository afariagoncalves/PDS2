#ifndef Empresa_h
#define Empresa_h

#include "Onibus.hpp"
#include <iostream>

struct Empresa {
    int cadastrados;
    struct Onibus* ptrOnibus[20];

    Empresa();

    struct Onibus* adicionarOnibus(std::string, int);
    struct Onibus* buscaOnibus(std::string);
    void imprimirEstado();

};


#endif
