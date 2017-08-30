#include "Mudgame.h"
#include "commder.h"

bool Game::Init ( User*& user )
{
    cout << "人工智能统治地球27391年之后" << endl;
    cout << "你是地球上200个人类幸存者之一" << endl;
    cout << "企图通过骚操作打倒人工智能政权" << endl << endl;
    cout << "1) 登录" << endl;
    cout << "2) 注册" << endl;
    cout << "3) 退出" << endl;
    int choice = -1;
    do
    {
        cout << ">>";
        cin >> choice;
    }
    while ( choice == -1 );
    string username, password;
    switch ( choice )
    {
    case 1:
    {
        cout << endl << "*********用户登录*********" << endl;
        cout << "用户名: ";
        cin >> username;
        cout << endl << "密码: ";
        cin >> password;
        user = new User ( username, password );
        if ( user->Login() )
        {
            cout << endl << "[*]登录成功！" << endl << endl;
            return true;
        }
        else
        {
            cout << endl << "[!]错误的用户名或密码！" << endl << endl;
            return false;
        }
        break;
    }
    case 2:
    {
        string cpassword;
        cout << "*********用户注册*********" << endl;
        cout << "用户名: ";
        cin >> username;
        cout << endl << "密码: ";
        cin >> password;
        cout << endl << "确认密码: ";
        cin >> cpassword;
        user = new User ( username, password );
        if ( password == cpassword )
        {
            if ( user->Register() )
            {
                cout << endl << "[*]注册成功！" << endl << endl;
                user->Login();
                return true;
            }
            else
            {
                cout << endl << "[!]用户名已存在！" << endl << endl;
                return false;
            }
        }
        else
        {
            cout << endl << "[!]两次输入的密码不一样！" << endl << endl;
            return false;
        }
        break;
    }
    case 3:
        exit ( 0 );
    default:
        return false;
    }
}

void Game::Select_Archive ( User* user )
{
    cout << endl << "*********选择存档*********" << endl;
    // Print archives
    cout << "1) ";
    user->Select_Player ( 1 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << user->player->Get_name() << endl;
    }
    cout << "2) ";
    user->Select_Player ( 2 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << user->player->Get_name() << endl;
    }
    cout << "3) ";
    user->Select_Player ( 3 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "无" << endl;
    }
    else
    {
        cout << user->player->Get_name() << endl;
    }
    int _choice = -1;
    do
    {
        cout << ">>";
        cin >> _choice;
    }
    while ( ! ( _choice >= 1 && _choice <= 3 ) );
    // Set arhcive name
    user->Select_Player ( _choice );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "请输入存档名称: ";
        string _arhcive_name;
        cin >> _arhcive_name;
        user->player->Set_name ( _arhcive_name );
    }
    cout << endl << "当前存档: " << user->player->Get_name() << endl;
}

bool Game::Run ( User* user )
{
    while ( true )
    {
        string choice1;
        cout << "你想要进行什么骚操作?(输入'help'可以进行帮助)" << endl;
        cin >> choice1;
        if ( choice1 == "help" )
        {
            cout << "你可以输入'starwar'进行战争 ,'practice'进行训练 ,'end'退出游戏" << endl;
        }
        else if ( choice1 == "starwar" )
        {
            // user->player.StartWar()
        }
        else if ( choice1 == "practice" )
        {
            while ( true )
            {
                string choice2;
                cout << "你想要训练什么?(输入'help'可以进行帮助)" << endl;
                cin >> choice2;
                if ( choice2 == "help" )
                {
                    cout << "你可以输入'train'训练码农,'dig'挖比特币,'washbrain'政治洗脑,'return'返回" << endl;
                }
                else if ( choice2 == "train" )
                {
                    user->player->TrainCoder();
                    user->player->showStatus();
                }
                else if ( choice2 == "dig" )
                {
                    user->player->DigMine();
                    user->player->showStatus();
                }
                else if ( choice2 == "washbrain" )
                {
                    user->player->WashBrain();
                    user->player->showStatus();
                }
                else if ( choice2 == "return" )
                    break;
                else
                    cout << "不存在该命令" << endl;
            }
        }
        else if ( choice1 == "end" )
            break;
        else
            cout << "不存在该命令" << endl;
    }
    return true;
}
