#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Player{
    private:
        double prestige;
        double bitcoin;
        double violence;
        int second;
        int warnum;
    public:
        Player() {
            this->prestige = 50.0;
            this->bitcoin = 10.0;
            this->violence = 50.0;
            this->second = 10;
            srand(unsigned(time(NULL)));
        }


        void TrainCoder() {
            this->bitcoin -= 0.2;
            if( rand() / double(RAND_MAX) <= 0.8) {
                this->violence += 5;
                this->second += 1;
                cout << "恭喜你，训练成功" << endl;
                return;
            }
            else {
                cout << "很遗憾，训练失败" << endl;
                return;
            }
        }
        void DigMine() {
            if((rand() / double(RAND_MAX)) <= 0.5) {
                this->bitcoin += 10;
                this->second += 1;
                cout << "恭喜你，本次挖出10个比特币！" << endl;
                return;
            }
            else {
                this->bitcoin += 0.01;
                this->second += 1;
                cout << "恭喜你，本次挖出0.1个比特币！" << endl;
                return;
            }
        }
        void WashBrain() {
            cout << "test";
            return;
        }

};

#endif
