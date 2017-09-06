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
    cout << endl << "$$$$$$$$$$$$$$$$$$$$$$$$e$$$$$$$$beee,       \"*$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$P\"\"     \"*$$$$\"\"$b.       \"$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$\"            \"$F   *$$$c      ^*$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$P              dP     ^$$$$c      ^*$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$\"              J$      $$$$$$b       \"$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$P       .eeee.  4$      $$$$$$$$b       ^$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$F      .d$$$$$$$b$\"     d$$$$$$$$$r       ^$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$P      d$$$$$$$$$$%     J$$$$$$$$$$$        3$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$      $$$$$$$$$$$F     4$\" \"$$$$$$$$         $$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$F     $$$$$$$$$$$P     .$%   ^*$$$$$$         $$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$F    4$$$$$$$$$$$eeeeee$$.     ^$c            $$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$F    $$$$               \"$b      \"$c         J$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$    $$$%                 *$c      *$.     .d$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$b   '$P                   ^$$.     ^$$$$$$$$$$*$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$.  *$$$$$$$$\"\"\"\"\"\"\"$$$$$$$$$b      \"$$$$$$$\"4$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$e  $$$$$$$%       $$$$$$$$$$$c      *$$$P\" $$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$b.*$$$$$        ^$$$$$$$$$$$$$$$$$$$P\"  4$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$.         \"**$$$$$$$$$$$*\"\"    4$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.                            d$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$c                        .d$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$c.              ,ee$$$$$$$$$$$$$$" << endl << endl;
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
