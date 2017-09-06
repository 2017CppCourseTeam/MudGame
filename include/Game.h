#ifndef MUDGAME_H
#define MUDGAME_H
#include "Commander.h"

class Game
{
    public:
        Game ( User*& user );
        ~Game();
        bool Init ( );
        void Select_Archive ( );
        bool Run ( );
        void Exit( );
    private:
        bool _Check();
        void _Logo();
        User* user;
        Commander* commander;
};

#endif // MUDGAME_H
