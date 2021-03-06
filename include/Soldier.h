#ifndef SOLDIER_H
#define SOLDIER_H

#include "Global.h"

class Soldier
{
    public:
        Soldier ( unsigned int id, int life, int attack, int defence, enum Species species, double pdclife, double pdcmagic, unsigned int pdccoin );

        int GetAttack(); // 得到该士兵的攻击力
        void UpdateAttack ( int attack ); // 更新该士兵的攻击力

        int GetDefence(); // 得到该士兵的防御力
        void UpdateDefence ( int defence ); // 更新该士兵的防御力

        int GetLife(); // 得到该士兵的生命值
        void UpdateLife ( int life ); // 更新该士兵的生命值

        unsigned int GetID(); // 得到该士兵的ID
        void UpdateID ( unsigned int id ); // 更新该士兵的ID

        enum LocalPower GetPower(); // 得到该士兵所属势力

        enum Species GetSpecies(); // 得到该士兵的种族名称（枚举类型）
        string SGetSpecies(); // 得到该士兵的种族名称（字符串类型）

        enum AllSoldiers GetSoldierName(); // 得到该士兵的兵种名称（枚举类型）
        string SGetName(); // 得到该士兵的兵种名称（字符串类型）

        unsigned int GetX(); // 得到该士兵的相对X坐标
        void UpdateX ( unsigned int x ); // 更新该士兵的相对X坐标

        unsigned int GetY(); // 得到该士兵的相对Y坐标
        void UpdateY ( unsigned int y ); // 更新该士兵的相对y坐标


        // 注：该坐标为绝对坐标，在对外的接口中会转换成相对坐标
        // 该类的派生类中的坐标均为绝对坐标
        unsigned int x;
        unsigned int y;

        enum AllSoldiers _name;
        enum Species species;
        enum LocalPower power;
        int life;
        int attack;
        int defence;
        double pdclife;
        double pdcmagic;
        unsigned int pdccoin;
        unsigned int id;
};

class Worker: public Soldier
{
    public:
        Worker ( unsigned int id,
                 unsigned int x,
                 unsigned int y,
                 enum LocalPower power,
                 double pdclife,
                 double pdcmagic,
                 unsigned int pdccoin ) :
            Soldier ( id,
                      WORKER_LIFE,
                      WORKER_ATTACK,
                      WORKER_DEFENCE,
                      humanity,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Worker;
            this->x = x;
            this->y = y;
        }
};

class Archer: public Soldier
{
    public:
        Archer ( unsigned int id,
                 unsigned int x,
                 unsigned int y,
                 enum LocalPower power,
                 double pdclife,
                 double pdcmagic,
                 unsigned int pdccoin ) :
            Soldier ( id,
                      ARCHER_LIFE,
                      ARCHER_ATTACK,
                      ARCHER_DEFENCE,
                      humanity,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Archer;
            this->x = x;
            this->y = y;
        }

};

class SwordsMan: public Soldier
{
    public:
        SwordsMan ( unsigned int id,
                    unsigned int x,
                    unsigned int y,
                    enum LocalPower power,
                    double pdclife,
                    double pdcmagic,
                    unsigned int pdccoin ) :
            Soldier ( id,
                      SWORDSMAN_LIFE,
                      SWORDSMAN_ATTACK,
                      SWORDSMAN_DEFENCE,
                      humanity,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _SwordsMan;
            this->x = x;
            this->y = y;
        }

};

class Priest: public Soldier
{
    public:
        Priest ( unsigned int id,
                 unsigned int x,
                 unsigned int y,
                 enum LocalPower power,
                 double pdclife,
                 double pdcmagic,
                 unsigned int pdccoin ) :
            Soldier ( id,
                      PRIEST_LIFE,
                      PRIEST_ATTACK,
                      PRIEST_DEFENCE,
                      humanity,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Priest;
            this->x = x;
            this->y = y;
        }

};

class SiegCar: public Soldier
{
    public:
        SiegCar ( unsigned int id,
                  unsigned int x,
                  unsigned int y,
                  enum LocalPower power,
                  double pdclife,
                  double pdcmagic,
                  unsigned int pdccoin ) :
            Soldier ( id,
                      SIEGCAR_LIFE,
                      SIEGCAR_ATTACK,
                      SIEGCAR_DEFENCE,
                      mechanical,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _SiegCar;
            this->x = x;
            this->y = y;
        }

};

