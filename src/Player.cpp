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
    return this->war_num + 1;
}

bool Player::Check_Win()
{
    if ( this->war_num == 6 )
        return true;
    else
        return false;
}

void Player::Start_War ( Map*& _map )
{
    this->war = new War ( this->prestige,
                          this->bitcoin,
                          this->violence,
                          this->second,
                          this->war_num,
                          _map );
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

void Player::First()
{
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.5 )
        this->war_first = true;
    else
        this->war_first = false;
}

bool Player::Is_First()
{
    return this->war_first;
}

bool Player::Select_Point ( unsigned int _x, unsigned int _y )
{
    return this->war->_Select_Point ( _x, _y );
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
    bool _result = this->war->_Create_Soldier ( soldier, power, x, y, &this->war->life, &this->war->magic, &this->war->coin );
    if ( _result )
    {
        cout << endl << "[*]�����ɹ�" << endl;
        this->war->_Show_Soldier_Status ( this->war->_id++ );
    }
    else
        cout << endl << "[!]����ʧ�ܣ���Դ����" << endl;
    return _result;
}

void Player::Delete_Soldier ( unsigned int _id )
{
    this->war->_Delete_Soldier ( _id );
}

Soldier* Player::GetSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id )
{
    return this->war->_GetSoldierFromPoint ( _x, _y, _id );
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

void Player::AI_Init ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first )
{
    this->prestige = prestige;
    this->bitcoin = bitcoin;
    this->violence = violence;
    this->second = second;
    this->war_num = war_num;
    this->war_first = first;
    this->SetIdentity ( _ai_ );
    this->act_num = 1;
    this->coldness = sqrt ( ( 10 - war_num ) * 0.03 ) + prestige * 0.05 + violence + 0.05 ;
}

