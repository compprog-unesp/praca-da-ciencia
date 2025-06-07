#include <iostream>
#include <vector>

using namespace std;

// Função que exibe o estado atual das pilhas
void mostrarPilhas(const vector<int>& pilhas) {
    cout << "\nEstado atual das pilhas: ";
    for (int pedras : pilhas) {
        cout << pedras << " ";
    }
    cout << endl;
}

// Função que executa o turno do jogador (voce)
void turnoJogador(vector<int>& pilhas) {
    int nim_sum = 0;
    for (int pedras : pilhas) {
        nim_sum ^= pedras;
    }

    if (nim_sum == 0) {
        cout << "Voce esta em uma posição perdedora. Faça qualquer jogada valida." << endl;
        
        int qtd, pilha;
        while (true) {
            cout << "Digite sua jogada (qtd_pedras pilha): ";
            cin >> qtd >> pilha;

            if (pilha >= 1 && pilha <= pilhas.size() && qtd >= 1 && qtd <= pilhas[pilha - 1]) {
                pilhas[pilha - 1] -= qtd;
                break;
            } else {
                cout << "Jogada invalida. Tente novamente." << endl;
            }
        }
    } else {
        for (int i = 0; i < pilhas.size(); ++i) {
            int alvo = pilhas[i] ^ nim_sum;
            if (alvo < pilhas[i]) {
                int tirar = pilhas[i] - alvo;
                pilhas[i] = alvo;
                cout << "Retire " << tirar << " pedra(s) da pilha " << i + 1 << "." << endl;
                break;
            }
        }
    }
}

int main() {
    int n;
    cout << "Digite o numero de pilhas: ";
    cin >> n;

    vector<int> pilhas(n);
    cout << "Digite a quantidade de pedras em cada pilha:\n";
    for (int i = 0; i < n; ++i) {
        cin >> pilhas[i];
    }

    while (true) {
        mostrarPilhas(pilhas);

        // Seu turno
        turnoJogador(pilhas);
        mostrarPilhas(pilhas);

        // Verifica se o jogo acabou
        bool acabou = true;
        for (int pedras : pilhas) {
            if (pedras != 0) {
                acabou = false;
                break;
            }
        }
        if (acabou) {
            cout << "Voce venceu!" << endl;
            break;
        }

        // Turno do adversário
        int qtd, pilha;
        cout << "Digite a acao do adversario (qtd_pedras pilha): ";
        cin >> qtd >> pilha;

        if (pilha < 1 || pilha > n || qtd < 1 || qtd > pilhas[pilha - 1]) {
            cout << "Jogada invalida. Encerrando o programa." << endl;
            break;
        }

        pilhas[pilha - 1] -= qtd;

        // Verifica se o jogo acabou
        acabou = true;
        for (int pedras : pilhas) {
            if (pedras != 0) {
                acabou = false;
                break;
            }
        }
        if (acabou) {
            cout << "Seu adversario venceu!" << endl;
            break;
        }
    }

    return 0;
}
