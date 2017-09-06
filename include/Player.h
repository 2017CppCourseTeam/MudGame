#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <sstream>

#include "War.h"
#include "AI-Settings.h"

using namespace std;

enum STATUS {_main = 0, practice, war, quit, start_war, win, lose};

class Player
{
    public:
        Player();
        ~Player();

        void Show_Status();

        void Train_Coder();
        void Dig_Mine();
        void Wash_Brain();

        void Random_Event();
        void Mine_Crash();
        void Brain_Unwashed();
        void AI_Rebel();
        void Naive();

        double Get_Prestige();
        double Get_Bitcoin();
        double Get_Violence();
        int Get_Second();
        unsigned short Get_War_Num();
        string Get_name();
        void Set_name ( string name );

        bool Is_First();
        void Restart_War();
        void Start_War();
        void End_War();
        bool Check_Win();

        void Show_War_Status();
        void Show_Map ( bool show_detail );
        bool Select_Point ( unsigned int _x, unsigned int _y );
        void Show_Ponit_Status();
        bool Select_Soldier ( unsigned int id );
        void Show_Soldier_Status ( unsigned int id );

        void Ai_Init ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first );
    private:
        double prestige;
        double bitcoin;
        double violence;
        int second;
        unsigned short war_num;
        bool war_first;
        string name;

        vector<Soldier> allow_species;

        HANDLE handle;
        War* war;
        friend class User;

};

#endif // PLAYER1_H_INCLUDED
