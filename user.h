#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <iostream>
#include "player.h"

class User
{
public:
    Player* player;
    User ( string username, string password );

    string Get_Username ( );
    string Get_Password ( );
    int Select_Player ( int no );
    bool Is_Login ( );
    bool Login ( );
    bool Register ( );
    bool Save ( );
    bool DeleteUser ( );
private:
    string username;
    string password;
    string filename;
    bool is_login;

    Player player1;
    Player player2;
    Player player3;

    void _Write ( ofstream &f );
    string _Read ( ifstream &f );
    string _Encrypt ( string str );
    string _Decrypt ( string str );
    void _Load_Player ( ifstream& login );

    template <class T>
    string _ConverNumToString ( T d );
    template <class T>
    T _ConvertStringToNum ( const std::string& str );



};

#endif // USER_H_INCLUDED
