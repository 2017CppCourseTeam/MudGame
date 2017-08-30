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
	 string filename;
	 bool is_login;

	 void _Write ( ofstream &f );
	 string _Read ( ifstream &f );

	 template <class T>
	 string _ConverNumToString ( T d );
	 template <class T>
	 T _ConvertStringToNum ( const std::string& str );

 public:
    Player player;

	string _Encrypt ( string str );
	string _Decrypt ( string str );
	User ( string username , string password );

	string Get_Username ( );
	string Get_Password ( );
	bool Is_Login ( );
	bool Login ( );
	bool Register ( );
	bool Save ( );
	bool DeleteUser ( );

};

#endif // USER_H_INCLUDED
