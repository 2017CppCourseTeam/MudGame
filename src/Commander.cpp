#include "Commander.h"

Commander::Commander ( User*& user )
{
    this->status = _main;
    this->user = user;
}

enum STATUS Commander::GetStatus()
{
    return this->status;
}

void Commander::SetStatus ( enum STATUS _status )
{
    this->status = _status;
}

template <class T>
T Commander::_ConvertStringToNum ( const string& str )
{
    istringstream iss ( str );
    T num;
    iss >> num;
    return num;
}

void Commander::_ToLower ( string& s )
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

void Commander::_ShowManual()
{
    HANDLE handle;
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    PlaySound ( ".\\BGM\\ddz.wav", NULL, SND_FILENAME | SND_ASYNC );
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
    cout << "  ��ս���У�����ʿ����ռ����У�������ˣ�    " << endl;
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
        PlaySound ( ".\\BGM\\HDL.wav", NULL, SND_FILENAME | SND_ASYNC );
    }
}

void Commander::_CurrentPage()
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

void Commander::_ShowHistory()
{
    cout << endl << "[*]��ʷ����: " << endl;
    for ( int i = this->history.size() - 1; i >= 0 ; i-- )
        cout << history[i] << endl;
}

bool Commander::Eval ( string& cmd )
{
    bool _result = false;
    _ToLower ( cmd );
    this->history.insert ( history.begin(), cmd );
    // Global command
    if ( cmd == string ( "status" ) )
    {
        this->user->player->ShowStatus();
        return true;
    }
    else if ( cmd == string ( "current page" ) )
    {
        this->_CurrentPage();
        return true;
    }
    else if ( cmd == string ( "manual" ) )
    {
        this->_ShowManual();
        return true;
    }
    else if ( cmd == string ( "history" ) )
    {
        this->_ShowHistory();
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
            PlaySound ( ".\\BGM\\StayinAlive.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
            this->status = practice;
            cout << endl << "[*]ѵ������" << endl;
            _result = true;
        }
        else if ( cmd == string ( "war" ) )
        {
            HANDLE handle;
            handle = GetStdHandle ( STD_OUTPUT_HANDLE );
            PlaySound ( ".\\BGM\\PacificRim.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
            this->status = war;
            cout << endl << "[*]ս������" << endl;
            SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout << endl << ".     /| ________________" << endl;
            cout << "O|===|* >________________>" << endl;
            cout << "'     \\|" << endl<<endl;
            SetConsoleTextAttribute ( handle, BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
            _result = true;
        }
        else if ( cmd == string ( "exit" ) )
        {
            this->status = _quit;
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
            this->user->player->TrainCoder();
            _result = true;
        }
        else if ( cmd == string ( "dig mine" ) )
        {
            this->user->player->DigMine();
            _result = true;
        }
        else if ( cmd == string ( "wash brain" ) )
        {
            this->user->player->WashBrain();
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
                this->user->player->RestartWar();
            }
            _result = true;
        }
        else if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]����ս��" << endl;
            this->status = start_war;
            this->LoadMap ( string ( "standard" ), this->user->player->GetWarNum() );
            this->user->player->StartWar ( this->_map );
            cout << endl << "[*]��ǰ�ؿ�: " << this->user->player->GetWarNum() << endl;
            this->user->player->ShowStatus();
            this->user->player->ShowWarStatus();
            this->user->player->ShowMap ( true );
            cout << "[*]ȷ�Ͽ�ʼ��(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice != string ( "y" ) && _choice != string ( "Y" ) )
            {
                this->status = war;
                this->user->player->EndWar ( this->_map );
            }
            else
            {
                cout << endl << "[*]ս����ʼ";
                this->user->player->First();
                this->user->ai = new Player();
                bool _first = this->user->player->IsFirst();
                if ( _first )
                    cout << endl << "[*]��һ�غ��������" << endl;
                else
                    cout << endl << "[*]��һ�غ�AI����" << endl;
                switch ( this->user->player->GetWarNum() )
                {
                    case 1:
                    {
                        this->user->ai->AIInit ( AI_PRESTIGE_1,
                                                 AI_BITCOIN_1,
                                                 AI_VIOLENCE_1,
                                                 AI_BITCOIN_1,
                                                 0,
                                                 !_first );
                        break;
                    }
                    case 2:
                    {
                        this->user->ai->AIInit ( AI_PRESTIGE_2,
                                                 AI_BITCOIN_2,
                                                 AI_VIOLENCE_2,
                                                 AI_BITCOIN_2,
                                                 1,
                                                 !_first );
                        break;
                    }
                    case 3:
                    {
                        this->user->ai->AIInit ( AI_PRESTIGE_3,
                                                 AI_BITCOIN_3,
                                                 AI_VIOLENCE_3,
                                                 AI_BITCOIN_3,
                                                 2,
                                                 !_first );
                        break;
                    }
                    case 4:
                    {
                        this->user->ai->AIInit ( AI_PRESTIGE_4,
                                                 AI_BITCOIN_4,
                                                 AI_VIOLENCE_4,
                                                 AI_BITCOIN_4,
                                                 3,
                                                 !_first );
                        break;
                    }
                    case 5:
                    {
                        this->user->ai->AIInit ( AI_PRESTIGE_5,
                                                 AI_BITCOIN_5,
                                                 AI_VIOLENCE_5,
                                                 AI_BITCOIN_5,
                                                 4,
                                                 !_first );
                        break;
                    }
                }
                this->user->ai->StartWar ( this->_map );
                if ( this->user->ai->IsFirst() )
                {
                    cout << endl << "[*]AI�غϿ�ʼ" << endl;
                    this->user->ai->Action();
                    this->user->ai->Recover();
                    cout << endl << "[*]AI�غϽ���" << endl;
                }
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
        if ( cmd == string ( "exit" ) )
        {
            cout << endl << "[*]������Ϸ�����ᱻ���棬Ҳ�������κν�����ȷ���˳���(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]�˳�ս��" << endl;
                this->user->player->EndWar ( this->_map );
                this->status = war;
                _result = true;
            }
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "help" ) )
        {
            if ( cmd.substr ( 4, 1 ) == string ( " " ) )
            {
                string subcmd = cmd.substr ( 5 );
                if ( subcmd == string ( "cmd" ) )
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
                    _result = true;
                }
                else if ( subcmd == string ( "map" ) )
                {
                    cout << endl << "[*]��ͼ˵��:" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| ** | ��һ��ػ���� |" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| XX | AI���ػ����   |" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| ++ | �յĳ���       |" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| +* | ���ռ��ĳ��� |" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| +* | AIռ��ĳ���   |" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| *  | ���ʿ��       |" << endl;
                    cout << "+----+----------------+" << endl;
                    cout << "| *  | AIʿ��         |" << endl;
                    cout << "+---------------------+" << endl;
                    _result = true;
                }
                else if ( subcmd == string ( "war" ) )
                {
                    cout << endl << "[*]ս������:" << endl;
                    cout << "ս�����ûغ��ƣ���ҶԿ�AI" << endl;
                    cout << "�ʼ�����50%�ļ�������" << endl;
                    cout << "��ҿ����ڻ�������ʿ����������Ҫʹ����Դ��ʿ��������Դ������ο� Show type" << endl;
                    cout << "��ұ���ʹ�� Select ָ�����ʿ��IDѡ��ʿ����Ȼ������ƶ���ʿ��" << endl;
                    cout << "����������������ƶ�һ��ʿ������һ���غ�" << endl;
                    cout << "��ʿ���ƶ������������˵ж�������ʿ�������ʱ�����Զ�����" << endl;
                    cout << "���������ܵ����˺� = ������������ - ��������������" << endl;
                    cout << "����������һ�����ʽ��з������ø��ʵ�������ֵ" << endl;
                }
            }
            if ( !_result )
            {
                cout << endl << "[!]Help ָ��ȱ�ٲ������������" << endl;
                cout << endl << "[*]Ҳ������ʹ�� Help map �� Help cmd ?" << endl;
            }
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "show" ) )
        {
            if ( cmd.substr ( 4, 1 ) == string ( " " ) )
            {
                string subcmd = cmd.substr ( 5 );
                if ( subcmd == string ( "status" ) )
                {
                    this->user->player->ShowWarStatus();
                    _result = true;
                }
                else if ( subcmd == string ( "map" ) )
                {
                    this->user->player->ShowMap ( true );
                    _result = true;
                }
                else if ( subcmd == string ( "all" ) )
                {
                    this->user->player->ShowWarStatus();
                    this->user->player->ShowMap ( true );
                    _result = true;
                }
                else if ( subcmd == string ( "type" ) )
                {
                    this->_ShowSoldierType();
                    _result = true;
                }
                PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
            }
            if ( !_result )
            {
                cout << endl << "[!]Show ָ��ȱ�ٲ������������" << endl;
                cout << endl << "[*]Ҳ������ʹ�� Show status �� Show map �� Show all �� Show  type ?" << endl;
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
                            if ( this->user->player->SelectPoint ( _x, _y ) )
                            {
                                this->user->player->ShowPonitStatus();
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
                        if ( this->user->player->SelectSoldier ( _id ) )
                        {
                            this->user->player->ShowSoldierStatus ( _id );
                            _result = true;
                        }
                    }
                }
            }
            PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
            PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
            if ( !_result )
            {
                cout << endl << "[!]Select ָ��ȱ�ٲ������������" << endl;
                cout << endl << "[*]Ҳ������ʹ�� Select building x,y �� Select soldier id ?" << endl;
            }
        }
        else if ( cmd == string ( "damn" ) )
            this->user->player->SetWarNum ( this->user->player->GetWarNum() + 1 );
        else if ( cmd.substr ( 0, 4 ) == string ( "move" ) )
        {
            if ( !this->user->player->IsSelectSoldier() )
                cout << endl << "[!]δѡ���κ�սʿ" << endl;
            else if ( cmd.substr ( 0 + 4, 1 ) == string ( " " ) )
            {
                if ( cmd.substr ( 0 + 4 + 1 ) == string ( "up" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->MoveUp() )
                    {
                        this->user->player->ShowSoldierStatus();
                        this->user->player->Recover();
                        cout << endl << "[*]��һغϽ���" << endl;
                        _result = true;
                        PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                        PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "down" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->MoveDown() )
                    {
                        this->user->player->ShowSoldierStatus();
                        this->user->player->Recover();
                        cout << endl << "[*]��һغϽ���" << endl;
                        _result = true;
                        PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                        PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "left" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->MoveLeft() )
                    {
                        this->user->player->ShowSoldierStatus();
                        this->user->player->Recover();
                        cout << endl << "[*]��һغϽ���" << endl;
                        _result = true;
                        PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                        PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                else if ( cmd.substr ( 0 + 4 + 1 ) == string ( "right" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->MoveRight() )
                    {
                        this->user->player->ShowSoldierStatus();
                        this->user->player->Recover();
                        cout << endl << "[*]��һغϽ���" << endl;
                        _result = true;
                        PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                        PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                    }
                    else
                        cout << endl << "[!]�ƶ��������ϰ���޷��ƶ�" << endl;
                }
                if ( _result && !this->user->ai->IsFirst() )
                {
                    cout << endl << "[*]AI�غϿ�ʼ" << endl;
                    this->user->ai->Action();
                    this->user->ai->Recover();
                    cout << endl << "[*]AI�غϽ���" << endl;
                }
            }
            if ( !_result )
            {
                cout << endl << "[!]Move ָ��ȱ�ٲ������������" << endl;
                cout << endl << "[*]Ҳ������ʹ�� Move up �� Move down �� Move left �� Move right ?" << endl;
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
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Worker, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "archer" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Archer, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "swordsman" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _SwordsMan, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "priest" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Priest, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "siegcar" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _SiegCar, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "dragon" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Dragon, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "wolf" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Wolf, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "slime" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Slime, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "goblin" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Goblin, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "icegiant" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _IceGiant, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "flamebirds" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _FlameBirds, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "naga" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Naga, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else if ( _subcmd == string ( "phoenix" ) )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    if ( this->user->player->CreateSoldier ( _Phoenix, player_city, _x, _y ) )
                        this->user->player->Recover();
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                if ( _result && !this->user->ai->IsFirst() )
                {
                    cout << endl << "[*]AI�غϿ�ʼ" << endl;
                    this->user->ai->Action();
                    this->user->ai->Recover();
                    cout << endl << "[*]AI�غϽ���" << endl;
                }
            }
            if ( !_result )
            {
                cout << endl << "[!]Produce ָ��ȱ�ٲ������������" << endl;
                cout << endl << "[*]Ҳ������ʹ�� Produce type ?" << endl;
                cout << endl << "[*]Type ��������� Show type" << endl;
            }
        }
        else if ( cmd.substr ( 0, 5 ) == string ( "build" ) )
        {
            if ( this->user->player->IsSelectSoldier() && this->user->player->GetCurrentSoldierName() == _Worker )
            {
                if ( this->user->player->GetCityPower() == empty_city )
                {
                    cout << endl << "[*]��һغϿ�ʼ" << endl;
                    this->user->player->BuildCity();
                    cout << endl << "[*]����ɹ�" << endl;
                    PlaySound ( ".\\BGM\\yessir.wav", NULL, SND_FILENAME | SND_SYNC );
                    PlaySound ( ".\\BGM\\Pacific2.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
                    cout << endl << "[*]��һغϽ���" << endl;
                    _result = true;
                }
                else
                    cout << endl << "[!]����ʧ�ܣ���ǰ�ص㲻��һ���ɽ���ĳ��У�" << endl;
            }
            else
                cout << endl << "[!]ֻ��Worker���Խ�����У���ǰѡ���ʿ��������Worker��������ѡ��";
            if ( _result && !this->user->ai->IsFirst() )
            {
                cout << endl << "[*]AI�غϿ�ʼ" << endl;
                this->user->ai->Action();
                this->user->ai->Recover();
                cout << endl << "[*]AI�غϽ���" << endl;
            }
        }
        if ( this->user->player->CheckWinOfWar() )
        {
            cout << endl << "[*]ս��������������ҳ��" << endl;
            this->status = _main;
        }
    }
    return _result;
}
