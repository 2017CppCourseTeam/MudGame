#include "Game.h"
#include <windows.h>
#include <string>

int main()
{
    Game* game = new Game ( );
    while ( true )
    {
        system ( "color E0" );
        if ( game->Init ( ) )   // 游戏初始化（登录、注册）
        {
            game->SelectArchive ( ); // 选择存档
            if ( game->Run ( ) )
            {
                game->Exit( );
                delete game;
                return 0;
            }
        }
    }
}
