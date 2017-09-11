#include "Player.h"

Player::Player()
{
    this->prestige = 50.0;
    this->bitcoin = 10.0;
    this->violence = 50.0;
    this->second = 10;
    this->war_num = 0;
    this->name = "";
    this->SetIdentity ( _player_ );
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
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
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_RED ); //����Ϊ��ɫ
    cout << " ---------------------- " << endl;
    cout << "|����ֵ��              |" << endl;
    cout << "|                      |" << endl;
    cout << "|   ������" << setw ( 10 ) << this->prestige << "   |" << endl;
    cout << "|   ���رң�" << setw ( 8 ) << this->bitcoin << "   |" << endl;
    cout << "|   ����ֵ��" << setw ( 8 ) << this->violence << "   |" << endl;
    cout << "|                      |" << endl;
    cout << "|                " << setw ( 3 ) << this->second << "s  |" << endl;
    cout << " ---------------------- " << endl;
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    return;
}

void Player::Train_Coder()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
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
        this->violence += 3;
        this->second += 1;
        cout << "|   ��ϲ�㣬ѵ���ɹ���                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ����ֵ+3��+1s    |" << endl;
    }
    else
    {
        this->violence -= 5;
        this->second -= 1;
        cout << "|   ���ź���ѵ��ʧ�ܡ�                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ����ֵ-5��-1s    |" << endl;
    }
    Player::Random_Event();
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    return;
}
void Player::Dig_Mine()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
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
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.15 )
    {
        this->bitcoin += 2;
        this->second += 1;
        cout << "|   ��NB�������ڳ�2�����رң�              |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ���ر�+2��+1s   |" << endl;
    }
    else
    {
        this->bitcoin += 0.5;
        this->second += 1;
        cout << "|   ��ϲ�㣬�����ڳ�0.5�����رң�           |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          ���ر�+0.5��+1s  |" << endl;
    }
    Player::Random_Event();
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    return;
}
void Player::Wash_Brain()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
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
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.8 )
    {
        this->prestige += 3;
        this->second += 1;
        cout << "|   ��ϲ����ѵ���ɹ�                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            ����+3�� +1s  |" << endl;
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
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    return;
}

void Player::Random_Event()
{
    cout << "|                                           |" << endl;
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.13 )
        Mine_Crash();
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.13 )
        Brain_Unwashed();
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.10 )
        AI_Rebel();
    cout << " ------------------------------------------- " << endl;
}

void Player::Mine_Crash()
{
    this->second -= 1;
    this->bitcoin -= 1;
    cout << " ------------------------------------------- " << endl;
    cout << "|  ����ͻ���¼������رҿ���                 |" << endl;
    cout << "|                            ���ر�-1��-1s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::Brain_Unwashed()
{
    this->second -= 2;
    this->prestige -= 5;
    cout << " ------------------------------------------- " << endl;
    cout << "|  ����ͻ���¼�����ũ˼�뽩��               |" << endl;
    cout << "|                              ����-5��-2s  |" << endl;
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
    this->SetIdentity ( _ai_ );
}

void Player::Start_War ( Map*& _map )
{
    this->war = new War ( this->prestige,
                          this->bitcoin,
                          this->violence,
                          this->second,
                          this->war_num,
                          _map );
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.5 )
        this->war_first = true;
    else
        this->war_first = false;
}

void Player::End_War ( Map*& _map )
{
    delete this->war;
    //delete _map;
}

void Player::Show_War_Status()
{
    this->war->_Show_Status();
}

void Player::Show_Map ( bool show_detail )
{
    this->war->_Show_Map ( show_detail );
}

bool Player::Is_First()
{
    return this->war_first;
}

bool Player::Select_Point ( unsigned int _x, unsigned int _y )
{
    if ( this->war->_Select_Point ( _x, _y ) )
        return true;
    else
        return false;
}

void Player::Show_Ponit_Status()
{
    this->war->_Show_Point_Status();
}

bool Player::Select_Soldier ( unsigned int id )
{
    return this->war->_Select_Soldier ( id );
}

