#include "Game.h"

int main()
{
    User* user;
    Game* game = new Game ( user );
    while ( true )
    {
        if ( game->Init ( ) )   // 游戏初始化（登录、注册）
        {
            game->Select_Archive ( ); // 选择存档
            if ( game->Run ( ) )
            {
                game->Exit( );
                delete game;
                return 0;
            }
        }
    }
}