class Dragon: public Soldier
{
    public:
        Dragon ( unsigned int id,
                 unsigned int x,
                 unsigned int y,
                 enum LocalPower power,
                 double pdclife,
                 double pdcmagic,
                 unsigned int pdccoin ) :
            Soldier ( id,
                      DRAGON_LIFE,
                      DRAGON_ATTACK,
                      DRAGON_DEFENCE,
                      beast,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Dragon;
            this->x = x;
            this->y = y;
        }

};

class Wolf: public Soldier
{

    public:
        Wolf ( unsigned int id,
               unsigned int x,
               unsigned int y,
               enum LocalPower power,
               double pdclife,
               double pdcmagic,
               unsigned int pdccoin ) :
            Soldier ( id,
                      WOLF_LIFE,
                      WOLF_ATTACK,
                      WOLF_DEFENCE,
                      beast,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Wolf;
            this->x = x;
            this->y = y;
        }
};

class Slime: public Soldier
{
    public:
        Slime ( unsigned int id,
                unsigned int x,
                unsigned int y,
                enum LocalPower power,
                double pdclife,
                double pdcmagic,
                unsigned int pdccoin ) :
            Soldier ( id,
                      SLIME_LIFE,
                      SLIME_ATTACK,
                      SLIME_DEFENCE,
                      wizard,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Slime;
            this->x = x;
            this->y = y;
        }
};

class Goblin: public Soldier
{
    public:
        Goblin ( unsigned int id,
                 unsigned int x,
                 unsigned int y,
                 enum LocalPower power,
                 double pdclife,
                 double pdcmagic,
                 unsigned int pdccoin ) :
            Soldier ( id,
                      GOBLIN_LIFE,
                      GOBLIN_ATTACK,
                      GOBLIN_DEFENCE,
                      wizard,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Goblin;
            this->x = x;
            this->y = y;
        }

};

class IceGiant: public Soldier
{

    public:
        IceGiant ( unsigned int id,
                   unsigned int x,
                   unsigned int y,
                   enum LocalPower power,
                   double pdclife,
                   double pdcmagic,
                   unsigned int pdccoin ) :
            Soldier ( id,
                      ICEGIANT_LIFE,
                      ICEGIANT_ATTACK,
                      ICEGIANT_DEFENCE,
                      warcraft,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _IceGiant;
            this->x = x;
            this->y = y;
        }
};

class FlameBirds: public Soldier
{

    public:
        FlameBirds ( unsigned int id,
                     unsigned int x,
                     unsigned int y,
                     enum LocalPower power,
                     double pdclife,
                     double pdcmagic,
                     unsigned int pdccoin ) :
            Soldier ( id,
                      FLAMEBIRDS_LIFE,
                      FLAMEBIRDS_ATTACK,
                      FLAMEBIRDS_DEFENCE,
                      warcraft,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _FlameBirds;
            this->x = x;
            this->y = y;
        }
};

class Naga: public Soldier
{
    public:
        Naga ( unsigned int id,
               unsigned int x,
               unsigned int y,
               enum LocalPower power,
               double pdclife,
               double pdcmagic,
               unsigned int pdccoin ) :
            Soldier ( id,
                      NAGA_LIFE,
                      NAGA_ATTACK,
                      NAGA_DEFENCE,
                      warcraft,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Naga;
            this->x = x;
            this->y = y;
        }
};

class Phoenix: public Soldier
{
    public:
        Phoenix ( unsigned int id,
                  unsigned int x,
                  unsigned int y,
                  enum LocalPower power,
                  double pdclife,
                  double pdcmagic,
                  unsigned int pdccoin ) :
            Soldier ( id,
                      PHOENIX_LIFE,
                      PHOENIX_ATTACK,
                      PHOENIX_DEFENCE,
                      warcraft,
                      pdclife,
                      pdcmagic,
                      pdccoin )
        {
            this->power = power;
            this->_name = _Phoenix;
            this->x = x;
            this->y = y;
        }
};


#endif // SOLDIER_H
