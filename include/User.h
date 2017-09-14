#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "Player.h"

class User
{
    public:
        User ( const string username, const string password );
        ~User();

        string GetUsername ( ); // �õ��û���
        string GetPassword ( ); // �õ�����
        unsigned int SelectPlayer ( short _no ); // �û�ѡ��浵
        bool IsLogin ( ); // �ж��û���ǰ�Ƿ��¼
        bool Login ( ); // ��¼
        bool Register ( ); // ע��
        bool Save ( ); // �����û���ǰ״̬
        bool DeleteUser ( ); // ɾ���û�

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

        void _Write ( ofstream &f ); // д���ļ�
        string _Read ( ifstream &f ); // ��ȡ�ļ�
        string _Encrypt ( string str ); // ���ܺ���
        string _Decrypt ( string str ); // ���ܺ���
        void _LoadPlayer ( ifstream& login ); // ����Player״̬

        template <class T>
        string _ConverNumToString ( T d );
        template <class T>
        T _ConvertStringToNum ( const std::string& str );

};

#endif // USER_H_INCLUDED