void Player::Show_Soldier_Status ( unsigned int id )
{
    this->war->_Show_Soldier_Status ( id );
}

void Player::Show_Soldier_Status()
{
    this->war->_Show_Soldier_Status();
}

bool Player::Create_Soldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y )
{
    return this->war->_Create_Soldier ( soldier, power, x, y, &this->war->life, &this->war->magic, &this->war->coin );
}

void Player::Delete_Soldier ( unsigned int _id )
{
    this->war->_Delete_Soldier ( _id );
}

bool Player::IsSelectSoldier()
{
    return this->war->_IsSelectSoldier();
}

unsigned int Player::GetPlayerBaseX()
{
    return this->war->_GetPlayerBaseX();
}

unsigned int Player::GetPlayerBaseY()
{
    return this->war->_GetPlayerBaseY();
}

unsigned int Player::GetAIBaseX()
{
    return this->war->_GetAIBaseY();
}

unsigned int Player::GetAIBaseY()
{
    return this->war->_GetAIBaseY();
}

enum AllSoldiers Player::GetCurrentSoldierName()
{
    return this->war->_GetCurrentSoldierName();
}

enum LocalPower Player::GetCityPower()
{
    return this->war->_GetCityPower();
}

void Player::BuildCity()
{
    this->war->_BuildCity();
}

void Player::Recover()
{
}

enum IDENTITY Player::GetIdentity()
{
    return this->identity;
}

void Player::SetIdentity ( enum IDENTITY identity )
{
    this->identity = identity;
}

bool Player::MoveUp()
{
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _y != 0 )
    {
        this->war->soldier_selecter->UpdateY ( - 1 );
        if ( this->GetIdentity() == _player_ )
            this->war->_map->DrawToMap ( '*', _x, _y - 1 , false);
        else
            this->war->_map->DrawToMap ( 'X', _x, _y - 1 , false );
        this->war->_map->AddSoldierToPoint ( _x, _y - 1, *this->war->soldier_selecter );
        this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
        if ( this->war->_map->IsEmptyCity ( _x, _y ) )
            this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        return true;
    }
    else
        return false;
}

bool Player::MoveDown()
{
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _y != this->war->_map->GetRHeight() )
    {
        this->war->soldier_selecter->UpdateY ( 1 );
        if ( this->GetIdentity() == _player_ )
            this->war->_map->DrawToMap ( '*', _x, _y + 1, false );
        else
            this->war->_map->DrawToMap ( 'X', _x, _y + 1, false );
        this->war->_map->AddSoldierToPoint ( _x, _y + 1, *this->war->soldier_selecter );
        this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
        if ( this->war->_map->IsEmptyCity ( _x, _y ) )
            this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        return true;
    }
    else
        return false;
}

bool Player::MoveLeft()
{
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _x != 0 )
    {
        this->war->soldier_selecter->UpdateX ( - 1 );
        if ( this->GetIdentity() == _player_ )
            this->war->_map->DrawToMap ( '*', _x - 1, _y, false );
        else
            this->war->_map->DrawToMap ( 'X', _x - 1, _y, false );
        this->war->_map->AddSoldierToPoint ( _x - 1, _y, *this->war->soldier_selecter );
        this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
        if ( this->war->_map->IsEmptyCity ( _x, _y ) )
            this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        return true;
    }
    else
        return false;
}

bool Player::MoveRight()
{
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _x !=  this->war->_map->GetRWidth() )
    {
        this->war->soldier_selecter->UpdateX ( 1 );
        if ( this->GetIdentity() == _player_ )
            this->war->_map->DrawToMap ( '*', _x + 1, _y, false );
        else
            this->war->_map->DrawToMap ( 'X', _x + 1, _y, false );
        this->war->_map->AddSoldierToPoint ( _x + 1, _y, *this->war->soldier_selecter );
        this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
        if ( this->war->_map->IsEmptyCity ( _x, _y ) )
            this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        return true;
    }
    else
        return false;
}
