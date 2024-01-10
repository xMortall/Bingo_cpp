#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void mostrarPainel(int totalNumeros, const vector<bool>& marcados) {
    cout << "xxxxxxxxxx PAINEL xxxxxxxxxx\n";
    for (int i = 1; i <= totalNumeros; ++i) {
        if (marcados[i - 1]) {
            cout << "x ";
        } else {
            cout << i << " ";
        }
        if (i % 15 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void gerarCartao(int numeroCartao, int totalNumeros, vector<bool>& marcados) {
    cout << "Gerando cartão " << numeroCartao << "...\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int numero = rand() % totalNumeros + 1;
            marcados[numero - 1] = true;
        }
    }
}

int main() {
    srand(time(0)); 

    int totalNumeros;
    int modoSorteio;

    cout << "Deves escolher entre um sorteio de 75 (1), 90 (2) ou 100 (3) números: ";
    cin >> modoSorteio;

    switch (modoSorteio) {
        case 1:
            totalNumeros = 75;
            break;
        case 2:
            totalNumeros = 90;
            break;
        case 3:
            totalNumeros = 100;
            break;
        default:
            cerr << "Opção inválida." << endl;
            return 1;
    }

    vector<bool> marcados(totalNumeros, false);
    mostrarPainel(totalNumeros, marcados);

    int escolha;
    cout << "Escolha o modo de sorteio (1 - Automático, 2 - Manual): ";
    cin >> escolha;

    if (escolha == 1) {
        int quantidadeSorteios;
        cout << "Quantos sorteios automáticos deseja realizar? ";
        cin >> quantidadeSorteios;

        for (int sorteio = 1; sorteio <= quantidadeSorteios; ++sorteio) {
            cout << "\nSorteio Automático #" << sorteio << endl;

            for (int i = 1; i <= totalNumeros; ++i) {
               
                cout << "Número sorteado: " << i << endl;
                if (i > 1) {
                    cout << "Anterior: " << i - 1 << endl;
                }
                marcados[i - 1] = true;
                mostrarPainel(totalNumeros, marcados);
                
                if (i == totalNumeros) {
                    cout << "Todos os números foram marcados!\n";
                }
            }

            
            marcados.assign(totalNumeros, false);
        }
    } else if (escolha == 2) {
        int quantidadeCartoes;

        cout << "Quantos cartões deseja gerar? ";
        cin >> quantidadeCartoes;

        if (quantidadeCartoes > 0) {
            for (int i = 1; i <= quantidadeCartoes; ++i) {
                gerarCartao(i, totalNumeros, marcados);
                mostrarPainel(totalNumeros, marcados);
                
                if (i == quantidadeCartoes) {
                    cout << "Todos os números foram marcados!\n";
                }
            }
        } else {
            cerr << "A quantidade de cartões deve ser maior que zero." << endl;
            return 1;
        }
    } else {
        cerr << "Opção inválida." << endl;
        return 1;
    }

    return 0;
}
