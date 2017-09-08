#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Soldier.h"

using namespace std;

enum LocalPower {_empty, player, ai, player_city, ai_city, empty_city};

class Point
{
    public:
        Point();
        Point ( unsigned int id, unsigned int _x, unsigned int _y );
        unsigned int GetNumber(); // 得到地图上该点士兵的数目
        unsigned int GetAttack(); // 得带该点的攻击力
        unsigned int GetDefense(); // 得到该点的防御力
        int GetLife(); // 得到该点的生命值
        unsigned int GetX(); // 得到该点的X绝对坐标
        unsigned int GetY(); // 得到该点的Y绝对坐标
        enum LocalPower GetPower(); // 得到该点所属势力（枚举类型）
        string SGetPower(); // 得到该点所属势力（字符串类型）
        void AddToCurrentSoldier ( Soldier& soldier ); // 在该点所有的士兵列表中添加一个士兵
        void RemoveFromCurrentSoldier ( unsigned int _id ); // 在该点所有的士兵列表中删除一个士兵

        void Reset ( unsigned int id, unsigned int _x, unsigned int _y ); // 构造函数的重载

        void UpdateNumber ( unsigned int number ); // 更新该点士兵数目
        void UpdateAttack ( unsigned int attack ); //  更新该点攻击力
        void UpdateDefense ( unsigned int defense ); // 更新该点防御力
        void UpdateLife ( unsigned int life ); //  更新该点生命值
        void UpdatePower ( enum LocalPower power ); // 更新该点所属势力
        ~Point();
    private:
        unsigned int id;
        unsigned int x;
        unsigned int y;
        enum LocalPower power;
        unsigned int number;
        unsigned int attack;
        unsigned int defense;
        int life;
        vector<Soldier> current_soldiers;
};

class Map
{
    public:
        Map ( unsigned int height, unsigned int width, string name, unsigned short level, unsigned char**& data );
        Point* Get_Point ( unsigned int _x, unsigned int _y ); // 得到相对坐标x y点的指针
        void Update(); // 更新地图上每个相对坐标的所属势力
        unsigned int GetRHeight(); // 得到该地图的相对高度
        unsigned int GetRWidth(); // 得到该地图的相对宽度
        unsigned int GetHeight(); // 得到该地图的绝对高度
        unsigned int GetWidth(); // 得到该地图的绝对高度
        void AddSoldierToMap ( const char& _c, unsigned int _x, unsigned int _y ); // 在地图上添加一个士兵
        void AddSoldierToPoint ( unsigned int _x, unsigned int _y, Soldier& _soldier ); // 在该点上添加一个士兵
        void Show_Map ( bool show_detail ); // 打印地图，可选是否打印详细地图
        ~Map();
    private:
        friend class War;
        unsigned int height;
        unsigned int rheight; // Real height
        unsigned int width;
        unsigned int rwidth; // Real width
        unsigned short level;
        unsigned int player_base_x;
        unsigned int player_base_y;
        unsigned int ai_base_x;
        unsigned int ai_base_y;
        Point** points;
        string _level;
        string name;
        unsigned char** _map;

        void _Init_Map_Points();

};
#endif // MAP_H
