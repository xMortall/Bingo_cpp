#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>  
#include <chrono>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

void mostrarPainel(int totalNumeros, const vector<bool>& marcados, int numeroSorteado, int anteriorSorteado) {
    cout << "\033[2J\033[1;1H";  
    cout << "xxxxxxxxxxxxxxxxxx PAINEL xxxxxxxxxxxxxxxxxx\n";
    for (int i = 1; i <= totalNumeros; ++i) {
        if (marcados[i - 1]) {
            cout << "\033[1;31m"; 
        } else if (i == numeroSorteado || i == anteriorSorteado) {
            cout << "\033[1;34m";  
        }
        cout << (i < 10 ? " " : "") << i << " ";
        if (marcados[i - 1] || i == numeroSorteado || i == anteriorSorteado) {
            cout << "\033[0m"; 
        }
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
                arquivo << (j == 0 ? "" : " ") << (numero < 10 ? " " : "") << numero;
            }
            arquivo << endl;
        }

        arquivo.close();
        cout << "Cartão gerado com sucesso: " << nomeArquivo << endl;
    } else {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
    }
}

void pausar(int milissegundos) {
#ifdef _WIN32
    Sleep(milissegundos);
#else
    usleep(milissegundos * 1000);  
#endif
}

int main() {
    srand(time(0));  
    int totalNumeros;
    int escolha;

    cout << "Escolha uma opção:\n";
    cout << "1 - Automático\n";
    cout << "2 - Manual\n";
    cout << "3 - Gerar Cartões\n";
    cin >> escolha;

    if (escolha == 3) {
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

        return 0;
    }

    if (escolha == 1) {
        totalNumeros = 75;
    } else if (escolha == 2) {
        totalNumeros = 90;
    } else {
        totalNumeros = 100;
    }

    vector<bool> marcados(totalNumeros, false);
    mostrarPainel(totalNumeros, marcados, 0, 0);

    if (escolha == 1) {
        int quantidadeSorteios;
        cout << "Quantos sorteios automáticos deseja realizar? ";
        cin >> quantidadeSorteios;

        vector<int> numerosDisponiveis(totalNumeros);
        iota(numerosDisponiveis.begin(), numerosDisponiveis.end(), 1);

        for (int sorteio = 1; sorteio <= quantidadeSorteios; ++sorteio) {
            cout << "\nSorteio Automático #" << sorteio << endl;

            int numeroSorteado, anteriorSorteado = 0;
            for (int i = 1; i <= totalNumeros; ++i) {
                random_shuffle(numerosDisponiveis.begin(), numerosDisponiveis.end());

                numeroSorteado = numerosDisponiveis.back();
                numerosDisponiveis.pop_back();

                if (i > 1) {
                    anteriorSorteado = numeroSorteado;
                } else {
                    anteriorSorteado = 0;
                }

                cout << "Número sorteado: " << numeroSorteado << endl;
                mostrarPainel(totalNumeros, marcados, numeroSorteado, anteriorSorteado);
                pausar(500); 

                marcados[numeroSorteado - 1] = true;
            }

            marcados.assign(totalNumeros, false);
        }
    } else if (escolha == 2) {
        char continuar;
        int numeroSorteado, anteriorSorteado = 0;

        vector<int> numerosDisponiveis(totalNumeros);
        iota(numerosDisponiveis.begin(), numerosDisponiveis.end(), 1);

        do {
            cout << "\nSorteio Manual" << endl;

          
            random_shuffle(numerosDisponiveis.begin(), numerosDisponiveis.end());

            numeroSorteado = numerosDisponiveis.back();
            numerosDisponiveis.pop_back();

            cout << "Número sorteado: " << numeroSorteado << endl;
            mostrarPainel(totalNumeros, marcados, numeroSorteado, anteriorSorteado);

            anteriorSorteado = numeroSorteado;

          
            marcados[numeroSorteado - 1] = true;

            cout << "Deseja sortear um novo número? (s/n): ";
            cin >> continuar;
        } while (continuar == 's' || continuar == 'S');
    } else {
        cerr << "Opção inválida." << endl;
        return 1;
    }

    return 0;
}
