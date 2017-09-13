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
        bool Init ( ); // 游戏初始化，包括登录注册
        void Select_Archive ( ); // 玩家选择一个存档
        bool Run ( ); // 运行
        void Exit( ); // 游戏结束
        void Narrative( );
    private:
        bool _Check();
        void _Logo();
        User* user;
        HANDLE handle;
        Commander* commander;
};

#endif // MUDGAME_H
