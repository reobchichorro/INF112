#include <iostream>
#include <fstream>
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

void clear(int **b, int n)
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


int main()
{
    int n;
    cout << "Digite o tamanho da matriz: ";
	int **a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	input(a, n);

	int **b = new int *[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = new int[n];
	}

	clear(b, n);

	// <backtracking>

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != -1)
			{
				int blockcount = 0;
				for (int c = i-1; c <= n+1; c++)
				{
					for (int d = j - 1; d <= n + 1; d++)
					{
						if ( (blockcount <= a[i][j]) && (c - 1 >= 0) && (d - 1 >= 0) )
						{
							b[c][d] = 1;
							blockcount++;
						}
						output(b, n);
					}
				}
			}
		}
	}

	// </backtracking>

	output(a, n);
    deletes(a, n);

	return 0;
}
