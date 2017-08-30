#ifndef USER1_HPP_INCLUDED
#define USER1_HPP_INCLUDED

#include "player.h"

class User {
 private:
     string username;
     string password;


 public:
    Player player;

    User(string username, string password) {
        this->username = username;
        this->password = password;
    }
};


#endif // USER1_HPP_INCLUDED
