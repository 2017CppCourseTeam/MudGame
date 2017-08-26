#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED

#include "player.hpp"

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

#endif // USER_HPP_INCLUDED
