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
    cout << "人工智能统治地球27391年之后" << endl;
    cout << "你是地球上200个人类幸存者之一" << endl;
    cout << "企图通过骚操作打倒人工智能政权" << endl << endl;
    cout << "+----------------+" << endl;
    cout << "|* 登录[login]   |" << endl;
    cout << "|* 注册[register]|" << endl;
    cout << "|* 退出[exit]    |" << endl;
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
            cout << endl << "[!]错误的命令: " << _choice << endl;
    }
    string username, password;
    switch ( _choice_ )
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
                        system ( "cls" );
                        delete this->user;
                        delete this->commander;
                        return false;
                    }
                }
                else
                {
                    cout << endl << "[!]两次输入的密码不一样！" << endl << endl;
                    getchar();
                    system ( "cls" );
                    delete this->user;
                    delete this->commander;
                    return false;
                }
                break;
            }
        case _exit:
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
    this->user->Select_Player ( 1 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "2) ";
    this->user->Select_Player ( 2 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << this->user->player->Get_name() << endl;
    }
    cout << "3) ";
    this->user->Select_Player ( 3 );
    if ( this->user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
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
            cout << endl << "[*]未知存档" << endl;
    }
    // Set arhcive name
    this->user->Select_Player ( _choice_ );
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
        this->user->player->Show_Status();
        cout << endl << "[*]按任意键退出" << endl;
        if ( getch() )
            return false;
    }
    if ( this->commander->Get_Status() == win )
    {
        cout << endl << "[*]你赢了" << endl;
        this->user->player->Show_Status();
        cout << endl << "[*]按任意键退出" << endl;
        if ( getch() )
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
