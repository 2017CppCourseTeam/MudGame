#include "Game.h"
#include "War.h"

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
    cout << "[*]��Ϸ����:                                                       " << endl;
    cout << "����һ�������������ս����Ϸ                                       " << endl;
    cout << "���������Ҫͨ��ѵ�������Լ������ԣ�����һ����ս��������ȡʤ�� " << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "|  �ʼ����ӵ�е�����ֵ�ֱ��ǣ�                 |" << endl;
    cout << "|    * 50������ֵ��ʿ�����ܹ�Ӱ��ս��ʱ������ֵ�� |" << endl;
    cout << "|    * 10�����رң�����ѵ��������ս����           |" << endl;
    cout << "|    * 50�㱩��ֵ��ս��������ֵ��                 |" << endl;
    cout << "|    * 10�������ֵ��������ֵС��0����Ϸʧ�ܣ�    |" << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "  �����ͨ��������Ӧ���������ѵ����ս��    " << endl;
    cout << "  ͨ��ѵ����ũ����������ֵ                    " << endl;
    cout << "  ͨ���ڿ󣬻�ñ��ر�                        " << endl;
    cout << "  ͨ������ϴ�ԣ���������ֵ                    " << endl;
    cout << "  ͨ������ս�������˸����ؿ���������յ�ʤ����" << endl;
    cout << "                                              " << endl;
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_BLUE );
    cout << "�����������" << endl;
    if ( getch() )
    {
        SetConsoleTextAttribute ( handle, FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
        cout << "+----------------------------------+" << endl;
        cout << "|[*]ȫ������:                      |" << endl;
        cout << "|manual         �����ϸ��Ϸ����   |" << endl;
        cout << "|help           ��õ�ǰ�������   |" << endl;
        cout << "|history        �����ʷ����       |" << endl;
        cout << "|status         ��ʾ�û�״̬       |" << endl;
        cout << "|save           ������Ϸ           |" << endl;
        cout << "|current page   ��ʾ��ǰ����       |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]����������:                    |" << endl;
        cout << "|war            ��ʼս��           |" << endl;
        cout << "|practice       ѵ��               |" << endl;
        cout << "|exit           �˳���Ϸ           |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]ѵ����������:                  |" << endl;
        cout << "|train coder    ѵ����ũ           |" << endl;
        cout << "|dig mine       �ڿ�               |" << endl;
        cout << "|wash brain     ����ϴ��           |" << endl;
        cout << "|back           ����������         |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]ս����ʼ��������:              |" << endl;
        cout << "|continue       ����ս��           |" << endl;
        cout << "|restart        ���¿�ʼս��       |" << endl;
        cout << "|back           ����������         |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "|[*]ս����������:                      |" << endl;
        cout << "|show  status     ���ս������         |" << endl;
        cout << "|      map        ��õ�ǰ��ͼ         |" << endl;
        cout << "|      all        ����������ͼ       |" << endl;
        cout << "|                                      |" << endl;
        cout << "|select build x,y   ѡ��ĳһ����Ľ��� |" << endl;
        cout << "|       soldier n   ѡ��IDΪn��ʿ��    |" << endl;
        cout << "|                                      |" << endl;
        cout << "|move {up,down,left,right}  �ƶ�ʿ��   |" << endl;
        cout << "|                                      |" << endl;
        cout << "|build    �����ˣ�ռ�첢������ݵ�     |" << endl;
        cout << "|                                      |" << endl;
        cout << "|produce TYPE ����TYPE���͵�ʿ��       |" << endl;
        cout << "|                                      |" << endl;
        cout << "|exit   �˳�ս��                       |" << endl;
        cout << "+--------------------------------------+" << endl;
        SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    }
}

