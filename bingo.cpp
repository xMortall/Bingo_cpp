#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrarPainel(int totalNumeros) {
    cout << "xxxxxxxxxx PAINEL xxxxxxxxxx\n";
    for (int i = 1; i <= totalNumeros; ++i) {
        cout << i << " ";
        if (i % 15 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

void gerarCartao(int numeroCartao, int totalNumeros) {
    string nomeArquivo = "cartao" + to_string(numeroCartao) + ".txt";
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                int numero = rand() % totalNumeros + 1;
                arquivo << numero << " ";
            }
            arquivo << endl;
        }

        arquivo.close();
        cout << "Cartão gerado com sucesso: " << nomeArquivo << endl;
    } else {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
    }
}

int main() {
    srand(time(0));  

    int totalNumeros;
    int modoSorteio;

    cout << "Deves escolher entre um sorteio de 75 , 90  ou 100 números: ";
    cin >> modoSorteio;

    switch (modoSorteio) {
        case 75:
            totalNumeros = 75;
            break;
        case 90:
            totalNumeros = 90;
            break;
        case 100:
            totalNumeros = 100;
            break;
        default:
            cerr << "Opção inválida." << endl;
            return 1;
    }

    mostrarPainel(totalNumeros);

    int escolha;
    cout << "Escolha o modo de sorteio (1 - Automático, 2 - Manual): ";
    cin >> escolha;

    if (escolha == 1) {
        for (int i = 1; i <= totalNumeros; ++i) {
            cout << "Número sorteado: " << i << endl;
            if (i > 1) {
                cout << "Anterior: " << i - 1 << endl;
            }
            
        }
    } else if (escolha == 2) {
        int quantidadeCartoes;

        cout << "Quantos cartões deseja gerar? ";
        cin >> quantidadeCartoes;

        if (quantidadeCartoes > 0) {
            for (int i = 1; i <= quantidadeCartoes; ++i) {
                gerarCartao(i, totalNumeros);
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
