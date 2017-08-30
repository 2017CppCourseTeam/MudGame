#include "Mudgame.h"

int main()
{
    Game game;
    User* user;
    while ( true )
    {
        if ( game.Init ( user ) )   // 游戏初始化，登陆
        {
            game.Select_Archive ( user ); // 选择存档
            if ( game.Run ( user ) )
            {
                // End Game code...
                return 0;
            }
        }
    }
}
