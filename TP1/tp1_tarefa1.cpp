#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

void input(int **a, const int m, const int n)   // Le do teclado os valores da matriz de entrada
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

void limpar(int **b, const int m, const int n)  // Atribui -1 para todas as casas da matriz, para evitar problemas com lixo de memoria
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = -1;
}

void output(int **b, const int m, const int n)  // Imprime a saida do programa
{
    cout << "P1" << endl;
    cout << m << " " << n << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

void deletes(int **mat, const int m, const int n)   // Deleta o ponteiro de ponteiros passado como argumento
{
    for(int i = 0; i < m; i++)
    {
        delete []mat[i];
    }
    delete []mat;
}

void subtrair_binarios(int *comb, int *subtraendo, const int tam, int i)    // Subtrai dois numeros binarios, representados como arranjos de inteiros
{
    for( ; i>=0; i--)
    {
        if(comb[i]==1 || subtraendo[i]==0)
        {
            comb[i] -= subtraendo[i];
        }
        else
        {
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

void subtrair_1_no_binario(int *comb, const int tam)    // Subtrai 1 de um numero binario representado em um arranjo de inteiros
{
    int subtraendo = 1;
    for(int i=tam-1; i>=0; i--)
    {
        if(comb[i]==1 || subtraendo==0)
        {
            comb[i] -= subtraendo;
            break;
        }
        else
        {
            comb[i] = 1;
        }
    }
}

int binario_igual_a_0(int *comb, const int tam) // Retorna a soma dos algarismos de um numero binario representado em um arranjo de inteiros.
                                                // Eh usado para verificar se o binario eh 0 (por isso o nome)
{
    int soma = 0;
    for(int i=tam-1; i>=0; i--)
    {
        soma += comb[i];
    }
    return soma;
}

int testa_comb(int **a, int **b, const int m, const int n, const int *comb, const int tam)  // Testa se uma combinacao eh valida, e, caso nao seja, retorna
                                                                                            // em qual etapa a combinacao falhou. Caso contrario, ela retorna -1
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(comb[n*i+j] == 1)
                b[i][j] = 1;
            else
                b[i][j] = 0;
            for(int k=i-1; k<=i+1; k++)
            {
                if(k<0 || k>=m)
                    continue;

                for(int l=j-1; l<=j+1; l++)
                {
                    if(l<0 || l>=n)
                        continue;
                    if(a[k][l] >= 0)
                    {
                        int blackblocks=0;  // Blocos pintados de preto ao redor de a[k][l]
                        int freeblocks=0;   // Blocos que ainda noo estao pintados ao redor de a[k][l]
                        for (int g = k-1; g <= k+1; g++)
                        {
                            if(g<0 || g>=m)
                                continue;
                            for (int h = l-1; h <= l+1; h++)
                            {
                                if(h<0 || h>=n)
                                    continue;

                                if(b[g][h]==-1)
                                    freeblocks++;
                                if (b[g][h] == 1)
                                    blackblocks++;
                            }
                        }
                        if( (freeblocks < a[k][l] - blackblocks) || (blackblocks > a[k][l]) )
                        {
                            limpar(b, m, n);
                            return n*i+j;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

void gerar_combinacoes(int **a, int **b, const int m, const int n)  // Gera as possiveis combinacoes, e chama testa_comb para testa-las
{
    int tam = m*n;
    int *comb = new int[tam];
    for(int i=0; i<tam; i++)
        comb[i] = 1;
    int *subtraendo = new int[tam];
    for(int i=0; i<tam; i++)
        subtraendo[i] = 0;
    while(binario_igual_a_0(comb, tam) != 0)
    {
        int jump = testa_comb(a, b, m, n, comb, tam);
        if(jump == -1)
        {
            delete []comb;
            delete []subtraendo;
            return;
        }
        else
        {
            subtraendo[jump] = 1;
            subtrair_binarios(comb, subtraendo, tam, jump);
            subtraendo[jump] = 0;
        }

    }
    int jump = testa_comb(a, b, m, n, comb, tam);
    if(jump == -1)
    {
        delete []comb;
        delete []subtraendo;
        return;
    }

}

int main()
{
    // Declaracao das matrizes. **a eh a matriz de entrada, e **b eh a matriz de saida

    int m, n;   // m sao o numero de linhas e n o numero de colunas
    cin >> n >> m;

    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }

    input(a, m, n);     // Atribuicao da matriz de entrada

    int **b = new int *[m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new int[n];
    }

    limpar(b, m, n);    // Evitando problemas com lixo de memoria


    // Gerando e testando as combinacoes

    gerar_combinacoes(a, b, m, n);

    // Saida da resposta

    output(b, m, n);

    // Deletar as matrizes **a e **b

    deletes(a, m, n);
    deletes(b, m, n);

    return 0;
}
