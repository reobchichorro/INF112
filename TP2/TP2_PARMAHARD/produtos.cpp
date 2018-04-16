#include <iostream>
#include "produtos.h"

#include <cstring>
#include <cmath>

PRODUTO::PRODUTO(int codigo, char* nome, DINHEIRO precoCusto, int margemLucro, DINHEIRO impostoMunicipal){
    this->codigo = codigo;
    strcpy(this->nome, nome);
    this->precoCusto = precoCusto;
    this->margemLucro = margemLucro;
    this->impostoMunicipal = impostoMunicipal;
    this->precoVenda = (precoCusto*((double)margemLucro/100)) + precoCusto + impostoMunicipal; //Formula da especificacao
}

PRODUTO::PRODUTO(){ //Construtor vazio. Representa um PRODUTO vazio
    codigo = -1; //Codigo -1
    for(int i=0; i<50; i++)
        nome[i] = '\0'; //Sem nome
    DINHEIRO precoCusto(); //Construtor vazio de DINHEIRO. Insere 0,00
    margemLucro = 0; //margemLucro 0
    DINHEIRO impostoMunicipal(); //Construtor vazio de DINHEIRO. Insere 0,00
    DINHEIRO precoVenda(); //Construtor vazio de DINHEIRO. Insere 0,00
}

PRODUTO::PRODUTO(const PRODUTO &copiado) { //Construtor de copia

    this->codigo = copiado.codigo;
    strcpy(this->nome, copiado.nome);
    this->precoCusto = copiado.precoCusto;
    this->margemLucro = copiado.margemLucro;
    this->impostoMunicipal = copiado.impostoMunicipal;
    this->precoVenda = copiado.precoVenda;
}

PRODUTO::~PRODUTO() { //Nao precisamos fazer nada no destrutor, pois nao temos alocacao dinamica
}

//Metodos get
int PRODUTO::getCodigo() const{
    return codigo;
}

const char* PRODUTO::getNome() const{
    return nome;
}

DINHEIRO PRODUTO::getPrecoCusto() const{
    return precoCusto;
}

int PRODUTO::getMargemLucro() const{
    return margemLucro;
}

DINHEIRO PRODUTO::getImpostoMunicipal() const{
    return impostoMunicipal;
}

DINHEIRO PRODUTO::getPrecoVenda() const{
    return precoVenda;
}

//Sobrecarga de operadores
PRODUTO & PRODUTO::operator=(const PRODUTO &c){
    this->codigo = c.getCodigo();
    strcpy(this->nome, c.getNome());
    this->precoCusto = c.getPrecoCusto();
    this->margemLucro = c.getMargemLucro();
    this->impostoMunicipal = c.getImpostoMunicipal();
    this->precoVenda = c.getPrecoVenda();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const PRODUTO& produto){
    os << "===================================================="                                    << std::endl;
    os << "|                                                  |"                                    << std::endl;

    os << "|  Nome: ";
    os << produto.getNome();
    for(int i=0; i<42-strlen(produto.getNome()); i++) { std::cout << " "; }
    std::cout << "|" << std::endl;

    os << "|  Codigo: " << produto.getCodigo();
    if(produto.getCodigo()<=0){
        for(int i=0;i<39;i++){ std::cout << " "; }
    }
    else
        for(int i=0; i<39-(int)std::log10((float)produto.getCodigo()); i++) { std::cout << " "; }
    std::cout <<  "|" << std::endl;


    os << "|  Preco de Custo: " << produto.getPrecoCusto();
    if(produto.getPrecoCusto().getReais()==0){
        for(int i=0;i<25;i++){ std::cout << " ";};
    }
    else
        for(int i=0; i<25-(int)std::log10((float)(produto.getPrecoCusto()).getReais()); i++) { std::cout << " "; }
    std::cout <<  "|" << std::endl;

    os << "|  Margem de Lucro (%): " << produto.getMargemLucro();
    if(produto.getMargemLucro()<=0){
        for(int i=0;i<26;i++){std::cout << " "; }
    }
    else
        for(int i=0; i<26-(int)log10((float)produto.getMargemLucro()); i++) { std::cout << " "; }
    std::cout << "|" << std::endl;

    os << "|  Valor do Imposto Municipal: " << produto.getImpostoMunicipal();
    if(produto.getImpostoMunicipal().getReais()==0){
        for(int i=0;i<13;i++){ std::cout << " ";}
    }
    else
        for(int i=0; i<13-(int)std::log10((float)(produto.getImpostoMunicipal().getReais())); i++) {std::cout << " "; }
    std::cout << "|" << std::endl;

    os << "|  Preco de Venda: " << produto.precoVenda;
    if(produto.getPrecoVenda().getReais()==0){
        for(int i=0;i<25;i++) {std::cout << " ";}
    }
    else
        for(int i=0; i<25-(int)std::log10((float)(produto.getPrecoVenda()).getReais()); i++) { std::cout << " "; }
    std::cout <<  "|" << std::endl;

    os << "|                                                  |"                                    << std::endl;
    os << "===================================================="                                    << std::endl;
    return os;
}

