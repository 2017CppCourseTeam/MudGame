#include "Game.h"

Game::Game ( User*& user )
{
    this->user = user;
}

Game::~Game()
{
    delete this->commander;
    delete this->user;
}

void Game::_Logo()
{
    cout << endl << "               ,ggddY\"\"\"Ybbgg," << endl;
    cout << "          .agd888b._ \"Y8. ___`\"\"Ybga." << endl;
    cout << "        .gdP\"\"88888888baa,\"\"8b    \"888g." << endl;
    cout << "      .dP\"     ]888888888P'  \"Y     `888Yb." << endl;
    cout << "    .dP\"      .88888888P\"  db.       \"8P\"\"Yb." << endl;
    cout << "   .8\"       .888888888b. d8888a           \"8." << endl;
    cout << "  .8'        d88888888888.88P\"' a.          `8." << endl;
    cout << " .8'         88888888888888PP\"  \"\"           `8." << endl;
    cout << " d'          I88888888888P\"                   `b" << endl;
    cout << " 8           `8\"88P\"\"Y8P'                      8" << endl;
    cout << " 8            Y 8[  _ \"                        8" << endl;
    cout << " 8              \"Y8d8b  \"Y a                   8" << endl;
    cout << " 8                 `\"\"8d.   __                 8" << endl;
    cout << " Y.                    `\"8bd888b.             .P" << endl;
    cout << " `8.                     .d8888888baaa       .8'" << endl;
    cout << "  `8.                    888888888888'      .8'" << endl;
    cout << "   `8a                   \"8888888888I      a8'" << endl;
    cout << "    `Yba                  `Y8888888P'    adP'" << endl;
    cout << "      \"Yba                 `888888P'   adY\"" << endl;
    cout << "        `\"Yba.             d8888P\" .adP\"'" << endl;
    cout << "           `\"Y8baa.      .d888P.ad8P\"'" << endl;
    cout << "                ``\"\"YYba8888P\"\"''" << endl << endl;
}

bool Game::Init ( )
{
    this->_Logo();
    cout << "�˹�����ͳ�ε���27391��֮��" << endl;
    cout << "���ǵ�����200�������Ҵ���֮һ" << endl;
    cout << "��ͼͨ��ɧ�������˹�������Ȩ" << endl << endl;
    cout << "+----------------+" << endl;
    cout << "|* ��¼[login]   |" << endl;
    cout << "|* ע��[register]|" << endl;
    cout << "|* �˳�[exit]    |" << endl;
    cout << "+----------------+" << endl;
    enum _CHOICE {login, regist, _exit};
    enum _CHOICE _choice_;
    while ( true )
    {
        string _choice;
        cout << endl << ">>";
        cin >> _choice;
        if ( _choice == string ( "login" ) )
        {
            _choice_ = login;
            break;
        }
        else if ( _choice == string ( "register" ) )
        {
            _choice_ = regist;
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
    string username, password;
    switch ( _choice_ )
    {
        case login:
            {
                cout << endl << "*********�û���¼*********" << endl;
                cout << "�û���: ";
                cin >> username;
                cout << endl << "����: ";
                cin >> password;
                this->user = new User ( username, password );
                this->commander = new Commander ( this->user );
                if ( user->Login() )
                {
                    cout << endl << "[*]��¼�ɹ���" << endl;
                    cout << "**************************" << endl;
                    return true;
                }
                else
                {
                    cout << endl << "[!]������û��������룡" << endl << endl;
                    getchar();
                    if ( getch() )
                    {
                        system ( "cls" );
                        delete this->user;
                        delete this->commander;
                        return false;
                    }
                }
                break;
            }
        case regist:
            {
                string cpassword;
                cout << endl << "*********�û�ע��*********" << endl;
                cout << "�û���: ";
                cin >> username;
                cout << endl << "����: ";
                cin >> password;
                cout << endl << "ȷ������: ";
                cin >> cpassword;
                this->user = new User ( username, password );
                this->commander = new Commander ( this->user );
                if ( password == cpassword )
                {
                    if ( this->user->Register() )
                    {
                        cout << endl << "[*]ע��ɹ���" << endl << endl;
                        cout << "**************************" << endl;
                        user->Login();
                        return true;
                    }
                    else
                    {
                        cout << endl << "[!]�û����Ѵ��ڣ�" << endl << endl;
                        getchar();
                        system ( "cls" );
                        delete this->user;
                        delete this->commander;
                        return false;
                    }
                }
                else
                {
                    cout << endl << "[!]������������벻һ����" << endl << endl;
                    getchar();
                    system ( "cls" );
                    delete this->user;
                    delete this->commander;
                    return false;
                }
                break;
            }
        case _exit:
            cout << endl << "[*]�˳���Ϸ" << endl;
            exit ( 0 );
        default:
            return false;
    }
}

void Game::Select_Archive ( )
{
    cout << endl << "*********ѡ��浵*********" << endl;
    // Print archives
    cout << "1) ";
    this->user->Select_Player ( 1 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "2) ";
    this->user->Select_Player ( 2 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "3) ";
    this->user->Select_Player ( 3 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    string _choice;
    short _choice_;
    while ( true )
    {
        cout << ">>";
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
    this->user->Select_Player ( _choice_ );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "������浵����: ";
        string _arhcive_name;
        cin >> _arhcive_name;
        this->user->player->Set_name ( _arhcive_name );
    }
    cout << endl << "[*]��ǰ�浵: " << this->user->player->Get_name() << endl;
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
                cout << endl << "[!]δ֪����: " << cmd << endl;
        }
        else
            break;
    }
    return true;
}

bool Game::_Check()
{
    if ( this->commander->Get_Status() == lose )
    {
        cout << endl << "[*]������" << endl;
        this->user->player->Show_Status();
        cout << endl << "[*]��������˳�" << endl;
        if ( getch() )
            return false;
    }
    if ( this->commander->Get_Status() == win )
    {
        cout << endl << "[*]��Ӯ��" << endl;
        this->user->player->Show_Status();
        cout << endl << "[*]��������˳�" << endl;
        if ( getch() )
            return false;
    }
    if ( this->commander->Get_Status() == quit )
    {
        cout << endl << "[*]����˳�" << endl;
        return false;
    }
    return true;
}

void Game::Exit()
{
    cout << endl << "[*]��Ϸ����" << endl;
}
