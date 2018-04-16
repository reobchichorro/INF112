#include <iostream>
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

void limpar_v2(int **b, bool **eh_fixo, const int m, const int n)  // Atribui -1 para todas as casas da matriz, para evitar problemas com lixo de memoria
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(!eh_fixo[i][j])
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

// para setar o valor de X para os blocos adjacentes ao que foi
// passado por parametro na funcao
void setX(int **b, const int m, const int n, int y, int x)
{
	for(int i = -1; i <= 1; i++)
	{
		if((y+i >= 0) && (y+i < m)) //verifica se a linha e valida
		{
			for(int j = -1; j <= 1; j++)
			{
				if((x+j >= 0) && (x+j < n)) // verifica se a coluna e valida
				{
					if(b[y+i][x+j] == -1) 	// verifica se o bloco e vazio
					{
						b[y+i][x+j] = 0;  	// seta o bloco como com X
					}
				}
			}
		}
	}
}

// para colorir todos os blocos adjacentes ao que foi
// passado por parametro na funcao
void setBlack(int **b, const int m, const int n, int y, int x)
{
	for(int i = -1; i <= 1; i++)
	{
		if((y+i >= 0) && (y+i < m)) //verifica se a linha e valida
		{
			for(int j = -1; j <= 1; j++)
			{
				if((x+j >= 0) && (x+j < n)) // verifica se a coluna e valida
				{
					if(b[y+i][x+j] == -1) 	// verifica se o bloco e vazio.
					{
						b[y+i][x+j] = 1;  	// seta b como um bloco colorido
					}
				}
			}
		}
	}
}

// para contar quantos blocos sao coloridos ou vazios em b
// (ou seja, sem X) adjacentes ao que foi passado por parametro na funcao
int num_blocks_without_X(int **b, const int m, const int n, int y, int x)
{
	int num = 0;

	for(int i = -1; i <= 1; i++)
	{
		if((y+i >= 0) && (y+i < m)) //verifica se a linha e valida
		{
			for(int j = -1; j <= 1; j++)
			{
				if((x+j >= 0) && (x+j < n)) // verifica se a coluna e valida
				{
					if(b[y+i][x+j] != 0) 	// verifica se b e vazio ou colorido.
					{
						num++;
					}
				}
			}
		}
	}
	return num;
}

// conta o numero de blocos coloridos ao redor de
// uma determinada posicao na matriz A
int num_black_blocks(int **b, const int m, const int n, int y, int x)
{
	int num = 0;

	for(int i = -1; i <= 1; i++) // verifica se a linha eh valida
	{
		if((y+i >= 0) && (y+i < m))
		{
			for(int j = -1; j <= 1; j++)
			{
				if((x+j >= 0) && (x+j < n)) // verifica se a coluna e valida
				{
					if(b[y+i][x+j] == 1) 	  // verifica se b e colorido.
					{
						num++;				  // em caso afirmativo, incrementa "num"
					}
				}
			}
		}
	}
	return num;
}

void adjacent_trick_vertical(int **a, int **b, const int m, const int n, int i, int j)
{
	if (a[i][j] - a[i+1][j] == 3)
	{
		if(i-1 >= 0 && j-1 >= 0)	b[i-1][j-1] = 1;
		if(i-1 >= 0)				b[i-1][j] = 1;
		if(i-1 >= 0 && j+1 < n)		b[i-1][j+1] = 1;
		if(i+2 >= 0 && j-1 >= 0)	b[i+2][j-1] = 0;
		if(i+2 >= 0)				b[i+2][j] = 0;
		if(i+2 >= 0 && j+1 < n)		b[i+2][j+1] = 0;
	}
	else if (a[i][j] - a[i+1][j] == -3)
	{
		if(i-1 >= 0 && j-1 >= 0)	b[i-1][j-1] = 0;
		if(i-1 >= 0)				b[i-1][j] = 0;
		if(i-1 >= 0 && j+1 < n)		b[i-1][j+1] = 0;
		if(i+2 >= 0 && j-1 >= 0)	b[i+2][j-1] = 1;
		if(i+2 >= 0)				b[i+2][j] = 1;
		if(i+2 >= 0 && j+1 < n)		b[i+2][j+1] = 1;
	}
}

