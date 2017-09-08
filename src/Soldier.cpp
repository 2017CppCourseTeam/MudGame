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

unsigned int Soldier::GetX()
{
    return ( this->x - 1 ) / 2;
}

unsigned int Soldier::GetY()
{
    return ( this->y - 1 ) / 3;
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

string Soldier::SGetName()
{
    switch ( this->GetSoldierName() )
    {
        case _Worker:
        {
            return string ( "Worker" );
        }
        case _Archer:
        {
            return string ( "Archer" );
        }
        case _SwordsMan:
        {
            return string ( "Swords Man" );
        }
        case _Priest:
        {
            return string ( "Priest" );
        }
        case _SiegCar:
        {
            return string ( "Sieg Car" );
        }
        case _Dragon:
        {
            return string ( "Dragon" );
        }
        case _Wolf:
        {
            return string ( "Wolf" );
        }
        case _Slime:
        {
            return string ( "Slime" );
        }
        case _Goblin:
        {
            return string ( "Goblin" );
        }
        case _IceGiant:
        {
            return string ( "IceGiant" );
        }
        case _FlameBirds:
        {
            return string ( "FlameBirds" );
        }
        case _Naga:
        {
            return string ( "Naga" );
        }
        case _Phoenix:
        {
            return string ( "Phoenix" );
        }
    }
}


void Soldier::UpdateAttack ( int attack )
{
    this->attack += attack;
}

void Soldier::UpdateDefence ( int defence )
{
    this->defence += defence;
}

void Soldier::UpdateLife ( int life )
{
    this->life += life;
}

void Soldier::UpdateID ( unsigned int id )
{
    this->id = id;
}

void Soldier::UpdateX ( unsigned int x )
{
    this->x += ( 2 * x ) + 1;
}

void Soldier::UpdateY ( unsigned int y )
{
    this->y += ( 3 * y ) + 1;
}

enum AllSoldiers Soldier::GetSoldierName()
{
    return this->_name;
}