void Player::Action()
{
    /*
       int manipulator = this->act_num % 8;
       cout << endl << "[*]NO." << this->act_num << " action" << endl;
       if ( this->Get_War_Num() == 1 )
       {
           if ( this->act_num <= 40 )
           {
               switch ( manipulator )
               {
                   case 1:
                   {
                       if ( this->act_num == 1 )
                       {
                           this->Create_Soldier ( _Worker, ai_city, 7, 8 );
                           this->Select_Soldier ( this->war->_id );
                       }
                       else
                       {
                           this->Create_Soldier ( _Archer, ai_city, 7, 8 );
                           this->Select_Soldier ( this->war->_id );
                       }
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->MoveUp();
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateY ( -1 );
                       if ( this->act_num == 8 )
                           this->BuildCity();
                       break;
                   }
               }
           }
           else if ( this->act_num > 40 && this->act_num <= 80 )
           {
               switch ( manipulator )
               {
                   case 1:
                   {
                       this->Select_Soldier ( ( this->act_num - 40 ) / 8 );
                       this->war->soldier_selecter->UpdateY ( -1 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->war->soldier_selecter->UpdateY ( -1 );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
               }
           }
       }
       if ( this->Get_War_Num() == 2 )
       {
           if ( this->act_num <= 56 )
           {
               switch ( manipulator )
               {
                   case 1:
                   {
                       if ( this->act_num == 1 )
                           this->Create_Soldier ( _Worker, ai_city, 7, 8 );
                       else if ( this->act_num == 9 && this->act_num == 17 && this->act_num == 25 )
                           this->Create_Soldier ( _Slime, ai_city, 7, 8 );
                       else
                           this->Create_Soldier ( _Goblin, ai_city, 7, 8 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateY ( -1 );
                       if ( this->act_num == 8 )
                           this->BuildCity();
                       break;
                   }
               }
           }
           else if ( this->act_num > 56 && this->act_num <= 112 )
               switch ( manipulator )
               {
                   case 1:
                   {
                       this->Select_Soldier ( ( this->act_num - 56 ) / 8 );
                       this->war->soldier_selecter->UpdateY ( -1 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->war->soldier_selecter->UpdateY ( -1 );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
               }
       }
       if ( this->Get_War_Num() == 3 )
       {
           if ( this->act_num <= 72 )
               switch ( manipulator )
               {
                   case 1:
                   {
                       if ( this->act_num == 1 )
                           this->Create_Soldier ( _Worker, ai_city, 7, 8 );
                       if ( this->act_num == 9 || this->act_num == 17 || this->act_num == 25 || this->act_num == 33 )
                           this->Create_Soldier ( _SwordsMan, ai_city, 7, 8 );
                       if ( this->act_num == 57 || this->act_num == 41 || this->act_num == 49 || this->act_num == 65 )
                           this->Create_Soldier ( _Dragon, ai_city, 7, 8 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->war->soldier_selecter->UpdateX ( - 1 );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateY ( - 1 );
                       if ( this->act_num == 8 )
                           this->BuildCity();
                       break;
                   }
               }
           else if ( this->act_num > 72 && this->act_num <= 144 )
           {
               int soldier_num = ( this->act_num - 72 ) / 8;
               switch ( manipulator )
               {
                   case 1:
                   {
                       this->Select_Soldier ( soldier_num );
                       if ( soldier_num == 1 && soldier_num == 2 && soldier_num == 3 && soldier_num == 4 )
                           this->war->soldier_selecter->UpdateY ( -1 );
                       else
                           this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->Select_Soldier ( soldier_num );
                       if ( soldier_num == 1 && soldier_num == 2 && soldier_num == 3 && soldier_num == 4 )
                           this->war->soldier_selecter->UpdateY ( -1 );
                       else
                           this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->Select_Soldier ( soldier_num );
                       if ( soldier_num == 1 && soldier_num == 2 && soldier_num == 3 && soldier_num == 4 )
                           this->war->soldier_selecter->UpdateX ( -1 );
                       else
                           this->war->soldier_selecter->UpdateY ( -1 );
                       break;
                   }
               }
           }
       }
       if ( this->Get_War_Num() == 4 )
       {
           if ( this->act_num <= 104 )
               switch ( manipulator )
               {
                   case 1:
                   {
                       if ( this->act_num == 1 )
                           this->Create_Soldier ( _Worker, ai_city, 7, 8 );
                       if ( this->act_num == 9 ||
                               this->act_num == 17 ||
                               this->act_num == 25 ||
                               this->act_num == 33 ||
                               this->act_num == 41 ||
                               this->act_num == 49 ||
                               this->act_num == 57 )
                           this->Create_Soldier ( _SiegCar, ai_city, 7, 8 );
                       if ( this->act_num == 65 ||
                               this->act_num == 73 ||
                               this->act_num == 81 ||
                               this->act_num == 89 )
                           this->Create_Soldier ( _Naga, ai_city, 7, 8 );
                       if ( this->act_num == 97 )
                           this->Create_Soldier ( _IceGiant, ai_city, 7, 8 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->war->soldier_selecter->UpdateX ( -1 );
                       this->war->_Show_Soldier_Status ( );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateY ( -1 );
                       this->war->_Show_Soldier_Status ( );
                       if ( act_num == 8 )
                           this->BuildCity();
                       break;
                   }
               }
           else if ( this->act_num > 104 && this->act_num <= 208 )
           {
               int soldier_num = ( this->act_num - 104 ) / 8;
               switch ( manipulator )
               {
                   case 1:
                   {
                       this->Select_Soldier ( soldier_num );
                       if ( soldier_num >= 1 && soldier_num <= 7 )
                       {
                           this->war->soldier_selecter->UpdateY ( -1 );
                           this->war->_Show_Soldier_Status ( );
                       }
                       else
                           this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->Select_Soldier ( soldier_num );
                       if ( soldier_num >= 1 && soldier_num <= 7 )
                           this->war->soldier_selecter->UpdateY ( -1 );
                       else
                           this->war->soldier_selecter->UpdateX ( -1 );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->Select_Soldier ( soldier_num );
                       if ( soldier_num >= 1 && soldier_num <= 7 )
                           this->war->soldier_selecter->UpdateX ( -1 );
                       else
                           this->war->soldier_selecter->UpdateY ( -1 );
                       break;
                   }
               }
           }
       }
       if ( this->Get_War_Num() == 5 )
       {
           if ( this->act_num == 1 )
           {
               this->Create_Soldier ( _Naga, ai_city, 8, 6 );
               this->Create_Soldier ( _Naga, ai_city, 7, 7 );
               this->Create_Soldier ( _Naga, ai_city, 6, 8 );
               cout << "�����������˲�����ϡ�" << endl;
           }
           int manipulator = act_num % 8;
           if ( this->act_num <= 176 )
           {
               switch ( manipulator )
               {
                   case 1:
                   {
                       if ( this->act_num >= 1 )
                           this->Create_Soldier ( _Worker, ai_city, 7, 8 );
                       if ( this->act_num >= 9 && this->act_num <= 73 )
                           this->Create_Soldier ( _Dragon, ai_city, 7, 8 );
                       if ( this->act_num >= 81 && this->act_num <= 105 )
                           this->Create_Soldier ( _IceGiant, ai_city, 7, 8 );
                       if ( this->act_num >= 113 && this->act_num <= 137 )
                           this->Create_Soldier ( _FlameBirds, ai_city, 7, 8 );
                       if ( this->act_num >= 145 && this->act_num <= 169 )
                           this->Create_Soldier ( _Phoenix, ai_city, 7, 8 );
                       break;
                   }
                   case 2:
                   case 3:
                   case 4:
                   {
                       this->war->soldier_selecter->UpdateX ( -1 );
                       this->war->_Show_Soldier_Status ( );
                       break;
                   }
                   case 5:
                   case 6:
                   case 7:
                   case 0:
                   {
                       this->war->soldier_selecter->UpdateY ( -1 );
                       this->war->_Show_Soldier_Status ( );
                       if ( this->act_num == 8 )
                           this->BuildCity();
                       break;
                   }
               }
           }
           else if ( this->act_num > 176 && this->act_num <= 332 )
           {
               int soldier_num = ( this->act_num - 176 ) / 8;
               if ( soldier_num % 3 == 1 )
               {
                   if ( manipulator == 1 )
                       this->Select_Soldier ( soldier_num );
                   if ( manipulator % 2 == 0 )
                       this->war->soldier_selecter->UpdateY ( -1 );
                   else
                       this->war->soldier_selecter->UpdateX ( -1 );
               }
               else
               {
                   int soldier_num = ( this->act_num - 176 ) / 8;
                   switch ( manipulator )
                   {
                       case 1:
                       {
                           this->Select_Soldier ( soldier_num );
                           if ( soldier_num % 3 == 0 )
                               this->war->soldier_selecter->UpdateY ( -1 );
                           else
                               this->war->soldier_selecter->UpdateX ( -1 );
                           break;
                       }
                       case 2:
                       case 3:
                       case 4:
                       {
                           this->Select_Soldier ( soldier_num );
                           if ( soldier_num % 3 == 0 )
                               this->war->soldier_selecter->UpdateY ( -1 );
                           else
                               this->war->soldier_selecter->UpdateX ( -1 );
                           break;
                       }
                       case 5:
                       case 6:
                       case 7:
                       case 0:
                       {
                           this->Select_Soldier ( soldier_num );
                           if ( soldier_num >= 1 && soldier_num <= 7 )
                               this->war->soldier_selecter->UpdateX ( -1 );
                           else
                               this->war->soldier_selecter->UpdateY ( -1 );
                           break;
                       }
                   }
               }
           }
       }
       this->act_num++;*/
}

