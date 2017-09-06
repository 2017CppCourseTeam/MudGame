#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

enum LocalPower {_empty, player, ai, player_city, ai_city, empty_city};

class Point
{
    public:
        Point();
        Point ( unsigned int id, unsigned int _x, unsigned int _y );
        unsigned int GetNumber();
        unsigned int GetAttack();
        unsigned int GetDefense();
        unsigned int GetX();
        unsigned int GetY();
        enum LocalPower GetPower();
        string SGetPower();
        int GetLife();

        void Reset ( unsigned int id, unsigned int _x, unsigned int _y );

        void UpdateNumber ( unsigned int number );
        void UpdateAttack ( unsigned int attack );
        void UpdateDefense ( unsigned int defense );
        void UpdateLife ( unsigned int life );
        void UpdatePower ( enum LocalPower power );
        ~Point();
    private:
        unsigned int id;
        unsigned int x;
        unsigned int y;
        enum LocalPower power;
        unsigned int number;
        unsigned int attack;
        unsigned int defense;
        int life;
};

class Map
{
    public:
        Map ( unsigned int height, unsigned int width, string name, unsigned short level, unsigned char**& data );
        Point* Get_Point ( unsigned int _x, unsigned int _y );
        void Update();
        void Show_Map ( bool show_detail );
        ~Map();
    private:
        friend class War;
        unsigned int height;
        unsigned int rheight; // Real height
        unsigned int width;
        unsigned int rwidth; // Real width
        unsigned short level;
        Point** points;
        string _level;
        string name;
        unsigned char** _map;

        void _Init_Map_Points();

};
#endif // MAP_H
