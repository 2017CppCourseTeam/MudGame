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
    cout << endl << "[*]��Ϸ����: " << endl;
    cout << "����һ�������������ս����Ϸ" << endl;
    cout << "���������Ҫͨ��ѵ�������Լ������ԣ�����һ����ս��������ȡʤ��" << endl;
    cout << "  �ʼ����ӵ�е�����ֵ�ֱ��ǣ�" << endl;
    cout << "     50������ֵ��ʿ�����ܹ�Ӱ��ս��ʱ������ֵ��" << endl;
    cout << "     10�����رң�����ѵ��������ս����" << endl;
    cout << "     50�㱩��ֵ��ս��������ֵ��" << endl;
    cout << "     10�������ֵ��������ֵС��0����Ϸʧ�ܣ�" << endl;
    cout << "  �����ͨ��������Ӧ���������ѵ����ս��" << endl;
    cout << "  ͨ��ѵ����ũ����������ֵ" << endl;
    cout << "  ͨ���ڿ󣬻�ñ��ر�" << endl;
    cout << "  ͨ������ϴ�ԣ���������ֵ" << endl;
    cout << "  ͨ������ս�������˸����ؿ���������յ�ʤ����" << endl;
    cout << endl << "[*]ȫ������: " << endl;
    cout << "manual         �����ϸ��Ϸ����" << endl;
    cout << "help           ��õ�ǰ�������" << endl;
    cout << "history        �����ʷ����" << endl;
    cout << "status         ��ʾ�û�״̬" << endl;
    cout << "current page   ��ʾ��ǰ����" << endl;
    cout << "[*]����������: " << endl;
    cout << "war            ��ʼս��" << endl;
    cout << "practice       ѵ��" << endl;
    cout << "save           ������Ϸ" << endl;
    cout << "exit           �˳���Ϸ" << endl;
    cout << "[*]ѵ����������: " << endl;
    cout << "train coder    ѵ����ũ" << endl;
    cout << "dig mine       �ڿ�" << endl;
    cout << "wash brain     ����ϴ��" << endl;
    cout << "back           ����������" << endl;
    cout << "[*]ս����������: " << endl;
    cout << "continue       ����ս��" << endl;
    cout << "restart        ���¿�ʼս��" << endl;
    cout << "back           ����������" << endl;
}

void Commander::_Current_Page()
{
    cout << endl << "[*]��ǰ����: ";
    switch ( this->status )
    {
    case _main:
        cout << "������" << endl;
        break;
    case practice:
        cout << "ѵ������" << endl;
        break;
    case war:
        cout << "ս������" << endl;
        break;
    }
}

void Commander::_Show_History()
{
    cout << endl << "[*]��ʷ����: " << endl;
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
            cout << endl << "[*]�����ѡ��: ս��[war], ѵ��[practice], ����[save], �˳�[exit]" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
        }
        else if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]ѵ������" << endl;
        }
        else if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]ս������" << endl;
        }
        else if ( cmd == string ( "save" ) )
        {
            if ( this->user->Save() )
                cout << endl << "[*]����ɹ�" << endl;
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
            cout << endl << "[*]�����ѡ��: ѵ��[train coder], �ڿ�[dig mine], ϴ��[wash brain], ����[back]" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
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
            cout << endl << "[*]����������" << endl;
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
            cout << endl << "[*]�����ѡ��: ���¿�ʼ[restart], ����[continue], ����[back]" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
            return true;
        }
        else if ( cmd == string ( "restart" ) )
        {
            string _choice;
            cout << endl << "[*]ȷ��Ҫ���¿�ʼ��(y/n)";
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]���¿�ʼս��" << endl;
                this->user->player->Restart_War();
            }
        }
        else if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]����ս��" << endl;
            this->user->player->Start_War();
            if (this->user->player->Get_War_Num() == 5)
                this->status = win;
        }
        else if ( cmd == string ( "back" ) )
        {
            this->status = _main;
            cout << endl << "[*]����������" << endl;
        }
        else
            return false;
        return true;
    }
}
