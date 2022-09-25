#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade): nome (nome), participantes(participantes), quantidade (quantidade) {
    this->ordem = NULL;
}

Modalidade::~Modalidade() {
}

string Modalidade::getNome() {
    return this->nome;
}


Equipe** Modalidade::getEquipes() {
    return  this->participantes;
}

int Modalidade::getQuantidadeDeEquipes() {
    return this->quantidade;
}

void Modalidade::setResultado(Equipe** ordem) {
    this->ordem = ordem;
}

int Modalidade::getPosicao(Equipe* participante) {
    if(this->ordem == NULL)
        return -1;
    for(int i = 0; i < quantidade; i++) {
        if(ordem[i] == participante)
            return i+1;
    }
    return -1;
}

void Modalidade::imprimir() {
    cout << "Modalidade: " << this->nome << endl;
        if(this->ordem != NULL) {
            cout << "Resultado: " << endl;
            for(int i = 0; i < quantidade; i++) {
                cout << "       " << i+1 << "o " << this->ordem[i]->getNome() << endl;
            }
        }
        else {
            cout << "Participantes: " << endl;
            for(int i = 0; i < quantidade; i++) {
                cout << "       " << this->participantes[i]->getNome() << endl;
            }
        }
}
