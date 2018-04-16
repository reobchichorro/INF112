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

void set_produtos(carga *produtos, int n);

void gerar_combinacoes_recursivo(opcao &opcoes_finais, opcao &resposta, const int n, const carga *produtos, const int peso_limite);

int main() {

    int n, peso_limite;
    cout << "Digite o numero de produtos existentes: ";
    cin >> n;
    cout << "Digite o peso maximo que pode ser carregado na mochila: ";
    cin >> peso_limite;

    carga *produtos = new carga[n];

    set_produtos(produtos, n);

    opcao opcoes_finais;
    opcoes_finais.total_carregado.peso = 0;
    opcoes_finais.total_carregado.valor = 0;
    opcoes_finais.combinacao = new bool[n];
    for(int j=0; j<n; j++)
    {
        opcoes_finais.combinacao[j] = false;
    }

    opcao resposta;
    resposta.total_carregado.peso = 0;
    resposta.total_carregado.valor = 0;
    resposta.combinacao = new bool[n];
    for(int j=0; j<n; j++)
    {
        resposta.combinacao[j] = false;
    }

    int j=0;

    gerar_combinacoes_recursivo(opcoes_finais, resposta, n, produtos, peso_limite);

//    for(int i=0; i<m; i++) {
//        cout << "Combinacao " << i << ": ";
//        for(int j=0; j<n; j++)
//            cout << opcoes_finais[i].combinacao[j] << " ";
//        cout << "carrega: " << opcoes_finais[i].total_carregado.peso << " Kgs " << opcoes_finais[i].total_carregado.valor << " reais";
//        cout << endl;
//    }

    cout << endl << "Devemos carregar os produtos: ";
    for(int j=0; j<n; j++)
        if(resposta.combinacao[j])
            cout << j << ", ";
    cout << "levando assim " << resposta.total_carregado.peso << "Kg e ";
    cout << resposta.total_carregado.valor << " reais." << endl;

    return 0;
}

void set_produtos(carga *produtos, int n) {
    for(int i=0; i<n; i++) {
        cout << "Digite o peso e o valor do produto " << i << ", separados por espaco: ";
        cin >> produtos[i].peso >> produtos[i].valor;
    }
}

void gerar_combinacoes_recursivo(opcao &opcoes_finais, opcao &resposta, const int n, const carga *produtos, const int peso_limite) {

    for(int i=0; i<n; i++)
        opcoes_finais.combinacao[i] = true;
    bool *subtraendo = new bool[n];
    for(int i=0; i<n; i++)
        subtraendo[i] = false;
    while(binario_igual_a_0(opcoes_finais.combinacao, n) != 0)
    {
        bool possivel_resposta = true;
        for(int j=0; j<n; j++)
        {
            if(opcoes_finais.combinacao[j])
            {
                opcoes_finais.total_carregado.peso += produtos[j].peso;
                opcoes_finais.total_carregado.valor += produtos[j].valor;

                if(opcoes_finais.total_carregado.peso > peso_limite)
                {
                    subtraendo[j] = 1;
                    subtrair_binarios(opcoes_finais.combinacao, subtraendo, n, j);
                    subtraendo[j] = 0;
                    opcoes_finais.total_carregado.peso=0;
                    opcoes_finais.total_carregado.valor=0;
                    possivel_resposta = false;
                    break;
                }
            }
        }
        if(possivel_resposta)
        {
            if(opcoes_finais.total_carregado.valor > resposta.total_carregado.valor)
            {
                resposta.total_carregado.peso = opcoes_finais.total_carregado.peso;
                resposta.total_carregado.valor = opcoes_finais.total_carregado.valor;
                for(int j=0; j<n; j++)
                    resposta.combinacao[j] = opcoes_finais.combinacao[j];
                opcoes_finais.total_carregado.peso=0;
                opcoes_finais.total_carregado.valor=0;
            }
            else
            {
                opcoes_finais.total_carregado.peso=0;
                opcoes_finais.total_carregado.valor=0;
            }
            subtraendo[n-1] = 1;
            subtrair_binarios(opcoes_finais.combinacao, subtraendo, n, n-1);
            subtraendo[n-1] = 0;
        }
    }
    delete []subtraendo;
}
