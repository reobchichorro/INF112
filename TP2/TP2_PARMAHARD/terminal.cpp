#include "terminal.h"

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>


void init(){
    GerenciadorProdutos gerenciador(100);

    std::cout << "\033[0;32m";

    draw_logo();

    std::cout << "Press enter..." << std::endl;

    char choose_option = '0';
    int MenuPos = 0;
    while(std::cin.get(choose_option)){
        if(choose_option=='1'){
            cadastro(gerenciador);
        }
        else if(choose_option=='2'){
            system("clear");
            listar(gerenciador);
            std::cout << "Pressione 'Enter' para sair...";
            while(!std::cin.get());
        }
        else if(choose_option=='3'){
            int codigo;
            std::cout << "Digite o codigo do produto a ser removido: "; std::cin >> codigo;
            gerenciador.removeProduto(codigo);
        }
        else if(choose_option=='4'){
            gerenciador.removeTodosProdutos();
        }
        else if(choose_option=='5'){
            int codigo;
            std::cout << "Digite o codigo do produto a ser pesquisado: "; std::cin >> codigo;
            std::cout << gerenciador.getProduto(codigo);
            std::cout << "Pressione 'Enter' para sair...";
            while(!std::cin.get());
        }
        else if(choose_option=='6'){
        system("clear");
            break;
        }
        else{
            draw_main_menu();
        }
    }

    std::cout << "\33[0m" << std::endl;
}

void draw_logo(){

    system("clear");

    std::cout << " _____                           _                   _" << std::endl;
    std::cout << "|  __ \\                         | |                 | |"<< std::endl;
    std::cout << "| |__) |_ _ _ __ _ __ ___   __ _| |__   __ _ _ __ __| |"<< std::endl;
    std::cout << "|  ___/ _` | '__| '_ ` _ \\ / _` | '_ \\ / _` | '__/ _` |"<< std::endl;
    std::cout << "| |  | (_| | |  | | | | | | (_| | | | | (_| | | | (_| |"<< std::endl;
    std::cout << "|_|   \\__,_|_|  |_| |_| |_|\\__,_|_| |_|\\__,_|_|  \\__,_|"<< std::endl;
    std::cout << "                                                       "<< std::endl;
}

void draw_main_menu(){

    system("clear");

    std::cout << "===================================" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "| Menu Principal:                 |" << std::endl;
    std::cout << "| 1- Cadastrar produto            |" << std::endl;
    std::cout << "| 2- Listar produtos              |" << std::endl;
    std::cout << "| 3- Remover produto              |" << std::endl;
    std::cout << "| 4- Remover todos produtos       |" << std::endl;
    std::cout << "| 5- Consultar produto com codigo |" << std::endl;
    std::cout << "| 6- Sair                         |" << std::endl;
    std::cout << "|                                 |" << std::endl;
    std::cout << "===================================" << std::endl;

}

void draw_produto(const PRODUTO produtoParaDesenhar) {
    system("clear");
    std::cout << produtoParaDesenhar;
}

void cadastro(GerenciadorProdutos& gerenciador) {

    system("clear");
    int codigo, margemLucro;
    char nome[50];
    int custoReais, custoCentavos;
    int impostoReais, impostoCentavos;
    std::cout << "Digite o codigo do produto: "; std::cin >> codigo;
    std::cin.ignore();
    std::cout << "Digite o nome do produto: "; std::cin.getline(nome, 50);
    std::cout << "Digite o preco do produto, separando os centavos com virgula (Ex: 2,52): ";
    std::cin >> custoReais; std::cin.ignore(1); std::cin >> custoCentavos;
    std::cout << "Digite a margem de lucro do produto (%): "; std::cin >> margemLucro;
    std::cout << "Digite o valor do imposto municipal (Ex: 0,78): ";
    std::cin >> impostoReais; std::cin.ignore(1); std::cin >> impostoCentavos;

    DINHEIRO precoCusto(custoReais, custoCentavos);
    DINHEIRO impostoMunicipal(impostoReais, impostoCentavos);
    PRODUTO adicionado(codigo, nome, precoCusto, margemLucro, impostoMunicipal);
    gerenciador.armazenaProduto(adicionado);
}

void listar(GerenciadorProdutos& gerenciador) {
    std::cout << "Produtos cadastrados:\n";
    system("sleep 0.25");
    for(int contador=0; contador<(gerenciador.getNumProdutosCadastrados()); contador++) {
        std::cout << gerenciador.getIesimoProduto(contador);
        system("sleep 0.1");
    }
}

