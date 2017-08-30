#include "player.h"
using namespace std;

Player::Player()
{
    this->prestige = 50.0;
    this->bitcoin = 10.0;
    this->violence = 50.0;
    this->second = 10;
    this->war_num = 0;
    srand ( unsigned ( time ( NULL ) ) );
}

void Player::showStatus()
{
    cout << " ---------------------- " << endl;
    cout << "|属性值：              |" << endl;
    cout << "|                      |" << endl;
    cout << "|   威望：" << setw ( 10 ) << this->prestige << "   |" << endl;
    cout << "|   比特币：" << setw ( 8 ) << this->bitcoin << "   |" << endl;
    cout << "|   暴力值：" << setw ( 8 ) << this->violence << "   |" << endl;
    cout << "|                      |" << endl;
    cout << "|                " << setw ( 3 ) << this->second << "s  |" << endl;
    cout << " ---------------------- " << endl;
    return;
}

void Player::TrainCoder()
{
    cout << " ------------------------------------------- " << endl;
    cout << "|   正在进行：训练码农（您有80%几率成功）   |" << endl;
    cout << "|                                           |" << endl;
    cout << "|                     ***                   |" << endl;
    cout << "|            ||       ***                   |" << endl;
    cout << "|            ||         *                   |" << endl;
    cout << "|            ||  //**//**                   |" << endl;
    cout << "|             =+++++++  *                   |" << endl;
    cout << "|                       *                   |" << endl;
    cout << "|                       *                   |" << endl;
    cout << "|                    *******                |" << endl;
    cout << "|                    *     *                |" << endl;
    cout << "|                     *   *                 |" << endl;
    cout << "|                                           |" << endl;
    this->bitcoin -= 0.2;
    if ( rand() / double ( RAND_MAX ) <= 0.8 ) {
        this->violence += 5;
        this->second += 1;
        cout << "|   恭喜你，训练成功。                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          暴力值+5，+1s    |" << endl;
        cout << " ------------------------------------------- " << endl;
    } else {
        cout << "|   很遗憾，训练失败。                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          暴力值-3，-1s    |" << endl;
        cout << " ------------------------------------------- " << endl;
    }
    return;
}
void Player::DigMine()
{
    cout << " ------------------------------------------- " << endl;
    cout << "|   正在进行：挖比特币矿                    |" << endl;
    cout << "|                                           |" << endl;
    cout << "|                  @@@@@   <$>              |" << endl;
    cout << "|                  {^ ^}    |               |" << endl;
    cout << "|                   |o|     |               |" << endl;
    cout << "|                    *      |               |" << endl;
    cout << "|              **************               |" << endl;
    cout << "|                    *                      |" << endl;
    cout << "|                    *                      |" << endl;
    cout << "|                   * *                     |" << endl;
    cout << "|                  *   *                    |" << endl;
    cout << "|                 *     *                   |" << endl;
    cout << "|                  *   *                    |" << endl;
    cout << "|                                           |" << endl;
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.05 ) {
        this->bitcoin += 10;
        this->second += 1;
        cout << "|   好NB，本次挖出10个比特币！              |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          比特币+10，+1s   |" << endl;
        cout << " ------------------------------------------- " << endl;
    } else {
        this->bitcoin += 0.01;
        this->second += 1;
        cout << "|   恭喜你，本次挖出0.1个比特币！           |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          比特币+0.1，+1s  |" << endl;
        cout << " ------------------------------------------- " << endl;
    }
    return;
}
void Player::WashBrain()
{
    cout << " ------------------------------------------- " << endl;
    cout << "|   正在进行： 政治洗脑                     |" << endl;
    cout << "|    ～～～～～～～～～～～～～～ ～～～    |" << endl;
    cout << "|   ～～～ ～   ____________ ～～～～～     |" << endl;
    cout << "|  ～～～～    {            }  ～～～～     |" << endl;
    cout << "|   ～～～～  [    X    X    ]   ～～～～   |" << endl;
    cout << "|    ～～   ～  {    ..     }  ～～   ～～  |" << endl;
    cout << "|  ～～～ ～～   {         } ～～～ ～ ～   |" << endl;
    cout << "|    ～ ～ ～  ～ {   B   }   ～～～～ ～～ |" << endl;
    cout << "|    ～ ～～～～   {____ }     ～～～ ～    |" << endl;
    cout << "|  ～  ～～～～～～         ～～～～～～～  |" << endl;
    cout << "|    ～～～～～～～～～～～～～～～～～～   |" << endl;
    cout << "|                                           |" << endl;
    this->bitcoin -= 0.2;
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.7 ) {
        this->prestige += 10;
        this->second += 1;
        cout << "|   恭喜您，训练成功                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            威望+10， +1s  |" << endl;
        cout << " ------------------------------------------- " << endl;
    } else {
        this->prestige -= 5;
        this->second -= 1;
        cout << "|   很遗憾，训练失败                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            威望-5， -1s   |" << endl;
        cout << " ------------------------------------------- " << endl;
    }
    return;
}
