#include "Game.h"
#include "Global.h"
#pragma comment(lib,"WINMM.LIB")

int main()
{
    Game* game = new Game ( );
    while ( true )
    {
        PlaySound ( ".\\BGM\\HDL.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
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
