#include "Soldier.h"

Soldier::Soldier ( unsigned int id, int life, int attack, int defence, enum Species species, double pdclife, double pdcmagic, unsigned int pdccoin )
{
    this->life = life;
    this->attack = attack;
    this->defence = defence;
    this->species = species;
    this->pdclife = pdclife;
    this->pdcmagic = pdcmagic;
    this->pdccoin = pdccoin;
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

/*unsigned int Soldier::GetPrice()
{
    return this->price;
}*/

unsigned int Soldier::GetID()
{
    return this->id;
}


enum Species Soldier::GetSpecies()
{
    return this->species;
}

unsigned int Soldier::GetY()
{
    return this->y ;
}

unsigned int Soldier::GetX()
{
    return this->x;
}


string Soldier::SGetSpecies()
{
    string _result;
    switch ( this->GetSpecies() )
    {
        case humanity:
        {
            _result =   "Humanity" ;
        }
        case mechanical:
        {
            _result = "Mechanical" ;
        }
        case beast:
        {
            _result = "Beast" ;
        }
        case wizard:
        {
            _result = "Wizard" ;
        }
        case warcraft:
        {
            _result = "Warcraft" ;
        }
    }
    return _result;
}

string Soldier::SGetName()
{
    string _result;
    switch ( this->GetSoldierName() )
    {
        case _Worker:
        {
            _result = "Worker";
        }
        case _Archer:
        {
            _result = "Archer";
        }
        case _SwordsMan:
        {
            _result = "Swords Man";
        }
        case _Priest:
        {
            _result = "Priest";
        }
        case _SiegCar:
        {
            _result = "Sieg Car";
        }
        case _Dragon:
        {
            _result = "Dragon";
        }
        case _Wolf:
        {
            _result = "Wolf";
        }
        case _Slime:
        {
            _result = "Slime";
        }
        case _Goblin:
        {
            _result = "Goblin";
        }
        case _IceGiant:
        {
            _result = "IceGiant";
        }
        case _FlameBirds:
        {
            _result = "FlameBirds";
        }
        case _Naga:
        {
            _result = "Naga";
        }
        case _Phoenix:
        {
            _result = "Phoenix";
        }
    }
    return _result;
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
    this->x += x;
}

void Soldier::UpdateY ( unsigned int y )
{
    this->y += y;
}

enum AllSoldiers Soldier::GetSoldierName()
{
    return this->_name;
}

enum LocalPower Soldier::GetPower()
{
    return this->power;
}
