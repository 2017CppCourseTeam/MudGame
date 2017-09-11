#ifndef MAP_H
#define MAP_H

#include <string>
using namespace std;
#include "Soldier.h"

class Point
{
    public:
        Point();
        void Reset ( unsigned int id, unsigned int _x, unsigned int _y ); // ���캯������һ��ʵ��
        Point ( unsigned int id, unsigned int _x, unsigned int _y );
        ~Point();

        int GetLife(); // �õ��õ������ֵ
        void UpdateLife ( unsigned int life ); //  ���¸õ�����ֵ
        void SetLife ( unsigned int life );

        unsigned int GetAttack(); // �ô��õ�Ĺ�����
        void UpdateAttack ( unsigned int attack ); //  ���¸õ㹥����
        void SetAttack ( unsigned int attack );

        unsigned int GetDefense(); // �õ��õ�ķ�����
        void UpdateDefense ( unsigned int defense ); // ���¸õ������
        void SetDefence ( unsigned int defence );

        unsigned int GetNumber(); // �õ���ͼ�ϸõ�ʿ������Ŀ
        void UpdateNumber ( unsigned int number ); // ���¸õ�ʿ����Ŀ
        void SetNumber ( unsigned int number );

        enum LocalPower GetPower(); // �õ��õ�����������ö�����ͣ�
        string SGetPower(); // �õ��õ������������ַ������ͣ�
        void UpdatePower ( enum LocalPower power ); // ���¸õ���������

        unsigned int GetX(); // �õ��õ��X��������
        unsigned int GetY(); // �õ��õ��Y��������

        void AddToCurrentSoldier ( Soldier& soldier ); // �ڸõ����е�ʿ���б������һ��ʿ��
        void RemoveFromCurrentSoldier ( unsigned int _id ); // �ڸõ����е�ʿ���б���ɾ��һ��ʿ��
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

        void InitMap(); // ��ʼ����ͼ

        const char GetChar ( unsigned int _x, unsigned int _y );
        void DrawToMap ( const char& _c, unsigned int _x, unsigned int _y, bool _right ); // �ڵ�ͼ�Ͼ������껭һ����־

        unsigned int GetRHeight(); // �õ��õ�ͼ����Ը߶�
        unsigned int GetRWidth(); // �õ��õ�ͼ����Կ��
        unsigned int GetHeight(); // �õ��õ�ͼ�ľ��Ը߶�
        unsigned int GetWidth(); // �õ��õ�ͼ�ľ��Ը߶�

        void AddSoldierToPoint ( unsigned int _x, unsigned int _y, Soldier& _soldier ); // �ڸõ������һ��ʿ��
        void RemoveSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id ); // �ڸõ���ɾ��һ��ʿ��

        void Show_Map ( bool show_detail ); // ��ӡ��ͼ����ѡ�Ƿ��ӡ��ϸ��ͼ

        bool IsEmptyCity ( unsigned int _x, unsigned int _y );
        char WhosCity ( unsigned int _x, unsigned int _y );
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

        void _InitCity(); // ��ʼ����ͼ��ÿ�����е�����
        void _Init_Map_Points();
        void _Init_Power(); // ���µ�ͼ��ÿ������������������

};
#endif // MAP_H
