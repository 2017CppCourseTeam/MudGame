#ifndef MUDGAME_H
#define MUDGAME_H
#include "user.h"

class Game
{
public:
    Game ( User*& user );
    bool Init ( );
    void Select_Archive ( );
    bool Run ( );
    void Exit( );
private:
    User* user;
};

#endif // MUDGAME_H
