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
            break;
        }
        case mechanical:
        {
            _result = "Mechanical" ;
            break;
        }
        case beast:
        {
            _result = "Beast" ;
            break;
        }
        case wizard:
        {
            _result = "Wizard" ;
            break;
        }
        case warcraft:
        {
            _result = "Warcraft" ;
            break;
        }
    }
    cout << _result;
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
            break;
        }
        case _Archer:
        {
            _result = "Archer";
            break;
        }
        case _SwordsMan:
        {
            _result = "Swords Man";
            break;
        }
        case _Priest:
        {
            _result = "Priest";
            break;
        }
        case _SiegCar:
        {
            _result = "Sieg Car";
            break;
        }
        case _Dragon:
        {
            _result = "Dragon";
            break;
        }
        case _Wolf:
        {
            _result = "Wolf";
            break;
        }
        case _Slime:
        {
            _result = "Slime";
            break;
        }
        case _Goblin:
        {
            _result = "Goblin";
            break;
        }
        case _IceGiant:
        {
            _result = "IceGiant";
            break;
        }
        case _FlameBirds:
        {
            _result = "FlameBirds";
            break;
        }
        case _Naga:
        {
            _result = "Naga";
            break;
        }
        case _Phoenix:
        {
            _result = "Phoenix";
            break;
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
