#include <iostream>

#include "Onibus.hpp"
#include "Empresa.hpp"

using namespace std;


int main(){
    string placa, placa_T;
    int max;
    int num_pessoas;
    char comando;
    struct Empresa* empresa = new Empresa();
    while (1){
        cout << "digite o comando :" << endl;
        cin >> comando;
        if (comando == 'C'){
            cin >> placa;
            cin >> max;
            if (empresa->adicionarOnibus(placa, max) == nullptr){
                cout << "ERRO : onibus repetido" << endl;
                continue;
            } 
            else {
                cout << "novo onibus cadastrado" << endl;
                continue;
            }
        } 
        else if (comando == 'S'){
            cin >> placa;
            cin >> num_pessoas;
            struct Onibus* onibusSelecionado;
            onibusSelecionado = empresa->buscaOnibus(placa);
            if (onibusSelecionado == nullptr){
                cout << "ERRO :  onibus inexistente" << endl;
                continue;
            } else {
                onibusSelecionado->subirPassageiros(num_pessoas);
            }
        }
        else if (comando == 'D'){
            cin >> placa;
            cin >> num_pessoas;
            struct Onibus* onibusSelecionado;
            onibusSelecionado = empresa->buscaOnibus(placa);
            if (onibusSelecionado == nullptr) {
                cout << "ERRO : onibus inexistente" << endl;
                continue;
            } else {
                onibusSelecionado->descerPassageiros(num_pessoas);
            }
        }
        else if (comando == 'T'){
            cin >> placa;
            cin >> placa_T;
            cin >> num_pessoas;
            struct Onibus* onibusAntigo = empresa->buscaOnibus(placa);
            struct Onibus* onibusNovo = empresa->buscaOnibus(placa_T);
            if (onibusAntigo == nullptr || onibusNovo == nullptr){
                cout << "ERRO : onibus inexistente" << endl;
                continue;
            } else {
                onibusAntigo->transferePassageiros(onibusNovo, num_pessoas);
            }
        }
        else if (comando == 'I'){
            empresa->imprimirEstado();
        }
        else if (comando == 'F'){
            break;
        } else {
            cout << "comando não reconhecido " << endl;
            continue;
        }
    }
    delete empresa;
    return 0;
}

// cd C:\Users\arthu\OneDrive\ufmg\projetos.ufmg\vpl3
// g++ -std=c++11 -g Onibus.cpp Empresa.cpp main.cpp -o gestao



