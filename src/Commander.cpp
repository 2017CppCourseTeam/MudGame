#include "Commander.h"

Commander::Commander ( User*& user )
{
    this->status = _main;
    this->user = user;
}

enum STATUS Commander::Get_Status()
{
    return this->status;
}

template <class T>
T Commander::_ConvertStringToNum ( const string& str )
{
    istringstream iss ( str );
    T num;
    iss >> num;
    return num;
}

void Commander::_To_Lower ( string& s )
{
    transform ( s.begin(), s.end(), s.begin(), ::tolower );
}

void Commander::_Show_Manual()
{
    HANDLE handle;
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << endl;
    cout << "                                                                   " << endl;
    cout << "[*]游戏介绍:                                                       " << endl;
    cout << "这是一个关于养成类的战争游戏                                       " << endl;
    cout << "在这里，你需要通过训练提升自己的属性，攻克一个个战争，最后获取胜利 " << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "|  最开始，你拥有的属性值分别是：                 |" << endl;
    cout << "|    * 50点威望值（士气，能够影响战斗时的能力值） |" << endl;
    cout << "|    * 10个比特币（用于训练、发动战争）           |" << endl;
    cout << "|    * 50点暴力值（战斗的能力值）                 |" << endl;
    cout << "|    * 10秒的生命值（当生命值小于0则游戏失败）    |" << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "  你可以通过输入相应的命令，进行训练与战争    " << endl;
    cout << "  通过训练码农，提升暴力值                    " << endl;
    cout << "  通过挖矿，获得比特币                        " << endl;
    cout << "  通过政治洗脑，提升威望值                    " << endl;
    cout << "  通过发动战争，攻克各个关卡，获得最终的胜利！" << endl;
    cout << "                                              " << endl;
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_BLUE );
    cout << "按任意键继续" << endl;
    if ( getch() )
    {
        SetConsoleTextAttribute ( handle, FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
        cout << "+----------------------------------+" << endl;
        cout << "|[*]全局命令:                      |" << endl;
        cout << "|manual         获得详细游戏帮助   |" << endl;
        cout << "|help           获得当前界面帮助   |" << endl;
        cout << "|history        获得历史命令       |" << endl;
        cout << "|status         显示用户状态       |" << endl;
        cout << "|save           保存游戏           |" << endl;
        cout << "|current page   显示当前界面       |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]主界面命令:                    |" << endl;
        cout << "|war            开始战争           |" << endl;
        cout << "|practice       训练               |" << endl;
        cout << "|exit           退出游戏           |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]训练界面命令:                  |" << endl;
        cout << "|train coder    训练码农           |" << endl;
        cout << "|dig mine       挖矿               |" << endl;
        cout << "|wash brain     政治洗脑           |" << endl;
        cout << "|back           返回主界面         |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]战争初始界面命令:              |" << endl;
        cout << "|continue       继续战争           |" << endl;
        cout << "|restart        重新开始战争       |" << endl;
        cout << "|back           返回主界面         |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "|[*]战争界面命令:                      |" << endl;
        cout << "|show  status     获得战争属性         |" << endl;
        cout << "|      map        获得当前地图         |" << endl;
        cout << "|      all        获得属性与地图       |" << endl;
        cout << "|                                      |" << endl;
        cout << "|select build x,y   选择某一坐标的建筑 |" << endl;
        cout << "|       soldier n   选择ID为n的士兵    |" << endl;
        cout << "|                                      |" << endl;
        cout << "|move {up,down,left,right}  移动士兵   |" << endl;
        cout << "|                                      |" << endl;
        cout << "|build    （工人）占领并建造根据地     |" << endl;
        cout << "|                                      |" << endl;
        cout << "|produce TYPE 生产TYPE类型的士兵       |" << endl;
        cout << "|                                      |" << endl;
        cout << "|exit   退出战争                       |" << endl;
        cout << "+--------------------------------------+" << endl;
        SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    }
}

