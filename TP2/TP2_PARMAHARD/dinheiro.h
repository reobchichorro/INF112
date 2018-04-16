#ifndef DINHEIRO_H
#define DINHEIRO_H

#include <iostream>
#include <stdlib.h>

class DINHEIRO{
    private:
        int Reais;
        int Centavos;
    public:
        DINHEIRO(const int, const int); //Construtor
        DINHEIRO(); //Construtor vazio
        DINHEIRO(const DINHEIRO &copiado); //Construtor de copia

        //Metodos get
        int getReais() const;
        int getCentavos() const;

        //Metodos set
        void setReais(const int);
        void setCentavos(const int);

        //Sobrecarga de operadores
        DINHEIRO & operator=(const DINHEIRO &);
        DINHEIRO operator+(DINHEIRO) const;
        DINHEIRO operator-(DINHEIRO) const;
        DINHEIRO& operator+=(const DINHEIRO);
        DINHEIRO& operator-=(const DINHEIRO);
        DINHEIRO operator*(const double);
        friend std::ostream& operator<<(std::ostream&, const DINHEIRO&);

};

#endif // DINHEIRO_H
