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
        bool Eval ( string& cmd ); // ������������
        enum STATUS Get_Status(); // �õ���ҵ�ǰҳ��
    private:
        User* user;
        Map* _map;
        enum STATUS status;
        vector<string> history;

        string _Read ( ifstream & f );  // ��ȡ�ļ�һ���е�����
        string _Decrypt ( string str ); // ��������

        bool LoadMap ( string name, unsigned short level ); // ����ս����ͼ����Ҫ��ͼ���ƺ͵ȼ�
        //��ͼ�������ܷ���ͬĿ¼map�£���Ҫʹ�����׵�MapBuilder����

        void _Show_History(); // ��ӡ����ҵ���ʷ����
        void _Show_Manual(); // ��ӡ����ϸ�����˵�
        void _To_Lower ( string& s ); // ��sת��ΪСд
        template <class T>
        T _ConvertStringToNum ( const string& str ); // ��strת��Ϊ��������
        void _Current_Page(); // ��ӡ��ǰ��������
};
#endif // COMMDER_H
