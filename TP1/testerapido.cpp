#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;


void subtrair_binarios(int *comb, int *subtraendo, const int tam, int i)
{
    for( ; i>=0; i--) {
        if(comb[i]==1 || subtraendo[i]==0) {
            comb[i] -= subtraendo[i];
        }
        else {
            comb[i] = 1;
            for(int j=i-1; j>=0; j--)
            {
                if(comb[j]==1)
                {
                    comb[j] = 0;
                    break;
                }
                comb[j] = 1;
            }
        }
    }
}

int binario_igual_a_0(int *comb, const int tam) {
    int soma = 0;
    for(int i=tam-1; i>=0; i--) {
        soma += comb[i];
    }
    return soma;
}

int main()
{
    int tam = 4;
    long long int total = pow(2, tam);
    int *comb = new int[tam];
    comb[0] = comb[1] = comb[3] = 1;
    comb[2] = 0;
    for(int i=0; i<tam; i++)
        cout << comb[i];
    cout << endl;
    int *subtraendo = new int[tam];
    subtraendo[0] = subtraendo[2] = subtraendo[3] = 0;
    subtraendo[1] = 1;
    for(int i=0; i<tam; i++)
        cout << subtraendo[i];
    cout << endl;
    subtrair_binarios(comb, subtraendo, tam, 1);
    for(int i=0; i<tam; i++)
        cout << comb[i];
    cout << endl;
    cout << binario_igual_a_0(comb, tam) << endl;


    return 0;
}
