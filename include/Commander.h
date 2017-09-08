#ifndef COMMDER_H
#define COMMDER_H
#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Commander
{
    public:
        Commander ( User*& user );
        bool Eval ( string& cmd ); // 处理所有命令
        enum STATUS Get_Status(); // 得到玩家当前页面
    private:
        User* user;
        Map* _map;
        enum STATUS status;
        vector<string> history;

        string _Read ( ifstream & f );  // 读取文件一行中的内容
        string _Decrypt ( string str ); // 凯撒解密

        bool LoadMap ( string name, unsigned short level ); // 加载战争地图，需要地图名称和等级
        //地图经过加密放在同目录map下，需要使用配套的MapBuilder制作

        void _Show_History(); // 打印出玩家的历史命令
        void _Show_Manual(); // 打印出详细帮助菜单
        void _To_Lower ( string& s ); // 将s转换为小写
        template <class T>
        T _ConvertStringToNum ( const string& str ); // 将str转换为数字类型
        void _Current_Page(); // 打印当前界面名称
};
#endif // COMMDER_H
