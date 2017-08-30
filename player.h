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
    void showStatus();
    void TrainCoder();
    void DigMine();
    void WashBrain();
    string Get_name();
    void Set_name ( string name );
    ~Player() {};
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
