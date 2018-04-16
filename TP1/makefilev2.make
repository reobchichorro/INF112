all: msgola tp1_tarefa1	tp1_tarefa2
	@echo Programa compilados com sucesso 
    
 

msgola:  
	
	@echo Bem vindo ao makefile. Vou tentar compilar os programas.
 


tp1_tarefa1: tp1_tarefa1.o 
	
	g++ -o tp1_tarefa1 tp1_tarefa1.o –lglui –lglut32 –lopengl32
 


tp1_tarefa1.o: tp1_tarefa1.cpp tp1_tarefa1.h 
	
	g++ -c tp1_tarefa1.cpp

tp1_tarefa2: tp1_tarefa2.o 
	
	g++ -o tp1_tarefa2 tp1_tarefa2.o –lglui –lglut32 –lopengl32
 


tp1_tarefa2.o: tp1_tarefa2.cpp tp1_tarefa2.h 
	
	g++ -c tp1_tarefa2.cpp



