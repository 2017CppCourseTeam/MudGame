#ifndef MAP_H
#define MAP_H
#include<iostream>
#include<string>
#include <fstream>

using namespace std;


enum LocalPower {_empty, player, ai};

class Point
{
    public:
        Point (unsigned int _x, unsigned int _y );
        unsigned int GetNumber();
        unsigned int GetAttack();
        unsigned int GetDefense();
        int GetLife();
        enum LocalPower GetPower();

        void UpdateNumber(unsigned int number);
        void UpdateAttack(unsigned int number);
        void UpdateDefense(unsigned int number);
        void UpdateLife(unsigned int number);
        void UpdatePower(unsigned int number);
        ~Point();
    private:
        unsigned int x;
        unsigned int y;
        enum LocalPower power;
        unsigned int number;
        unsigned int attack;
        unsigned int defense;
        int life;
};

class BaseBuilding: public Point
{
    public:
        BaseBuilding ( );
        ~BaseBuilding();
    private:
};

class City: public Point
{
    public:
        City ( );
        ~City();
    private:

};

class EmptyPoint: public Point
{
     public:
        EmptyPoint ( );
        ~EmptyPoint();
    private:
};

class Map
{
    public:
        Map ( unsigned int height, unsigned int width, string name, unsigned short level, unsigned char**& data );
        ~Map();
    private:
        unsigned int height;
        unsigned int rheight;
        unsigned int width;
        unsigned int rwidth;
        unsigned short level;
        string name;
        unsigned char** _map;

        string _Read ( ifstream &f );
        string _Decrypt ( string str );
        template <class T>
        T _ConvertStringToNum ( const std::string& str );
};
#endif // MAP_H
