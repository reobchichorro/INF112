#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "dinheiro.h"

#include <iostream>

typedef unsigned char uint8_t;

class PRODUTO{
    private:
        int codigo;
        char nome[50];
        DINHEIRO precoCusto;
        int margemLucro;
        DINHEIRO impostoMunicipal;

        DINHEIRO precoVenda;

    public:
        PRODUTO(int codigo, char* nome, DINHEIRO precoCusto, int margemLucro, DINHEIRO impostoMunicipal); //Construtor
        PRODUTO(); //Construtor vazio
        PRODUTO(const PRODUTO &copiado); //Construtor de copia
        ~PRODUTO(); //Destrutor

        //Metodos get
        int getCodigo() const;
        const char* getNome() const;
        DINHEIRO getPrecoCusto() const;
        int getMargemLucro() const;
        DINHEIRO getImpostoMunicipal() const;
        DINHEIRO getPrecoVenda() const;

        //Sobrecarga de operadores
        PRODUTO & operator=(const PRODUTO &);
        friend std::ostream& operator<<(std::ostream&, const PRODUTO&);
};

#endif // PRODUTOS_H
