#ifndef TERMINAL_H
#define TERMINAL_H

#include "dinheiro.h"
#include "produtos.h"
#include "gerenciadorProdutos.h"

void init();

void draw_main_menu();

void draw_logo();

void draw_produto(const PRODUTO);

void cadastro(GerenciadorProdutos&);

void listar(GerenciadorProdutos&);

#endif // TERMINAL_H
