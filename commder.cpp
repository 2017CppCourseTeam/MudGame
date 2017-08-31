#include "commder.h"

Commder::Commder ( User*& user )
{
    this->status = main;
    this->user = user;
}

void Commder::_Show_Manual()
{
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

void Commder::_Current_Page()
{
    cout << endl << "[*]��ǰ����: ";
    switch ( this->status )
    {
    case main:
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

void Commder::_Show_History()
{
    cout << endl << "[*]��ʷ����: " << endl;
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
            cout << endl << "[*]�����ѡ��: ս��[war], ѵ��[practice], ����[save], �˳�[exit]" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
            return true;
        }
        if ( cmd == string ( "practice" ) )
        {
            this->status = practice;
            cout << endl << "[*]ѵ������" << endl;
            return true;
        }
        if ( cmd == string ( "war" ) )
        {
            this->status = war;
            cout << endl << "[*]ս������" << endl;
            return true;
        }
        if ( cmd == string ( "save" ) )
        {
            if ( this->user->Save() )
            {
                cout << endl << "[*]����ɹ�" << endl;
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
            cout << endl << "[*]�����ѡ��: ѵ��[train coder], �ڿ�[dig mine], ϴ��[wash brain], ����[back]" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
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
            cout << endl << "[*]����������" << endl;
            return true;
        }
        return false;
    }
    // War page
    if ( this->status == war )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]�����ѡ��: ���¿�ʼ[restart], ����[continue], ����[back]" << endl;
            cout << "[*]������Ӧ����ִ�в���" << endl;
            return true;
        }
        if ( cmd == string ( "restart" ) )
        {
            string _choice;
            cout << endl << "[*]ȷ��Ҫ���¿�ʼ��(y/N)";
            cin >> _choice;
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]���¿�ʼս��";
                this->user->player->Restart_War();
            }
            return true;
        }
        if ( cmd == string ( "continue" ) )
        {
            cout << endl << "[*]����ս��";
            this->user->player->Start_War();
            return true;
        }
        if ( cmd == string ( "back" ) )
        {
            this->status = main;
            cout << endl << "[*]����������" << endl;
            return true;
        }
        return false;
    }
}
