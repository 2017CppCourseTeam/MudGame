#include "commder.h"

Commder::Commder ( User*& user )
{
    this->status = main;
    this->user = user;
}

void Commder::_Show_Manual()
{
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

void Commder::_Current_Page()
{
    cout << endl << "[*]当前界面: ";
    switch ( this->status )
    {
    case main:
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

void Commder::_Show_History()
{
    cout << endl << "[*]历史命令: " << endl;
    for ( int i = this->history.size() - 1; i >= 0 ; i-- )
    {
        time_t now = time ( 0 );
        char* dt = ctime ( &now );
        cout << history[i] << "  --- " << dt << endl;
    }
}

bool Commder::Eval ( string& cmd )
{
    this->history.insert ( history.begin(), cmd );
    // Global command
    if ( cmd == string ( "status" ) )
    {
        this->user->player->Show_Status();
        return true;
    }
    if ( cmd == string ( "current page" ) )
    {
        this->_Current_Page();
        return true;
    }
    if ( cmd == string ( "manual" ) )
    {
        this->_Show_Manual();
        return true;
    }
    if ( cmd == string ( "history" ) )
    {
        this->_Show_History();
        return true;
    }
    // Main page
    if ( this->status == main )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: 战争[war], 训练[practice], 保存[save], 退出[exit]" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            return true;
        }
        if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]训练界面" << endl;
            return true;
        }
        if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]战争界面" << endl;
            return true;
        }
        if ( cmd == string ( "save" ) )
        {
            if ( this->user->Save() )
            {
                cout << endl << "[*]保存成功" << endl;
                return true;
            }
        }
        if ( cmd == string ( "exit" ) )
        {
            this->status = exit;
            return true;
        }
        return false;
    }
    // Practice page
    if  ( this->status == practice )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: 训练[train coder], 挖矿[dig mine], 洗脑[wash brain], 返回[back]" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            return true;
        }
        if ( cmd == string ( "train coder" ) )
        {
            this->user->player->Train_Coder();
            return true;
        }
        if ( cmd == string ( "dig mine" ) )
        {
            this->user->player->Dig_Mine();
            return true;
        }
        if ( cmd == string ( "wash brain" ) )
        {
            this->user->player->Wash_Brain();
            return true;
        }
        if ( cmd == string ( "back" ) )
        {
            this->status = main;
            cout << endl << "[*]返回主界面" << endl;
            return true;
        }
        return false;
    }
    // War page
    if ( this->status == war )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]你可以选择: 重新开始[restart], 继续[continue], 返回[back]" << endl;
            cout << "[*]输入相应命令执行操作" << endl;
            return true;
        }
        if ( cmd == string ( "restart" ) )
        {
            string _choice;
            cout << endl << "[*]确定要重新开始吗？(y/N)";
            cin >> _choice;
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]重新开始战争";
                this->user->player->Restart_War();
            }
            return true;
        }
        if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]继续战争";
            this->user->player->Start_War();
            return true;
        }
        if ( cmd == string ( "back" ) )
        {
            this->status = main;
            cout << endl << "[*]返回主界面" << endl;
            return true;
        }
        return false;
    }
}