int Player::getAct_num()
{
    return this->act_num;
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
    this->war->UpdateLife();
}
enum IDENTITY Player::GetIdentity()
{
    return this->identity;
}
void Player::SetIdentity ( enum IDENTITY identity )
{
    this->identity = identity;
}

bool Player::IsCounterAttack()
{
    bool _result = false;
    return _result;
}

void Player::AttackBase ( unsigned int _x, unsigned int _y )
{
    cout << endl << "[*]";
    if ( this->GetIdentity() == _player_ )
        cout << "����";
    else
        cout << "���";
    cout << "�������ܹ���" << endl;
    double _hurt = this->war->soldier_selecter->GetAttack();
    cout << "[*]�ܵ� " << _hurt << " ���˺�" << endl;
    this->war->_map->Get_Point ( _x, _y )->UpdateLife ( -_hurt );
    cout << "[*]��ǰʣ������ֵΪ " << this->war->_map->Get_Point ( _x, _y )->GetLife() << endl ;
}

void Player::AttackSoldier ( unsigned int _x, unsigned int _y )
{
    cout << endl << "[*]";
    if ( this->GetIdentity() == _player_ )
        cout << "����";
    else
        cout << "���";
    cout << "ʿ����������" << endl;
    unsigned int _pid = this->war->_map->Get_Point ( _x, _y )->GetCurrentSoldierNum() - 1;
    double _hurt = this->war->soldier_selecter->GetAttack() - this->GetSoldierFromPoint ( _x, _y, _pid )->GetDefence();
    if ( _hurt > 0 )
    {
        unsigned int _id = this->GetSoldierFromPoint ( _x, _y, _pid )->GetID();
        cout << "[*]IDΪ " << _id << " ��ʿ���ܵ� " << _hurt << " ���˺�" << endl;
        this->GetSoldierFromPoint ( _x, _y, _pid )->UpdateLife ( _hurt );
        if ( this->GetSoldierFromPoint ( _x, _y, _pid )->GetLife() <= 0 )
            this->Delete_Soldier ( _id );
        else if ( this->IsCounterAttack() )
        {
        }
    }
    else
        cout << "[*]���������㣬δ�ܻ������˵�װ��" << endl;
}

