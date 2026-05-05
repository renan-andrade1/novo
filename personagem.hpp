#include <iostream>
#include <string>  
#include "posicao.hpp"
using namespace std;

class Personagem{
    private: 
    int vida;
    string nome;
    string tipo;
    Posicao pos;

    protected:
    int dano;
    
    public:
    bool defendendo = false;

    Personagem(int vida, string nome, int dano, string tipo = "")
    {
        this->vida = vida;
        this->nome = nome;
        this->dano = dano;
        this->tipo = tipo;
    }

    string getNome()
    {
        return nome;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    int getVida()
    {
        return vida;
    }

    void setVida(int vida)
    {
        this->vida = vida;
    }

    virtual void recebeDano(int dano)
    {   
        if (defendendo)
        {
            dano /= 2;
            defendendo = false;
        }
        this->vida -= dano;
    }

    virtual void causaDano(Personagem &p, int dano)
    {
        p.recebeDano(dano);
    }

    virtual string getTipo()
    {
        return tipo;
    }

    void setTipo(string tipo)
    {
        this->tipo = tipo;
    }

    virtual int getDano()
    {
        return dano;
    }

    Posicao getPosicao()
    {
        return pos;
    }

    void setPosicao(Posicao p)
    {
        pos = p;
    }

    void setDefendendo(bool d)
    {
        defendendo = d;
    }
};

class Jogador : public Personagem{
    public:
    Jogador(int vida, string nome, int dano) : Personagem(vida, nome, dano) {}

    string getTipo() override
    {
        return "Jogador";
    }

    int getDano() override
    {
        return dano;
    }
};

class Inimigo : public Personagem{
    public:
    Inimigo(int vida, string nome, int dano) : Personagem(vida, nome, dano) {}

    string getTipo() override
    {
        return "Inimigo";
    }

    int getDano() override
    {
        return dano;
    }
};
