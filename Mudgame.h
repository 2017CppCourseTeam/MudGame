#ifndef MUDGAME_H
#define MUDGAME_H
#include "commder.h"

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
    User* user;
    Commder* commder;
};

#endif // MUDGAME_H
