#ifndef WAR_H
#define WAR_H
#include <iostream>
#include "Map.h"
#include "Soldier.h"

using namespace std;

class War
{
    public:
        War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num );
        ~War();
        void Show_Status();
        void Show_Map ( bool show_detail = false );
        bool Select_Point ( unsigned int _x, unsigned int _y );
        void Show_Point_Status();
        bool Select_Soldier(unsigned int id);
        void Show_Soldier_Status(unsigned int id);
    private:
        double life;
        double magic;
        int coin;
        double lucky;
        unsigned int _id;

        Map* _map;
        Point* poing_selecter;
        Soldier* soldier_selecter;

        bool _Load_Map ( string name, unsigned short level );
        template <class T>
        T _ConvertStringToNum ( const string& str );
        string _Read ( ifstream &f );
        string _Decrypt ( string str );
};

#endif // WAR_H