void Commander::_Current_Page()
{
    cout << endl << "[*]��ǰ����: ";
    switch ( this->status )
    {
        case _main:
            cout << "������" << endl;
            break;
        case practice:
            cout << "ѵ������" << endl;
            break;
        case start_war:
        case war:
            cout << "ս������" << endl;
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
    cout << endl << "[*]��ʷ����: " << endl;
    for ( int i = this->history.size() - 1; i >= 0 ; i-- )
        cout << history[i] << endl;
}

bool Commander::Eval ( string& cmd )
{
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
            cout << endl << "[*]����ɹ�" << endl;
        return true;
    }
    // Main page
    if ( this->status == _main )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]�����ѡ��: " << endl;
            cout << "+-----------------+" << endl;
            cout << "|* ѵ��[practice] |" << endl;
            cout << "|* ս��[war]      |" << endl;
            cout << "|* �˳�[exit]     |" << endl;
            cout << "+-----------------+" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
        }
        else if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]ѵ������" << endl;
        }
        else if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]ս������" << endl;
        }
        else if ( cmd == string ( "exit" ) )
        {
            this->status = quit;
        }
        else
            return false;
        return true;
    }
    // Practice page
    else if  ( this->status == practice )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]�����ѡ��: " << endl;
            cout << "+---------------------+" << endl;
            cout << "|* ѵ��[train coder]  |" << endl;
            cout << "|* �ڿ�[dig mine]     |" << endl;
            cout << "|* ϴ��[wash brain]   |" << endl;
            cout << "|* ����[back]         |" << endl;
            cout << "+---------------------+" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
        }
        else if ( cmd == string ( "train coder" ) )
        {
            this->user->player->Train_Coder();
        }
        else if ( cmd == string ( "dig mine" ) )
        {
            this->user->player->Dig_Mine();
        }
        else if ( cmd == string ( "wash brain" ) )
        {
            this->user->player->Wash_Brain();
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]����������" << endl;
        }
        else
            return false;
        if ( this->user->player->Get_Second() == 0 )
            this->status = lose;
        return true;
    }
    // War page
    else if ( this->status == war )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]�����ѡ��: " << endl;
            cout << "+---------------------+" << endl;
            cout << "|* ���¿�ʼ[restart]  |" << endl;
            cout << "|* ����[continue]     |" << endl;
            cout << "|* ����[back]         |" << endl;
            cout << "+---------------------+" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
            return true;
        }
        else if ( cmd == string ( "restart" ) )
        {
            string _choice;
            cout << endl << "[*]ȷ��Ҫ���¿�ʼ��(y/n)";
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]���¿�ʼս��" << endl;
                this->user->player->Restart_War();
            }
        }
        else if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]����ս��" << endl;
            this->status = start_war;
            this->LoadMap ( string ( "standard" ), this->user->player->Get_War_Num() + 1 );
            this->user->player->Start_War ( this->_map );
            cout << endl << "[*]��ǰ�ؿ�: " << this->user->player->Get_War_Num() << endl;
            this->user->player->Show_Status();
            this->user->player->Show_War_Status();
            this->user->player->Show_Map ( true );
            cout << "[*]ȷ�Ͽ�ʼ��(y/n)" << endl << ">>";
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
                cout << endl << "[*]ս����ʼ";
                this->user->ai = new AI();
                bool _first = this->user->player->Is_First();
                this->user->ai->Init_Order(!_first);
                if ( _first )
                    {cout << endl << "[*]��һ�غ��������" << endl;}
                else
                    {cout << endl << "[*]��һ�غϵ�������" << endl;}
                switch ( this->user->player->Get_War_Num() )
                {
                    case 1:
                    {
                        this->user->ai->AI_Init (100, 100, 100, 1);
                        break;
                    }
                    case 2:
                    {
                        this->user->ai->AI_Init (200, 200, 200, 2);
                        break;
                    }
                    case 3:
                    {
                        this->user->ai->AI_Init (300, 300, 300, 3);
                        break;
                    }
                    case 4:
                    {
                        this->user->ai->AI_Init (400, 400, 400, 4);
                        break;
                    }
                    case 5:
                    {
                        this->user->ai->AI_Init (500, 500, 500, 5);
                        break;
                    }
                }
                this->user->ai->Start_War ( this->_map );
            }
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]����������" << endl;
        }
        else
            return false;
        return true;
    }
    else if ( this->status == start_war )
    {
        //cout << "*******��" << this->user->ai->getAct_num() << "�غ�********" << endl << endl;
        if (this->user->ai->getIfFirst()) {
            cout << "AI���֣�" << endl;
            this->user->ai->action();
            cout << "�����֣�" << endl;
        }
        else {
            cout << "�����֣�" << endl;
        }
        if ( cmd == string ( "exit" ) )
        {
            cout << endl << "[*]������Ϸ�����ᱻ���棬Ҳ�������κν�����ȷ���˳���(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]�˳�ս��" << endl;
                this->user->player->End_War ( this->_map );
                this->status = war;
                return true;
            }
            else
                return false;
        }
        else if ( cmd == string ( "help" ) )
        {
            cout << "+--------------------------------------+" << endl;
            cout << "|[*]ս����������:                      |" << endl;
            cout << "|show  status     ���ս������         |" << endl;
            cout << "|      map        ��õ�ǰ��ͼ         |" << endl;
            cout << "|      all        ����������ͼ       |" << endl;
            cout << "|                                      |" << endl;
            cout << "|select build x,y   ѡ��ĳһ����Ľ��� |" << endl;
            cout << "|       soldier n   ѡ��IDΪn��ʿ��    |" << endl;
            cout << "|                                      |" << endl;
            cout << "|move {up,down,left,right}  �ƶ�ʿ��   |" << endl;
            cout << "|                                      |" << endl;
            cout << "|build    �����ˣ�ռ�첢������ݵ�     |" << endl;
            cout << "|                                      |" << endl;
            cout << "|produce TYPE ����TYPE���͵�ʿ��       |" << endl;
            cout << "|                                      |" << endl;
            cout << "|exit   �˳�ս��                       |" << endl;
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
                }
                else if ( subcmd == string ( "map" ) )
                {
                    this->user->player->Show_Map ( true );
                }
                else if ( subcmd == string ( "all" ) )
                {
                    this->user->player->Show_War_Status();
                    this->user->player->Show_Map ( true );
                }
                else
                    return false;
            }
            else
                return false;
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
                                this->user->player->Show_Ponit_Status();
                            else
                                return false;
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else if ( cmd.substr ( 0 + 6 + 1, 7 ) == string ( "soldier" ) )
                {
                    if ( cmd.substr (  0 + 6 + 1 + 7, 1 ) == string ( " " ) )
                    {
                        string _subcmd = cmd.substr ( 0 + 6 + 1 + 7 + 1 );
                        unsigned int _id = this->_ConvertStringToNum<unsigned int> ( _subcmd );
                        if ( this->user->player->Select_Soldier ( _id ) )
                            this->user->player->Show_Soldier_Status ( _id );
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "move" ) )
        {
            if ( !this->user->player->IsSelectSoldier() )
            {
                cout << endl << "[!]δѡ���κ�սʿ" << endl;
                return false;
            }
            else if ( cmd.substr ( 0 + 4, 1 ) == string ( " " ) )
            {
                if ( cmd.substr ( 0 + 4 + 1 ) == string ( "up" ) )
                {
                    this->user->player->GetCurrentWar()->soldier_selecter->UpdateY(this->user->player->GetCurrentWar()->soldier_selecter->GetY()-1);
                    this->user->player->GetCurrentWar()->_Show_Soldier_Status ( );
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "down" ) )
                {
                    this->user->player->GetCurrentWar()->soldier_selecter->UpdateY(this->user->player->GetCurrentWar()->soldier_selecter->GetY()+1);
                    this->user->player->GetCurrentWar()->_Show_Soldier_Status ();
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "left" ) )
                {
                    this->user->player->GetCurrentWar()->soldier_selecter->UpdateX(this->user->player->GetCurrentWar()->soldier_selecter->GetX()-1);
                    this->user->player->GetCurrentWar()->_Show_Soldier_Status ();
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "right" ) )
                {
                    this->user->player->GetCurrentWar()->soldier_selecter->UpdateX(this->user->player->GetCurrentWar()->soldier_selecter->GetX()+1);
                    this->user->player->GetCurrentWar()->_Show_Soldier_Status ();
                }
            }
            else
                return false;
        }
        else if ( cmd.substr ( 0, 7 ) == string ( "produce" ) )
        {
            if ( cmd.substr ( 0 + 7, 1 ) == string ( " " ) )
            {
                string _subcmd = cmd.substr ( 8 );
                unsigned int _x = this->user->player->GetPlayerBaseX();
                unsigned int _y = this->user->player->GetPlayerBaseY();
                if ( _y == this->_map->GetHeight() - 1 )
                    _y = _y - 2;
                else
                    _y = _y + 2;
                if ( _subcmd == string ( "worker" ) )
                {
                    this->user->player->Create_Soldier ( _Worker, _x, _y );
                }
                else if ( _subcmd == string ( "archer" ) )
                {
                    this->user->player->Create_Soldier ( _Archer, _x, _y );
                }
                else if ( _subcmd == string ( "swordsman" ) )
                {
                    this->user->player->Create_Soldier ( _SwordsMan, _x, _y );
                }
                else if ( _subcmd == string ( "priest" ) )
                {
                    this->user->player->Create_Soldier ( _Priest, _x, _y );
                }
                else if ( _subcmd == string ( "siegcar" ) )
                {
                    this->user->player->Create_Soldier ( _SiegCar, _x, _y );
                }
                else if ( _subcmd == string ( "dragon" ) )
                {
                    this->user->player->Create_Soldier ( _Dragon, _x, _y );
                }
                else if ( _subcmd == string ( "wolf" ) )
                {
                    this->user->player->Create_Soldier ( _Wolf, _x, _y );
                }
                else if ( _subcmd == string ( "slime" ) )
                {
                    this->user->player->Create_Soldier ( _Slime, _x, _y );
                }
                else if ( _subcmd == string ( "goblin" ) )
                {
                    this->user->player->Create_Soldier ( _Goblin, _x, _y );
                }
                else if ( _subcmd == string ( "icegiant" ) )
                {
                    this->user->player->Create_Soldier ( _IceGiant, _x, _y );
                }
                else if ( _subcmd == string ( "flamebirds" ) )
                {
                    this->user->player->Create_Soldier ( _FlameBirds, _x, _y );
                }
                else if ( _subcmd == string ( "naga" ) )
                {
                    this->user->player->Create_Soldier ( _Naga, _x, _y );
                }
                else if ( _subcmd == string ( "phoenix" ) )
                {
                    this->user->player->Create_Soldier ( _Phoenix, _x, _y );
                }
                else
                    return false;
            }
            else
                return false;
        }
        if (!this->user->ai->getIfFirst()) {
                cout << "AI���֣�" << endl;
                this->user->ai->action();
            }
        this->_map->Update();
        this->user->player->Show_Map ( false );
        return true;
    }
    return false;
}

