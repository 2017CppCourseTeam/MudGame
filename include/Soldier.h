#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>

using namespace std;

enum Species {humanity, mechanical, beast, wizard, warcraft};

class Soldier
{
    public:
        Soldier (unsigned int id, int life, int attack, int defence, enum Species species, unsigned int price );

        int GetAttack();
        int GetDefence();
        int GetLife();
        unsigned int GetID();
        unsigned int GetPrice();
        enum Species GetSpecies();
        string SGetSpecies();

        void UpdateAttack ( int attack );
        void UpdateDefence ( int defence );
        void UpdateLife ( int life );
        void UpdateSpecies ( enum Species species );
    private:
        unsigned int id;
        int attack;
        int defence;
        int life;
        unsigned int price;
        enum Species species;
};

class Worker: public Soldier
{
    public:
        Worker(unsigned int id) : Soldier (id, 100, 20, 50, humanity, 20 ) {};
};

class Archer: public Soldier
{
    public:
        Archer(unsigned int id) : Soldier (id, 200, 150, 80, humanity, 50 ) {};

};

class SwordsMan: public Soldier
{
    public:
        SwordsMan(unsigned int id) : Soldier (id, 250, 210, 140, humanity, 110 ) {};

};

class Priest: public Soldier
{
    public:
        Priest(unsigned int id) : Soldier (id, 160, 0, 70, humanity, 100 ) {};

};

class SiegCar: public Soldier
{
    public:
        SiegCar(unsigned int id) : Soldier (id, 500, 700, 310, mechanical, 450 ) {};

};

class Dragon: public Soldier
{
    public:
        Dragon(unsigned int id) : Soldier (id, 450, 525, 430, beast, 310 ) {};

};

class Wolf: public Soldier
{

    public:
        Wolf(unsigned int id) : Soldier (id, 210, 200, 160, beast, 130 ) {};
};

class Slime: public Soldier
{
    public:
        Slime(unsigned int id) : Soldier (id, 140, 120, 75, wizard, 60) {};

};

class Goblin: public Soldier
{
    public:
        Goblin(unsigned int id) : Soldier (id, 210, 185, 120, wizard, 100 ) {};

};

class IceGiant: public Soldier
{

    public:
        IceGiant(unsigned int id) : Soldier (id, 400, 575, 500, warcraft, 850 ) {};
};

class FlameBirds: public Soldier
{

    public:
        FlameBirds(unsigned int id) : Soldier (id, 450, 670, 260 , warcraft, 970 ) {};
};

class Naga: public Soldier
{
    public:
        Naga(unsigned int id) : Soldier (id, 380, 430, 350, warcraft, 700 ) {};

};

class Phoenix: public Soldier
{
    public:
        Phoenix(unsigned int id) : Soldier (id, 350, 770, 120, warcraft, 1300 ) {};

};


#endif // SOLDIER_H
