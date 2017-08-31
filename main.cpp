#include "Mudgame.h"

int main()
{
    User* user;
    Game game ( user );
    while ( true )
    {
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
