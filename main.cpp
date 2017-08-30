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
    cout << "人工智能统治地球27391年之后。。" << endl;
    cout << "你是地球上200个人类幸存者，企图通过骚操作打倒人工智能政权。。" << endl;

    cout << "勇士，是时候给自己起个萌萌哒的用户名了" << endl;
    cout << "用户名：";
    cin >> username;
    cout << "密码：";
    cin >> password;

    User *user = new User(username, password);
    while(true) {
        string choice1;
        cout << "你想要进行什么骚操作?(输入'help'可以进行帮助)" << endl;
        cin >> choice1;
        if(choice1 == "help")
        {
            cout << "你可以输入'starwar'进行战争 ,'practice'进行训练 ,'end'退出游戏" << endl;
        }
        else if(choice1 == "starwar")
        {
           // user->player.StartWar()
        }
        else if(choice1 == "practice")
        {
            while(true){
                string choice2;
                cout << "你想要训练什么?(输入'help'可以进行帮助)" << endl;
                cin >> choice2;
                if(choice2 == "help")
                {
                    cout << "你可以输入'train'训练码农,'dig'挖比特币,'washbrain'政治洗脑,'return'返回" << endl;
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
                    cout << "不存在该命令" << endl;
            }
        }
        else if(choice1 == "end")
            break;
        else
            cout << "不存在该命令" << endl;
    }
    return 0;
}
>>>>>>> origin/master
