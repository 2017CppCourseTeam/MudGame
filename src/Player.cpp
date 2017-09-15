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

string Player::GetName()
{
    return this->name;
}

void Player::SetName ( string name )
{
    this->name = name;
}

void Player::RestartWar()
{
    this->war_num = 0;
}

void Player::ShowStatus()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_INTENSITY | BACKGROUND_INTENSITY | BACKGROUND_GREEN | FOREGROUND_RED ); //设置为红色
    cout << " ---------------------- " << endl;
    cout << "|属性值：              |" << endl;
    cout << "|                      |" << endl;
    cout << "|   威望：" << setw ( 10 ) << this->prestige << "   |" << endl;
    cout << "|   比特币：" << setw ( 8 ) << this->bitcoin << "   |" << endl;
    cout << "|   暴力值：" << setw ( 8 ) << this->violence << "   |" << endl;
    cout << "|                      |" << endl;
    cout << "|                " << setw ( 3 ) << this->second << "s  |" << endl;
    cout << " ---------------------- " << endl;
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    return;
}

void Player::TrainCoder()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
    cout << "+-------------------------------------------+" << endl;
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
    if ( rand() / double ( RAND_MAX ) <= 0.8 )
    {
        this->violence += 3;
        this->second += 1;
        cout << "|   恭喜你，训练成功。                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          暴力值+3，+1s    |" << endl;
        PlaySound ( ".\\BGM\\+1s.wav", NULL, SND_FILENAME | SND_SYNC );
    }
    else
    {
        this->violence -= 5;
        this->second -= 1;
        cout << "|   很遗憾，训练失败。                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          暴力值-5，-1s    |" << endl;
        PlaySound ( ".\\BGM\\8848.wav", NULL, SND_FILENAME | SND_SYNC );
    }
    Player::RandomEvent();
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    PlaySound ( ".\\BGM\\StayinAlive.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    return;
}
void Player::DigMine()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
    cout << "+-------------------------------------------+" << endl;
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
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.15 )
    {
        this->bitcoin += 2;
        this->second += 1;
        cout << "|   好NB，本次挖出2个比特币！               |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          比特币+2，+1s    |" << endl;
        PlaySound ( ".\\BGM\\8488.wav", NULL, SND_FILENAME | SND_SYNC );
    }
    else
    {
        this->bitcoin += 0.5;
        this->second += 1;
        cout << "|   恭喜你，本次挖出0.5个比特币！           |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          比特币+0.5，+1s  |" << endl;
        PlaySound ( ".\\BGM\\bitcoin.wav", NULL, SND_FILENAME | SND_SYNC );
    }
    Player::RandomEvent();
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    PlaySound ( ".\\BGM\\StayinAlive.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    return;
}
void Player::WashBrain()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
    cout << "+-------------------------------------------+" << endl;
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
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.8 )
    {
        this->prestige += 3;
        this->second += 1;
        cout << "|   恭喜您，训练成功                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            威望+3， +1s   |" << endl;
        PlaySound ( ".\\BGM\\brainwash.wav", NULL, SND_FILENAME | SND_SYNC );
    }
    else
    {
        this->prestige -= 5;
        this->second -= 1;
        cout << "|   很遗憾，训练失败                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            威望-5， -1s   |" << endl;
        PlaySound ( ".\\BGM\\8848.wav", NULL, SND_FILENAME | SND_SYNC );
    }
    Player::RandomEvent();
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    PlaySound ( ".\\BGM\\StayinAlive.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
    return;
}

void Player::RandomEvent()
{
    cout << "|                                           |" << endl;
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.13 )
        MineCrash();
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.13 )
        BrainUnwashed();
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.10 )
        AIRebel();
    cout << "+-------------------------------------------+" << endl;
}

