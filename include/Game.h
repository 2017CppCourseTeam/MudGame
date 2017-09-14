#ifndef MUDGAME_H
#define MUDGAME_H

#include "Global.h"
#include "User.h"
#include "Commander.h"
#include "windows.h"

class Game
{
    public:
        Game ( );
        ~Game( );
        bool Init ( ); // ��Ϸ��ʼ����������¼ע��
        void SelectArchive ( ); // ���ѡ��һ���浵
        bool Run ( ); // ����
        void Exit( ); // ��Ϸ����
    private:
        bool _Check(); // �����Ϸ��Ӯ
        void _Logo(); // ��ʾLogo
        void _Narrative( ); // ��ʾ����

        User* user;
        HANDLE handle;
        Commander* commander;
};

#endif // MUDGAME_H
