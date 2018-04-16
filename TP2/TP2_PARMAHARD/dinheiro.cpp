#include <iostream>
#include "dinheiro.h"

DINHEIRO::DINHEIRO(const int Reais, const int Centavos){ //Construtor
    setReais(Reais);
    if(Centavos>=100)
        setCentavos(0);
    else
        setCentavos(Centavos);
}

DINHEIRO::DINHEIRO(){ //Construtor vazio
    setReais(0);
    setCentavos(0);
}

DINHEIRO::DINHEIRO(const DINHEIRO &copiado) { //Construtor de copia
    this->Reais = copiado.Reais;
    this->Centavos = copiado.Centavos;
}

//Metodos get
int DINHEIRO::getReais() const{
    return Reais;
}

int DINHEIRO::getCentavos() const{
    return Centavos;
}

//Metodos set
void DINHEIRO::setReais(const int valor){
    Reais = valor;
}

void DINHEIRO::setCentavos(const int valor){
    Centavos = valor;
}

//Sobrecarga de operadores
DINHEIRO & DINHEIRO::operator=(const DINHEIRO &c){
	if (&c == this)
		return *this;

    this->setReais(c.getReais());
    this->setCentavos(c.getCentavos());
	return *this;
}

DINHEIRO DINHEIRO::operator+(DINHEIRO ObjetoSoma) const{
    DINHEIRO ObjetoResultado;

    ObjetoResultado.setCentavos(getCentavos() + ObjetoSoma.getCentavos());
    ObjetoResultado.setReais(getReais() + ObjetoSoma.getReais());

    if(ObjetoResultado.getCentavos()>=100){ //Nao armazenamos mais que 99 Centavos.
        ObjetoResultado.setCentavos( ObjetoResultado.getCentavos() - 100 ); //Caso isso ocorra, tiramos 100 Centavos...
        ObjetoResultado.setReais( ObjetoResultado.getReais() + 1 ); //e adicionamos 1 Real, ou seja, nao perdemos o valor excedente.
    }

    return ObjetoResultado;
}

DINHEIRO DINHEIRO::operator-(DINHEIRO ObjetoSubtracao) const{
    DINHEIRO ObjetoResultado;

    ObjetoResultado.setCentavos(getCentavos() - ObjetoSubtracao.getCentavos());
    ObjetoResultado.setReais(getReais() - ObjetoSubtracao.getReais());

    if(ObjetoResultado.getCentavos()<0){ //Se o valor de Centavos eh negativo, devemos compensar tirando 1 real
        ObjetoResultado.setCentavos( ObjetoResultado.getCentavos() + 100 ); //e adicionando esse valor em Centavos
        ObjetoResultado.setReais( ObjetoResultado.getReais() - 1 );
    }
    if(ObjetoResultado.getReais()<0){ //Se o valor dReais eh negativo, eh porque o resultado da subtracao eh negativo
        ObjetoResultado.setReais(0); //Logo, como pedido na especificacao, os atributos sao setados para 0.
        ObjetoResultado.setCentavos(0);
    }

    return ObjetoResultado;
}

DINHEIRO& DINHEIRO::operator+=(const DINHEIRO ObjetoSoma){ //Mesma logica do operador +

    this->setCentavos(this->getCentavos() + ObjetoSoma.getCentavos());
    this->setReais(this->getReais() + ObjetoSoma.getReais());

    if(this->getCentavos()>=100){
        this->setCentavos( this->getCentavos() - 100 );
        this->setReais( this->getReais() + 1 );
    }

    return *this;
}

DINHEIRO& DINHEIRO::operator-=(const DINHEIRO ObjetoSubtracao){ //Mesma logica do operador -

    this->setCentavos(getCentavos() - ObjetoSubtracao.getCentavos());
    this->setReais(getReais() - ObjetoSubtracao.getReais());

    if(this->getCentavos()<0){
        this->setCentavos( this->getCentavos() + 100 );
        this->setReais( this->getReais() - 1 );
    }
    if(this->getReais()<0){
        this->setReais(0);
        this->setCentavos(0);
    }

    return *this;
}

DINHEIRO DINHEIRO::operator*(const double multiplicador){

    double resposta = getReais() + ((double)getCentavos()/100); //Passamos o valor do DINHEIRO para um double
                                                                //Assim, R$ 2,25 torna-se 2.25
    resposta *= multiplicador; //Dessa maneira, fazer a multiplicacao eh muito mais facil

    DINHEIRO ObjetoResultado;
    ObjetoResultado.setReais( (int)resposta ); //A parte inteira de resposta eh a parte Reais


    ObjetoResultado.setCentavos( (int)( (resposta-ObjetoResultado.getReais())*100  ) ); //Ja a parte decimal de resposta eh a parte Centavos

    if(ObjetoResultado.getReais() < 0) { //Resultado negativo retorna 0
        ObjetoResultado.setCentavos(0);
        ObjetoResultado.setReais(0);
    }

    return ObjetoResultado;
}

std::ostream& operator<<(std::ostream& os, const DINHEIRO& ObjetoPrint){ //Imprimimos R$ Reais,Centavos
    if(ObjetoPrint.getCentavos()<10){                                    //Ex.: R$ 2,05
        os <<  "R$ " <<ObjetoPrint.getReais() << ",0" << ObjetoPrint.getCentavos();
    }
    else{
        os <<  "R$ " <<ObjetoPrint.getReais() << "," << ObjetoPrint.getCentavos();
    }
    return os;
}
