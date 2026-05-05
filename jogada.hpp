#include <iostream>
#include "personagem.hpp"

void atacarJ(Jogador &j, Inimigo &i)
{
    if(i.getTipo() == "Jogador"){
        return;
    }
    j.causaDano(i, j.getDano());
}

void atacarI(Inimigo &i, Jogador &j)
{
    if(j.getTipo() == "Inimigo"){
        return;
    }
    i.causaDano(j, i.getDano());
}

