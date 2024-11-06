#include <iostream>

#include "Onibus.hpp"


Onibus::Onibus(std::string placa,int max) {
    this->placa = placa;
    this->capacidadeMax = max;
    this->lotacaoAtual = 0;
}

void Onibus::subirPassageiros(int passageiros){
    if (this->lotacaoAtual + passageiros > this->capacidadeMax){
        std::cout << "ERRO : onibus lotado" << std::endl;
        return;
    }
    std::cout << "passageiros subiram com sucesso" << std::endl;
    this->lotacaoAtual = this->lotacaoAtual + passageiros;
}

void Onibus::descerPassageiros(int passageiros){
    if (this->lotacaoAtual - passageiros < 0){
        std::cout << "ERRO : faltam passageiros" << std::endl;
        return;
    }
    std::cout << "passageiros desceram com sucesso" << std::endl;
    this->lotacaoAtual = this->lotacaoAtual - passageiros;
}

void Onibus::transferePassageiros(struct Onibus *Onibus, int passageiros){
    if (this->lotacaoAtual - passageiros < 0 || Onibus->lotacaoAtual + passageiros > Onibus->capacidadeMax){
        std::cout << "ERRO : transferencia cancelada" << std::endl;
        return;
    }
    
    this->lotacaoAtual = this->lotacaoAtual - passageiros;
    Onibus->lotacaoAtual = Onibus->lotacaoAtual + passageiros;
    std::cout << "transferencia de passageiros efetuada" << std::endl;
}

void Onibus::imprimirEstado(){
    std::cout << this->placa << " (" << this->lotacaoAtual << "/" << this->capacidadeMax << ")" << std::endl;
}