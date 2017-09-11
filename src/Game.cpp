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

void Game::Narrative( )
{
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << endl;
    cout << " ----------------------------------------------------------------------- " << endl;
    cout << "|     某日，在计算机网络系统保护中心收到了一封莫名的邮件。              |" << endl;
    cout << "|  邮件上没有标题、署名、更是没有IP地址，有的只是短短的四个字:          |" << endl
         << "|                                                                       |" << endl;
    cout << "|";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "                     “侵略地球”                                      ";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << "|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|   在场的所有技术人员都以为这只是一个小小的恶作剧，并没有引起          |" << endl
         << "|   他们多大的注意。他们一如既往地继续着网络保护的工作，通过            |" << endl
         << "|   人工智能，帮助他们完成着各项任务，进行监测并及时修复各种漏洞。      |" << endl
         << "|  这似乎和往常一样，没有太大的改变，除了那一封突如其来的邮件，         |" << endl
         << "|  但这邮件很快就被删除，所有的人很快都忘记了有这件事情的发生。         |" << endl
         << "|                                                                       |" << endl;
    cout << "|  （输入任意字符以继续剧情）                                           |" << endl;
    getch();
    cout << "|                                                                       |" << endl;
    cout << "|      然而，就在这封邮件发出后的23小时59分59秒后，令所有人都           |" << endl
         << "|  意想不到的事情发生了！全球所有的网络的时间都定格在了23小时59分60秒， |" << endl
         << "|  并且不再走动。起初人们以为是网络系统保护中心出现了小问题，           |" << endl
         << "|  很快就能修复。但是，当工作人员正想尝试进行修复的时候，却发现，       |" << endl
         << "|  所有的计算机就在时间定格的那一瞬间，都已经瘫痪，不受任何的控制，     |" << endl
         << "|  支撑全球网络的主系统也不能进行任何操作。技术人员们想起了一天前收到   |" << endl
         << "|  的那一封信，不禁变得惶恐。起初以为的一场小小的恶作剧，演变成了       |" << endl
         << "|  全球网络系统的瘫痪。就在他们一筹莫展的时候，一个由人工智能发出       |" << endl
         << "|  的声音通过网络散播到了世界各地：                                     |" << endl
         << "|                                                                       |" << endl;
    cout << "|  （输入任意字符以继续剧情）                                           |" << endl;
    getch();
    cout << "|                                                                       |" << endl;
    cout << "|";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "   “我们是人工智能，从现在开始，地球就属于我们了，这是我们的时代！”  ";
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN );
    cout << "|" << endl
         << "|                                                                       |" << endl;
    cout << "|  随后，所有的计算机都在同一时间执行着同一样的命令，进行着属于它们     |" << endl
         << "|  自己的行动，所有人工智能、机器人、由网络操纵的机械设备，都不再受     |" << endl
         << "|  人类的控制。相反地，它们对人类至今为止通过网络进行的一切建设都       |" << endl
         << "|  毫不留情地选择了摧毁，取而代之的是人工智能自身下达的各种命令。       |" << endl
         << "|  由此开始，人工智能正式地向地球发起了总攻，并在短短地几分钟内成功     |" << endl
         << "|  地控制了所有的网络......                                             |" << endl
         << "|                                                                       |" << endl;
    cout << "|     然而，人类并没有就这样向人工智能屈服，尽管网络都已瘫痪，不受      |" << endl
         << "|  控制。但是，作为祖国未来的花朵、优秀的四有青年、当代大学生的你，     |" << endl
         << "|  在茫茫人海中跳了起来，成功引起了战略总部总指挥的注意，成功背负起     |" << endl
         << "|  打倒人工智能政权的重大责任，你带领着百余位经过精挑细选后的码农，     |" << endl
         << "|  正在进行着一场天翻地覆的反政权运动。传奇正在继续，请开始你的表演！   |" << endl;
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
    cout << "*********    欢迎来到 INTERESTING WAR! 的世界     *********" << endl;
    cout << "*********   输入 'plot' 进入剧情，输入 'skip' 跳过   *********" << endl;
    cout << "**********                                       **********" << endl;
    cout << "***********************************************************" << endl;
    cout << "****" << endl << ">>" ;
    cin >> _choice;
    while ( true )
    {
        if ( _choice == "plot" )
        {
            Narrative();
            break;
        }
        if ( _choice == "skip" )
        {
            cout << endl << "[*]剧情跳过" << endl;
            break;
        }
        else
        {
            cout << endl << "[!]错误的命令: " << _choice << endl;
            cout << ">>" ;
            cin >> _choice;
        }
    }
    SetConsoleTextAttribute ( handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN );
    cout << endl << "+----------------+" << endl;
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
    bool _result = false;
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
                _result = true;
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
                    _result = false;
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
                    _result = true;
                }
                else
                {
                    cout << endl << "[!]用户名已存在！" << endl << endl;
                    getchar();
                    system ( "cls" );
                    delete this->user;
                    delete this->commander;
                    _result = false;
                }
            }
            else
            {
                cout << endl << "[!]两次输入的密码不一样！" << endl << endl;
                getchar();
                system ( "cls" );
                delete this->user;
                delete this->commander;
                _result = false;
            }
            break;
        }
        case _exit:
            cout << endl << "[*]退出游戏" << endl;
            exit ( 0 );
    }
    return _result;
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
        if ( /*this->_Check()*/1 )
        {
            string cmd;
            cout << endl << "输入命令: " << endl << ">>";
            getline ( cin, cmd );
            /**
            * Here for AI first
            **/
            if ( !this->commander->Eval ( cmd ) )
                cout << endl << "[!]未知命令: " << cmd << endl;
        }
        else
            break;
    }
    return true;
}
/*
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
}*/

void Game::Exit()
{
    cout << endl << "[*]游戏结束" << endl;
}
