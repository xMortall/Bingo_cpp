#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    int myArray[] = {1, 2};

    string numeros1[10][10] = {
        {"1","2","3","4","5","6","7","8","9","10"},
        {"11","12","13","14","15","16","17","18","19","20"},
        {"21","22","23","24","25","26","27","28","29","30"},
        {"31","32","33","34","35","36","37","38","39","40"},
        {"41","42","43","44","45","46","47","48","49","50"},
        {"51","52","53","54","55","56","57","58","59","60"},
        {"61","62","63","64","65","66","67","68","69","70"},
        {"71","72","73","74","75","76","77","78","79","80"},
        {"81","82","83","84","85","86","87","88","89","90"},
        {"91","92","93","94","95","96","97","98","99","100"}
    };

    char swt;
    double num1, num2, num3, painel;
    cout << " Deves escolher entre um sorteio de 75, 90 e 100 números" << endl;
    cin >> swt;

    switch (swt)
    {
    case '75':
        cout << "xxxxxxxxxx PAINEL xxxxxxxxxx\n";
        cout << "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n";
        cout << "16 17 18 19 20 21 22 23 25 26 27 28 29 30\n";
        cout << "xxxxxxxxxx PAINEL xxxxxxxxxx\n";
        cout << "xxxxxxxxxx PAINEL xxxxxxxxxx\n";
        cout << "xxxxxxxxxx PAINEL xxxxxxxxxx\n";
        break;
    case '90':
        /* code */
        break;
    case '100':
        /* code */
        break;
    
    default:
        break;
    }



    return 0;
};
void gerarCartao(int numeroCartao) {
    string nomeArquivo = "cartao" + std::to_string(numeroCartao) + ".txt";
    ofstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        arquivo << "x  x  x  x  x\n";
        arquivo << "x  x      x  x\n";
        arquivo << "x  x      x  x\n";
        arquivo << "x  x  x  x  x\n";

        arquivo.close();
        std::cout << "Cartão gerado com sucesso: " << nomeArquivo << endl;
    } else {
        std::cerr << "Erro ao criar o arquivo: " << nomeArquivo << endl;
    }
}

int main() {
    int quantidadeCartoes;

    cout << "Quantos cartões deseja gerar? ";
    cin >> quantidadeCartoes;

    if (quantidadeCartoes > 0) {
        for (int i = 1; i <= quantidadeCartoes; ++i) {
            gerarCartao(i);
        }
    } else {
        cerr << "A quantidade de cartões deve ser maior que zero." << endl;
    }

    return 0;
}
