#ifndef GERENCIADORPRODUTOS_H
#define GERENCIADORPRODUTOS_H

#include "produtos.h"
#include "dinheiro.h"

class GerenciadorProdutos{
    private:
        PRODUTO* produtos; //Array dinamico que armazena os produtos
        int numProdutos; //Numero maximo de produtos que podem ser cadastrados
    public:
        GerenciadorProdutos(const int maxProdutos); //Construtor
        GerenciadorProdutos(); //Construtor
        GerenciadorProdutos(const GerenciadorProdutos &copiado); //Construtor de copia
        ~GerenciadorProdutos(); //Destrutor

        int getNumProdutos() const; //Retorna o valor de numProdutos

        PRODUTO getIesimoProduto(int i) const; //Retorna o i-esimo PRODUTO
        PRODUTO getProduto(int codigo) const; //Retorna on PRODUTO que possui o codigo passado como parametro
        int getNumProdutosCadastrados() const; //Retorna o numero de PRODUTOs nao-vazios armazenados pelo programa

        void OrdenarProdutos(); //Insertion Sort alterado que ordena de forma crescente em relacao ao codigo

        void armazenaProduto(const PRODUTO); //Armazena o PRODUTO no arranjo
        void removeProduto(const int codigo); //Remove o PRODUTO que possui o parametro como codigo
        void removeTodosProdutos(); //Auto-explicativo
};

#endif // GERENCIADOR_H
