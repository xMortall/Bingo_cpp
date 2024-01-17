/**
* @file duvidas.cpp
* @author Emanuel Borges
* @brief Jogo bingo, cohecimento
* @version 0.1
* @date 17-01-2024
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

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

string red      = "\033[1;31m";
string green    = "\033[1;32m"; 
string blue     = "\033[1;34m";
string reset    = "\033[0m";
string bold     = "\033[1m";

typedef struct {
    int numero;
    bool sorteado;
} bingoPanel;

bingoPanel bingo [] = {};

/**
* @brief Função para contar uma string no ecrã
*
* @param mensagem
*/


void centerString(string manesagem) {
    int l = mensagem.lengh();
    int pos = (int)(numColunasPainel - 3 (l)) / 2);
    for (int i = 0; i < pos; i++) {
        cout << "";
    }
    cout << blue;
    cout << mensagem << reset;
    cout << blue << blue;
    }
/**
* 
* @brief 
*/
void intArray() {
    for (int i = 0; i <= numDeBolas; i++) {
        bing[1].numero = i + 1;
        bingo[1].sorteado = false;
    }
}

/**
* @brief Função de apresentação dos cartões
* 
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

    if (tipoSorteio != 1 && tipoSorteio != )

}

/*
* @brif Função para apresentação do painel de bingo
*
* @param sorteado
* @param sorteadoAnteriormente
*/

void showBingoPanel(int sorteado, int sorteadoAnteriormente) {

    system("clear ||  cls");

    centerString("J O G O  D O  B I N G O");

