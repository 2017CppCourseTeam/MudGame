#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include "windows.h"

using namespace std;

enum STATUS {_main = 0, practice, war, quit, win, lose};

class Player
{
public:
    Player();
    ~Player() {};

    void Show_Status();
    void Train_Coder();
    void Dig_Mine();
    void Wash_Brain();

    void Random_Event();

    void Mine_Crash();
    void Brain_Unwashed();
    void AI_Rebel();
    void Naive();

    void Start_War();
    void Restart_War();

    int Get_Second();
    int Get_War_Num();

    string Get_name();
    void Set_name ( string name );
private:
    double prestige;
    double bitcoin;
    double violence;
    int second;
    int war_num;
    string name;
    friend class User;
    HANDLE handle;
};

#endif // PLAYER1_H_INCLUDED
