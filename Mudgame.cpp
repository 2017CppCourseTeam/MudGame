#include "Mudgame.h"

bool Game::Init_User(User* user)
{
    cout << "�˹�����ͳ�ε���27391��֮��" << endl;
    cout << "���ǵ�����200�������Ҵ���֮һ" << endl;
    cout << "��ͼͨ��ɧ�������˹�������Ȩ" << endl << endl;
    cout << "1) ��¼" << endl;
    cout << "2) ע��" << endl;
    int choice = -1;
    do {
        cout << ">>";
        cin >> choice;
    } while ( choice == -1 );
    string username, password;
    switch ( choice ) {
    case 1: {
            cout << endl << "*********�û���¼*********" << endl;
            cout << "�û���: ";
            cin >> username;
            cout << endl << "����: ";
            cin >> password;
            user = new User ( username, password );
            if ( user->Login() ) {
                cout << "[*]��¼�ɹ���" << endl;
                return true;
            } else {
                cout << "[!]������û��������룡" << endl;
                return false;
            }
            break;
        }
    case 2: {
            string cpassword;
            cout << "*********�û�ע��*********" << endl;
            cout << "�û���: ";
            cin >> username;
            cout << endl << "����: ";
            cin >> password;
            cout << endl << "ȷ������: ";
            cin >> cpassword;
            user = new User ( username, password );
            if ( password == cpassword ) {
                if ( user->Register() ) {
                    cout << "[*]ע��ɹ���" << endl;
                    user->Login();
                    return true;
                } else {
                    cout << "[!]�û����Ѵ��ڣ�" << endl;
                    return false;
                }
            } else {
                cout << "[!]������������벻һ����" << endl;
                return false;
            }
            break;
        }
    }
}