void Player::AttackCity ( unsigned int _x, unsigned int _y )
{
    cout << endl << "[*]";
    if ( this->GetIdentity() == _player_ )
        cout << "����";
    else
        cout << "���";
    cout << "������������" << endl;
    double _hurt = this->war->soldier_selecter->GetAttack();
    if ( this->war->_map->Get_Point ( _x, _y )->GetLife() > 0 )
    {
        cout << "[*]�ó����ܵ� " << _hurt << " ���˺�" << endl;
        this->war->_map->Get_Point ( _x, _y )->UpdateLife ( -_hurt );
    }
    else
    {
        cout << "[*]�ó����ѱ��ݻ٣������е�ʿ��ȫ������" << endl;
        while ( true )
        {
            unsigned int _pid = this->war->_map->Get_Point ( _x, _y )->GetCurrentSoldierNum() - 1;
            if(_pid < 0)
                break;
            unsigned int _id = this->GetSoldierFromPoint ( _x, _y, _pid )->GetID();
            this->Delete_Soldier ( _id );
        }
    }
}


bool Player::MoveUp()
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _y != 0 &&
            ( ( this->GetIdentity() == _player_ &&
                this->war->_map->Get_Point ( _x, _y - 1 )->GetPower() != _player ) ||
              ( this->GetIdentity() == _ai_ &&
                this->war->_map->Get_Point ( _x, _y - 1 )->GetPower() != _ai ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x, _y - 1, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x, _y - 1, true ) == 'X' )
                    this->AttackBase ( _x, _y - 1 );
                else
                    this->AttackSoldier ( _x, _y - 1 );
            }
            else if ( this->war->_map->GetChar ( _x, _y - 1, false ) == '+' &&
                      this->war->_map->GetChar ( _x, _y - 1, true ) == 'X' )
            {
                _isattack = true;
                this->AttackCity ( _x, _y - 1 );
            }
            else
                this->war->_map->DrawToMap ( '*', _x, _y - 1, false );
        }
        else
        {
            if ( this->war->_map->GetChar ( _x, _y - 1, false ) == '*' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x, _y - 1, true ) == '*' )
                    this->AttackBase ( _x, _y - 1 );
                else
                    this->AttackSoldier ( _x, _y - 1 );
            }
            else if ( this->war->_map->GetChar ( _x, _y - 1, false ) == '+' &&
                      this->war->_map->GetChar ( _x, _y - 1, true ) == '*' )
            {
                _isattack = true;
                this->AttackCity ( _x, _y - 1 );
            }
            else
                this->war->_map->DrawToMap ( 'X', _x, _y - 1, false );
        }
        if ( !_isattack )
        {
            this->war->soldier_selecter->UpdateY ( - 1 );
            this->war->_map->AddSoldierToPoint ( _x, _y - 1, *this->war->soldier_selecter );
            this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
            if ( this->war->_map->IsEmptyCity ( _x, _y ) )
                this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        }
        _result = true;
    }
    return _result;
}

