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
        unsigned int GetNumber(); // �õ���ͼ�ϸõ�ʿ������Ŀ
        unsigned int GetAttack(); // �ô��õ�Ĺ�����
        unsigned int GetDefense(); // �õ��õ�ķ�����
        int GetLife(); // �õ��õ������ֵ
        unsigned int GetX(); // �õ��õ��X��������
        unsigned int GetY(); // �õ��õ��Y��������
        enum LocalPower GetPower(); // �õ��õ�����������ö�����ͣ�
        string SGetPower(); // �õ��õ������������ַ������ͣ�
        void AddToCurrentSoldier ( Soldier& soldier ); // �ڸõ����е�ʿ���б������һ��ʿ��
        void RemoveFromCurrentSoldier ( unsigned int _id ); // �ڸõ����е�ʿ���б���ɾ��һ��ʿ��

        void Reset ( unsigned int id, unsigned int _x, unsigned int _y ); // ���캯��������

        void UpdateNumber ( unsigned int number ); // ���¸õ�ʿ����Ŀ
        void UpdateAttack ( unsigned int attack ); //  ���¸õ㹥����
        void UpdateDefense ( unsigned int defense ); // ���¸õ������
        void UpdateLife ( unsigned int life ); //  ���¸õ�����ֵ
        void UpdatePower ( enum LocalPower power ); // ���¸õ���������
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
        Point* Get_Point ( unsigned int _x, unsigned int _y ); // �õ��������x y���ָ��
        void Update(); // ���µ�ͼ��ÿ������������������
        unsigned int GetRHeight(); // �õ��õ�ͼ����Ը߶�
        unsigned int GetRWidth(); // �õ��õ�ͼ����Կ��
        unsigned int GetHeight(); // �õ��õ�ͼ�ľ��Ը߶�
        unsigned int GetWidth(); // �õ��õ�ͼ�ľ��Ը߶�
        void AddSoldierToMap ( const char& _c, unsigned int _x, unsigned int _y ); // �ڵ�ͼ�����һ��ʿ��
        void AddSoldierToPoint ( unsigned int _x, unsigned int _y, Soldier& _soldier ); // �ڸõ������һ��ʿ��
        void Show_Map ( bool show_detail ); // ��ӡ��ͼ����ѡ�Ƿ��ӡ��ϸ��ͼ
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
