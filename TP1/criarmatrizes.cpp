#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    int **mat = new int*[n];
    for(int i = 0; i < m; i++) {
        mat[i] = new int[n];
        for(int j = 0; j < n; j++)
            mat[i][j] = -1;
    }

    int valor, x, y;
	do {
        cin >> valor >> x >> y;

	} while(valor >= 0);

    cout << m << " " << n << endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
	}

    for(int i = 0; i < m; i++)
        delete []mat[i];
    delete []mat;

    return 0;
}
