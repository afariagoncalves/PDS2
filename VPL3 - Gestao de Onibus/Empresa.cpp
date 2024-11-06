#include <iostream>

#include "Empresa.hpp"
#include "Onibus.hpp"

Empresa::Empresa(){
    this->cadastrados = 0;
    for (int i = 0; i < 20; i++){
        this->ptrOnibus[i] = nullptr;
    }
}

struct Onibus* Empresa::adicionarOnibus(std::string placa, int max){
    for (int i = 0; i < 20; i++){
        if (this->ptrOnibus[i] == nullptr){
            this->ptrOnibus[i] = new Onibus(placa, max);
            this->cadastrados++;
            return this->ptrOnibus[i];
        }
        else if (placa == this->ptrOnibus[i]->placa){
            return nullptr;
        } else {
            continue;
        }
    }
}


struct Onibus* Empresa::buscaOnibus(std::string placa){
    for (int i = 0; i < 20; i++){
        if (this->ptrOnibus[i] == nullptr)
            return nullptr;
        if (this->ptrOnibus[i]->placa == placa)
            return ptrOnibus[i];
    }
    return nullptr;
}

void Empresa::imprimirEstado(){
    for (int i = 0; i < 20; i++){
        if (this->ptrOnibus[i] == nullptr){
            return;
        }
        std::cout << this->ptrOnibus[i]->placa << " (" << this->ptrOnibus[i]->lotacaoAtual << "/" << this->ptrOnibus[i]->capacidadeMax << ")" << std::endl;
    }
}