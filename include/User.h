#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "Player.h"

class User
{
    public:
        User ( const string username, const string password );
        ~User();

        string GetUsername ( ); // 得到用户名
        string GetPassword ( ); // 得到密码
        unsigned int SelectPlayer ( short _no ); // 用户选择存档
        bool IsLogin ( ); // 判断用户当前是否登录
        bool Login ( ); // 登录
        bool Register ( ); // 注册
        bool Save ( ); // 保存用户当前状态
        bool DeleteUser ( ); // 删除用户

        Player* ai;
        Player* player;
    private:
        string* username;
        string* password;
        string* filename;
        bool is_login;

        Player player1;
        Player player2;
        Player player3;

        void _Write ( ofstream &f ); // 写入文件
        string _Read ( ifstream &f ); // 读取文件
        string _Encrypt ( string str ); // 加密函数
        string _Decrypt ( string str ); // 解密函数
        void _LoadPlayer ( ifstream& login ); // 加载Player状态

        template <class T>
        string _ConverNumToString ( T d );
        template <class T>
        T _ConvertStringToNum ( const std::string& str );

};

#endif // USER_H_INCLUDED
