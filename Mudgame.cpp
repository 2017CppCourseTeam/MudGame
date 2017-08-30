#include "Mudgame.h"

void Game::Run()
{
    cout << "人工智能统治地球27391年之后" << endl;
    cout << "你是地球上200个人类幸存者之一" << endl;
    cout << "企图通过骚操作达到人工智能政权" << endl << endl;

    cout << "1) 登录" << endl;
    cout << "2) 注册" << endl;

    int choice = -1;

    do {
        cin >> choice;
    } while ( choice == -1 );

    string username, password;

    switch ( choice ) {
    case 1: {

            cout << "用户登录：" << endl;
            cout << "用户名: ";
            cin >> username;
            cout << endl << "密码: ";
            cin >> password;
            User user ( username, password );

            if ( user.Login() ) {
                cout << "登录成功！" << endl;
            } else {
                cout << "错误的用户名或密码！" << endl;
                return;
            }

            break;

        }

    case 2: {

            string cpassword;
            cout << "用户注册:" << endl;
            cout << "用户名: ";
            cin >> username;
            cout << endl << "密码: ";
            cin >> password;
            cout << endl << "确认密码: ";
            cin >> cpassword;
            User user ( username, password );

            if ( password == cpassword ) {
                if ( user.Register() ) {
                    cout << "注册成功！" << endl;
                    user.Login();
                } else {
                    cout << "错误的用户名或密码！" << endl;
                    return;
                }
            } else {
                cout << "两次输入的密码不一样！" << endl;
                return;
            }

            break;

        }
    }
}