void Commander::_Current_Page()
{
    cout << endl << "[*]当前界面: ";
    switch ( this->status )
    {
        case _main:
            cout << "主界面" << endl;
            break;
        case practice:
            cout << "训练界面" << endl;
            break;
        case start_war:
        case war:
            cout << "战争界面" << endl;
            break;
    }
}

string Commander::_Decrypt ( string str )
{
    int c = str.length ( );
    string h = "";
    string o = "";
    for ( int i = 0; i < c; i++ )
    {
        if ( str [ i ] >= 'F' && str [ i ] <= '_' )
        {
            h = int ( str [ i ] ) + 27;
        }
        else if ( str [ i ] >= 'L' && str [ i ] <= 'e' )
        {
            h = int ( str [ i ] ) - 11;
        }
        else
        {
            h = int ( str [ i ] ) + 14;
        }
        o.append ( string ( h ) );
    }
    return o;
}

string Commander::_Read ( ifstream & f )
{
    string _tmp;
    getline ( f, _tmp );
    return this->_Decrypt ( _tmp );
}

bool Commander::LoadMap ( string name, unsigned short level )
{
    ifstream load;
    switch ( level )
    {
        case 1:
        {
            load.open (   ( string ( ".\\map\\" ) + name + string ( "1.dat" ) ).c_str(), ios::in );
            break;
        }
        case 2:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "2.dat" ) ).c_str() ), ios::in );
            break;
        }
        case 3:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "3.dat" ) ).c_str() ), ios::in );
            break;
        }
        case 4:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "4.dat" ) ).c_str() ), ios::in );
            break;
        }
        case 5:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "5.dat" ) ).c_str() ), ios::in );
            break;
        }
    }
    if ( !load ) return false;
    string _name = this->_Read ( load );
    string _level = this->_Read ( load );
    unsigned int _height = this->_ConvertStringToNum<unsigned int> ( this->_Read ( load ) );
    unsigned int _width = this->_ConvertStringToNum<unsigned int> ( this->_Read ( load ) );
    unsigned char** data;
    data = new unsigned char* [ _height ];
    for ( unsigned int i = 0; i < _height; i++ )
        data [ i ] = new unsigned char [ _width ];
    string _tmp;
    getline ( load, _tmp );
    for ( unsigned int i = 0, k = 0; i < _height; i++ )
    {
        for ( unsigned int j = 0; j < _width; j++ )
        {
            data[i][j] = _tmp[k++];
        }
    }
    this->_map = new Map ( _height, _width, _name, level, data );
    for ( unsigned int i = 0; i < _height; i++ )
        delete [ ]data [ i ];
    delete [ ]data;
    load.close();
    return true;
}

void Commander::_Show_History()
{
    cout << endl << "[*]历史命令: " << endl;
    for ( int i = this->history.size() - 1; i >= 0 ; i-- )
        cout << history[i] << endl;
}

