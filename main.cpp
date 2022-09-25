#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"

#include <iostream>
#include <string>

using namespace std;

int main(){
    string nomeCompeticao, nomeEquipe, nomeModalidade;
    int m, n, colocacao;

    cout << "Informe o nome da competicao: " ;
    cin >> nomeCompeticao;
    cout << endl;

    cout << "Informe a quantidade de equipes: ";
    cin >> n;

    Equipe** equipes = new Equipe*[n];

    for(int i = 0; i < n; i++) {
        cout << "Informe o nome da equipe " << i+1 << ": ";
        cin >> nomeEquipe;
        equipes[i] = new Equipe(nomeEquipe);
    }
    cout << endl;

    cout << "Informe a quantidade de modalidades: ";
    cin >> m;

    Modalidade** modalidades = new Modalidade*[m];
    Competicao* comp = new Competicao(nomeCompeticao, equipes, n, m);

    for(int k = 0; k < m; k++) {
        Equipe** ordem = new Equipe*[n];

        cout << "Informe o nome da modalidade " << k+1 << ": ";
        cin >> nomeModalidade;

        modalidades[k] = new Modalidade(nomeModalidade, equipes, n);

        for(int j = 0; j < n; j++) {
            cout << "Informe a equipe " << j+1 << "a colocada: ";
            cin >>colocacao;

            ordem[j] = equipes[colocacao-1];
        }
            cout << endl;
            modalidades[k]->setResultado(ordem);
            comp->adicionar(modalidades[k]);
    }
        comp->imprimir();
        return 0;
}




