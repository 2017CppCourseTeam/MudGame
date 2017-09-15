#ifndef COMMDER_H
#define COMMDER_H

#include "User.h"

class Commander
{
    public:
        Commander ( User*& user );
        bool Eval ( string& cmd ); // ������������
        enum STATUS GetStatus(); // �õ���ҵ�ǰҳ��
        void SetStatus ( enum STATUS _status ); // ������ҵ�ǰҳ��
    private:
        User* user;
        Map* _map;
        enum STATUS status;
        vector<string> history;

        string _Read ( ifstream & f );  // ��ȡ�ļ�һ���е�����
        string _Decrypt ( string str ); // ��������

        bool LoadMap ( string name, unsigned short level ); // ����ս����ͼ����Ҫ��ͼ���ƺ͵ȼ�
        //��ͼ�������ܷ���ͬĿ¼map�£���Ҫʹ�����׵�MapBuilder����

        void _ShowHistory(); // ��ӡ����ҵ���ʷ����
        void _ShowManual(); // ��ӡ����ϸ�����˵�
        void _ShowSoldierType();
        void _ToLower ( string& s ); // ��sת��ΪСд
        template <class T>
        T _ConvertStringToNum ( const string& str ); // ��strת��Ϊ��������
        void _CurrentPage(); // ��ӡ��ǰ��������
        HANDLE handle;
};
#endif // COMMDER_H
