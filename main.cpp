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
    while(1) {
        char choice1;
        cout << "������Ҫ����ʲô������" << endl << "a. ����ս�� b.���� c.�˳�" << endl;
        cin >> choice1;
        if(choice1 == 'a') {
            user->player.StartWar()
        }
        else if(choice1 == 'b'){
            int choice2;
            cout << "1��ѵ����ũ     2���ڿ�      3������ϴ��" << endl;
            cin >> choice2;
            if(choice2 == 1){
                user->player.TrainCoder();
            }
            if(choice2 == 2){
                user->player.DigMine();
            }
            if(choice2 == 3){
                user->player.WashBrain();
            }
        }
        else if(choice1 == 'c'){
            break;
        }
    }
    return 0;
}
