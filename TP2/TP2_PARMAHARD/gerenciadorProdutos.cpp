#include "gerenciadorProdutos.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstdlib>
#include <cstring>

GerenciadorProdutos::GerenciadorProdutos(const int maxProdutos){
    produtos = new PRODUTO[maxProdutos];
    numProdutos = maxProdutos;

    std::ifstream arquivo("produtos.dat",std::ios::binary);

	if (!arquivo) { //Se o arquivo nao existir, nao temos que ler mais nada. O arquivo sera criado no destrutor
		return;
	}

	for(int i=0; !arquivo.eof(); i++) {
        arquivo.read(reinterpret_cast<char *>(&(this->produtos[i])),sizeof(PRODUTO));
    }

	arquivo.close();
}

GerenciadorProdutos::GerenciadorProdutos(){
    this->numProdutos = 0;
    this->produtos = new PRODUTO[1];
}

GerenciadorProdutos::GerenciadorProdutos(const GerenciadorProdutos &copiado) { //Construtor de copia
    this->numProdutos = copiado.numProdutos;

    delete []this->produtos;
    this->produtos = new PRODUTO[this->numProdutos];

    for(int i=0; i<(this->numProdutos); i++) {
        this->produtos[i] = copiado.produtos[i];
    }
}

GerenciadorProdutos::~GerenciadorProdutos(){

    std::ofstream arquivo("produtos.dat",std::ios::out | std::ios::binary);

	if (!arquivo) {
		std::cerr << "Erro ao abrir arquivo de saída.." << std::endl;
		exit(1);
	}

	for(int i=0; i<(getNumProdutosCadastrados()); i++) { //Note que imprimimos apenas os PRODUTOs cadastrados
        arquivo.write(reinterpret_cast<char *>(&(this->produtos[i])),sizeof(PRODUTO)); //PRODUTOs vazios nao sao gravados
    }

    arquivo.close();

    delete [](this->produtos);
}

int GerenciadorProdutos::getNumProdutos() const {
    return numProdutos;
}

PRODUTO GerenciadorProdutos::getIesimoProduto(int i) const{
    if(i<0 || i >= this->numProdutos) {
        PRODUTO vazio;
        return vazio;
    }
    return this->produtos[i];
}

PRODUTO GerenciadorProdutos::getProduto(int codigo) const{
    for(int contador=0; contador<numProdutos; contador++) {
        PRODUTO temp = this->produtos[contador];
        if(temp.getCodigo() == codigo) {
            return this->produtos[contador];
        }

        else if(this->produtos[contador].getCodigo() == -1) { //Chegamos a um codigo -1, ou seja, nao temos mais nenhum produto cadastrado.
            PRODUTO vazio;
            return vazio;
        }
    }

    PRODUTO vazio;
    return vazio;
}

int GerenciadorProdutos::getNumProdutosCadastrados() const{
    for(int contador=0; contador<numProdutos; contador++) {
        if(this->getIesimoProduto(contador).getCodigo() == -1)  //Chegamos a um codigo -1, ou seja, nao temos mais nenhum produto cadastrado.
            return contador;
    }
    return this->numProdutos;
}

void GerenciadorProdutos::OrdenarProdutos() {   //Insertion Sort modificado para ordenar os produtos

    for (int i=1; i<(this->numProdutos); i++) {

        PRODUTO produtoInserir = this->getIesimoProduto(i);
        if(produtoInserir.getCodigo() == -1)
            continue;

        int j = i-1;
        while(j>=0 && (this->getIesimoProduto(j).getCodigo() > produtoInserir.getCodigo()
        || this->getIesimoProduto(j).getCodigo()==-1) ) {
            this->produtos[j+1] = this->produtos[j];
            j--;
        }
        this->produtos[j+1] = produtoInserir;
    }

    return;
}

void GerenciadorProdutos::armazenaProduto(const PRODUTO adicionado){

    if(adicionado.getCodigo() < 0) {
        return;
    }
    if(this->getProduto(adicionado.getCodigo()).getCodigo() != -1) {
        std::cout << "\nEste produto ja existe. Por favor utilize outro codigo.\n";
        system("sleep 2.0");
        return;
    }
    if(this->numProdutos == this->getNumProdutosCadastrados()) {
        std::cout << "\nVoce chegou no limite. Nao podemos adicionar mais produtos.\n";
        system("sleep 2.0");
        return;
    }

    this->produtos[this->getNumProdutosCadastrados()] = adicionado;
    this->OrdenarProdutos();

    return;
}

void GerenciadorProdutos::removeProduto(const int codigo){
    PRODUTO vazio;
    int contador=0;

    for( ; contador<(this->getNumProdutosCadastrados()); contador++) {
        if(this->produtos[contador].getCodigo() == codigo)
            break;
    }

    this->produtos[contador] = vazio;

    this->OrdenarProdutos();
}

void GerenciadorProdutos::removeTodosProdutos(){
    PRODUTO vazio;
    int numProdutosQueSeraoRemovidos = this->getNumProdutosCadastrados();
    for(int contador=0; contador<numProdutosQueSeraoRemovidos; contador++) {
        this->produtos[contador] = vazio;
    }
}
