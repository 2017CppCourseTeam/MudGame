#include "Mudgame.h"
#include "commder.h"

Game::Game ( User*& user )
{
    this->user = user;
}

bool Game::Init ( )
{
    cout << "�˹�����ͳ�ε���27391��֮��" << endl;
    cout << "���ǵ�����200�������Ҵ���֮һ" << endl;
    cout << "��ͼͨ��ɧ�������˹�������Ȩ" << endl << endl;
    cout << "��¼[login]" << endl;
    cout << "ע��[register]" << endl;
    cout << "�˳�[exit]" << endl;
    enum _CHOICE {login = 1, regist, exits};
    enum _CHOICE __choice;
    while ( true )
    {
        string _choice;
        cout << endl << ">>";
        cin >> _choice;
        if ( _choice == string ( "login" ) )
        {
            __choice = login;
            break;
        }
        else if ( _choice == string ( "register" ) )
        {
            __choice = regist;
            break;
        }
        else if ( _choice == string ( "exit" ) )
        {
            __choice = exits;
            break;
        }
        else
            cout << endl << "[!]���������: " << _choice << endl;
    }
    string username, password;
    switch ( __choice )
    {
    case login:
    {
        cout << endl << "*********�û���¼*********" << endl;
        cout << "�û���: ";
        cin >> username;
        cout << endl << "����: ";
        cin >> password;
        this->user = new User ( username, password );
        if ( user->Login() )
        {
            cout << endl << "[*]��¼�ɹ���" << endl << endl;
            return true;
        }
        else
        {
            cout << endl << "[!]������û��������룡" << endl << endl;
            return false;
        }
        break;
    }
    case regist:
    {
        string cpassword;
        cout << "*********�û�ע��*********" << endl;
        cout << "�û���: ";
        cin >> username;
        cout << endl << "����: ";
        cin >> password;
        cout << endl << "ȷ������: ";
        cin >> cpassword;
        this->user = new User ( username, password );
        if ( password == cpassword )
        {
            if ( this->user->Register() )
            {
                cout << endl << "[*]ע��ɹ���" << endl << endl;
                user->Login();
                return true;
            }
            else
            {
                cout << endl << "[!]�û����Ѵ��ڣ�" << endl << endl;
                return false;
            }
        }
        else
        {
            cout << endl << "[!]������������벻һ����" << endl << endl;
            return false;
        }
        break;
    }
    case exits:
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
    user->Select_Player ( 1 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "2) ";
    user->Select_Player ( 2 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "3) ";
    user->Select_Player ( 3 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    int _choice;
    while ( true )
    {
        cout << ">>";
        cin >> _choice; // BUG
        if ( ( int ( _choice ) >= 1 && int ( _choice ) <= 3 ) || ( char ( _choice ) >= '1' && char ( _choice ) <= '3' ) )
            break;
        else
            cout << endl << "[*]δ֪�浵" << endl;
    }
    // Set arhcive name
    user->Select_Player ( _choice );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "������浵����: ";
        string _arhcive_name;
        cin >> _arhcive_name;
        this->user->player->Set_name ( _arhcive_name );
    }
    cout << endl << "[*]��ǰ�浵: " << this->user->player->Get_name() << endl;
    getchar();
}

bool Game::Run ( )
{
    Commder commder ( this->user );
    cout << endl << "[*]����'manual'�����Ϸ��ϸ����" << endl;
    while ( true )
    {
        if ( commder.status == Commder::exit )
            break;
        string cmd;
        cout << endl << "��������: " << endl << ">>";
        getline ( cin, cmd );
        if ( !commder.Eval ( cmd ) )
            cout << endl << "[!]δ֪����: " << cmd << endl;
    }
    return true;
}

void Game::Exit()
{
    cout << endl << "[*]�˳���Ϸ" << endl;
    delete this->user;
}
