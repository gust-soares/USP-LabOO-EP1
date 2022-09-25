#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades):
nome(nome),equipes(equipes),quantidade(quantidade),maximoDeModalidades(maximoDeModalidades) {

    quantidadeDeModalidades = 0;
    this->modalidades = new Modalidade*[maximoDeModalidades];
}
Competicao::~Competicao() {

}
string Competicao::getNome() {
    return this->nome;
}
Equipe** Competicao::getEquipes() {
    return this->equipes;
}
int Competicao::getQuantidadeDeEquipes() {
    return this->quantidade;
}
bool Competicao::adicionar(Modalidade* m) {

    if(quantidadeDeModalidades >= maximoDeModalidades)
        return false;

    for(int i = 0; i < quantidadeDeModalidades; i++) {
        if(m->getNome() == this->modalidades[i]->getNome())
            return false;
    }

    this->modalidades[quantidadeDeModalidades] = m;
    quantidadeDeModalidades++;
    return true;
}

Modalidade** Competicao::getModalidades() {
    return this->modalidades;

}

int Competicao::getQuantidadeDeModalidades() {
    return this->quantidadeDeModalidades;
}

Tabela* Competicao::getTabela() {
    Tabela* r = new Tabela(this->getEquipes(),this->getQuantidadeDeEquipes());
    int pos;

    for(int i = 0; i < quantidadeDeModalidades; i++) {

       for(int j = 0; j < this->modalidades[i]->getQuantidadeDeEquipes(); j++) {

            pos = modalidades[i]->getPosicao(this->equipes[j]);

            if (pos == 1)
                r->pontuar(this->equipes[j],13);
            if (pos == 2)
                r->pontuar(this->equipes[j],10);
            if (pos == 3)
                r->pontuar(this->equipes[j],8);
            if (pos == 4)
                r->pontuar(this->equipes[j],7);
            if (pos == 5)
                r->pontuar(this->equipes[j],5);
            if (pos == 6)
                r->pontuar(this->equipes[j],4);
            if (pos == 7)
                r->pontuar(this->equipes[j],3);
            if (pos == 8)
                r->pontuar(this->equipes[j],2);
            if (pos == 9)
                r->pontuar(this->equipes[j],1);
            //para posicoes maiores ou iguais a 10, a pontuacao somada = 0.
       }
   }
   return r;
}

void Competicao::imprimir() {
    cout << this->nome << endl;
     Tabela* r = this->getTabela();

     r->imprimir();
}
