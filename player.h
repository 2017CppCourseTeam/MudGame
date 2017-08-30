#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Player
{
private:
    double prestige;
    double bitcoin;
    double violence;
    int second;
    int war_num;
    friend class User;
public:
    Player ( );

    void TrainCoder ( );
    void DigMine ( );
    void WashBrain ( );
    void StartWar ( );
};

#endif // PLAYER_H_INCLUDED
