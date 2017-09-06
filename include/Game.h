#ifndef MUDGAME_H
#define MUDGAME_H
#include "Commander.h"
#include "windows.h"

class Game
{
    public:
        Game ( User*& user );
        ~Game();
        bool Init ( );
        void Select_Archive ( );
        bool Run ( );
        void Exit( );
        void Narrative( );
    private:
        bool _Check();
        void _Logo();
        User* user;
        HANDLE handle;
        Commander* commander;
};

#endif // MUDGAME_H
