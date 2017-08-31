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

using namespace std;

class Player
{
public:
    Player();
    ~Player() {};

    void Show_Status();
    void Train_Coder();
    void Dig_Mine();
    void Wash_Brain();

    void Start_War();
    void Restart_War();

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

};

#endif // PLAYER1_H_INCLUDED
