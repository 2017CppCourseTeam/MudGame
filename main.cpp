#include "Game.h"
#include <windows.h>
#include <string>

int main()
{
    User* user;
    Game game ( user );
    while ( true )
    {
        system("color 90");
        if ( game.Init ( ) )   // 游戏初始化（登录、注册）
        {
            game.Select_Archive ( ); // 选择存档
            if ( game.Run ( ) )
            {
                game.Exit( );
                return 0;
            }
        }
    }
}
