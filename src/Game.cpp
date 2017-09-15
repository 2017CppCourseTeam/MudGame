#include "Game.h"
#define EARTH SetConsoleTextAttribute(handle, FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY|BACKGROUND_BLUE);
#define DEFAULT SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN);

Game::Game ( )
{
    this->user = 0;
}

Game::~Game()
{
    delete this->commander;
    delete this->user;
}

void Game::_Logo()
{
    handle = GetStdHandle ( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute ( handle, FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE );
    cout << endl;
    DEFAULT cout << "                ";
    EARTH cout << ",ggddY///5443//Y3g," << endl;
    DEFAULT cout << "              ";
    EARTH cout << ".agd888b._ \"Y8. ___`\"\"Ybga." << endl;
    DEFAULT cout << "          ";
    EARTH cout << ".gdP\"\"88888888baa,\"\"8b    \"888g." << endl;
    DEFAULT cout << "        ";
    EARTH cout << ".dP\"     ]888888888P'  \"Y     `888Yb." << endl;
    DEFAULT cout << "      ";
    EARTH cout << ".dP\"      .88888888P\"  db.       \"8P\"\"Yb." << endl;
    DEFAULT cout << "     ";
    EARTH cout << ".8\"       .888888888b. d8888a           \"8." << endl;
    DEFAULT cout << "    ";
    EARTH cout << ".8'        d88888888888.88P\"' a.          `8." << endl;
    DEFAULT cout << "  ";
    EARTH cout << " .8'         88888888888888PP\"  \"\"           `8. " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " d'          I88888888888P\"                   `b " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " 8           `8\"88P\"\"Y8P'                      8 " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " 8            Y 8[  _ \"                        8 " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " 8              \"Y8d8b  \"Y a                   8 " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " 8                 `\"\"8d.   __                 8 " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " Y.                    `\"8bd888b.             .P " << endl;
    DEFAULT cout << "  ";
    EARTH cout << " `8.                     .d8888888baaa       .8' " << endl;
    DEFAULT cout << "    ";
    EARTH cout << "`8.                    888888888888'      .8'" << endl;
    DEFAULT cout << "     ";
    EARTH cout << "`8a                   \"8888888888I      a8'" << endl;
    DEFAULT cout << "    `  ";
    EARTH cout << "Yba                  `Y8888888P'    adP'" << endl;
    DEFAULT cout << "        ";
    EARTH cout << "\"Yba                 `888888P'   adY\"" << endl;
    DEFAULT cout << "          `";
    EARTH cout << "\"Yba.             d8888P\" .adP\"'" << endl;
    DEFAULT cout << "             ";
    EARTH cout << "`\"Y8baa.      .d888P.ad8P\"'" << endl;
    DEFAULT cout << "                  ";
    EARTH cout << "``\"\"YYba8888P\"\"''" << endl << endl;
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
}

void Game::_Narrative( )
{
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << endl;
    cout << " ----------------------------------------------------------------------- " << endl;
    cout << "|     ĳ�գ��ڼ��������ϵͳ���������յ���һ��Ī�����ʼ���              |" << endl;
    cout << "|  �ʼ���û�б��⡢����������û��IP��ַ���е�ֻ�Ƕ̶̵��ĸ���:          |" << endl
         << "|                                                                       |" << endl;
    cout << "|";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "                     �����Ե���                                      ";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << "|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|   �ڳ������м�����Ա����Ϊ��ֻ��һ��СС�Ķ����磬��û������          |" << endl
         << "|   ���Ƕ���ע�⡣����һ������ؼ��������籣���Ĺ�����ͨ��            |" << endl
         << "|   �˹����ܣ�������������Ÿ������񣬽��м�Ⲣ��ʱ�޸�����©����      |" << endl
         << "|  ���ƺ�������һ����û��̫��ĸı䣬������һ��ͻ���������ʼ���         |" << endl
         << "|  �����ʼ��ܿ�ͱ�ɾ�������е��˺ܿ춼���������������ķ�����         |" << endl
         << "|                                                                       |" << endl;
    cout << "|  �����������ַ��Լ������飩                                           |" << endl;
    getch();
    cout << "|                                                                       |" << endl;
    cout << "|      Ȼ������������ʼ��������23Сʱ59��59����������˶�           |" << endl
         << "|  ���벻�������鷢���ˣ�ȫ�����е������ʱ�䶼��������23Сʱ59��60�룬 |" << endl
         << "|  ���Ҳ����߶������������Ϊ������ϵͳ�������ĳ�����С���⣬           |" << endl
         << "|  �ܿ�����޸������ǣ���������Ա���볢�Խ����޸���ʱ��ȴ���֣�       |" << endl
         << "|  ���еļ��������ʱ�䶨�����һ˲�䣬���Ѿ�̱���������κεĿ��ƣ�     |" << endl
         << "|  ֧��ȫ���������ϵͳҲ���ܽ����κβ�����������Ա��������һ��ǰ�յ�   |" << endl
         << "|  ����һ���ţ�������û̿֡������Ϊ��һ��СС�Ķ����磬�ݱ����       |" << endl
         << "|  ȫ������ϵͳ��̱������������һ��Īչ��ʱ��һ�����˹����ܷ���       |" << endl
         << "|  ������ͨ������ɢ������������أ�                                     |" << endl
         << "|                                                                       |" << endl;
    cout << "|  �����������ַ��Լ������飩                                           |" << endl;
    getch();
    cout << "|                                                                       |" << endl;
    cout << "|";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "   ���������˹����ܣ������ڿ�ʼ����������������ˣ��������ǵ�ʱ������  ";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << "|" << endl
         << "|                                                                       |" << endl;
    cout << "|  ������еļ��������ͬһʱ��ִ����ͬһ���������������������     |" << endl
         << "|  �Լ����ж��������˹����ܡ������ˡ���������ݵĻ�е�豸����������     |" << endl
         << "|  ����Ŀ��ơ��෴�أ����Ƕ���������Ϊֹͨ��������е�һ�н��趼       |" << endl
         << "|  ���������ѡ���˴ݻ٣�ȡ����֮�����˹����������´�ĸ������       |" << endl
         << "|  �ɴ˿�ʼ���˹�������ʽ������������ܹ������ڶ̶̵ؼ������ڳɹ�     |" << endl
         << "|  �ؿ��������е�����......                                             |" << endl
         << "|                                                                       |" << endl;
    cout << "|     Ȼ�������ಢû�о��������˹������������������綼��̱��������      |" << endl
         << "|  ���ơ����ǣ���Ϊ���δ���Ļ��䡢������������ꡢ������ѧ�����㣬     |" << endl
         << "|  ��ãã�˺��������������ɹ�������ս���ܲ���ָ�ӵ�ע�⣬�ɹ�������     |" << endl
         << "|  ���˹�������Ȩ���ش����Σ�������Ű���λ��������ϸѡ�����ũ��     |" << endl
         << "|  ���ڽ�����һ���췭�ظ��ķ���Ȩ�˶����������ڼ������뿪ʼ��ı��ݣ�   |" << endl;
    cout << " -----------------------------------------------------------------------" << endl << endl;
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
}

bool Game::Init ( )
{
    string _choice;
    this->_Logo();
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_BLUE );
    cout << "***********************************************************" << endl;
    cout << "**********                                       **********" << endl;
    cout << "*********    ��ӭ���� INTERESTING WAR! ������     *********" << endl;
    cout << "*********   ���� 'plot' ������飬���� 'skip' ����   ******" << endl;
    cout << "**********                                       **********" << endl;
    cout << "***********************************************************" << endl;
    cout << "****" << endl << ">>" ;
    cin >> _choice;
    while ( true )
    {
        if ( _choice == "plot" )
        {
            this->_Narrative();
            break;
        }
        if ( _choice == "skip" )
        {
            cout << endl << "[*]��������" << endl;
            break;
        }
        else
        {
            cout << endl << "[!]���������: " << _choice << endl;
            cout << endl << ">>" ;
            cin >> _choice;
        }
    }
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    cout << endl << "+----------------+" << endl;
    cout << "|* ��¼[login]   |" << endl;
    cout << "|* ע��[register]|" << endl;
    cout << "|* �˳�[exit]    |" << endl;
    cout << "+----------------+" << endl;
    enum _CHOICE {_login, _regist, _exit};
    enum _CHOICE _choice_;
    while ( true )
    {
        string _choice;
        cout << endl << ">>";
        cin >> _choice;
        if ( _choice == string ( "login" ) )
        {
            _choice_ = _login;
            break;
        }
        else if ( _choice == string ( "register" ) )
        {
            _choice_ = _regist;
            break;
        }
        else if ( _choice == string ( "exit" ) )
        {
            _choice_ = _exit;
            break;
        }
        else
            cout << endl << "[!]���������: " << _choice << endl;
    }
    string _username, _password;
    bool _result = false;
    switch ( _choice_ )
    {
        case _login:
        {
            cout << endl << "*********�û���¼*********" << endl;
            cout << "�û���: ";
            cin >> _username;
            cout << endl << "����: ";
            cin >> _password;
            this->user = new User ( _username, _password );
            this->commander = new Commander ( this->user );
            if ( user->Login() )
            {
                cout << endl << "[*]��¼�ɹ���" << endl;
                cout << "**************************" << endl;
                _result = true;
            }
            else
            {
                cout << endl << "[!]������û��������룡" << endl << endl;
                if ( getch() )
                {
                    system ( "cls" );
                    delete this->user;
                    delete this->commander;
                    _result = false;
                }
            }
            break;
        }
        case _regist:
        {
            string _cpassword;
            cout << endl << "*********�û�ע��*********" << endl;
            cout << "�û���: ";
            cin >> _username;
            cout << endl << "����: ";
            cin >> _password;
            cout << endl << "ȷ������: ";
            cin >> _cpassword;
            this->user = new User ( _username, _password );
            this->commander = new Commander ( this->user );
            if ( _password == _cpassword )
            {
                if ( this->user->Register() )
                {
                    cout << endl << "[*]ע��ɹ���" << endl << endl;
                    cout << "**************************" << endl;
                    this->user->Login();
                    _result = true;
                }
                else
                {
                    cout << endl << "[!]�û����Ѵ��ڣ�" << endl << endl;
                    if ( getche() )
                    {
                        system ( "cls" );
                        delete this->user;
                        delete this->commander;
                        _result = false;
                    }
                }
            }
            else
            {
                cout << endl << "[!]������������벻һ����" << endl << endl;
                if ( getche() )
                {
                    system ( "cls" );
                    delete this->user;
                    delete this->commander;
                    _result = false;
                }
            }
            break;
        }
        case _exit:
            cout << endl << "[*]�˳���Ϸ" << endl;
            exit ( 0 );
    }
    return _result;
}

