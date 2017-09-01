#include "Game.h"

Commander::Commander ( User*& user )
{
    this->status = _main;
    this->user = user;
}

enum STATUS Commander::Get_Status()
{
    return this->status;
}

void Commander::_Show_Manual()
{
    cout << endl << "[*]游戏介绍: " << endl;
    cout << "这是一个关于养成类的战争游戏" << endl;
    cout << "在这里，你需要通过训练提升自己的属性，攻克一个个战争，最后获取胜利" << endl;
    cout << "  最开始，你拥有的属性值分别是：" << endl;
    cout << "     50点威望值（士气，能够影响战斗时的能力值）" << endl;
    cout << "     10个比特币（用于训练、发动战争）" << endl;
    cout << "     50点暴力值（战斗的能力值）" << endl;
    cout << "     10秒的生命值（当生命值小于0则游戏失败）" << endl;
    cout << "  你可以通过输入相应的命令，进行训练与战争" << endl;
    cout << "  通过训练码农，提升暴力值" << endl;
    cout << "  通过挖矿，获得比特币" << endl;
    cout << "  通过政治洗脑，提升威望值" << endl;
    cout << "  通过发动战争，攻克各个关卡，获得最终的胜利！" << endl;
    cout << endl << "[*]全局命令: " << endl;
    cout << "manual         获得详细游戏帮助" << endl;
    cout << "help           获得当前界面帮助" << endl;
    cout << "history        获得历史命令" << endl;
    cout << "status         显示用户状态" << endl;
    cout << "current page   显示当前界面" << endl;
    cout << "[*]主界面命令: " << endl;
    cout << "war            开始战争" << endl;
    cout << "practice       训练" << endl;
    cout << "save           保存游戏" << endl;
    cout << "exit           退出游戏" << endl;
    cout << "[*]训练界面命令: " << endl;
    cout << "train coder    训练码农" << endl;
    cout << "dig mine       挖矿" << endl;
    cout << "wash brain     政治洗脑" << endl;
    cout << "back           返回主界面" << endl;
    cout << "[*]战争界面命令: " << endl;
    cout << "continue       继续战争" << endl;
    cout << "restart        重新开始战争" << endl;
    cout << "back           返回主界面" << endl;
}

void Commander::_Current_Page()
{
    cout << endl << "[*]当前界面: ";
    switch ( this->status )
    {
    case _main:
        cout << "主界面" << endl;
        break;
    case practice:
        cout << "训练界面" << endl;
        break;
    case war:
        cout << "战争界面" << endl;
        break;
    }
}

void Commander::_Show_History()
{
    cout << endl << "[*]历史命令: " << endl;
    for ( int i = this->history.size() - 1; i >= 0 ; i-- )
    {
        time_t now = time ( 0 );
        char* dt = ctime ( &now );
        cout << history[i] << "  --- " << dt << endl;
    }
}

bool Commander::Eval ( string& cmd )
{
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
    // Main page
    if ( this->status == _main )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: 战争[war], 训练[practice], 保存[save], 退出[exit]" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
        }
        else if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]训练界面" << endl;
        }
        else if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]战争界面" << endl;
        }
        else if ( cmd == string ( "save" ) )
        {
            if ( this->user->Save() )
                cout << endl << "[*]保存成功" << endl;
        }
        else if ( cmd == string ( "exit" ) )
        {
            this->status = quit;
        }
        else
            return false;
        return true;
    }
    // Practice page
    else if  ( this->status == practice )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: 训练[train coder], 挖矿[dig mine], 洗脑[wash brain], 返回[back]" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
        }
        else if ( cmd == string ( "train coder" ) )
        {
            this->user->player->Train_Coder();
        }
        else if ( cmd == string ( "dig mine" ) )
        {
            this->user->player->Dig_Mine();
        }
        else if ( cmd == string ( "wash brain" ) )
        {
            this->user->player->Wash_Brain();
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]返回主界面" << endl;
        }
        else
            return false;
        if ( this->user->player->Get_Second() == 0 )
            this->status = lose;
        return true;
    }
    // War page
    else if ( this->status == war )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: 重新开始[restart], 继续[continue], 返回[back]" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            return true;
        }
        else if ( cmd == string ( "restart" ) )
        {
            string _choice;
            cout << endl << "[*]确定要重新开始吗？(y/n)";
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]重新开始战争" << endl;
                this->user->player->Restart_War();
            }
        }
        else if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]继续战争" << endl;
            this->user->player->Start_War();
            if (this->user->player->Get_War_Num() == 5)
                this->status = win;
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]返回主界面" << endl;
        }
        else
            return false;
        return true;
    }
}
