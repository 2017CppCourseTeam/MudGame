<<<<<<< HEAD
#include <iostream>
#include "Mudgame.h"
using namespace std;

int main()
{
    Game a;
    a.Run();
}
=======
#include <iostream>
#include "user.hpp"
using namespace std;

int main()
{
    string username, password;
    cout << "�˹�����ͳ�ε���27391��֮�󡣡�" << endl;
    cout << "���ǵ�����200�������Ҵ��ߣ���ͼͨ��ɧ�������˹�������Ȩ����" << endl;

    cout << "��ʿ����ʱ����Լ���������յ��û�����" << endl;
    cout << "�û�����";
    cin >> username;
    cout << "���룺";
    cin >> password;

    User *user = new User(username, password);
    while(true) {
        string choice1;
        cout << "����Ҫ����ʲôɧ����?(����'help'���Խ��а���)" << endl;
        cin >> choice1;
        if(choice1 == "help")
        {
            cout << "���������'starwar'����ս�� ,'practice'����ѵ�� ,'end'�˳���Ϸ" << endl;
        }
        else if(choice1 == "starwar")
        {
           // user->player.StartWar()
        }
        else if(choice1 == "practice")
        {
            while(true){
                string choice2;
                cout << "����Ҫѵ��ʲô?(����'help'���Խ��а���)" << endl;
                cin >> choice2;
                if(choice2 == "help")
                {
                    cout << "���������'train'ѵ����ũ,'dig'�ڱ��ر�,'washbrain'����ϴ��,'return'����" << endl;
                }
                else if(choice2 == "train")
                {
                    user->player.TrainCoder();
                    user->player.showStatus();
                }
                else if(choice2 == "dig")
                {
                    user->player.DigMine();
                    user->player.showStatus();
                }
                else if(choice2 == "washbrain")
                {
                    user->player.WashBrain();
                    user->player.showStatus();
                }
                else if(choice2 == "return")
                    break;
                else
                    cout << "�����ڸ�����" << endl;
            }
        }
        else if(choice1 == "end")
            break;
        else
            cout << "�����ڸ�����" << endl;
    }
    return 0;
}
>>>>>>> origin/master
