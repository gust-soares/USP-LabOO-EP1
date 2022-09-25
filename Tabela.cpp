#include "Tabela.h"

Tabela::Tabela(Equipe** participantes, int quantidade): participantes(participantes), quantidade(quantidade) {

    this->pontuacao = new int[quantidade];

    for(int i = 0; i < quantidade; i++) {
        pontuacao[i] = 0;
    }
}
Tabela::~Tabela() {
}

void Tabela::pontuar(Equipe* participante, int pontos) {
    for(int i = 0; i < quantidade; i++) {
        if(participante == this->participantes[i]) {
            this->pontuacao[i] += pontos;
        }
    }
}
int Tabela::getPontos(Equipe* participante) {
    for(int i = 0; i < quantidade; i++) {
        if(participante == this->participantes[i]) {
            return this->pontuacao[i];
        }
    }
    return -1;
}
int Tabela::getPosicao(Equipe* participante) {
    int j=0, posicao=1;
    for(int i = 0; i < quantidade; i++) {
        j = i;
        if(participante == this->participantes[i])
            i = quantidade;
    }
    for (int i = 0; i < quantidade; i++) {
        if (this->pontuacao[j] < this->pontuacao[i])
            posicao++;
    }
    return posicao;
}

void Tabela::imprimir() {
    for(int i = 0; i < quantidade; i++)
        cout << this->participantes[i]->getNome() << " - " << this->getPontos(participantes[i]) << " pontos  (" << this->getPosicao(participantes[i]) << "o)" << endl;
}
