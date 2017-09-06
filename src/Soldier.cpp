#include "Soldier.h"

Soldier::Soldier ( unsigned int id,  int life, int attack, int defence, enum Species species, unsigned int price )
{
    this->life = life;
    this->attack = attack;
    this->defence = defence;
    this->species = species;
    this->price = price;
    this->id = id;
}

int Soldier::GetAttack()
{
    return this->attack;
}

int Soldier::GetDefence()
{
    return this->defence;
}

int Soldier::GetLife()
{
    return this->life;
}

unsigned int Soldier::GetPrice()
{
    return this->price;
}

unsigned int Soldier::GetID()
{
    return this->id;
}


enum Species Soldier::GetSpecies()
{
    return this->species;
}

string Soldier::SGetSpecies()
{
    switch ( this->GetSpecies() )
    {
        case humanity:
        {
            return string ( "Humanity" );
        }
        case mechanical:
        {
            return string ( "Mechanical" );
        }
        case beast:
        {
            return string ( "Beast" );
        }
        case wizard:
        {
            return string ( "Wizard" );
        }
        case warcraft:
        {
            return string ( "Warcraft" );
        }
    }
}

void Soldier::UpdateAttack ( int attack )
{
    this->attack = attack;
}

void Soldier::UpdateDefence ( int defence )
{
    this->defence = defence;
}

void Soldier::UpdateLife ( int life )
{
    this->life = life;
}

void Soldier::UpdateSpecies ( enum Species species )
{
    this->species = species;
}
