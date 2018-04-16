#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

void input(int **a, int n)
{
	cout << "digite os valores da matriz: " << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void limpar(int **b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = -1;
		}
	}
}

void output(int **b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
}

void deletes(int **a, int n)
{
    for(int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete []a;
}

void transforma_bin(int *a, const int tam, int c)
{
    for(int i=tam-1; i>=0; i--, c/=2)
    {
        a[i] = c%2;
    }
    for(int i=0; i<tam; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void gerar_combinacoes(const int **a, int **b, const int n);

int main()
{
    int n;
    cout << "Digite o tamanho da matriz: ";
    cin >> n;

    int *teste = new int[n];
    transforma_bin(teste, n, 23);

	int **a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
//
//	input(a, n);
//
//	int **b = new int *[n];
//	for (int i = 0; i < n; i++)
//	{
//		b[i] = new int[n];
//	}
//
//	limpar(b, n);
//
//	// <backtracking>
//
////	for (int i = 0; i < n; i++)
////	{
////		for (int j = 0; j < n; j++)
////		{
////			if (a[i][j] != -1)
////			{
////				int blockcount = 0;
////				for (int c = i-1; c <= n+1; c++)
////				{
////					for (int d = j - 1; d <= n + 1; d++)
////					{
////						if ( (blockcount <= a[i][j]) && (c - 1 >= 0) && (d - 1 >= 0) )
////						{
////							b[c][d] = 1;
////							blockcount++;
////						}
////						output(b, n);
////					}
////				}
////			}
////		}
////	}
//
//	// </backtracking>
//
//	output(a, n);
//    deletes(a, n);

	return 0;
}

//void gerar_combinacoes(const int **a, int **b, const int n)
//{
//    bool **combin = new bool*[n]
//    for(int i=0; i<n; i++)
//        combin[i] = new bool[n];
//    int tam = n*n;
//    int total = pow(2, tam);
//    int *comb = new int[tam];
//    for(int c=total-1; c>=0; c--)
//    {
//        transforma_bin(comb, tam, c);
////        int jump = pow(2, n-i-1);
////        for(int i=0; i<n; i++);
////        {
////            for(int j=0; j<n; j++)
////            {
////
////            }
////        }
//    }
//}
//
//
