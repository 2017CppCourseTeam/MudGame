#include "Mudgame.h"
#include "commder.h"

bool Game::Init ( User*& user )
{
    cout << "�˹�����ͳ�ε���27391��֮��" << endl;
    cout << "���ǵ�����200�������Ҵ���֮һ" << endl;
    cout << "��ͼͨ��ɧ�������˹�������Ȩ" << endl << endl;
    cout << "1) ��¼" << endl;
    cout << "2) ע��" << endl;
    cout << "3) �˳�" << endl;
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
        cout << endl << "*********�û���¼*********" << endl;
        cout << "�û���: ";
        cin >> username;
        cout << endl << "����: ";
        cin >> password;
        user = new User ( username, password );
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
    case 2:
    {
        string cpassword;
        cout << "*********�û�ע��*********" << endl;
        cout << "�û���: ";
        cin >> username;
        cout << endl << "����: ";
        cin >> password;
        cout << endl << "ȷ������: ";
        cin >> cpassword;
        user = new User ( username, password );
        if ( password == cpassword )
        {
            if ( user->Register() )
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
    case 3:
        exit ( 0 );
    default:
        return false;
    }
}

void Game::Select_Archive ( User* user )
{
    cout << endl << "*********ѡ��浵*********" << endl;
    // Print archives
    cout << "1) ";
    user->Select_Player ( 1 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << user->player->Get_name() << endl;
    }
    cout << "2) ";
    user->Select_Player ( 2 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
    }
    else
    {
        cout << user->player->Get_name() << endl;
    }
    cout << "3) ";
    user->Select_Player ( 3 );
    if ( user->player->Get_name() == string ( "" ) )
    {
        cout << "��" << endl;
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
        cout << "������浵����: ";
        string _arhcive_name;
        cin >> _arhcive_name;
        user->player->Set_name ( _arhcive_name );
    }
    cout << endl << "��ǰ�浵: " << user->player->Get_name() << endl;
}

bool Game::Run ( User* user )
{
    while ( true )
    {
        string choice1;
        cout << "����Ҫ����ʲôɧ����?(����'help'���Խ��а���)" << endl;
        cin >> choice1;
        if ( choice1 == "help" )
        {
            cout << "���������'starwar'����ս�� ,'practice'����ѵ�� ,'end'�˳���Ϸ" << endl;
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
                cout << "����Ҫѵ��ʲô?(����'help'���Խ��а���)" << endl;
                cin >> choice2;
                if ( choice2 == "help" )
                {
                    cout << "���������'train'ѵ����ũ,'dig'�ڱ��ر�,'washbrain'����ϴ��,'return'����" << endl;
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
                    cout << "�����ڸ�����" << endl;
            }
        }
        else if ( choice1 == "end" )
            break;
        else
            cout << "�����ڸ�����" << endl;
    }
    return true;
}