void Player::MineCrash()
{
    this->second -= 1;
    this->bitcoin -= 1;
    cout << "+-------------------------------------------+" << endl;
    cout << "|  发生突发事件：比特币矿难                 |" << endl;
    cout << "|                            比特币-1，-1s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::BrainUnwashed()
{
    this->second -= 2;
    this->prestige -= 5;
    cout << "+-------------------------------------------+" << endl;
    cout << "|  发生突发事件：码农思想僵化               |" << endl;
    cout << "|                              威望-5，-2s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::AIRebel()
{
    this->violence += 5;
    this->prestige += 5;
    cout << " ------------------------------------------- " << endl;
    cout << "|  发生突发事件：人工智能被感化             |" << endl;
    cout << "|                         威望+5，暴力值+5  |" << endl;
    cout << "|                                           |" << endl;
}

double Player::GetBitcoin()
{
    return this->bitcoin;
}

double Player::GetPrestige()
{
    return this->prestige;
}

double Player::GetViolence()
{
    return this->violence;
}

int Player::GetSecond()
{
    return this->second;
}

unsigned short Player::GetWarNum()
{
    return this->war_num + 1;
}

bool Player::CheckWin()
{
    if ( this->war_num == 6 )
        return true;
    else
        return false;
}

bool Player::CheckLose()
{
    if ( this->second <= 0 )
        return true;
    else
        return false;
}


void Player::StartWar ( Map*& _map )
{
    this->war = new War ( this->prestige,
                          this->bitcoin,
                          this->violence,
                          this->second,
                          this->war_num,
                          _map );
}

void Player::EndWar ( Map*& _map )
{
    delete this->war;
    //delete _map;
}

void Player::ShowWarStatus()
{
    this->war->_ShowStatus();
}

void Player::ShowMap ( bool show_detail )
{
    this->war->_ShowMap ( show_detail );
}

void Player::First()
{
    if ( ( rand() / double ( RAND_MAX ) ) <= 0.5 )
        this->war_first = true;
    else
        this->war_first = false;
}

bool Player::IsFirst()
{
    return this->war_first;
}

bool Player::SelectPoint ( unsigned int _x, unsigned int _y )
{
    return this->war->_SelectPoint ( _x, _y );
}

void Player::ShowPonitStatus()
{
    this->war->_ShowPointStatus();
}

bool Player::SelectSoldier ( unsigned int id )
{
    return this->war->_SelectSoldier ( id );
}

void Player::ShowSoldierStatus ( unsigned int id )
{
    this->war->_ShowSoldierStatus ( id );
}

void Player::ShowSoldierStatus()
{
    this->war->_ShowSoldierStatus();
}

bool Player::CreateSoldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y )
{
    bool _result = this->war->_CreateSoldier ( soldier, power, x, y, &this->war->life, &this->war->magic, &this->war->coin );
    if ( _result )
    {
        cout << endl << "[*]生产成功" << endl;
        this->war->_ShowSoldierStatus ( this->war->_id++ );
    }
    else
        cout << endl << "[!]生产失败，资源不足" << endl;
    return _result;
}

void Player::DeleteSoldier ( unsigned int _id )
{
    this->war->_DeleteSoldier ( _id );
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

void Player::AIInit ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first )
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
    int manipulator = this->act_num % 4;
    //int times = this->act_num / 32 + 1;
    cout << endl << "[*]NO." << this->act_num << " action" << endl;
    if ( this->GetWarNum() == 1 )
    {
        if ( this->act_num % 32 > 0 && this->act_num % 32 <= 16 )
        {
            switch ( manipulator )
            {
                case 1:
                {
                    if ( this->act_num % 32 == 1 )
                    {
                        this->CreateSoldier ( _Worker, ai_city, 3, 4 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    else
                    {
                        this->CreateSoldier ( _Archer, ai_city, 3, 4 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    break;
                }
                case 2:
                {
                    this->MoveLeft();
                    break;
                }
                case 3:
                case 0:
                {
                    this->MoveUp();
                    if ( this->act_num % 32 == 4 )
                        this->BuildCity();
                    break;
                }
            }
        }
        else if ( this->act_num % 32 > 16 || this->act_num % 32 == 0 )
        {
            switch ( manipulator )
            {
                case 1:
                {
                    this->SelectSoldier ( ( this->act_num % 32 - 16 ) / 4 );
                    this->MoveUp();
                    break;
                }
                case 2:
                {
                    this->MoveUp();
                    break;
                }
                case 3:
                case 0:
                {
                    this->MoveLeft();
                    break;
                }
            }
        }
    }
    if ( this->GetWarNum() == 2 )
    {
        if ( this->act_num % 72 > 0 && this->act_num % 72 <= 36 )
        {
            manipulator = act_num % 6;
            switch ( manipulator )
            {
                case 1:
                {
                    if ( this->act_num % 72 == 1 )
                    {
                        this->CreateSoldier ( _Worker, ai_city, 5, 6 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    else if ( this->act_num % 72 >= 7 && this->act_num % 72 <= 19 )
                    {
                        this->CreateSoldier ( _Slime, ai_city, 5, 6 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    else
                    {
                        this->CreateSoldier ( _Goblin, ai_city, 5, 6 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    break;
                }
                case 2:
                case 3:
                case 4:
                {
                    this->MoveUp();
                    if ( act_num == 4 ) this->BuildCity();
                    break;
                }
                case 5:
                case 0:
                {
                    this->MoveLeft();
                    if ( this->act_num == 6 )
                        this->BuildCity();
                    break;
                }
            }
        }
        else if ( this->act_num % 72 > 36 )
            switch ( manipulator )
            {
                case 1:
                {
                    this->SelectSoldier ( ( this->act_num - 36 ) / 8 );
                    this->MoveLeft();
                    break;
                }
                case 2:
                {
                    this->MoveLeft();
                    break;
                }
                case 3:
                case 4:
                case 5:
                {
                    this->MoveUp();
                    break;
                }
                case 0:
                {
                    this->MoveLeft();
                    break;
                }
            }
    }
    if ( this->GetWarNum() == 3 )
    {
        manipulator = act_num % 8;
        if ( this->act_num % 144 > 0 && this->act_num % 144 <= 72 )
            switch ( manipulator )
            {
                case 1:
                {
                    if ( this->act_num % 144 == 1 )
                    {
                        this->CreateSoldier ( _Worker, ai_city, 7, 8 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    if ( this->act_num % 144 >= 9 && this->act_num % 144 <= 33 )
                    {
                        this->CreateSoldier ( _SwordsMan, ai_city, 7, 8 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    if ( this->act_num % 144 >= 41 && this->act_num % 144 <= 65 )
                    {
                        this->CreateSoldier ( _Dragon, ai_city, 7, 8 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    break;
                }
                case 2:
                case 3:
                {
                    this->MoveUp();
                    break;
                }
                case 4:
                case 5:
                {
                    this->MoveLeft();
                    if ( act_num == 4 )    this->BuildCity();
                    break;
                }
                case 6:
                case 7:
                {
                    this->MoveUp();
                    break;
                }
                case 0:
                {
                    this->MoveLeft();
                    if ( this->act_num == 8 )
                        this->BuildCity();
                    break;
                }
            }
        else if ( this->act_num % 144 > 72 )
        {
            int soldier_num = ( this->act_num % 144 - 72 ) / 8;
            //int flag = act_num % 2;
            switch ( manipulator )
            {
                case 1:
                {
                    this->SelectSoldier ( soldier_num );
                    if ( soldier_num == 1 || soldier_num == 2 || soldier_num == 3 || soldier_num == 0 )
                        this->MoveUp();
                    else
                        this->MoveLeft();
                    break;
                }
                case 2:
                case 3:
                case 4:
                {
                    if ( soldier_num == 1 || soldier_num == 2 || soldier_num == 3 || soldier_num == 0 )
                        this->MoveUp();
                    else
                        this->MoveLeft();
                    break;
                }
                case 5:
                case 6:
                case 7:
                case 0:
                {
                    if ( soldier_num == 1 || soldier_num == 2 || soldier_num == 3 || soldier_num == 0 )
                        this->MoveLeft();
                    else
                        this->MoveUp();
                    break;
                }
            }
        }
    }
    if ( this->GetWarNum() == 4 )
    {
        if ( this->act_num % 260 > 0 && this->act_num % 260 <= 130 )
            switch ( manipulator )
            {
                case 1:
                {
                    if ( this->act_num % 260 == 1 )
                    {
                        this->CreateSoldier ( _Worker, ai_city, 9, 10 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    if ( this->act_num % 260 >= 11 && this->act_num % 260 <= 71 )
                    {
                        this->CreateSoldier ( _SiegCar, ai_city, 9, 10 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    if ( this->act_num % 260 >= 81 && this->act_num % 260 <=  111 )
                    {
                        this->CreateSoldier ( _Naga, ai_city, 9, 10 );
                        this->SelectSoldier ( this->war->_id - 1 );
                    }
                    if ( this->act_num % 260 == 121 )
                    {
                        this->CreateSoldier ( _IceGiant, ai_city, 9, 10 );
                        this->SelectSoldier ( this->war->_id - 1 );
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
                {
                    this->MoveLeft();
                    if ( act_num == 6 )
                        this->BuildCity();
                    break;
                }
                case 7:
                case 8:
                {
                    this->MoveUp();
                    break;
                }
                case 9:
                case 0:
                {
                    this->MoveLeft();
                    if ( act_num == 10 )
                        this->BuildCity();
                    break;
                }
            }
        else if ( this->act_num % 260 > 130 )
        {
            int soldier_num = ( this->act_num - 130 ) / 10;
            switch ( manipulator )
            {
                case 1:
                {
                    this->SelectSoldier ( soldier_num );
                    if ( soldier_num % 2 == 1 )
                        this->MoveUp();
                    else
                        this->MoveLeft();
                    break;
                }
                case 2:
                {
                    if ( soldier_num % 2 == 1 )
                        this->MoveUp();
                    else
                        this->MoveLeft();
                    break;
                }
                case 3:
                case 4:
                {
                    if ( soldier_num % 2 == 1 )
                        this->MoveLeft();
                    else
                        this->MoveUp();
                    if ( act_num == 134 )  this->BuildCity();
                    break;
                }
                case 5:
                case 6:
                case 7:
                {
                    if ( soldier_num % 2 == 1 )
                        this->MoveLeft();
                    else
                        this->MoveUp();
                }
                case 8:
                case 9:
                case 0:
                {
                    if ( soldier_num % 2 == 1 )
                        this->MoveUp();
                    else
                        this->MoveLeft();
                }
            }
        }
    }
    if ( this->GetWarNum() == 5 )
    {
        int round_num = act_num / 28 + 1;
        int base_num = act_num % 4;
        int manipulator = act_num % 28;
        if ( this->act_num == 1 )
        {
            for ( int i = 0 ; i < 5; i++ )
            {
                this->CreateSoldier ( _Naga, ai_city, 6, 1 );
                this->CreateSoldier ( _Naga, ai_city, 6, 5 );
                this->CreateSoldier ( _Naga, ai_city, 6, 9 );
            }
            cout << "蛤蛤蛤*5，15个蛙人部署完毕。" << endl;
            for ( int i = 15; i <= 17; i++ )
                for ( int j = 1; j <= 3 ; j++ )
                {
                    this->CreateSoldier ( _FlameBirds, ai_city, i, 3 );
                    this->CreateSoldier ( _FlameBirds, ai_city, i, 7 );
                }
            for ( int i = 4; i <= 6; i++ )
                for ( int j = 1; j <= 3 ; j++ )
                    this->CreateSoldier ( _FlameBirds, ai_city, 15, i );
        }
        if ( manipulator >= 1 && manipulator <= 4 )
        {
            if ( round_num == 1 )
                this->CreateSoldier ( _Dragon, ai_city, 7, manipulator * 2 );
            if ( round_num == 2 )
                this->CreateSoldier ( _IceGiant, ai_city, 7, manipulator * 2 );
            if ( round_num == 3 )
                this->CreateSoldier ( _Phoenix, ai_city, 7, manipulator * 2 );
            this->SelectSoldier ( this->war->_id - 1 );
        }
        if ( manipulator >= 5 )
        {
            switch ( base_num )
            {
                case 1:
                    this->SelectSoldier ( this->war->_id - 4 );
                    break;
                case 2:
                    this->SelectSoldier ( this->war->_id - 3 );
                    break;
                case 3:
                    this->SelectSoldier ( this->war->_id - 2 );
                    break;
                case 0:
                    this->SelectSoldier ( this->war->_id - 1 );
                    break;
            }
            this->MoveLeft();
        }
    }
    this->act_num++;
}

void Player::SetWarNum ( unsigned int num )
{
    this->war_num = num;
}


int Player::GetActNum()
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
    unsigned int rlife = this->war->recover_life * this->war->occupied_city;
    unsigned int rmagic = this->war->recover_magic * this->war->occupied_city;
    unsigned int rcoin = this->war->recover_coin * this->war->occupied_city;
    cout << endl << "[*]";
    if ( this->GetIdentity() == _player_ )
        cout << "玩家";
    else
        cout << "AI";
    cout << "恢复 " << rlife << " 点生命源, " << rmagic << " 点魔法源, " << rcoin << " 点金钱" << endl;
    this->war->_UpdateLife ( rlife );
    this->war->_UpdateMagic ( rmagic );
    this->war->_UpdateCoin ( rcoin );
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
    if ( ( rand() / RAND_MAX ) < this->war->_GetLucky() )
        _result = true;
    return _result;
}

void Player::AttackBase ( unsigned int _x, unsigned int _y )
{
    cout << endl << "[*]";
    if ( this->GetIdentity() == _player_ )
        cout << "AI";
    else
        cout << "玩家";
    cout << "基地遭受攻击" << endl;
    double _hurt = this->war->soldier_selecter->GetAttack();
    cout << "[*]受到 " << _hurt << " 点伤害" << endl;
    this->war->_map->GetPoint ( _x, _y )->UpdateLife ( -_hurt );
    cout << "[*]当前剩余生命值为 " << this->war->_map->GetPoint ( _x, _y )->GetLife() << endl ;
}

void Player::AttackSoldier ( unsigned int _x, unsigned int _y, enum Direct _direct, bool _cattack )
{
    cout << endl << "[*]";
    if ( ( this->GetIdentity() == _player_ && !_cattack ) || ( this->GetIdentity() == _ai_ && _cattack ) )
        cout << "玩家";
    else if ( ( this->GetIdentity() == _ai_ && !_cattack ) || ( this->GetIdentity() == _player_ && _cattack ) )
        cout << "AI";
    cout << "士兵遭遇攻击" << endl;
    unsigned int _pid = this->war->_map->GetPoint ( _x, _y )->GetCurrentSoldierNum() - 1;
    double _hurt = this->war->soldier_selecter->GetAttack() - this->GetSoldierFromPoint ( _x, _y, _pid )->GetDefence();
    if ( _hurt > 0 )
    {
        unsigned int _id = this->GetSoldierFromPoint ( _x, _y, _pid )->GetID();
        cout << "[*]ID为 " << _id << " 的";
        if ( ( this->GetIdentity() == _player_ && !_cattack ) || ( this->GetIdentity() == _ai_ && _cattack ) )
            cout << "玩家";
        else if ( ( this->GetIdentity() == _ai_ && !_cattack ) || ( this->GetIdentity() == _player_ && _cattack ) )
            cout << "AI";
        cout << "士兵受到 " << _hurt << " 点伤害" << endl;
        this->GetSoldierFromPoint ( _x, _y, _pid )->UpdateLife ( _hurt );
        if ( this->GetSoldierFromPoint ( _x, _y, _pid )->GetLife() <= 0 )
            this->DeleteSoldier ( _id );
        else if ( this->IsCounterAttack() && _cattack )
        {
            cout << endl << "[*]";
            if ( this->GetIdentity() == _player_ )
                cout << "AI";
            else
                cout << "玩家";
            cout << "士兵发起反击" << endl;
            switch ( _direct )
            {
                case _up:
                {
                    this->AttackSoldier ( _x, _y + 1, _down, false );
                    break;
                }
                case _down:
                {
                    this->AttackSoldier ( _x, _y - 1, _up, false );
                    break;
                }
                case _left:
                {
                    this->AttackSoldier ( _x + 1, _y, _right, false );
                    break;
                }
                case _right:
                {
                    this->AttackSoldier ( _x + 1, _y, _left, false );
                    break;
                }
            }
        }
    }
    else
        cout << "[*]攻击力不足，未能击穿敌人的装甲" << endl;
}

void Player::AttackCity ( unsigned int _x, unsigned int _y )
{
    cout << endl << "[*]";
    if ( this->GetIdentity() == _player_ )
        cout << "AI";
    else
        cout << "玩家";
    cout << "城市遭遇攻击" << endl;
    double _hurt = this->war->soldier_selecter->GetAttack();
    if ( this->war->_map->GetPoint ( _x, _y )->GetLife() > 0 )
    {
        cout << "[*]该城市受到 " << _hurt << " 点伤害" << endl;
        this->war->_map->GetPoint ( _x, _y )->UpdateLife ( -_hurt );
    }
    else
    {
        cout << "[*]该城市已被摧毁，城市中的士兵全部死亡" << endl;
        while ( true )
        {
            unsigned int _pid = this->war->_map->GetPoint ( _x, _y )->GetCurrentSoldierNum() - 1;
            if ( _pid < 0 )
                break;
            unsigned int _id = this->GetSoldierFromPoint ( _x, _y, _pid )->GetID();
            this->DeleteSoldier ( _id );
        }
    }
}


bool Player::MoveUp( )
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _y != 0 && ( ( this->GetIdentity() == _player_ &&  this->war->_map->GetPoint ( _x, _y - 1 )->GetPower() != _player ) || ( this->GetIdentity() == _ai_ && this->war->_map->GetPoint ( _x, _y - 1 )->GetPower() != _ai ) || ( this->war->soldier_selecter->GetSoldierName() == _Worker  && this->war->_map->GetPoint ( _x, _y - 1 )->GetPower() == empty_city ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x, _y - 1, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x, _y - 1, true ) == 'X' )
                {
                    if ( this->war->_map->GetPoint ( _x, _y - 1 )->GetPower() == ai_city )
                        this->AttackCity ( _x, _y - 1 );
                    else
                        this->AttackBase ( _x, _y - 1 );
                }
                else
                    this->AttackSoldier ( _x, _y - 1, _up );
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
                {
                    if ( this->war->_map->GetPoint ( _x, _y - 1 )->GetPower() == player_city )
                        this->AttackCity ( _x, _y - 1 );
                    else
                        this->AttackBase ( _x, _y - 1 );
                }
                else
                    this->AttackSoldier ( _x, _y - 1, _up );
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

bool Player::MoveDown( )
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( ( _y != this->war->_map->GetRHeight() - 1 ) && ( ( this->GetIdentity() == _player_ &&  this->war->_map->GetPoint ( _x, _y + 1 )->GetPower() != _player ) || ( this->GetIdentity() == _ai_ && this->war->_map->GetPoint ( _x, _y + 1 )->GetPower() != _ai ) || ( this->war->soldier_selecter->GetSoldierName() == _Worker  && this->war->_map->GetPoint ( _x, _y + 1 )->GetPower() == empty_city ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x, _y + 1, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x, _y + 1, true ) == 'X' )
                {
                    if ( this->war->_map->GetPoint ( _x, _y + 1 )->GetPower() == ai_city )
                        this->AttackCity ( _x, _y + 1 );
                    else
                        this->AttackBase ( _x, _y + 1 );
                }
                else
                    this->AttackSoldier ( _x, _y + 1, _down );
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
                {
                    if ( this->war->_map->GetPoint ( _x, _y + 1 )->GetPower() == player_city )
                        this->AttackCity ( _x, _y + 1 );
                    else
                        this->AttackBase ( _x, _y + 1 );
                }
                else
                    this->AttackSoldier ( _x, _y + 1, _down );
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

bool Player::MoveLeft( )
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( _x != 0 && ( ( this->GetIdentity() == _player_ &&  this->war->_map->GetPoint ( _x - 1, _y )->GetPower() != _player ) || ( this->GetIdentity() == _ai_ && this->war->_map->GetPoint ( _x - 1, _y )->GetPower() != _ai ) || ( this->war->soldier_selecter->GetSoldierName() == _Worker  && this->war->_map->GetPoint ( _x - 1, _y )->GetPower() == empty_city ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x - 1, _y, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x - 1, _y, true ) == 'X' )
                {
                    if ( this->war->_map->GetPoint ( _x - 1, _y )->GetPower() == ai_city )
                        this->AttackCity ( _x - 1, _y );
                    else
                        this->AttackBase ( _x - 1, _y );
                }
                else
                    this->AttackSoldier ( _x - 1, _y, _left );
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
                {
                    if ( this->war->_map->GetPoint ( _x - 1, _y )->GetPower() == player_city )
                        this->AttackCity ( _x - 1, _y );
                    else
                        this->AttackBase ( _x - 1, _y );
                }
                else
                    this->AttackSoldier ( _x - 1, _y, _left );
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
bool Player::MoveRight( )
{
    bool _result = false;
    unsigned int _y = this->war->soldier_selecter->GetY();
    unsigned int _x = this->war->soldier_selecter->GetX();
    if ( ( _x !=  this->war->_map->GetRWidth() - 1 ) && ( ( this->GetIdentity() == _player_ &&  this->war->_map->GetPoint ( _x + 1, _y )->GetPower() != _player ) || ( this->GetIdentity() == _ai_ && this->war->_map->GetPoint ( _x + 1, _y )->GetPower() != _ai ) || ( this->war->soldier_selecter->GetSoldierName() == _Worker  && this->war->_map->GetPoint ( _x + 1, _y )->GetPower() == empty_city ) ) )
    {
        bool _isattack = false;
        if ( this->GetIdentity() == _player_ )
        {
            if ( this->war->_map->GetChar ( _x + 1, _y, false ) == 'X' )
            {
                _isattack = true;
                if ( this->war->_map->GetChar ( _x + 1, _y, true ) == 'X' )
                {
                    if ( this->war->_map->GetPoint ( _x + 1, _y )->GetPower() == ai_city )
                        this->AttackCity ( _x + 1, _y );
                    else
                        this->AttackBase ( _x + 1, _y );
                }
                else
                    this->AttackSoldier ( _x + 1, _y, _right );
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
                {
                    if ( this->war->_map->GetPoint ( _x + 1, _y )->GetPower() == player_city )
                        this->AttackCity ( _x + 1, _y );
                    else
                        this->AttackBase ( _x + 1, _y );
                }
                else
                    this->AttackSoldier ( _x + 1, _y, _right );
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
    if ( this->war->_map->GetPoint ( player_x, player_y )->GetLife() <= 0 )
        return _lose;
    else if ( this->war->_map->GetPoint ( ai_x, ai_y )->GetLife() <= 0 )
        return _win;
    else
        return _draw;
}
bool Player::CheckWinOfWar( )
{
    bool _result = false;
    enum Is_Win win_result;
    win_result = this->_Result( );
    if ( win_result != _draw )
    {
        if ( win_result == _win )
        {
            cout << endl << "[*]恭喜你赢得了这场战争，所有属性增加" << endl;
            this->prestige *= 1.2;
            this->bitcoin *= 1.2;
            this->violence *= 1.2;
            this->second *= 1.2;
        }
        else if ( win_result == _lose )
        {
            cout << endl << "[*]抱歉你输掉了这场战争，所有属性减少" << endl;
            this->prestige *= 0.2;
            this->bitcoin *= 0.2;
            this->violence *= 0.2;
            this->second *= 0.2;
        }
        this->EndWar ( this -> war -> _map );
        _result = true;
    }
    return _result;
}
