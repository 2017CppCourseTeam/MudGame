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

bool Game::Init ( )
{
    HANDLE handle;

    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "人工智能统治地球27391年之后" << endl;
    cout << "你是地球上200个人类幸存者之一" << endl;
    cout << "企图通过骚操作打倒人工智能政权" << endl << endl;
    SetConsoleTextAttribute(handle, BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_BLUE);
    cout << " +----------------+ " << endl;
    cout << " |* 登录[login]   | " << endl;
    cout << " |* 注册[register]| " << endl;
    cout << " |* 退出[exit]    | " << endl;
    cout << " +----------------+ " << endl;
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
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
            cout << endl << "[!]错误的命令: " << _choice << endl;
    }
    string username, password;
    switch ( __choice )
    {
    case login:
    {
        cout << endl << "*********用户登录*********" << endl;
        cout << "用户名: ";
        cin >> username;
        cout << endl << "密码: ";
        cin >> password;
        this->user = new User ( username, password );
        this->commander = new Commander ( this->user );
        if ( user->Login() )
        {
            cout << endl << "[*]登录成功！" << endl;
            cout << "**************************" << endl;
            return true;
        }
        else
        {
            cout << endl << "[!]错误的用户名或密码！" << endl << endl;
            getchar();
            system("cls");
            return false;
        }
        break;
    }
    case regist:
    {
        string cpassword;
        cout << endl << "*********用户注册*********" << endl;
        cout << "用户名: ";
        cin >> username;
        cout << endl << "密码: ";
        cin >> password;
        cout << endl << "确认密码: ";
        cin >> cpassword;
        this->user = new User ( username, password );
        this->commander = new Commander ( this->user );
        if ( password == cpassword )
        {
            if ( this->user->Register() )
            {
                cout << endl << "[*]注册成功！" << endl << endl;
                cout << "**************************" << endl;
                user->Login();
                return true;
            }
            else
            {
                cout << endl << "[!]用户名已存在！" << endl << endl;
                getchar();
                system("cls");
                return false;
            }
        }
        else
        {
            cout << endl << "[!]两次输入的密码不一样！" << endl << endl;
            getchar();
            system("cls");
            return false;
        }
        break;
    }
    case exits:
        cout << endl << "[*]退出游戏" << endl;
        exit ( 0 );
    default:
        return false;
    }
}

void Game::Select_Archive ( )
{
    cout << endl << "*********选择存档*********" << endl;
    // Print archives
    cout << "1) ";
    user->Select_Player ( 1 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "2) ";
    user->Select_Player ( 2 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "3) ";
    user->Select_Player ( 3 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
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
            cout << endl << "[*]未知存档" << endl;
    }
    // Set arhcive name
    user->Select_Player ( _choice );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "请输入存档名称: ";
        string _arhcive_name;
        cin >> _arhcive_name;
        this->user->player->Set_name ( _arhcive_name );
    }
    cout << endl << "[*]当前存档: " << this->user->player->Get_name() << endl;
    cout << "**************************" << endl;
    getchar();
}

bool Game::Run ( )
{
    cout << endl << "[*]输入'manual'获得游戏详细帮助" << endl;
    while ( true )
    {
        if ( this->_Check() )
        {
            string cmd;
            cout << endl << "输入命令: " << endl << ">>";
            getline ( cin, cmd );
            if ( !this->commander->Eval ( cmd ) )
                cout << endl << "[!]未知命令: " << cmd << endl;
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
        cout << endl << "[*]你输了" << endl;
        return false;
    }
    if ( this->commander->Get_Status() == win )
    {
        cout << endl << "[*]你赢了" << endl;
        return false;
    }
    if ( this->commander->Get_Status() == quit )
    {
        cout << endl << "[*]玩家退出" << endl;
        return false;
    }
    return true;
}

void Game::Exit()
{
    cout << endl << "[*]游戏结束" << endl;
}
