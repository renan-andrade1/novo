#include <iostream>
#include "personagem.hpp"
#include "jogada.hpp"
#include "posicao.hpp"
using namespace std;

int main() {

    srand(time(NULL));

    string nome;
    int vida, dano;

    cout << "--- CRIANDO JOGADOR ---" << endl;
    cout << "Digite o nome do personagem: ";
    cin >> nome;
    cout << "Digite a vida do personagem: ";
    cin >> vida;
    cout << "Digite o dano do personagem: ";
    cin >> dano;

    Jogador jogador(vida, nome, dano);
    Inimigo inimigo(80, "Monster", 15);

    Posicao mapa[LIN][COL];
    inicializarMapa(mapa);
    inserirNoMapa(jogador);
    inserirNoMapa(inimigo, &jogador);
    imprimirMapa(mapa, &jogador, &inimigo);


    int op;

    while (jogador.getVida() > 0 && inimigo.getVida() > 0){

        cout << "Escolha uma acao: " << endl;
        cout << "1 - Atacar" << endl;
        cout << "2 - Defender" << endl;
        cout << "3 - Andar" << endl;
        cin >> op;

        switch(op)
        {
            case 1:
                jogador.causaDano(inimigo, jogador.getDano());
                break;
            case 2:
                jogador.setDefendendo(true);
                cout << "Voce esta defendendo!\n";
                break;
            case 3:
                // Usar item
                break;
            default:
                cout << "Acao invalida!" << endl;
                break;
        }
        if (inimigo.getVida() > 0)
            atacarI(inimigo, jogador);
    }

    return 0;
}
