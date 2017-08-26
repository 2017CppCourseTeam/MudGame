#include <iostream>
#include "user.hpp"
using namespace std;

int main()
{
    string username, password;
    cout << "人工智能统治地球27391年之后。。" << endl;
    cout << "你是地球上200个人类幸存者，企图通过骚操作打倒人工智能政权。。" << endl;

    cout << "勇士，是时候给自己起个萌萌哒的用户名了" << endl;
    cout << "用户名：";
    cin >> username;
    cout << "密码：";
    cin >> password;

    User *user = new User(username, password);
    while(1) {
        char choice1;
        cout << "下面你要进行什么操作：" << endl << "a. 发起战争 b.休整 c.退出" << endl;
        cin >> choice1;
        if(choice1 == 'a') {
            user->player.StartWar()
        }
        else if(choice1 == 'b'){
            int choice2;
            cout << "1、训练码农     2、挖矿      3、政治洗脑" << endl;
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
