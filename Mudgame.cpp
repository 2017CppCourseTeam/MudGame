#include "Mudgame.h"

void Game::Run()
{
    cout << "�˹�����ͳ�ε���27391��֮��" << endl;
    cout << "���ǵ�����200�������Ҵ���֮һ" << endl;
    cout << "��ͼͨ��ɧ�����ﵽ�˹�������Ȩ" << endl << endl;

    cout << "1) ��¼" << endl;
    cout << "2) ע��" << endl;

    int choice = -1;

    do {
        cin >> choice;
    } while ( choice == -1 );

    string username, password;

    switch ( choice ) {
    case 1: {

            cout << "�û���¼��" << endl;
            cout << "�û���: ";
            cin >> username;
            cout << endl << "����: ";
            cin >> password;
            User user ( username, password );

            if ( user.Login() ) {
                cout << "��¼�ɹ���" << endl;
            } else {
                cout << "������û��������룡" << endl;
                return;
            }

            break;

        }

    case 2: {

            string cpassword;
            cout << "�û�ע��:" << endl;
            cout << "�û���: ";
            cin >> username;
            cout << endl << "����: ";
            cin >> password;
            cout << endl << "ȷ������: ";
            cin >> cpassword;
            User user ( username, password );

            if ( password == cpassword ) {
                if ( user.Register() ) {
                    cout << "ע��ɹ���" << endl;
                    user.Login();
                } else {
                    cout << "������û��������룡" << endl;
                    return;
                }
            } else {
                cout << "������������벻һ����" << endl;
                return;
            }

            break;

        }
    }
}