void adjacent_trick_horizontal(int **a, int **b, const int m, const int n, int i, int j)
{
	if (a[i][j] - a[i][j+1] == 3)
	{
		if(i-1 >= 0 && j-1 >= 0)	b[i-1][j-1] = 1;
		if(j-1 >= 0)				b[i][j-1] = 1;
		if(i+1 < m && j-1 >= 0)		b[i+1][j-1] = 1;
		if(i-1 >= 0 && j+2 < n)		b[i-1][j+2] = 0;
		if(j+2 < n)					b[i][j+2] = 0;
		if(i-1 >= 0 && j+2 < n)		b[i-1][j+2] = 0;
	}
	else if (a[i][j] - a[i][j+1] == -3)
	{
		if(i-1 >= 0 && j-1 >= 0)	b[i-1][j-1] = 0;
		if(j-1 >= 0)				b[i][j-1] = 0;
		if(i+1 < m && j-1 >= 0)		b[i+1][j-1] = 0;
		if(i-1 >= 0 && j+2 < n)		b[i-1][j+2] = 1;
		if(j+2 < n)					b[i][j+2] = 1;
		if(i-1 >= 0 && j+2 < n)		b[i-1][j+2] = 1;
	}
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
    static bool **eh_fixo = new bool*[m];
    for(int i=0; i<m; i++)
    {
        eh_fixo[i] = new bool[n];
        for(int j=0; j<n; j++)
            eh_fixo[i][j] = true;
    }
    int dummy = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(b[i][j] == -1)
            {
                eh_fixo[i][j] = false;
                if(comb[dummy] == 1)
                    b[i][j] = 1;
                else
                    b[i][j] = 0;
                dummy++;
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
                                limpar_v2(b, eh_fixo, m, n);
//                                for(int linha=0; linha<m; linha++)
//                                    delete []eh_fixo[linha];
//                                delete []eh_fixo;
                                return dummy;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i=0; i<m; i++)
        delete []eh_fixo[i];
    delete []eh_fixo;
    return -1;
}

int contar_pos_vazias(int **b, const int m, const int n) {
    int tam=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(b[i][j] == -1)
                tam++;
        }
    }
    return tam;
}

void gerar_combinacoes(int **a, int **b, const int m, const int n, const int &tam)  // Gera as possiveis combinacoes, e chama testa_comb para testa-las
{
    int *comb = new int[tam];
    for(int i=0; i<tam; i++)
        comb[i] = 1;
    int *subtraendo = new int[tam];
    cout << "comb\n";
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

// Funcao principal que preenche a matriz "b" ou com blocos vazios
// ou com blocos coloridos
void fill(int **a, int **b, const int m, const int n)
{
	// para achar valores em a que nao dependem de outros resultados para alterar b
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				setX(b, m, n, i, j);
			}
			else if (a[i][j] == 4 && ((i - 1 == -1 && j - 1 == -1) || (i - 1 == -1 && j + 1 == n)
				|| (i + 1 == n && j - 1 == -1) || (i + 1 == n && j + 1 == n)))
			{
				setBlack(b, m, n, i, j);
			}
			else if (a[i][j] == 6 && ( ( (i==0 || i==n-1) && j>0 && j<n-1 ) || ( (j==0 || j==n-1) && i>0 && i<n-1 ) ) )
			{
				setBlack(b, m, n, i, j);
			}
			else if (a[i][j] == 9)
			{
				setBlack(b, m, n, i, j);
			}
			if ((i+1 < n) && (a[i][j] != -1) && (a[i+1][j] != -1))
			{
				if((abs(a[i][j] - a[i+1][j])) == 3)
				{
					adjacent_trick_vertical(a, b, m, n, i, j);
				}
			}
			// if ((abs(a[i][j] - a[i][j+1]) == 3) && (j+1 < n) && a[i][j] != -1 && a[i][j+1] != -1)
			// {
			// 	adjacent_trick_horizontal(a, b, n, i, j);
			// }
		}
	}

	// para preencher o campo continuamente ate nao sobrar campos vazios
	bool continua = true;
    int vezes_que_a_passagem_nao_fez_nada = 0;
	while (continua && vezes_que_a_passagem_nao_fez_nada < 3)
	{
	    vezes_que_a_passagem_nao_fez_nada++;
		continua = false;
		for(int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(b[i][j] == -1)
				{
					continua = true;
				}
				//cout << num_blocks_without_X(b, m, n, i, j) << " " << a[i][j] << " " << i << " " << j << endl;
				if(num_black_blocks(b, m, n, i, j) != num_blocks_without_X(b, m, n, i, j))
				{
				    if (num_blocks_without_X(b, m, n, i, j) == a[i][j])
                    {
                        setBlack(b, m, n, i, j);
                        vezes_que_a_passagem_nao_fez_nada=0;
                    }
                    if (num_black_blocks(b, m, n, i, j) == a[i][j])
                    {
                        setX(b, m, n, i, j);
                        vezes_que_a_passagem_nao_fez_nada=0;
                    }
                }
			}
		}
	}

	int tam = contar_pos_vazias(b, m, n);
	gerar_combinacoes(a, b, m, n, tam);
}

int main()
{
    int m, n;
	cin >> n >> m;
	// n eh o numero de linhas e colunas. para que nao haja conflito com
	// a entrada especificada no pdf, foram feitos dois "cin's".

	int **a = new int *[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
	// a matriz "a" eh a matriz de entrada. nada sera alterado
	// nela durante a execucao.

	input(a, m, n);

	int **b = new int *[m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new int[n];
	}
	// a matriz b eh a matriz que diz se os blocos devem ser coloridos ou nao.
	// em b, o valor -1 representa um bloco vazio, 0 representa um bloco com X
	// e o valor 1 representa um bloco preenchido.

	limpar(b, m, n);

	fill(a, b, m, n);

	output(b, m, n);
    deletes(a, m, n);
    deletes(b, m, n);

	return 0;
}

