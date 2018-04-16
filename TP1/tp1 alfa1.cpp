#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

void input(int **a, const int m, const int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void limpar(int **b, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = -1;
		}
	}
}

void output(int **b, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}

void deletes(int **a, const int m, const int n)
{
    for(int i = 0; i < m; i++)
    {
        delete []a[i];
    }
    delete []a;
}

void transforma_binario(int *comb, const int tam, long long int c)
{
    for(int i=tam-1; i>=0; i--, c/=2)
    {
        comb[i] = c%2;
    }
}

int testa_comb(int **a, int **b, const int m, const int n, const int *comb, const int tam)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(comb[n*i+j] == 1)
                b[i][j] = 1;
            else
                b[i][j] = 0;
            //cout << "b[" << i << "][" << j << "] = " << b[i][j] << endl;
            // A limitacao do a deu errado
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
                        //cout << "Test. a[" << k << "][" << l << "] = " << a[k][l] << endl;
                        int blockcount=0;
                        int blocksfilled=0;
                        int num_de_vizinhos=0;
                        for (int g = k-1; g <= k+1; g++)
                        {
                            if(g<0 || g>=m)
                                continue;
                            for (int h = l-1; h <= l+1; h++)
                            {
                                if(h<0 || h>=n)
                                    continue;

                                num_de_vizinhos++;
                                if(b[g][h]>=0)
                                {
                                    blocksfilled++;
                                    if (b[g][h] == 1)
                                    {
                                        blockcount++;
                                    }
                                }
                                if(blockcount > a[k][l]) {
                                    limpar(b, m, n);
                                    return n*i+j;
                                }

                                //(blockcount <= a[k][l])
                            }
                        }
                        if(blocksfilled == num_de_vizinhos && blockcount<a[k][l]) {
                            limpar(b, m, n);
                            return n*i+j;
                        }


                    }
                }
            }
        }
    }
    //if(deu_errado)
    return -1;
}

void gerar_combinacoes(int **a, int **b, const int m, const int n)
{
    int tam = m*n;
    long long int total = pow(2, tam);
    int *comb = new int[tam];
    for(long long int c=total-1; c>=0; c--)
    {
        //cout << "Testando comb " << c << " - ";
        transforma_binario(comb, tam, c);
        int jump = testa_comb(a, b, m, n, comb, tam);
        if(jump = -1)
            return;
        else{}

        //cout << jump << endl;

//        int jump = pow(2, n-i-1);
//        for(int i=0; i<n; i++);
//        {
//            for(int j=0; j<n; j++)
//            {
//
//            }
//        }
    }
}



int main()
{
    int m, n;
    cout << "Digite o tamanho da matriz (colunas x linhas): ";
    cin >> n >> m;

	int **a = new int *[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}

	input(a, m, n);

	int **b = new int *[m];
	for (int i = 0; i < m; i++)
	{
		b[i] = new int[n];
	}

	limpar(b, m, n);

	int tam = m*n;
    long long int total = pow(2, tam); pow
    int *comb = new int[tam];
	transforma_binario(comb, tam, 479168902156295875247103331838);
	int jump = testa_comb(a, b, m, n, comb, tam);
	cout << jump << endl;

	//gerar_combinacoes(a, b, m, n);

//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] != -1)
//			{
//				int blockcount = 0;
//				for (int c = i-1; c <= n+1; c++)
//				{
//					for (int d = j - 1; d <= n + 1; d++)
//					{
//						if ( (blockcount <= a[i][j]) && (c - 1 >= 0) && (d - 1 >= 0) )
//						{
//							b[c][d] = 1;
//							blockcount++;
//						}
//						output(b, n);
//					}
//				}
//			}
//		}
//	}

	// </backtracking>

	output(b, m, n);
    deletes(a, m, n);

	return 0;
}

