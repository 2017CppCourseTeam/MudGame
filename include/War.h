#ifndef WAR_H
#define WAR_H
#include <iostream>
#include "Map.h"

using namespace std;

class War
{
    public:
        War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num );
        ~War();
        void Show_Status();
        void Show_Map ( bool show_detail = false );
        void Select_Point ( unsigned int _x, unsigned int _y );
        void Show_Point_Status();
    private:
        double life;
        double magic;
        int coin;
        double lucky;

        Map* _map;
        Point* selecter;

        bool _Load_Map ( string name, unsigned short level );
        template <class T>
        T _ConvertStringToNum ( const string& str );
        string _Read ( ifstream &f );
        string _Decrypt ( string str );
};

#endif // WAR_H
