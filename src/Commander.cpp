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

template <class T>
T Commander::_ConvertStringToNum ( const string& str )
{
    istringstream iss ( str );
    T num;
    iss >> num;
    return num;
}


void Commander::_Show_Manual()
{
    HANDLE handle;

    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED |BACKGROUND_GREEN | FOREGROUND_GREEN);
    cout << endl;
    cout << "                                                                   " << endl;
    cout << "[*]��Ϸ����:                                                       " << endl;
    cout << "����һ�������������ս����Ϸ                                       " << endl;
    cout << "���������Ҫͨ��ѵ�������Լ������ԣ�����һ����ս��������ȡʤ�� " << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "|  �ʼ����ӵ�е�����ֵ�ֱ��ǣ�                 |" << endl;
    cout << "|    * 50������ֵ��ʿ�����ܹ�Ӱ��ս��ʱ������ֵ�� |" << endl;
    cout << "|    * 10�����رң�����ѵ��������ս����           |" << endl;
    cout << "|    * 50�㱩��ֵ��ս��������ֵ��                 |" << endl;
    cout << "|    * 10�������ֵ��������ֵС��0����Ϸʧ�ܣ�    |" << endl;
    cout << "+-------------------------------------------------+" << endl;
<<<<<<< HEAD:src/Commander.cpp
    cout << "  �����ͨ��������Ӧ���������ѵ����ս��" << endl;
    cout << "  ͨ��ѵ����ũ����������ֵ" << endl;
    cout << "  ͨ���ڿ󣬻�ñ��ر�" << endl;
    cout << "  ͨ������ϴ�ԣ���������ֵ" << endl;
    cout << "  ͨ������ս�������˸����ؿ���������յ�ʤ����" << endl << endl;
    cout << "�����������" << endl;
    if ( getch() )
=======
    cout << "  �����ͨ��������Ӧ���������ѵ����ս��    " << endl;
    cout << "  ͨ��ѵ����ũ����������ֵ                    " << endl;
    cout << "  ͨ���ڿ󣬻�ñ��ر�                        " << endl;
    cout << "  ͨ������ϴ�ԣ���������ֵ                    " << endl;
    cout << "  ͨ������ս�������˸����ؿ���������յ�ʤ����" << endl;
    cout << "                                              "<< endl;
    SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
    cout << "�����������"<< endl;
    if (getchar())
>>>>>>> origin/master:Commander.cpp
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | FOREGROUND_GREEN);
        cout << "+----------------------------------+" << endl;
        cout << "|[*]ȫ������:                      |" << endl;
        cout << "|manual         �����ϸ��Ϸ����   |" << endl;
        cout << "|help           ��õ�ǰ�������   |" << endl;
        cout << "|history        �����ʷ����       |" << endl;
        cout << "|status         ��ʾ�û�״̬       |" << endl;
        cout << "|save           ������Ϸ           |" << endl;
        cout << "|current page   ��ʾ��ǰ����       |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]����������:                    |" << endl;
        cout << "|war            ��ʼս��           |" << endl;
        cout << "|practice       ѵ��               |" << endl;
        cout << "|exit           �˳���Ϸ           |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]ѵ����������:                  |" << endl;
        cout << "|train coder    ѵ����ũ           |" << endl;
        cout << "|dig mine       �ڿ�               |" << endl;
        cout << "|wash brain     ����ϴ��           |" << endl;
        cout << "|back           ����������         |" << endl;
        cout << "+----------------------------------+" << endl;
        cout << "|[*]ս����ʼ��������:              |" << endl;
        cout << "|continue       ����ս��           |" << endl;
        cout << "|restart        ���¿�ʼս��       |" << endl;
        cout << "|back           ����������         |" << endl;
        cout << "+----------------------------------+" << endl;
<<<<<<< HEAD:src/Commander.cpp
        cout << "|[*]ս����������:                  |" << endl;
        cout << "+----------------------------------+" << endl;
=======
        SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY|BACKGROUND_BLUE);
>>>>>>> origin/master:Commander.cpp
    }
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
        case start_war:
        case war:
            cout << "ս������" << endl;
            break;
    }
}

