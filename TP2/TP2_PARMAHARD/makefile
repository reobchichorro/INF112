all: Gerenciador.exe

Gerenciador.exe: main.o terminal.o gerenciadorProdutos.o produtos.o dinheiro.o
	g++ main.o terminal.o gerenciadorProdutos.o produtos.o dinheiro.o -o Gerenciador.exe 

main.o: main.cpp terminal.h gerenciadorProdutos.h produtos.h dinheiro.h
	g++ -c main.cpp

terminal.o: terminal.h terminal.cpp gerenciadorProdutos.h produtos.h dinheiro.h
	g++ -c terminal.cpp

gerenciadorProdutos.o: gerenciadorProdutos.h gerenciadorProdutos.cpp
	g++ -c gerenciadorProdutos.cpp

produtos.o: produtos.h produtos.cpp
	g++ -c produtos.cpp

dinheiro.o: dinheiro.h dinheiro.cpp
	g++ -c dinheiro.cpp