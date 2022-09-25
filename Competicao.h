#ifndef COMPETICAO_H
#define COMPETICAO_H

#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"

#include <iostream>
#include <string>

using namespace std;

class Competicao {
public:
    Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades);
    ~Competicao();
    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();
    bool adicionar(Modalidade* m);

    Modalidade** getModalidades();
    int getQuantidadeDeModalidades();
    Tabela* getTabela();
    void imprimir();

private:
    Equipe** equipes;
    int quantidadeDeModalidades;
    Modalidade** modalidades;
    int maximoDeModalidades;
    int quantidade;
    string nome;
};


#endif
