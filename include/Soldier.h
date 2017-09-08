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

        int GetAttack(); // �õ���ʿ���Ĺ�����
        int GetDefence(); // �õ���ʿ���ķ�����
        int GetLife(); // �õ���ʿ��������ֵ
        unsigned int GetX(); // �õ���ʿ�������X����
        unsigned int GetY(); // �õ���ʿ�������Y����
        unsigned int GetID(); // �õ���ʿ����ID
        unsigned int GetPrice(); // �õ���ʿ���������ɱ�
        enum Species GetSpecies(); // �õ���ʿ�����������ƣ�ö�����ͣ�
        string SGetSpecies(); // �õ���ʿ�����������ƣ��ַ������ͣ�
        enum AllSoldiers GetSoldierName(); // �õ���ʿ���ı������ƣ�ö�����ͣ�
        string SGetName(); // �õ���ʿ���ı������ƣ��ַ������ͣ�


        void UpdateX ( unsigned int x ); // ���¸�ʿ�������X����
        void UpdateY ( unsigned int y ); // ���¸�ʿ�������y����
        void UpdateAttack ( int attack ); // ���¸�ʿ���Ĺ�����
        void UpdateDefence ( int defence ); // ���¸�ʿ���ķ�����
        void UpdateID ( unsigned int id ); // ���¸�ʿ����ID
        void UpdateLife ( int life ); // ���¸�ʿ��������ֵ

        // ע��������Ϊ������ߣ��ڶ���Ľӿ��л�ת�����������
        // ������������е������Ϊ��������
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
