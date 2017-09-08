#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>
#include <algorithm>

using namespace std;

enum Species {humanity, mechanical, beast, wizard, warcraft};
enum AllSoldiers {_Worker, _Archer, _SwordsMan, _Priest, _SiegCar, _Dragon, _Wolf, _Slime, _Goblin, _IceGiant, _FlameBirds, _Naga, _Phoenix};

class Soldier
{
    public:
        Soldier ( unsigned int id, int life, int attack, int defence, enum Species species, unsigned int price );

        int GetAttack(); // 得到该士兵的攻击力
        int GetDefence(); // 得到该士兵的防御力
        int GetLife(); // 得到该士兵的生命值
        unsigned int GetX(); // 得到该士兵的相对X坐标
        unsigned int GetY(); // 得到该士兵的相对Y坐标
        unsigned int GetID(); // 得到该士兵的ID
        unsigned int GetPrice(); // 得到该士兵的生产成本
        enum Species GetSpecies(); // 得到该士兵的种族名称（枚举类型）
        string SGetSpecies(); // 得到该士兵的种族名称（字符串类型）
        enum AllSoldiers GetSoldierName(); // 得到该士兵的兵种名称（枚举类型）
        string SGetName(); // 得到该士兵的兵种名称（字符串类型）


        void UpdateX ( unsigned int x ); // 更新该士兵的相对X坐标
        void UpdateY ( unsigned int y ); // 更新该士兵的相对y坐标
        void UpdateAttack ( int attack ); // 更新该士兵的攻击力
        void UpdateDefence ( int defence ); // 更新该士兵的防御力
        void UpdateID ( unsigned int id ); // 更新该士兵的ID
        void UpdateLife ( int life ); // 更新该士兵的生命值

        // 注：该坐标为绝对左边，在对外的接口中会转换成相对坐标
        // 该类的派生类中的坐标均为绝对坐标
        unsigned int x;
        unsigned int y;

        enum AllSoldiers _name;
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
        Worker ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 100, 20, 50, humanity, 20 )
        {
            this->_name = _Worker;
            this->x = x;
            this->y = y;
        }
};

class Archer: public Soldier
{
    public:
        Archer ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 200, 150, 80, humanity, 50 )
        {
            this->_name = _Archer;
            this->x = x;
            this->y = y;
        }

};

class SwordsMan: public Soldier
{
    public:
        SwordsMan ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 250, 210, 140, humanity, 110 )
        {
            this->_name = _SwordsMan;
            this->x = x;
            this->y = y;
        }

};

class Priest: public Soldier
{
    public:
        Priest ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 160, 0, 70, humanity, 100 )
        {
            this->_name = _Priest;
            this->x = x;
            this->y = y;
        }

};

class SiegCar: public Soldier
{
    public:
        SiegCar ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 500, 700, 310, mechanical, 450 )
        {
            this->_name = _SiegCar;
            this->x = x;
            this->y = y;
        }

};

class Dragon: public Soldier
{
    public:
        Dragon ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 450, 525, 430, beast, 310 )
        {
            this->_name = _Dragon;
            this->x = x;
            this->y = y;
        }

};

class Wolf: public Soldier
{

    public:
        Wolf ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 210, 200, 160, beast, 130 )
        {
            this->_name = _Wolf;
            this->x = x;
            this->y = y;
        }
};

class Slime: public Soldier
{
    public:
        Slime ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 140, 120, 75, wizard, 60 )
        {
            this->_name = _Slime;
            this->x = x;
            this->y = y;
        }
};

class Goblin: public Soldier
{
    public:
        Goblin ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 210, 185, 120, wizard, 100 )
        {
            this->_name = _Goblin;
            this->x = x;
            this->y = y;
        }

};

class IceGiant: public Soldier
{

    public:
        IceGiant ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 400, 575, 500, warcraft, 850 )
        {
            this->_name = _IceGiant;
            this->x = x;
            this->y = y;
        }
};

class FlameBirds: public Soldier
{

    public:
        FlameBirds ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 450, 670, 260, warcraft, 970 )
        {
            this->_name = _FlameBirds;
            this->x = x;
            this->y = y;
        }
};

class Naga: public Soldier
{
    public:
        Naga ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 380, 430, 350, warcraft, 700 )
        {
            this->_name = _Naga;
            this->x = x;
            this->y = y;
        }
};

class Phoenix: public Soldier
{
    public:
        Phoenix ( unsigned int id, unsigned int x, unsigned int y ) : Soldier ( id, 350, 770, 120, warcraft, 1300 )
        {
            this->_name = _Phoenix;
            this->x = x;
            this->y = y;
        }
};


#endif // SOLDIER_H
