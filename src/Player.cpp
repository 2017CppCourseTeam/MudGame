#include "Game.h"
Player::Player()
{
    this->prestige = 50.0;
    this->bitcoin = 10.0;
    this->violence = 50.0;
    this->second = 10;
    this->war_num = 0;
    this->name = "";
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

void Player::Train_Coder()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_BLUE );
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
    if ( rand() / double ( RAND_MAX ) <= 0.8 )
    {
        this->violence += 3;
        this->second += 1;
        cout << "|   恭喜你，训练成功。                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          暴力值+3，+1s    |" << endl;
    }
    else
    {
        this->violence -= 5;
        this->second -= 1;
        cout << "|   很遗憾，训练失败。                      |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          暴力值-5，-1s    |" << endl;
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
        cout << "|   好NB，本次挖出2个比特币！              |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          比特币+2，+1s   |" << endl;
    }
    else
    {
        this->bitcoin += 0.5;
        this->second += 1;
        cout << "|   恭喜你，本次挖出0.5个比特币！           |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                          比特币+0.5，+1s  |" << endl;
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
        cout << "|                            威望+3， +1s  |" << endl;
    }
    else
    {
        this->prestige -= 5;
        this->second -= 1;
        cout << "|   很遗憾，训练失败                        |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                            威望-5， -1s   |" << endl;
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
    cout << "|  发生突发事件：比特币矿难                 |" << endl;
    cout << "|                            比特币-1，-1s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::Brain_Unwashed()
{
    this->second -= 2;
    this->prestige -= 5;
    cout << " ------------------------------------------- " << endl;
    cout << "|  发生突发事件：码农思想僵化               |" << endl;
    cout << "|                              威望-5，-2s  |" << endl;
    cout << "|                                           |" << endl;
}

void Player::AI_Rebel()
{
    this->violence += 5;
    this->prestige += 5;
    cout << " ------------------------------------------- " << endl;
    cout << "|  发生突发事件：人工智能被感化             |" << endl;
    cout << "|                         威望+5，暴力值+5  |" << endl;
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
    delete _map;
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


void Player::Create_Soldier ( enum AllSoldiers soldier, unsigned int x, unsigned int y )
{
    this->war->_Create_Soldier ( soldier, x, y );
}


void Player::Delete_Soldier ( unsigned int _id )
{
    this->war->_Delete_Soldier ( _id );
}

War* Player::GetCurrentWar() {
    return war;
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

AI::AI() {
    this->ifFirst = true;
    act_num = 1;
    war_num = 1;
    intellegence = 0;
    wealth = 0;
    strength = 0;
    coldness = 0;
}

void AI::Init_Order(bool ifFirst) {
    this->ifFirst = ifFirst;
}

void AI::action() {
    int manipulator = act_num % 8;
    cout << "no." << act_num << " action" << endl;
    if(war_num == 1) {
    if(act_num <= 40)
    switch(manipulator) {
        case 1:
            if(act_num == 1)
                this->Create_Soldier(_Worker, 7, 8);
            else
                this->Create_Soldier(_Archer, 7, 8);
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            if(act_num == 8)    //bulid
            break;
            }
            else if (act_num > 40 && act_num <= 80)
            switch(manipulator){
        case 1:
            this->Select_Soldier ((act_num - 40) / 8);
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
            }
        }


    if(war_num == 2) {
    if(act_num <= 56)
    switch(manipulator) {
        case 1:
            if(act_num == 1)
                {this->Create_Soldier(_Worker, 7, 8);}
            else if(act_num == 9 && act_num == 17 && act_num == 25)
                {this->Create_Soldier(_Slime, 7, 8);}
            else
                {this->Create_Soldier(_Goblin, 7, 8);}
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            if(act_num == 8)    //bulid
            break;
            }
            else if (act_num > 56 && act_num <= 112)
            switch(manipulator){
        case 1:
            this->Select_Soldier ((act_num - 56) / 8);
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
            }
        }

    if(war_num == 3) {
    if(act_num <= 72)
    switch(manipulator) {
        case 1:
            if(act_num == 1)
                {this->Create_Soldier(_Worker, 7, 8);}
            if(act_num == 9 || act_num == 17 || act_num == 25 || act_num == 33)
                {this->Create_Soldier(_SwordsMan, 7, 8);}
            if(act_num == 57|| act_num == 41 || act_num == 49 || act_num == 65)
                {this->Create_Soldier(_Dragon, 7, 8);}
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            if(act_num == 8)    //bulid
            break;
            }
            else if (act_num > 72 && act_num <= 144) {
            int soldier_num = (act_num - 72) / 8;
        switch(manipulator){
        case 1:
            this->Select_Soldier(soldier_num);
            if(soldier_num == 1 && soldier_num == 2 && soldier_num == 3 && soldier_num == 4) {
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
        case 2:
        case 3:
        case 4:
            this->Select_Soldier(soldier_num);
            if(soldier_num == 1 && soldier_num == 2 && soldier_num == 3 && soldier_num == 4) {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->Select_Soldier(soldier_num);
            if(soldier_num == 1 && soldier_num == 2 && soldier_num == 3 && soldier_num == 4) {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
            }
        }
    }


    if(war_num == 4) {
    if(act_num <= 104)
    switch(manipulator) {
        case 1:
            if(act_num == 1)
                {this->Create_Soldier(_Worker, 7, 8);}
            if(act_num == 9 || act_num == 17 || act_num == 25 || act_num == 33 || act_num == 41 || act_num == 49 || act_num == 57)
                {this->Create_Soldier(_SiegCar, 7, 8);}
            if(act_num == 65 || act_num == 73 || act_num == 81 || act_num == 89)
                {this->Create_Soldier(_Naga, 7, 8);}
            if(act_num == 97)
                {this->Create_Soldier(_IceGiant, 7, 8);}
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            if(act_num == 8)    //bulid
            break;
            }
            else if (act_num > 104 && act_num <= 208) {
        int soldier_num = (act_num - 104) / 8;
        switch(manipulator){
        case 1:
            this->Select_Soldier(soldier_num);
            if(soldier_num >= 1 && soldier_num <= 7) {
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
        case 2:
        case 3:
        case 4:
            this->Select_Soldier(soldier_num);
            if(soldier_num >= 1 && soldier_num <= 7) {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->Select_Soldier(soldier_num);
            if(soldier_num >= 1 && soldier_num <= 7) {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
            }
        }
    }


    if(war_num == 5) {
        if(act_num == 1) {
            this->Create_Soldier(_Naga, 8, 6);
            this->Create_Soldier(_Naga, 7, 7);
            this->Create_Soldier(_Naga, 6, 8);
        cout << "蛤蛤蛤，三个蛙人部署完毕。" << endl;
        }
        int manipulator = act_num % 8;
    if(act_num <= 176) {
        switch(manipulator){
        case 1:
            if(act_num >= 1)
                {this->Create_Soldier(_Worker, 7, 8);}
            if(act_num >= 9 && act_num <= 73)
                {this->Create_Soldier(_Dragon, 7, 8);}
            if(act_num >= 81 && act_num <= 105)
                {this->Create_Soldier(_IceGiant, 7, 8);}
            if(act_num >= 113 && act_num <= 137)
                {this->Create_Soldier(_FlameBirds, 7, 8);}
            if(act_num >= 145 && act_num <= 169)
                {this->Create_Soldier(_Phoenix, 7, 8);}
            break;
        case 2:
        case 3:
        case 4:
            this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
            this->GetCurrentWar()->_Show_Soldier_Status ( );
            if(act_num == 8)    //bulid
            break;
            }
        }
        else if (act_num > 176 && act_num <= 332) {

        int soldier_num = (act_num - 176) / 8;
        if(soldier_num % 3 == 1) {
            if(manipulator == 1) this->Select_Soldier(soldier_num);
            if(manipulator % 2 == 0) {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
        }
        else {
        int soldier_num = (act_num - 176) / 8;
        switch(manipulator) {
        case 1:
            this->Select_Soldier(soldier_num);
            if(soldier_num % 3 == 0) {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
        case 2:
        case 3:
        case 4:
            this->Select_Soldier(soldier_num);
            if(soldier_num % 3 == 0) {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
        case 5:
        case 6:
        case 7:
        case 0:
            this->Select_Soldier(soldier_num);
            if(soldier_num >= 1 && soldier_num <= 7) {
                this->GetCurrentWar()->soldier_selecter->UpdateX(this->GetCurrentWar()->soldier_selecter->GetX()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            else {
                this->GetCurrentWar()->soldier_selecter->UpdateY(this->GetCurrentWar()->soldier_selecter->GetY()-1);
                this->GetCurrentWar()->_Show_Soldier_Status ( );
            }
            break;
            }
            }
        }
      }
    act_num++;
}

int AI::getAct_num() {
    return this->act_num;
}

void AI::AI_Init(int prestige,int violence, int bitcoin, int war_num) {
    this->intellegence = prestige * 5;
    this->strength = violence * 3;
    this->wealth = bitcoin;
    this->coldness = sqrt((10-war_num)*0.03) + prestige * 0.05 + violence + 0.05 ;
}

bool AI::getIfFirst() {
    return ifFirst;
}