bool Commander::Eval ( string& cmd )
{
    bool _result = false;
    _To_Lower ( cmd );
    this->history.insert ( history.begin(), cmd );
    // Global command
    if ( cmd == string ( "status" ) )
    {
        this->user->player->Show_Status();
        return true;
    }
    else if ( cmd == string ( "current page" ) )
    {
        this->_Current_Page();
        return true;
    }
    else if ( cmd == string ( "manual" ) )
    {
        this->_Show_Manual();
        return true;
    }
    else if ( cmd == string ( "history" ) )
    {
        this->_Show_History();
        return true;
    }
    else if ( cmd == string ( "save" ) )
    {
        if ( this->user->Save() )
            cout << endl << "[*]保存成功" << endl;
        return true;
    }
    // Main page
    if ( this->status == _main )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: " << endl;
            cout << "+-----------------+" << endl;
            cout << "|* 训练[practice] |" << endl;
            cout << "|* 战争[war]      |" << endl;
            cout << "|* 退出[exit]     |" << endl;
            cout << "+-----------------+" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            _result = true;
        }
        else if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]训练界面" << endl;
            _result = true;
        }
        else if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]战争界面" << endl;
            _result = true;
        }
        else if ( cmd == string ( "exit" ) )
        {
            this->status = quit;
            _result = true;
        }
        else
            _result = false;
    }
    // Practice page
    else if  ( this->status == practice )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: " << endl;
            cout << "+---------------------+" << endl;
            cout << "|* 训练[train coder]  |" << endl;
            cout << "|* 挖矿[dig mine]     |" << endl;
            cout << "|* 洗脑[wash brain]   |" << endl;
            cout << "|* 返回[back]         |" << endl;
            cout << "+---------------------+" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            _result = true;
        }
        else if ( cmd == string ( "train coder" ) )
        {
            this->user->player->Train_Coder();
            _result = true;
        }
        else if ( cmd == string ( "dig mine" ) )
        {
            this->user->player->Dig_Mine();
            _result = true;
        }
        else if ( cmd == string ( "wash brain" ) )
        {
            this->user->player->Wash_Brain();
            _result = true;
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]返回主界面" << endl;
            _result = true;
        }
        else
            _result = false;;
        if ( this->user->player->Get_Second() == 0 )
            this->status = lose;
    }
    // War page
    else if ( this->status == war )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: " << endl;
            cout << "+---------------------+" << endl;
            cout << "|* 重新开始[restart]  |" << endl;
            cout << "|* 继续[continue]     |" << endl;
            cout << "|* 返回[back]         |" << endl;
            cout << "+---------------------+" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            _result = true;
        }
        else if ( cmd == string ( "restart" ) )
        {
            string _choice;
            cout << endl << "[*]确定要重新开始吗？(y/n)";
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]重新开始战争" << endl;
                this->user->player->Restart_War();
            }
            _result = true;
        }
        else if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]继续战争" << endl;
            this->status = start_war;
            this->LoadMap ( string ( "standard" ), this->user->player->Get_War_Num() + 1 );
            this->user->player->Start_War ( this->_map );
            cout << endl << "[*]当前关卡: " << this->user->player->Get_War_Num() << endl;
            this->user->player->Show_Status();
            this->user->player->Show_War_Status();
            this->user->player->Show_Map ( true );
            cout << "[*]确认开始？(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice != string ( "y" ) && _choice != string ( "Y" ) )
            {
                this->status = war;
                this->user->player->End_War ( this->_map );
            }
            else
            {
                cout << endl << "[*]战争开始";
                this->user->ai = new Player();
                bool _first = this->user->player->Is_First();
                if ( _first )
                    cout << endl << "[*]第一回合玩家先手" << endl;
                else
                    cout << endl << "[*]第一回合电脑先手" << endl;
                switch ( this->user->player->Get_War_Num() )
                {
                    case 1:
                    {
                        this->user->ai->Ai_Init ( AI_PRESTIGE_1, AI_BITCOIN_1, AI_VIOLENCE_1, AI_SECOND_1, 1, !_first );
                        break;
                    }
                    case 2:
                    {
                        this->user->ai->Ai_Init ( AI_PRESTIGE_2, AI_BITCOIN_2, AI_VIOLENCE_2, AI_SECOND_2, 2, !_first );
                        break;
                    }
                    case 3:
                    {
                        this->user->ai->Ai_Init ( AI_PRESTIGE_3, AI_BITCOIN_3, AI_VIOLENCE_3, AI_SECOND_3, 3, !_first );
                        break;
                    }
                    case 4:
                    {
                        this->user->ai->Ai_Init ( AI_PRESTIGE_4, AI_BITCOIN_4, AI_VIOLENCE_4, AI_SECOND_4, 4, !_first );
                        break;
                    }
                    case 5:
                    {
                        this->user->ai->Ai_Init ( AI_PRESTIGE_5, AI_BITCOIN_5, AI_VIOLENCE_5, AI_SECOND_5, 5, !_first );
                        break;
                    }
                }
                this->user->ai->Start_War ( this->_map );
            }
            _result = true;
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]返回主界面" << endl;
            _result = true;
        }
        else
            _result = false;
    }
    else if ( this->status == start_war )
    {
        if ( cmd == string ( "exit" ) )
        {
            cout << endl << "[*]本局游戏将不会被保存，也不会获得任何奖励，确认退出吗？(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]退出战争" << endl;
                this->user->player->End_War ( this->_map );
                this->status = war;
                _result = true;
            }
        }
        else if ( cmd == string ( "help" ) )
        {
            cout << "+--------------------------------------+" << endl;
            cout << "|[*]战争界面命令:                      |" << endl;
            cout << "|show  status     获得战争属性         |" << endl;
            cout << "|      map        获得当前地图         |" << endl;
            cout << "|      all        获得属性与地图       |" << endl;
            cout << "|                                      |" << endl;
            cout << "|select build x,y   选择某一坐标的建筑 |" << endl;
            cout << "|       soldier n   选择ID为n的士兵    |" << endl;
            cout << "|                                      |" << endl;
            cout << "|move {up,down,left,right}  移动士兵   |" << endl;
            cout << "|                                      |" << endl;
            cout << "|build    （工人）占领并建造根据地     |" << endl;
            cout << "|                                      |" << endl;
            cout << "|produce TYPE 生产TYPE类型的士兵       |" << endl;
            cout << "|                                      |" << endl;
            cout << "|exit   退出战争                       |" << endl;
            cout << "+--------------------------------------+" << endl;
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "show" ) )
        {
            if ( cmd.substr ( 4, 1 ) == string ( " " ) )
            {
                string subcmd = cmd.substr ( 5 );
                if ( subcmd == string ( "status" ) )
                {
                    this->user->player->Show_War_Status();
                    _result = true;
                }
                else if ( subcmd == string ( "map" ) )
                {
                    this->user->player->Show_Map ( true );
                    _result = true;
                }
                else if ( subcmd == string ( "all" ) )
                {
                    this->user->player->Show_War_Status();
                    this->user->player->Show_Map ( true );
                    _result = true;
                }
                else
                    _result = false;
            }
            else
                _result = false;
        }
        else if ( cmd.substr ( 0, 6 ) == string ( "select" ) )
        {
            if ( cmd.substr ( 0 + 6, 1 ) == string ( " " ) )
            {
                if ( cmd.substr ( 0 + 6 + 1, 8 ) == string ( "building" ) )
                {
                    if ( cmd.substr ( 0 + 6 + 1 + 8, 1 ) == string ( " " ) )
                    {
                        string _subcmd = cmd.substr ( 0 + 6 + 1 + 8 + 1 );
                        string::size_type position = _subcmd.find ( ',' );
                        if ( position != string::npos && position != 0 && position != ( _subcmd.size() - 1 ) )
                        {
                            unsigned int _x = this->_ConvertStringToNum<unsigned int> ( _subcmd.substr ( 0, position ) );
                            unsigned int _y = this->_ConvertStringToNum<unsigned int> ( _subcmd.substr ( position + 1 ) );
                            if ( this->user->player->Select_Point ( _x, _y ) )
                            {
                                this->user->player->Show_Ponit_Status();
                                _result = true;
                            }
                            else
                                _result = false;;
                        }
                        else
                            _result = false;
                    }
                    else
                        _result = false;
                }
                else if ( cmd.substr ( 0 + 6 + 1, 7 ) == string ( "soldier" ) )
                {
                    if ( cmd.substr (  0 + 6 + 1 + 7, 1 ) == string ( " " ) )
                    {
                        string _subcmd = cmd.substr ( 0 + 6 + 1 + 7 + 1 );
                        unsigned int _id = this->_ConvertStringToNum<unsigned int> ( _subcmd );
                        if ( this->user->player->Select_Soldier ( _id ) )
                        {
                            this->user->player->Show_Soldier_Status ( _id );
                            _result = true;
                        }
                        else
                            _result = false;
                    }
                    else
                        _result = false;
                }
                else
                    _result = false;
            }
            else
                _result = false;
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "move" ) )
        {
            if ( !this->user->player->IsSelectSoldier() )
            {
                cout << endl << "[!]未选择任何战士" << endl;
                _result = false;
            }
            else if ( cmd.substr ( 0 + 4, 1 ) == string ( " " ) )
            {
                if ( cmd.substr ( 0 + 4 + 1 ) == string ( "up" ) )
                {
                    if ( this->user->player->MoveUp() )
                    {
                        this->user->player->Show_Soldier_Status();
                        _result = true;
                    }
                    else
                    {
                        cout << endl << "[!]移动方向有障碍物，无法移动" << endl;
                        _result = false;
                    }
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "down" ) )
                {
                    if ( this->user->player->MoveDown() )
                    {
                        this->user->player->Show_Soldier_Status();
                        _result = true;
                    }
                    else
                    {
                        cout << endl << "[!]移动方向有障碍物，无法移动" << endl;
                        _result = false;
                    }
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "left" ) )
                {
                    if ( this->user->player->MoveLeft() )
                    {
                        this->user->player->Show_Soldier_Status();
                        _result = true;
                    }
                    else
                    {
                        cout << endl << "[!]移动方向有障碍物，无法移动" << endl;
                        _result = false;
                    }
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "right" ) )
                {
                    if ( this->user->player->MoveRight() )
                    {
                        this->user->player->Show_Soldier_Status();
                        _result = true;
                    }
                    else
                    {
                        cout << endl << "[!]移动方向有障碍物，无法移动" << endl;
                        _result = false;
                    }
                }
            }
            else
                _result = false;
        }
        else if ( cmd.substr ( 0, 7 ) == string ( "produce" ) )
        {
            if ( cmd.substr ( 0 + 7, 1 ) == string ( " " ) )
            {
                string _subcmd = cmd.substr ( 8 );
                unsigned int _x = this->user->player->GetPlayerBaseX();
                unsigned int _y = this->user->player->GetPlayerBaseY();
                if ( _y == this->_map->GetRHeight() )
                    _y = _y - 1;
                else
                    _y = _y + 1;
                if ( _subcmd == string ( "worker" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Worker, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "archer" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Archer, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "swordsman" ) )
                {
                    if ( this->user->player->Create_Soldier ( _SwordsMan, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "priest" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Priest, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "siegcar" ) )
                {
                    if ( this->user->player->Create_Soldier ( _SiegCar, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "dragon" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Dragon, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "wolf" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Wolf, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "slime" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Slime, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "goblin" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Goblin, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "icegiant" ) )
                {
                    if ( this->user->player->Create_Soldier ( _IceGiant, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "flamebirds" ) )
                {
                    if ( this->user->player->Create_Soldier ( _FlameBirds, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "naga" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Naga, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else if ( _subcmd == string ( "phoenix" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Phoenix, player_city, _x, _y ) )
                        _result = true;
                    else
                    {
                        cout << endl << "[!]生产资源不足" << endl;
                        _result = false;
                    }
                }
                else
                    _result = false;
            }
            else
                _result = false;
        }
        else if ( cmd.substr ( 0, 5 ) == string ( "build" ) )
        {
            if ( this->user->player->GetCurrentSoldierName() == _Worker )
            {
                if ( this->user->player->GetCityPower() == empty_city )
                {
                    this->user->player->BuildCity();
                    cout << endl << "[*]建造成功" << endl;
                    _result = true;
                }
                else
                {
                    cout << endl << "[!]建造失败，当前城市不是一个可建造的城市！" << endl;
                    _result = false;
                }
            }
            else
            {
                cout << endl << "[!]只有Worker可以建造城市，当前选择的士兵并不是Worker，请重新选择。";
                _result = false;
            }
        }
        else
            _result = false;
        //this->_map->Update();
        /**
        * Here for AI second.
        **/
        //this->user->player->Recover();
        //this->user->player->Show_Map ( false );
    }
    return _result;
}