bool Player::MoveDown()
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( ( _y != this->war->_map->GetRHeight() - 1 ) &&
            ( ( this->GetIdentity() == _player_ &&
                this->war->_map->Get_Point ( _x, _y + 1 )->GetPower() != _player ) ||
              ( this->GetIdentity() == _ai_ &&
                this->war->_map->Get_Point ( _x, _y + 1 )->GetPower() != _ai ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x, _y + 1, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x, _y + 1, true ) == 'X' )
                    this->AttackBase ( _x, _y + 1 );
                else
                    this->AttackSoldier ( _x, _y + 1 );
            }
            else if ( this->war->_map->GetChar ( _x, _y + 1, false ) == '+' &&
                      this->war->_map->GetChar ( _x, _y + 1, true ) == 'X' )
            {
                _isattack = true;
                this->AttackCity ( _x, _y + 1 );
            }
            else
                this->war->_map->DrawToMap ( '*', _x, _y + 1, false );
        }
        else
        {
            if ( this->war->_map->GetChar ( _x, _y + 1, false ) == '*' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x, _y + 1, true ) == '*' )
                    this->AttackBase ( _x, _y + 1 );
                else
                    this->AttackSoldier ( _x, _y + 1 );
            }
            else if ( this->war->_map->GetChar ( _x, _y + 1, false ) == '+' &&
                      this->war->_map->GetChar ( _x, _y + 1, true ) == '*' )
            {
                _isattack = true;
                this->AttackCity ( _x, _y + 1 );
            }
            else
                this->war->_map->DrawToMap ( 'X', _x, _y + 1, false );
        }
        if ( !_isattack )
        {
            this->war->soldier_selecter->UpdateY ( 1 );
            this->war->_map->AddSoldierToPoint ( _x, _y + 1, *this->war->soldier_selecter );
            this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
            if ( this->war->_map->IsEmptyCity ( _x, _y ) )
                this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        }
        _result = true;
    }
    return _result;
}

