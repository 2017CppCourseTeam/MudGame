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
        void Select_Archive ( ); // ���ѡ��һ���浵
        bool Run ( ); // ����
        void Exit( ); // ��Ϸ����
        void Narrative( );
    private:
        bool _Check();
        void _Logo();
        User* user;
        HANDLE handle;
        Commander* commander;
};

#endif // MUDGAME_H
