#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BingoGame {
private:
    int maxNumbers;
    vector<int> numbersDrawn;
    bool automaticDraw;

public:
    BingoGame(int maxNumbers) : maxNumbers(maxNumbers), automaticDraw(true) {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    void drawNumber() {
        int newNumber = rand() % maxNumbers + 1;
        numbersDrawn.push_back(newNumber);
        sort(numbersDrawn.begin(), numbersDrawn.end());

        if (numbersDrawn.size() >= 2) {
            cout << "Número anterior: " << numbersDrawn[numbersDrawn.size() - 2] << endl;
        }

        cout << "Número sorteado: " << newNumber << endl;
    }

    void drawNumbersManually() {
        automaticDraw = false;
        char input;
        do {
            cout << "Pressione qualquer tecla para sortear um novo número (ou 'q' para sair): ";
            cin >> input;

            if (input != 'q') {
                drawNumber();
            }

        } while (input != 'q');
    }

    void drawNumbersAutomatically() {
        automaticDraw = true;
        char input;
        do {
            drawNumber();
            cout << "Pressione 'q' para sair ou qualquer outra tecla para continuar automaticamente: ";
            cin >> input;

        } while (input != 'q');
    }

    void generateBingoCard(int numCards) {
        for (int i = 1; i <= numCards; ++i) {
            string filename = "bingo_card_" + to_string(i) + ".txt";
            ofstream outFile(filename);

            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    int number = rand() % maxNumbers + 1;
                    outFile << (rand() % 2 == 0 ? to_string(number) : "  ") << "\t";
                }
                outFile << endl;
            }

            outFile.close();
            cout << "Cartão gerado: " << filename << endl;
        }
    }

    void play() {
        cout << "Bem-vindo ao jogo de Bingo!" << endl;
        cout << "Escolha a quantidade de números (75, 90 ou 100): ";
        int selectedMaxNumbers;
        cin >> selectedMaxNumbers;

        if (selectedMaxNumbers != 75 && selectedMaxNumbers != 90 && selectedMaxNumbers != 100) {
            cout << "Escolha inválida. Saindo do jogo." << endl;
            return;
        }

        BingoGame bingo(selectedMaxNumbers);

        cout << "Escolha o modo de sorteio (1 - Automático, 2 - Manual): ";
        int drawMode;
        cin >> drawMode;

        if (drawMode == 1) {
            bingo.drawNumbersAutomatically();
        } else if (drawMode == 2) {
            bingo.drawNumbersManually();
        } else {
            cout << "Modo de sorteio inválido. Saindo do jogo." << endl;
            return;
        }

        cout << "Quantos cartões de Bingo você deseja gerar? ";
        int numCards;
        cin >> numCards;

        bingo.generateBingoCard(numCards);
    }
};

int main() {
    BingoGame bingoGame(75);  // Inicializa o jogo com 75 números
    bingoGame.play();

    return 0;
}