void Game::SelectArchive ( )
{
    cout << endl << "*********ѡ��浵*********" << endl;
    // Print archives
    cout << "1) ";
    this->user->SelectPlayer ( 1 );
    if ( this->user->player->GetName() == string ( "" ) )
        cout << "��" << endl;
    else
        cout << this->user->player->GetName() << endl;
    cout << "2) ";
    this->user->SelectPlayer ( 2 );
    if ( this->user->player->GetName() == string ( "" ) )
        cout << "��" << endl;
    else
        cout << this->user->player->GetName() << endl;
    cout << "3) ";
    this->user->SelectPlayer ( 3 );
    if ( this->user->player->GetName() == string ( "" ) )
        cout << "��" << endl;
    else
        cout << this->user->player->GetName() << endl;
    string _choice;
    short _choice_;
    while ( true )
    {
        cout << endl << ">>";
        cin >> _choice; // BUG
        if ( _choice == string ( "1" ) )
        {
            _choice_ = 1;
            break;
        }
        else if ( _choice == string ( "2" ) )
        {
            _choice_ = 2;
            break;
        }
        else if ( _choice == string ( "3" ) )
        {
            _choice_ = 3;
            break;
        }
        else
            cout << endl << "[*]δ֪�浵" << endl;
    }
    // Set arhcive name
    this->user->SelectPlayer ( _choice_ );
    if ( user->player->GetName() == string ( "" ) )
    {
        cout << "������浵����: ";
        string _arhcive_name;
        cin >> _arhcive_name;
        this->user->player->SetName ( _arhcive_name );
    }
    cout << endl << "[*]��ǰ�浵: " << this->user->player->GetName() << endl;
    cout << "**************************" << endl;
    getchar();
}

