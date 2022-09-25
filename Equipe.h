#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include <iostream>

using namespace std;

class Equipe {
public:
    Equipe(string nome);
    ~Equipe();

    string getNome();
    void imprimir();

private:
    string nome;

};


#endif // EQUIPE_H_INCLUDED
