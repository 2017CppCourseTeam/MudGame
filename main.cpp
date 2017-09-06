#include "Game.h"
#include <windows.h>
#include <string>

int main()
{
    User* user;
    Game* game = new Game ( user );
    while ( true )
    {
<<<<<<< HEAD
        system("color E0");
=======
        system ( "color 90" );
>>>>>>> 6729415ffba56967d04c58f1f4224bd6a083faa8
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
