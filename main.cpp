#include "Mudgame.h"

int main()
{
    Game game;
    User* user;
    while ( true )
    {
        if ( game.Init ( user ) )   // ��Ϸ��ʼ������½
        {
            game.Select_Archive ( user ); // ѡ��浵
            if ( game.Run ( user ) )
            {
                // End Game code...
                return 0;
            }
        }
    }
}
