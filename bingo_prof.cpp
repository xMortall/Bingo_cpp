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

