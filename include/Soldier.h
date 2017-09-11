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
                 unsigned int pdccoin ) : Soldier ( id, 100, 20, 50, humanity, pdclife, pdcmagic, pdccoin )
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
                 unsigned int pdccoin ) : Soldier ( id, 200, 150, 80, humanity, pdclife, pdcmagic, pdccoin )
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
                    unsigned int pdccoin ) : Soldier ( id, 250, 210, 140, humanity, pdclife, pdcmagic, pdccoin )
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
                 unsigned int pdccoin ) : Soldier ( id, 160, 0, 70, humanity, pdclife, pdcmagic, pdccoin )
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
                  unsigned int pdccoin ) : Soldier ( id, 500, 700, 310, mechanical, pdclife, pdcmagic, pdccoin )
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
                 unsigned int pdccoin ) : Soldier ( id, 450, 525, 430, beast, pdclife, pdcmagic, pdccoin )
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
               unsigned int pdccoin ) : Soldier ( id, 210, 200, 160, beast, pdclife, pdcmagic, pdccoin )
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
                unsigned int pdccoin ) : Soldier ( id, 140, 120, 75, wizard, pdclife, pdcmagic, pdccoin )
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
                 unsigned int pdccoin ) : Soldier ( id, 210, 185, 120, wizard, pdclife, pdcmagic, pdccoin )
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
                   unsigned int pdccoin ) : Soldier ( id, 400, 575, 500, warcraft, pdclife, pdcmagic, pdccoin )
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
                     unsigned int pdccoin ) : Soldier ( id, 450, 670, 260, warcraft, pdclife, pdcmagic, pdccoin )
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
               unsigned int pdccoin ) : Soldier ( id, 380, 430, 350, warcraft, pdclife, pdcmagic, pdccoin )
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
                  unsigned int pdccoin ) : Soldier ( id, 350, 770, 120, warcraft, pdclife, pdcmagic, pdccoin )
        {
            this->power = power;
            this->_name = _Phoenix;
            this->x = x;
            this->y = y;
        }
};


#endif // SOLDIER_H