bool Game::Run ( )
{
    cout << endl << "[*]����'manual'�����Ϸ��ϸ����" << endl;
    while ( true )
    {
        if ( this->_Check() )
        {
            string cmd;
            cout << endl << "��������: " << endl << ">>";
            getline ( cin, cmd );
            if ( !this->commander->Eval ( cmd ) )
                cout << endl << "[!]���������: " << cmd << endl;
            if ( this->user->player->CheckWin() )
                this->commander->SetStatus ( _win_ );
            else if ( this->user->player->CheckLose() )
                this->commander->SetStatus ( _lose_ );
        }
        else
            break;
    }
    return true;
}

bool Game::_Check()
{
    bool _result = true;
    if ( this->commander->GetStatus() == _lose_ )
    {
        cout << endl << "[*]���ź���������Ϸ" << endl;
        this->user->player->ShowStatus();
        cout << endl << "[*]��������˳�" << endl;
        if ( getch() )
            _result = false;
    }
    if ( this->commander->GetStatus() == _win_ )
    {
        cout << endl << "[*]�㹧ϲ��Ӯ����Ϸ" << endl;
        this->user->player->ShowStatus();
        cout << endl << "[*]��������˳�" << endl;
        if ( getch() )
            _result = false;
    }
    if ( this->commander->GetStatus() == _quit )
    {
        cout << endl << "[*]����˳�" << endl;
        _result = false;
    }
    return _result;
}

void Game::Exit()
{
    cout << endl << "[*]��Ϸ����" << endl;
}
