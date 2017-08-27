#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <iostream>
#include "player.h"

class User {
 private:
     string username;
	 string password;
	 const char* filename;
	 bool is_login;

	 string _Crypto ( string str );
	 void _Write ( ofstream &f );
	 string _Read ( ifstream &f );

	 template <class T>
	 string _ConverNumToString ( T d );
	 template <class T>
	 T _ConvertStringToNum ( const std::string& str );

 public:
    Player player;

	User ( string username , string password );

	bool Is_Login ( );
	bool Login ( );
	bool Register ( );
	bool Save ( );
	bool DeleteUser ( );

};

#endif // USER_H_INCLUDED