void Commander::_Show_History()
{
    cout << endl << "[*]��ʷ����: " << endl;
    for ( int i = this->history.size() - 1; i >= 0 ; i-- )
        cout << history[i] << endl;
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
    else if ( cmd == string ( "save" ) )
    {
        if ( this->user->Save() )
            cout << endl << "[*]����ɹ�" << endl;
        return true;
    }
    // Main page
    if ( this->status == _main )
    {
        if ( cmd == string ( "help" ) )
        {
            cout << endl << "[*]�����ѡ��: " << endl;
            cout << "+-----------------+" << endl;
            cout << "|* ѵ��[practice] |" << endl;
            cout << "|* ս��[war]      |" << endl;
            cout << "|* �˳�[exit]     |" << endl;
            cout << "+-----------------+" << endl;
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
            cout << endl << "[*]�����ѡ��: " << endl;
            cout << "+---------------------+" << endl;
            cout << "|* ѵ��[train coder]  |" << endl;
            cout << "|* �ڿ�[dig mine]     |" << endl;
            cout << "|* ϴ��[wash brain]   |" << endl;
            cout << "|* ����[back]         |" << endl;
            cout << "+---------------------+" << endl;
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
            cout << endl << "[*]�����ѡ��: " << endl;
            cout << "+---------------------+" << endl;
            cout << "|* ���¿�ʼ[restart]  |" << endl;
            cout << "|* ����[continue]     |" << endl;
            cout << "|* ����[back]         |" << endl;
            cout << "+---------------------+" << endl;
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
            this->status = start_war;
            this->user->player->Start_War();
            cout << endl << "[*]��ǰ�ؿ�: " << this->user->player->Get_War_Num() << endl;
            this->user->player->Show_Status();
            this->user->player->Show_War_Status();
            this->user->player->Show_Map ( true );
            cout << "[*]ȷ�Ͽ�ʼ��(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice != string ( "y" ) && _choice != string ( "Y" ) )
            {
                this->status = war;
                this->user->player->End_War();
            }
            else
            {
                cout << endl << "[*]ս����ʼ";
                this->user->ai = new Player();
                bool _first = this->user->player->Is_First();
                switch ( this->user->player->Get_War_Num() )
                {
                    case 1:
                        {
                            this->user->ai->Ai_Init ( AI_PRESTIGE_1, AI_BITCOIN_1, AI_VIOLENCE_1, AI_SECOND_1, 1, !_first );
                            break;
                        }
                    case 2:
                        {
                            this->user->ai->Ai_Init ( AI_PRESTIGE_2, AI_BITCOIN_2, AI_VIOLENCE_2, AI_SECOND_2, 2, !_first );
                            break;
                        }
                    case 3:
                        {
                            this->user->ai->Ai_Init ( AI_PRESTIGE_3, AI_BITCOIN_3, AI_VIOLENCE_3, AI_SECOND_3, 3, !_first );
                            break;
                        }
                    case 4:
                        {
                            this->user->ai->Ai_Init ( AI_PRESTIGE_4, AI_BITCOIN_4, AI_VIOLENCE_4, AI_SECOND_4, 4, !_first );
                            break;
                        }
                    case 5:
                        {
                            this->user->ai->Ai_Init ( AI_PRESTIGE_5, AI_BITCOIN_5, AI_VIOLENCE_5, AI_SECOND_5, 5, !_first );
                            break;
                        }
                }
                this->user->ai->Start_War();
            }
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
    else if ( this->status == start_war )
    {
        //this->user->player->Show_War_Status();
        //this->user->player->Show_Map ( false );
        if ( cmd == string ( "exit" ) )
        {
            cout << endl << "[*]������Ϸ�����ᱻ���棬Ҳ�������κν�����ȷ���˳���(y/n)" << endl << ">>";
            string _choice;
            cin >> _choice;
            getchar();
            if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            {
                cout << endl << "[*]�˳�ս��" << endl;
                this->user->player->End_War();
                this->status = war;
                return true;
            }
            else
                return false;
        }
        else if ( cmd == string ( "help" ) )
        {
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "show" ) )
        {
            if ( cmd.substr ( 4, 1 ) == string ( " " ) )
            {
                string subcmd = cmd.substr ( 5 );
                if ( subcmd == string ( "status" ) )
                {
                    this->user->player->Show_War_Status();
                }
                else if ( subcmd == string ( "map" ) )
                {
                    this->user->player->Show_Map ( true );
                }
                else if ( subcmd == string ( "all" ) )
                {
                    this->user->player->Show_War_Status();
                    this->user->player->Show_Map ( true );
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if ( cmd.substr ( 0, 6 ) == string ( "select" ) )
        {
            if ( cmd.substr ( 0 + 6, 1 ) == string ( " " ) )
            {
                if ( cmd.substr ( 0 + 6 + 1, 8 ) == string ( "building" ) )
                {
                    if ( cmd.substr ( 0 + 6 + 1 + 8, 1 ) == string ( " " ) )
                    {
                        string _subcmd = cmd.substr ( 0 + 6 + 1 + 8 + 1, 3 );
                        if ( _subcmd.substr ( 1, 1 ) == string ( "," ) )
                        {
                            unsigned int _x = this->_ConvertStringToNum<unsigned int> ( _subcmd.substr ( 0, 1 ) );
                            unsigned int _y = this->_ConvertStringToNum<unsigned int> ( _subcmd.substr ( 2, 1 ) );
                            this->user->player->Select_Point ( _x, _y );
                            this->user->player->Show_Ponit_Status();
                        }
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else if ( cmd.substr ( 0 + 6 + 1, 7 ) == string ( "soldier" ) )
                {
                    if ( cmd.substr (  0 + 6 + 1 + 7, 1 ) == string ( " " ) )
                    {
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return false;
        }
        else if ( cmd.substr ( 0, 4 ) == string ( "move" ) )
        {
            if ( cmd.substr ( 0 + 4, 1 ) == string ( " " ) )
            {
            }
            else
                return false;
        }
        else if ( cmd.substr ( 0, 7 ) == string ( "produce" ) )
        {
            if ( cmd.substr ( 0 + 7, 1 ) == string ( " " ) )
            {
            }
            else
                return false;
        }
        else
            return false;
        return true;
    }
}
