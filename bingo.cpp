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

void mostrarPainel(int totalNumeros, const vector<bool>& marcados, int numeroSorteado, int anteriorSorteado, int numeroSorteio) {
    cout << "\033[2J\033[1;1H"; 
    cout << "\033[1;34m            P A I N E L - B I N G O     \033[0m\n";
    cout << "\n\033[1;34m        S O R T E I O  C O M " << numeroSorteio << " B O L A S\033[0m\n";
    for (int i = 1; i <= totalNumeros; ++i) {
        cout << "\033[1;34m";  
        if (marcados[i - 1] || i == anteriorSorteado) {
            cout << "\033[1;31m";  
        }
        cout << (i < 10 ? " " : "") << i << " \033[0m";
        if (i % 15 == 0) {
            cout << endl;
        }
    }
    cout << "\nNúmero Sorteado: \033[0m";
    cout << "\033[1;34m\033[1;31m" << (numeroSorteado < 10 ? " " : "") << numeroSorteado << "\033[0m\n";
    if (anteriorSorteado > 0) {
        cout << "Número Anterior: \033[0m";
        cout << "\033[1;34m" << (anteriorSorteado < 10 ? " " : "") << anteriorSorteado << "\033[0m\n";
    }
    cout << endl;
}

void gerarCartao(int numeroCartao, int totalNumeros) {
    string nomeArquivo = "cartao" + to_string(numeroCartao) + ".txt";
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        vector<int> numeros(totalNumeros);
        iota(numeros.begin(), numeros.end(), 1);

        // Embaralha os números em ordem aleatória
        random_shuffle(numeros.begin(), numeros.end());

        // Organiza os números no formato desejado
        vector<int> cartaoOrganizado = {
            numeros[0], numeros[1], numeros[2], numeros[3], numeros[4],
            numeros[5], numeros[6], numeros[7], numeros[8], numeros[9],
            numeros[10], numeros[11], -1, numeros[12], numeros[13],
            numeros[14], numeros[15], numeros[16], numeros[17], numeros[18],
            numeros[19], numeros[20], numeros[21], numeros[22], numeros[23], numeros[24]
        };

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (cartaoOrganizado[i * 5 + j] == -1) {
                    arquivo << "      ";
                } else {
                    arquivo << (cartaoOrganizado[i * 5 + j] < 10 ? " " : "") << cartaoOrganizado[i * 5 + j] << "  ";
                }
            }
            arquivo << endl;
        }

        arquivo.close();
        cout << "Cartão gerado com sucesso: " << nomeArquivo << endl;
    } else {
        cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
    }
}

void substituirXporNumeros(const string& nomeArquivo, int totalNumeros) {
    ifstream arquivoEntrada(nomeArquivo);
    ofstream arquivoSaida("temp.txt");

    if (arquivoEntrada.is_open() && arquivoSaida.is_open()) {
        string linha;
        int numero = 0;

        while (getline(arquivoEntrada, linha)) {
            size_t pos = linha.find("x");
            while (pos != string::npos) {
                linha.replace(pos, 1, to_string(++numero));
                pos = linha.find("x", pos + 1);
            }

            arquivoSaida << linha << endl;
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        // Renomeia o arquivo temporário para o nome original
        remove(nomeArquivo.c_str());
        rename("temp.txt", nomeArquivo.c_str());
    } else {
        cerr << "Erro ao abrir os arquivos." << endl;
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
    int escolhaIntervalo;

    while (true) {
        cout << "\nEscolha a quantidade de bolas (75, 90, 100) ou 0 para Sair: ";
        cin >> escolhaIntervalo;

        if (escolhaIntervalo == 0) {
            return 0; // Sair do programa
        }

        if (escolhaIntervalo == 75) {
            totalNumeros = 75;
        } else if (escolhaIntervalo == 90) {
            totalNumeros = 90;
        } else if (escolhaIntervalo == 100) {
            totalNumeros = 100;
        } else {
            cerr << "Opção inválida." << endl;
            continue; // Volta para o início do loop
        }

        while (true) {
            cout << "\nEscolha uma opção:\n";
            cout << "1 - Automático\n";
            cout << "2 - Manual\n";
            cout << "3 - Gerar Cartões\n";
            cout << "4 - Voltar\n";
            cout << "0 - Sair\n";
            cin >> escolha;

            if (escolha == 0) {
                return 0; // Sair do programa
            }

            if (escolha == 4) {
                break; // Voltar ao início
            }

            if (escolha == 3) {
                int quantidadeCartoes;
                cout << "Quantos cartões deseja gerar? ";
                cin >> quantidadeCartoes;

                if (quantidadeCartoes > 0) {
                    for (int i = 1; i <= quantidadeCartoes; ++i) {
                        gerarCartao(i, totalNumeros);
                    }

                    cout << "Substituindo 'x' pelos números nos cartões gerados..." << endl;

                    for (int i = 1; i <= quantidadeCartoes; ++i) {
                        substituirXporNumeros("cartao" + to_string(i) + ".txt", totalNumeros);
                    }

                    cout << "Substituição concluída." << endl;
                } else {
                    cerr << "A quantidade de cartões deve ser maior que zero." << endl;
                }
            } else if (escolha == 1 || escolha == 2) {
                int quantidadeSorteios;
                cout << "Quantos sorteios deseja realizar? ";
                cin >> quantidadeSorteios;

                vector<int> numerosDisponiveis;
                vector<bool> marcados;
                int anteriorSorteado = 0;

                for (int sorteio = 1; sorteio <= quantidadeSorteios; ++sorteio) {
                    numerosDisponiveis.resize(totalNumeros);
                    marcados.assign(totalNumeros, false);
                    iota(numerosDisponiveis.begin(), numerosDisponiveis.end(), 1);

                    cout << "\nSorteio #" << sorteio << endl;

                    int numeroSorteado;
                    for (int i = 1; i <= totalNumeros; ++i) {
                        random_shuffle(numerosDisponiveis.begin(), numerosDisponiveis.end());

                        numeroSorteado = numerosDisponiveis.back();
                        numerosDisponiveis.pop_back();

                        mostrarPainel(totalNumeros, marcados, numeroSorteado, anteriorSorteado, totalNumeros);

                        pausar(1000); // Adicionei um atraso de 1000 milissegundos (1 segundo) aqui

                        marcados[numeroSorteado - 1] = true;
                        anteriorSorteado = numeroSorteado;
                    }
                }
            } else {
                cerr << "Opção inválida." << endl;
            }
        }
    }

    return 0;
}
