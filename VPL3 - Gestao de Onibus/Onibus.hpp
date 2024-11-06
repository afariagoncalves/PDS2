#ifndef Onibus_h
#define Onibus_h
#include <iostream>

struct Onibus {
    std::string placa;
    int capacidadeMax;
    int lotacaoAtual;

    Onibus(std::string, int);

    void subirPassageiros(int);
    void descerPassageiros(int);
    void transferePassageiros(struct Onibus *, int);
    void imprimirEstado();
};

#endif 

