#ifndef MUDGAME_H
#define MUDGAME_H
#include "user.h"

class Game
{
private:

public:
    bool Init ( User*& user );
    void Select_Archive ( User* user );
    bool Run ( User* user );
};

#endif // MUDGAME_H
