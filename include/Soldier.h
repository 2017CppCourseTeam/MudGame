#ifndef SOLDIER_H
#define SOLDIER_H

#include "Global.h"

class Soldier
{
    public:
        Soldier ( unsigned int id, int life, int attack, int defence, enum Species species, double pdclife, double pdcmagic, unsigned int pdccoin );

        int GetAttack(); // �õ���ʿ���Ĺ�����
        void UpdateAttack ( int attack ); // ���¸�ʿ���Ĺ�����

        int GetDefence(); // �õ���ʿ���ķ�����
        void UpdateDefence ( int defence ); // ���¸�ʿ���ķ�����

        int GetLife(); // �õ���ʿ��������ֵ
        void UpdateLife ( int life ); // ���¸�ʿ��������ֵ

        unsigned int GetID(); // �õ���ʿ����ID
        void UpdateID ( unsigned int id ); // ���¸�ʿ����ID

        enum LocalPower GetPower(); // �õ���ʿ����������

        enum Species GetSpecies(); // �õ���ʿ�����������ƣ�ö�����ͣ�
        string SGetSpecies(); // �õ���ʿ�����������ƣ��ַ������ͣ�

        enum AllSoldiers GetSoldierName(); // �õ���ʿ���ı������ƣ�ö�����ͣ�
        string SGetName(); // �õ���ʿ���ı������ƣ��ַ������ͣ�

        unsigned int GetX(); // �õ���ʿ�������X����
        void UpdateX ( unsigned int x ); // ���¸�ʿ�������X����

        unsigned int GetY(); // �õ���ʿ�������Y����
        void UpdateY ( unsigned int y ); // ���¸�ʿ�������y����


        // ע��������Ϊ�������꣬�ڶ���Ľӿ��л�ת�����������
        // ������������е������Ϊ��������
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
