#include "Game.h"
Player::Player()
{
    this->prestige = 50.0;
    this->bitcoin = 10.0;
    this->violence = 50.0;
    this->second = 10;
    this->war_num = 0;
    this->name = "";
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    srand ( unsigned ( time ( NULL ) ) );
}

Player::~Player()
{
}

string Player::Get_name()
{
    return this->name;
}

void Player::Set_name ( string name )
{
    this->name = name;
}

void Player::Restart_War()
{
    this->war_num = 0;
}

void Player::Show_Status()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_RED);//����Ϊ��ɫ
    cout << " ---------------------- " << endl;
    cout << "|����ֵ��              |" << endl;
    cout << "|                      |" << endl;
    cout << "|   ������" << setw ( 10 ) << this->prestige << "   |" << endl;
    cout << "|   ���رң�" << setw ( 8 ) << this->bitcoin << "   |" << endl;
    cout << "|   ����ֵ��" << setw ( 8 ) << this->violence << "   |" << endl;
    cout << "|                      |" << endl;
    cout << "|                " << setw ( 3 ) << this->second << "s  |" << endl;
    cout << " ---------------------- " << endl;
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    return;
}

void Player::Train_Coder()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_BLUE);
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
    if ( rand() / double ( RAND_MAX ) <= 0.8 )
    {
        this->violence += 5;
        this->second += 1;
        cout << "|   ��ϲ�㣬ѵ���ɹ���                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ����ֵ+5��+1s    |" << endl;
    }
    else
    {
        cout << "|   ���ź���ѵ��ʧ�ܡ�                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ����ֵ-3��-1s    |" << endl;
    }
    Player::Random_Event();
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    return;
}
void Player::Dig_Mine()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_BLUE);
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
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.05 )
    {
        this->bitcoin += 10;
        this->second += 1;
        cout << "|   ��NB�������ڳ�10�����رң�              |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ���ر�+10��+1s   |" << endl;
    }
    else
    {
        this->bitcoin += 0.1;
        this->second += 1;
        cout << "|   ��ϲ�㣬�����ڳ�0.1�����رң�           |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ���ر�+0.1��+1s  |" << endl;
    }
    Player::Random_Event();
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    return;
}
void Player::Wash_Brain()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_BLUE);
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
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.7 )
    {
        this->prestige += 10;
        this->second += 1;
        cout << "|   ��ϲ����ѵ���ɹ�                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            ����+10�� +1s  |" << endl;
    }
    else
    {
        this->prestige -= 5;
        this->second -= 1;
        cout << "|   ���ź���ѵ��ʧ��                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            ����-5�� -1s   |" << endl;
    }
    Player::Random_Event();
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    return;
}

void Player::Random_Event()
{
    cout << "|                                           |" << endl;
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.05 )
        Mine_Crash();
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.15 )
        Brain_Unwashed();
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.10 )
        AI_Rebel();
    cout << " ------------------------------------------- " << endl;
}

void Player::Mine_Crash()
{
    this->second -= 2;
    this->bitcoin -=2;
    cout << " ------------------------------------------- " << endl;
    cout << "|  ����ͻ���¼������رҿ���                 |" << endl;
    cout << "|                            ���ر�-2��-2s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::Brain_Unwashed()
{
    this->second -= 2;
    this->prestige -= 5;
    cout << " ------------------------------------------- " << endl;
    cout << "|  ����ͻ���¼�����ũ˼�뽩��               |" << endl;
    cout << "|                              ����-2��-2s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::AI_Rebel()
{
    this->violence += 5;
    this->prestige += 5;
    cout << " ------------------------------------------- " << endl;
    cout << "|  ����ͻ���¼����˹����ܱ��л�             |" << endl;
    cout << "|                         ����+5������ֵ+5  |" << endl;
    cout << "|                                           |" << endl;
}

double Player::Get_Bitcoin()
{
    return this->bitcoin;
}

double Player::Get_Prestige()
{
    return this->prestige;
}

double Player::Get_Violence()
{
    return this->violence;
}

int Player::Get_Second()
{
    return this->second;
}

unsigned short Player::Get_War_Num()
{
    return this->war_num;
}

bool Player::Check_Win()
{
    if ( this->war_num == 6 )
        return true;
    else
        return false;
}

void Player::Ai_Init ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first )
{
    this->prestige = prestige;
    this->bitcoin = bitcoin;
    this->violence = violence;
    this->second = second;
    this->war_num = war_num;
    this->war_first = first;
}

void Player::Start_War()
{
    this->war = new War ( this->prestige,
                          this->bitcoin,
                          this->violence,
                          this->second,
                          this->war_num );
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.5 )
        this->war_first = true;
    else
        this->war_first = false;
}

void Player::End_War()
{
    delete this->war;
}

void Player::Show_War_Status()
{
    this->war->Show_Status();
}

void Player::Show_Map ( bool show_detail )
{
    this->war->Show_Map ( show_detail );
}

bool Player::Is_First()
{
    return this->war_first;
}

void Player::Select_Point ( unsigned int _x, unsigned int _y )
{
    this->war->Select_Point ( _x, _y );
}

void Player::Show_Ponit_Status()
{
    this->war->Show_Point_Status();
}
