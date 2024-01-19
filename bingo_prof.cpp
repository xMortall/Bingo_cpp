/**
* @file duvidas.cpp
* @author Emanuel Borges
* @brief Jogo bingo, conhecimento
* @version 0.1
* @date 17-01-2024
*/

// int : 4 bytes (32 bites)  00000000 00000000 00000000 00000000
//char : 1 byte (8 bites)    00000000
//bool : 1 byte (8 bites)    00000000(false) 00000001 (true) 
//float : 4 bytes (32 bites) 00000000 00000000 00000000 00000000
//double : 8 bytes (64 bites)
//double : 8 bytes (64b bites)

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

const int numLinhasCartao       = 5;
const int numColunasCartao      = 5;
const int numColunasPainel      = 20;
const int intervaloEntreBolas   = 500000;
const int msgPause              = 2000000;

int sorteados        = 0;
int numeroSorteado   = 0;
int anterior         = 0;

int numeroDeBolas, tipoSorteio, numeroDeCartoes;

string red       = "\033[1;31m";
string green     = "\033[1;32m"; 
string blue      = "\033[1;34m";
string reset     = "\033[0m";
string bold      = "\033[1m";
string blink     = "\033[5m";

string figletFont = "big";

typedef struct {
    int numero;
    bool sorteado;
} bingoPanel;

bingoPanel bingo[100];  

/**
* @brief Função para centralizar uma string no console
*
* @param mensagem
*/
void centerString(string mensagem) {
    int l = mensagem.length();
    int pos = (int)((numColunasPainel - 3 * l) / 2);
    for (int i = 0; i < pos; i++) {
        cout << " ";
    }
    cout << blue << mensagem << reset << endl;
}

/**
* @brief Função para inicializar o array de bingo
*/
void initArray() {
    for (int i = 0; i < numeroDeBolas; i++) {
        bingo[i].numero = i + 1;
        bingo[i].sorteado = false;
    }
}

/**
* @brief Função de apresentação dos cartões
*/
void opcoes() {
    tipoSorteio = 0;

    while (tipoSorteio < 1 || tipoSorteio > 4) {
        system("clear || cls");
        cout << blue
            << "--------------------------------\n"
            << blue << bold
            << "M E N U      P R I N C I P A L\n" << reset << blue
            << "--------------------------------" << endl
            << "1 - Sorteio Manual\n"
            << "2 - Sorteio Automático\n"
            << "3 - Gerar Cartões\n"
            << "4 - Sair\n"
            << "--------------------------------" << endl
            << bold << "Opção: " << reset << blue;
        cin >> tipoSorteio;
    }

    if (tipoSorteio != 1 && tipoSorteio != 2 && tipoSorteio != 3 && tipoSorteio != 4) {
        
    }
}

/*
* @brief Função para apresentação do painel de bingo
*
* @param sorteado
* @param sorteadoAnteriormente
*/
void showBingoPanel(int sorteado, int sorteadoAnteriormente) {
    system("clear || cls");
    centerString("J O G O  D O  B I N G O");
 
}
