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
    cout << "|����ֵ��              |" << endl;
    cout << "|                      |" << endl;
    cout << "|   ������" << setw ( 10 ) << this->prestige << "   |" << endl;
    cout << "|   ���رң�" << setw ( 8 ) << this->bitcoin << "   |" << endl;
    cout << "|   ����ֵ��" << setw ( 8 ) << this->violence << "   |" << endl;
    cout << "|                      |" << endl;
    cout << "|                " << setw ( 3 ) << this->second << "s  |" << endl;
    cout << " ---------------------- " << endl;
    return;
}

void Player::TrainCoder()
{
    cout << " ------------------------------------------- " << endl;
    cout << "|   ���ڽ��У�ѵ����ũ������80%���ʳɹ���   |" << endl;
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
        cout << "|   ��ϲ�㣬ѵ���ɹ���                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ����ֵ+5��+1s    |" << endl;
        cout << " ------------------------------------------- " << endl;
    } else {
        cout << "|   ���ź���ѵ��ʧ�ܡ�                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ����ֵ-3��-1s    |" << endl;
        cout << " ------------------------------------------- " << endl;
    }
    return;
}
void Player::DigMine()
{
    cout << " ------------------------------------------- " << endl;
    cout << "|   ���ڽ��У��ڱ��رҿ�                    |" << endl;
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
        cout << "|   ��NB�������ڳ�10�����رң�              |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ���ر�+10��+1s   |" << endl;
        cout << " ------------------------------------------- " << endl;
    } else {
        this->bitcoin += 0.01;
        this->second += 1;
        cout << "|   ��ϲ�㣬�����ڳ�0.1�����رң�           |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ���ر�+0.1��+1s  |" << endl;
        cout << " ------------------------------------------- " << endl;
    }
    return;
}
void Player::WashBrain()
{
    cout << " ------------------------------------------- " << endl;
    cout << "|   ���ڽ��У� ����ϴ��                     |" << endl;
    cout << "|    ���������������������������� ������    |" << endl;
    cout << "|   ������ ��   ____________ ����������     |" << endl;
    cout << "|  ��������    {            }  ��������     |" << endl;
    cout << "|   ��������  [    X    X    ]   ��������   |" << endl;
    cout << "|    ����   ��  {    ..     }  ����   ����  |" << endl;
    cout << "|  ������ ����   {         } ������ �� ��   |" << endl;
    cout << "|    �� �� ��  �� {   B   }   �������� ���� |" << endl;
    cout << "|    �� ��������   {____ }     ������ ��    |" << endl;
    cout << "|  ��  ������������         ��������������  |" << endl;
    cout << "|    ������������������������������������   |" << endl;
    cout << "|                                           |" << endl;
    this->bitcoin -= 0.2;
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.7 ) {
        this->prestige += 10;
        this->second += 1;
        cout << "|   ��ϲ����ѵ���ɹ�                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            ����+10�� +1s  |" << endl;
        cout << " ------------------------------------------- " << endl;
    } else {
        this->prestige -= 5;
        this->second -= 1;
        cout << "|   ���ź���ѵ��ʧ��                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            ����-5�� -1s   |" << endl;
        cout << " ------------------------------------------- " << endl;
    }
    return;
}
