#include "Equipe.h"

Equipe::Equipe(string nome): nome(nome) {

}
Equipe::~Equipe() {

}

string Equipe::getNome() {
    return this->nome;
}

void Equipe::imprimir(){
    cout << "Equipe " << this->nome << endl;
}
