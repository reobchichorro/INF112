#include <iostream>
#include <cmath>
using namespace std;

struct carga {
    int peso;
    int valor;
};

struct opcao {
    bool *combinacao;
    carga total_carregado;
};

void set_produtos(carga *produtos, int n) {
    for(int i=0; i<n; i++) {
        cout << "Digite o peso e o valor do produto " << i << ", separados por espaco: ";
        cin >> produtos[i].peso >> produtos[i].valor;
    }
}

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

void gerar_combinacoes_recursivo(opcao *opcoes_finais, bool *subtraendo, int i, const int m, const int n, const carga *produtos) {
    if(i>0)
    {
        for(int j=0; j<n; j++)
            opcoes_finais[i].combinacao[j] = opcoes_finais[i-1].combinacao[j];
        subtrair_binarios(opcoes_finais[i].combinacao, subtraendo, n, n-1);
        for(int j=0; j<n; j++)
        {
            if(opcoes_finais[i].combinacao[j]) {
                opcoes_finais[i].total_carregado.peso += produtos[j].peso;
                opcoes_finais[i].total_carregado.valor += produtos[j].valor;
            }
        }
    }
    else
        for(int j=0; j<n; j++)
            opcoes_finais[i].combinacao[j] = true;

    if(i<m-1)
        gerar_combinacoes_recursivo(opcoes_finais, subtraendo, i+1, m, n, produtos);

}

void achar_melhor_combinacao(opcao *opcoes_finais, carga *produtos, int &indice_da_resposta,
const int m, const int n, const int peso_limite) {

    for(int i=0; i<m; i++) {
        if(opcoes_finais[i].total_carregado.peso <= peso_limite &&
        opcoes_finais[i].total_carregado.valor > opcoes_finais[indice_da_resposta].total_carregado.valor) {
            indice_da_resposta = i;
        }
    }
    return;
}

int main() {

    int n, peso_limite;
    cout << "Digite o numero de produtos existentes: ";
    cin >> n;
    cout << "Digite o peso maximo que pode ser carregado na mochila: ";
    cin >> peso_limite;

    carga *produtos = new carga[n];

    set_produtos(produtos, n);

    int m = pow(2, n);  // m eh o numero de linhas, que eh o numero de combinacoes possiveis
    opcao *opcoes_finais = new opcao[m];
    bool *subtraendo = new bool[n];
    for(int i=0; i<m; i++) {
        opcoes_finais[i].combinacao = new bool[n];
        for(int j=0; j<n; j++)
        {
            opcoes_finais[i].combinacao[j] = false;
            subtraendo[j] = false;
        }
        opcoes_finais[i].total_carregado.peso = 0;
        opcoes_finais[i].total_carregado.valor = 0;
    }
    subtraendo[n-1] = true;

    gerar_combinacoes_recursivo(opcoes_finais, subtraendo, 0, m, n, produtos);

    int indice_da_resposta = m-1;

    achar_melhor_combinacao(opcoes_finais, produtos, indice_da_resposta, m, n, peso_limite);

    cout << endl << "Devemos carregar os produtos: ";
    for(int j=0; j<n; j++)
        if(opcoes_finais[indice_da_resposta].combinacao[j])
            cout << j << ", ";
    cout << "levando assim " << opcoes_finais[indice_da_resposta].total_carregado.peso << "Kg e ";
    cout << opcoes_finais[indice_da_resposta].total_carregado.valor << " reais." << endl;

    delete []subtraendo;
}
