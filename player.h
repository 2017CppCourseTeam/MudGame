#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

class Player{
    private:
        double prestige;
        double bitcoin;
        double violence;
        int second;
        int warnum;
        friend class User;
    public:
        Player();
        void showStatus();
        void TrainCoder();
        void DigMine();
        void WashBrain() ;
        ~Player(){};
};

#endif // PLAYER1_H_INCLUDED
