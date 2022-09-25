#ifndef TABELA_H
#define TABELA_H

#include "Equipe.h"
#include "Modalidade.h"

#include <iostream>

using namespace std;

class Tabela {
public:
    Tabela(Equipe** participantes, int quantidade);
    ~Tabela();
    void pontuar (Equipe* participante, int pontos);
    int getPontos (Equipe* participante);
    int getPosicao (Equipe* participante);
    void imprimir();

private:
    int pontos;
    int quantidade;
    Equipe* participante;
    Equipe** participantes;
    int* pontuacao;
};


#endif // TABELA_H_INCLUDED