bool Player::MoveLeft()
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _x != 0 &&
            ( ( this->GetIdentity() == _player_ && this->war->_map->Get_Point ( _x - 1, _y )->GetPower() != _player ) ||
              ( this->GetIdentity() == _ai_ && this->war->_map->Get_Point ( _x - 1, _y )->GetPower() != _ai ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x - 1, _y, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x - 1, _y, true ) == 'X' )
                    this->AttackBase ( _x - 1, _y );
                else
                    this->AttackSoldier ( _x - 1, _y );
            }
            else if ( this->war->_map->GetChar ( _x - 1, _y, false ) == '+' &&
                      this->war->_map->GetChar ( _x - 1, _y, true ) == 'X' )
            {
                _isattack = true;
                this->AttackCity ( _x - 1, _y );
            }
            else
                this->war->_map->DrawToMap ( '*', _x - 1, _y, false );
        }
        else
        {
            if ( this->war->_map->GetChar ( _x - 1, _y, false ) == '*' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x - 1, _y, true ) == '*' )
                    this->AttackBase ( _x - 1, _y );
                else
                    this->AttackSoldier ( _x - 1, _y );
            }
            else if ( this->war->_map->GetChar ( _x - 1, _y, false ) == '+' &&
                      this->war->_map->GetChar ( _x - 1, _y, true ) == '*' )
            {
                _isattack = true;
                this->AttackCity ( _x - 1, _y );
            }
            else
                this->war->_map->DrawToMap ( 'X', _x - 1, _y, false );
        }
        if ( !_isattack )
        {
            this->war->soldier_selecter->UpdateX ( - 1 );
            this->war->_map->AddSoldierToPoint ( _x - 1, _y, *this->war->soldier_selecter );
            this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
            if ( this->war->_map->IsEmptyCity ( _x, _y ) )
                this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        }
        _result = true;
    }
    return _result;
}
bool Player::MoveRight()
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( ( _x !=  this->war->_map->GetRWidth() - 1 ) &&
            ( ( this->GetIdentity() == _player_ && this->war->_map->Get_Point ( _x + 1, _y )->GetPower() != _player ) ||
              ( this->GetIdentity() == _ai_ && this->war->_map->Get_Point ( _x + 1, _y )->GetPower() != _ai ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x + 1, _y, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x + 1, _y, true ) == 'X' )
                    this->AttackBase ( _x + 1, _y );
                else
                    this->AttackSoldier ( _x + 1, _y );
            }
            else if ( this->war->_map->GetChar ( _x + 1, _y, false ) == '+' &&
                      this->war->_map->GetChar ( _x + 1, _y, true ) == 'X' )
            {
                _isattack = true;
                this->AttackCity ( _x + 1, _y );
            }
            else
                this->war->_map->DrawToMap ( '*', _x + 1, _y, false );
        }
        else
        {
            if ( this->war->_map->GetChar ( _x + 1, _y, false ) == '*' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x + 1, _y, true ) == '*' )
                    this->AttackBase ( _x + 1, _y );
                else
                    this->AttackSoldier ( _x + 1, _y );
            }
            else if ( this->war->_map->GetChar ( _x + 1, _y, false ) == '+' &&
                      this->war->_map->GetChar ( _x + 1, _y, true ) == '*' )
            {
                _isattack = true;
                this->AttackCity ( _x + 1, _y );
            }
            else
                this->war->_map->DrawToMap ( 'X', _x + 1, _y, false );
        }
        if ( !_isattack )
        {
            this->war->soldier_selecter->UpdateX ( 1 );
            this->war->_map->AddSoldierToPoint ( _x + 1, _y, *this->war->soldier_selecter );
            this->war->_map->RemoveSoldierFromPoint ( _x, _y, this->war->soldier_selecter->GetID() );
            if ( this->war->_map->IsEmptyCity ( _x, _y ) )
                this->war->_map->DrawToMap ( this->war->_map->WhosCity ( _x, _y ), _x, _y, false );
        }
        _result = true;
    }
    return _result;
}
enum Is_Win Player::_Result()
{
    int player_x, player_y;
    int ai_x, ai_y;
    player_x = GetPlayerBaseX();
    player_y = GetPlayerBaseY();
    ai_x = GetAIBaseX();
    ai_y = GetAIBaseY();
    if ( this->war->_map->Get_Point ( player_x, player_y )->GetLife() <= 0 )
        return _lose;
    else if ( this->war->_map->Get_Point ( ai_x, ai_y )->GetLife() <= 0 )
        return _win;
    else
        return _draw;
}
bool Player::CheckWin( )
{
    bool _result = false;
    enum Is_Win win_result;
    win_result = this->_Result( );
    if ( win_result != _draw )
    {
        if ( win_result == _win )
        {
            cout << endl << "[*]��ϲ��Ӯ�����ⳡս����������������" << endl;
            this->prestige *= 1.2;
            this->bitcoin *= 1.2;
            this->violence *= 1.2;
            this->second *= 1.2;
        }
        else if ( win_result == _lose )
        {
            cout << endl << "[*]��Ǹ��������ⳡս�����������Լ���" << endl;
            this->prestige *= 0.2;
            this->bitcoin *= 0.2;
            this->violence *= 0.2;
            this->second *= 0.2;
        }
        this->End_War ( this -> war -> _map );
        _result = true;
    }
    return _result;
}
