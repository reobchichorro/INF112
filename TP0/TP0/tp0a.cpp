#include <iostream>
#include <cmath>
using namespace std;

struct produto {
    int peso;
    int valor;
};

void subtrair_binarios(bool *comb, bool *subtraendo, const int n, int i)    // Subtrai dois numeros binarios, representados como arranjos de inteiros
{
    for( ; i>=0; i--)
    {
        if((int)comb[i]==1 || (int)subtraendo[i]==0)
        {
            int temp = (int)comb[i] - (int)subtraendo[i];
            comb[i] = (bool)temp;
        }
        else
        {
            comb[i] = true;
            for(int j=i-1; j>=0; j--)
            {
                if((int)comb[j]==1)
                {
                    comb[j] = false;
                    break;
                }
                comb[j] = true;
            }
        }
    }
}

int binario_igual_a_0(bool *comb, const int tam) // Retorna a soma dos algarismos de um numero binario representado em um arranjo de inteiros.
                                                // Eh usado para verificar se o binario eh 0 (por isso o nome)
{
    int soma = 0;
    for(int i=tam-1; i>=0; i--)
    {
        soma += (int)comb[i];
    }
    return soma;
}

void gerar_combinacoes_recursivo(bool **combinacoes, bool *subtraendo, int i, const int m, const int n) {
    if(i>0)
    {
        for(int j=0; j<n; j++)
            combinacoes[i][j] = combinacoes[i-1][j];
        subtrair_binarios(combinacoes[i], subtraendo, n, n-1);
    }
    else
        for(int j=0; j<n; j++)
            combinacoes[i][j] = true;

    if(i<m-1)
        gerar_combinacoes_recursivo(combinacoes, subtraendo, i+1, m, n);

}

int main() {

    int n;
    cout << "Digite o numero de produtos existentes: ";
    cin >> n;

    int m = pow(2, n); // m eh o numero de linhas, que eh o numero de combinacoes possiveis
    bool **combinacoes = new bool*[m];  // A matriz de combinacoes armazenara as combinacoes de produtos
    for(int i=0; i<m; i++)              // Cada linha eh uma combinacao diferente, e cada coluna eh um produto diferente
        combinacoes[i] = new bool[n];   // Exemplo: Se a posicao [4][3] for true, quer dizer na combinacao 4, o produto 3
                                        // eh colocado na mochila.
    bool *subtraendo = new bool[n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++) {
            combinacoes[i][j] = false;  // Todas as posicoes sao inicializadas como falso, para evitar problemas com lixo de memoria
            subtraendo[j] = false;
        }

    subtraendo[n-1] = true;



    gerar_combinacoes_recursivo(combinacoes, subtraendo, 0, m, n);

    for(int i=0; i<m; i++) {
        cout << "Combinacao " << i << ": ";
        for(int j=0; j<n; j++)
            cout << combinacoes[i][j] << " ";
        cout << endl;
    }
    delete []subtraendo;

}

