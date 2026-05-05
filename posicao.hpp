#include <iostream>
#include <cstdlib>
#include <ctime>
#include "personagem.hpp"
using namespace std;
#define Jogador '🥷🏻'
#define Inimigo '👹'
#define Chao '🟩'
#define LIN 20
#define COL 20

struct Posicao
{
    int x;
    int y;
};

void inicializarMapa(Posicao mapa[LIN][COL])
{
    for(int i = 0; i < LIN; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            mapa[i][j].x = i;
            mapa[i][j].y = j;
        }
    }
}

void imprimirMapa(Posicao mapa[LIN][COL], Jogador *jogador, Inimigo *inimigo)
{
    for(int i = 0; i < LIN; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if (jogador->getPosicao().x == i && jogador->getPosicao().y == j)
            {
                cout << Jogador;
            }else if (inimigo->getPosicao().x == i && inimigo->getPosicao().y == j){
                cout << Inimigo;
            }else{
                cout << Chao;
            }
        }
        cout << endl;
    }
}

void inserirNoMapa(Personagem &p, Personagem *outro = nullptr)
{
    Posicao pos;

    do {
        pos.x = rand() % 10;
        pos.y = rand() % 10;
    } 
    while (outro != nullptr &&
           pos.x == outro->getPosicao().x &&
           pos.y == outro->getPosicao().y);

    p.setPosicao(pos);
}
