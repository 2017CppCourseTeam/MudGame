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

void Commander::_ShowSoldierType()
{
    cout << endl << "[*] ʿ�������б�:" << endl;
    cout << "+---------------------------------------------------------------------------------------------+" << endl;
    cout << "|       ����         |    ����    | ����ֵ | ������ | ������ | �������� | �������� | �������� |" << endl;
    cout << "|      (Type)        |            |        |        |        |  ����ֵ  |  ħ��ֵ  |   ���   | " << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ����(Worker)       | humanity   |  " << WORKER_LIFE << "   |  " << WORKER_ATTACK << "    |  " << WORKER_DEFENCE << "    |   " << WORKER_COST_LIFE << "     |   " << WORKER_COST_MAGIC << "      |   " << WORKER_COST_COIN << "     |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ������(Archer)     | humanity   |  " << ARCHER_LIFE << "   |  " << ARCHER_ATTACK << "   |  " << ARCHER_DEFENCE << "    |   " << ARCHER_COST_LIFE << "     |   " << ARCHER_COST_MAGIC << "      |   " << ARCHER_COST_COIN << "     |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ��ʿ(SwordsMan)    | humanity   |  " << SWORDSMAN_LIFE << "   |  " << SWORDSMAN_ATTACK << "   |  " << SWORDSMAN_DEFENCE << "   |   " << SWORDSMAN_COST_LIFE << "    |   " << SWORDSMAN_COST_MAGIC << "      |   " << SWORDSMAN_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ��ʦ(Priest)       | humanity   |  " << PRIEST_LIFE << "   |  " << PRIEST_ATTACK << "     |  " << PRIEST_DEFENCE << "    |   " << PRIEST_COST_LIFE << "     |   " << PRIEST_COST_MAGIC << "      |   " << PRIEST_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ���ǳ�(SiegCar)    | mechanical |  " << SIEGCAR_LIFE << "   |  " << SIEGCAR_ATTACK << "   |  " << SIEGCAR_DEFENCE << "   |   " << SIEGCAR_COST_LIFE << "    |   " << SIEGCAR_COST_MAGIC << "      |   " << SIEGCAR_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ����(Dragon)       | beast      |  " << DRAGON_LIFE << "   |  " << DRAGON_ATTACK << "   |  " << DRAGON_DEFENCE << "   |   " << DRAGON_COST_LIFE << "    |   " << DRAGON_COST_MAGIC << "    |   " << DRAGON_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ����(Wolf)         | beast      |  " << WOLF_LIFE << "   |  " << WOLF_ATTACK << "   |  " << WOLF_DEFENCE << "   |   " << WOLF_COST_LIFE << "    |   " << WOLF_COST_MAGIC << "      |   " << WOLF_COST_COIN << "     |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ʷ��ķ(Slime)      | wizard     |  " << ARCHER_LIFE << "   |  " << ARCHER_ATTACK << "   |  " << ARCHER_DEFENCE << "    |   " << ARCHER_COST_LIFE << "     |   " << ARCHER_COST_MAGIC << "      |   " << ARCHER_COST_COIN << "     |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| �粼��(Goblin)     | wizard     |  " << GOBLIN_LIFE << "   |  " << GOBLIN_ATTACK << "   |  " << GOBLIN_DEFENCE << "   |   " << GOBLIN_COST_LIFE << "    |   " << GOBLIN_COST_MAGIC << "     |   " << GOBLIN_COST_COIN << "     |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ������(IceGiant)   | warcraft   |  " << ICEGIANT_LIFE << "   |  " << ICEGIANT_ATTACK << "   |  " << ICEGIANT_DEFENCE << "   |   " << ICEGIANT_COST_LIFE << "    |   " << ICEGIANT_COST_MAGIC << "    |   " << ICEGIANT_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ������(FlameBirds) | warcraft   |  " << FLAMEBIRDS_LIFE << "   |  " << FLAMEBIRDS_ATTACK << "   |  " << FLAMEBIRDS_DEFENCE << "   |   " << FLAMEBIRDS_COST_LIFE << "    |   " << FLAMEBIRDS_COST_MAGIC << "    |   " << FLAMEBIRDS_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ����(Naga)         | warcraft   |  " << NAGA_LIFE << "   |  " << NAGA_ATTACK << "   |  " << NAGA_DEFENCE << "   |   " << NAGA_COST_LIFE << "    |   " << NAGA_COST_MAGIC << "    |   " << NAGA_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
    cout <<
         "| ���(Phoenix)      | warcraft   |  " << PHOENIX_LIFE << "   |  " << PHOENIX_ATTACK << "   |  " << PHOENIX_DEFENCE << "   |   " << PHOENIX_COST_LIFE << "    |   " << PHOENIX_COST_MAGIC << "    |   " << PHOENIX_COST_COIN << "    |" << endl;
    cout << "+--------------------+------------+--------+--------+--------+----------+----------+----------+" << endl;
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
        cout << endl << "[*]��������:" << endl;
        cout << "+----------------------------------------------------------+" << endl;
        cout << "|[*]ȫ������:                                              |" << endl;
        cout << "|manual                �����ϸ��Ϸ����                    |" << endl;
        cout << "|help                  ��õ�ǰ�������                    |" << endl;
        cout << "|history               �����ʷ����                        |" << endl;
        cout << "|status                ��ʾ�û�״̬                        |" << endl;
        cout << "|save                  ������Ϸ                            |" << endl;
        cout << "|current page          ��ʾ��ǰ����                        |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
        cout << "|[*]����������:                                            |" << endl;
        cout << "|war                   ��ʼս��                            |" << endl;
        cout << "|practice              ѵ��                                |" << endl;
        cout << "|exit                  �˳���Ϸ                            |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
        cout << "|[*]ѵ����������:                                          |" << endl;
        cout << "|train coder           ѵ����ũ                            |" << endl;
        cout << "|dig mine              �ڿ�                                |" << endl;
        cout << "|wash brain            ����ϴ��                            |" << endl;
        cout << "|back                  ����������                          |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
        cout << "|[*]ս����ʼ��������:                                      |" << endl;
        cout << "|continue              ����ս��                            |" << endl;
        cout << "|restart               ���¿�ʼս��                        |" << endl;
        cout << "|back                  ����������                          |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
        cout << "|[*]ս����������:                                          |" << endl;
        cout << "|show status           ��ʾս������                        |" << endl;
        cout << "|show map              ��ʾ��ǰ��ͼ                        |" << endl;
        cout << "|show all              ��ʾ�������ͼ                      |" << endl;
        cout << "|show type             ��ʾʿ����ϸ�б�                    |" << endl;
        cout << "|                                                          |" << endl;
        cout << "|select building x,y   ��ʾ x,y ����Ľ�������             |" << endl;
        cout << "|select soldier n      ѡ��IDΪn��ʿ��������ʾ��ʿ�������� |" << endl;
        cout << "|                                                          |" << endl;
        cout << "|move up               ��ǰѡ���ʿ�������ƶ�              |" << endl;
        cout << "|move down             ��ǰѡ���ʿ�������ƶ�              |" << endl;
        cout << "|move left             ��ǰѡ���ʿ�������ƶ�              |" << endl;
        cout << "|move right            ��ǰѡ���ʿ�������ƶ�              |" << endl;
        cout << "|                                                          |" << endl;
        cout << "|produce type          ����type���͵�ʿ��                  |" << endl;
        cout << "|                      ������ο� show type ָ��           |" << endl;
        cout << "|                                                          |" << endl;
        cout << "|build                 ��ǰѡ���ʿ��(����)ռ��ó���      |" << endl;
        cout << "|help                  ��ʾ��ҳ��                          |" << endl;
        cout << "|exit                  �˳�ս��                            |" << endl;
        cout << "+----------------------------------------------------------+" << endl;
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
            load.open ( ( string ( ".\\map\\" ) + name + string ( "1.dat" ) ).c_str(), ios::in );
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
            _result = true;
        }
        else if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]ѵ������" << endl;
            _result = true;
        }
        else if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]ս������" << endl;
            _result = true;
        }
        else if ( cmd == string ( "exit" ) )
        {
            this->status = quit;
            _result = true;
        }
    }
    // Practice page
    else if ( this->status == practice )
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
            cout << endl << "[*]����������" << endl;
            _result = true;
        }
        else
            _result = false;;
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
            _result = true;
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
            _result = true;
        }
        else if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]����ս��" << endl;
            this->status = start_war;
            this->LoadMap ( string ( "standard" ), this->user->player->Get_War_Num() );
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
                this->user->player->First();
                this->user->ai = new Player();
                bool _first = this->user->player->Is_First();
                if ( _first )
                    cout << endl << "[*]��һ�غ��������" << endl;
                else
                    cout << endl << "[*]��һ�غϵ�������" << endl;
                switch ( this->user->player->Get_War_Num() )
                {
                    case 1:
                    {
                        this->user->ai->AI_Init ( AI_PRESTIGE_1,
                                                  AI_BITCOIN_1,
                                                  AI_VIOLENCE_1,
                                                  AI_BITCOIN_1,
                                                  0,
                                                  !_first );
                        break;
                    }
                    case 2:
                    {
                        this->user->ai->AI_Init ( AI_PRESTIGE_2,
                                                  AI_BITCOIN_2,
                                                  AI_VIOLENCE_2,
                                                  AI_BITCOIN_2,
                                                  1,
                                                  !_first );
                        break;
                    }
                    case 3:
                    {
                        this->user->ai->AI_Init ( AI_PRESTIGE_3,
                                                  AI_BITCOIN_3,
                                                  AI_VIOLENCE_3,
                                                  AI_BITCOIN_3,
                                                  2,
                                                  !_first );
                        break;
                    }
                    case 4:
                    {
                        this->user->ai->AI_Init ( AI_PRESTIGE_4,
                                                  AI_BITCOIN_4,
                                                  AI_VIOLENCE_4,
                                                  AI_BITCOIN_4,
                                                  3,
                                                  !_first );
                        break;
                    }
                    case 5:
                    {
                        this->user->ai->AI_Init ( AI_PRESTIGE_5,
                                                  AI_BITCOIN_5,
                                                  AI_VIOLENCE_5,
                                                  AI_BITCOIN_5,
                                                  4,
                                                  !_first );
                        break;
                    }
                }
                this->user->ai->Start_War ( this->_map );
                if ( this->user->ai->Is_First() )
                    this->user->ai->Action();
            }
            _result = true;
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]����������" << endl;
            _result = true;
        }
    }
    else if ( this->status == start_war )
    {
        if ( this->user->ai->Is_First() )
            this->user->ai->Action();
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
                _result = true;
            }
        }
        else if ( cmd == string ( "help" ) )
        {
            cout << endl << "+----------------------------------------------------------+" << endl;
            cout << "|[*]ս����������:                                          |" << endl;
            cout << "|show status           ��ʾս������                        |" << endl;
            cout << "|show map              ��ʾ��ǰ��ͼ                        |" << endl;
            cout << "|show all              ��ʾ�������ͼ                      |" << endl;
            cout << "|show type             ��ʾʿ����ϸ�б�                    |" << endl;
            cout << "|                                                          |" << endl;
            cout << "|select building x,y   ��ʾ x,y ����Ľ�������             |" << endl;
            cout << "|select soldier n      ѡ��IDΪn��ʿ��������ʾ��ʿ�������� |" << endl;
            cout << "|                                                          |" << endl;
            cout << "|move up               ��ǰѡ���ʿ�������ƶ�              |" << endl;
            cout << "|move down             ��ǰѡ���ʿ�������ƶ�              |" << endl;
            cout << "|move left             ��ǰѡ���ʿ�������ƶ�              |" << endl;
            cout << "|move right            ��ǰѡ���ʿ�������ƶ�              |" << endl;
            cout << "|                                                          |" << endl;
            cout << "|produce type          ����type���͵�ʿ��                  |" << endl;
            cout << "|                      ������ο� show type ָ��           |" << endl;
            cout << "|                                                          |" << endl;
            cout << "|build                 ��ǰѡ���ʿ��(����)ռ��ó���      |" << endl;
            cout << "|help                  ��ʾ��ҳ��                          |" << endl;
            cout << "|exit                  �˳�ս��                            |" << endl;
            cout << "+----------------------------------------------------------+" << endl;
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
                else if ( subcmd == string ( "type" ) )
                {
                    this->_ShowSoldierType();
                    _result = true;
                }
            }
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
                        }
                    }
                }
                else if ( cmd.substr ( 0 + 6 + 1, 7 ) == string ( "soldier" ) )
                {
                    if ( cmd.substr ( 0 + 6 + 1 + 7, 1 ) == string ( " " ) )
                    {
                        string _subcmd = cmd.substr ( 0 + 6 + 1 + 7 + 1 );
                        unsigned int _id = this->_ConvertStringToNum<unsigned int> ( _subcmd );
                        if ( this->user->player->Select_Soldier ( _id ) )
                        {
                            this->user->player->Show_Soldier_Status ( _id );
                            _result = true;
                        }
                    }
                }
            }
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "move" ) )
        {
            if ( !this->user->player->IsSelectSoldier() )
                cout << endl << "[!]δѡ���κ�սʿ" << endl;
            else if ( cmd.substr ( 0 + 4, 1 ) == string ( " " ) )
            {
                if ( cmd.substr ( 0 + 4 + 1 ) == string ( "up" ) )
                {
                    if ( this->user->player->MoveUp() )
                    {
                        this->user->player->Show_Soldier_Status();
                        this->user->player->Recover();
                        _result = true;
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "down" ) )
                {
                    if ( this->user->player->MoveDown() )
                    {
                        this->user->player->Show_Soldier_Status();
                        this->user->player->Recover();
                        _result = true;
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "left" ) )
                {
                    if ( this->user->player->MoveLeft() )
                    {
                        this->user->player->Show_Soldier_Status();
                        this->user->player->Recover();
                        _result = true;
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "right" ) )
                {
                    if ( this->user->player->MoveRight() )
                    {
                        this->user->player->Show_Soldier_Status();
                        this->user->player->Recover();
                        _result = true;
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                if ( !this->user->ai->Is_First() )
                    this->user->ai->Action();
            }
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
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "archer" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Archer, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "swordsman" ) )
                {
                    if ( this->user->player->Create_Soldier ( _SwordsMan, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "priest" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Priest, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "siegcar" ) )
                {
                    if ( this->user->player->Create_Soldier ( _SiegCar, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "dragon" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Dragon, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "wolf" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Wolf, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "slime" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Slime, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "goblin" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Goblin, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "icegiant" ) )
                {
                    if ( this->user->player->Create_Soldier ( _IceGiant, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "flamebirds" ) )
                {
                    if ( this->user->player->Create_Soldier ( _FlameBirds, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "naga" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Naga, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                else if ( _subcmd == string ( "phoenix" ) )
                {
                    if ( this->user->player->Create_Soldier ( _Phoenix, player_city, _x, _y ) )
                        this->user->player->Recover();
                        _result = true;
                }
                if ( !this->user->ai->Is_First() )
                    this->user->ai->Action();
            }
        }
        else if ( cmd.substr ( 0, 5 ) == string ( "build" ) )
        {
            if ( this->user->player->IsSelectSoldier() && this->user->player->GetCurrentSoldierName() == _Worker )
            {
                if ( this->user->player->GetCityPower() == empty_city )
                {
                    this->user->player->BuildCity();
                    this->user->player->Recover();
                    cout << endl << "[*]����ɹ�" << endl;
                    _result = true;
                }
                else
                    cout << endl << "[!]����ʧ�ܣ���ǰ�ص㲻��һ���ɽ���ĳ��У�" << endl;
            }
            else
                cout << endl << "[!]ֻ��Worker���Խ�����У���ǰѡ���ʿ��������Worker��������ѡ��";
            if ( !this->user->ai->Is_First() )
                this->user->ai->Action();
        }
        if ( this->user->player->CheckWin() )
        {
            cout << endl << "[*]ս��������������ҳ��" << endl;
            this->status = _main;
        }
        //this->user->player->Recover();
    }
    return _result;
}
