#include "user.h"

User::User ( string username , string password )
{
	this->username = username;
	this->password = password;
	this->filename = ( string ( "./userdata/" ) + this->username ).c_str ( );
	this->is_login = false;
}

string User::Get_Username ( )
{
	return this->username;
}

string User::Get_Password ( )
{
	return this->password;
}

bool User::Is_Login ( )
{
	return this->is_login;
}

bool User::Login ( )
{
	ifstream login;
	login.open ( this->filename , ios::in );
	if ( !login )
	{
		return false;
	}
	else
	{
		string username , password;
		// Get username.
		username = this->_Read ( login );
		// Get password.
		password = this->_Read ( login );
		if ( username == this->username && password == this->password )
		{
			// Get player status
			this->player.prestige = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
			this->player.bitcoin = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
			this->player.violence = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
			this->player.second = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
			this->player.war_num = this->_ConvertStringToNum<int> ( this->_Read ( login ) );

			// User login success.
			this->is_login = true;
			login.close ( );
			return true;
		}
		else
		{
			login.close ( );
			return false;
		}
	}
}

bool User::Register ( )
{
	// Test the user if exists.
	ifstream test_user_exists;
	test_user_exists.open ( this->filename , ios::in );
	if ( test_user_exists )
	{
		test_user_exists.close ( );
		return false;
	}
	else
	{
		test_user_exists.close ( );
		// Ready to register.
		ofstream regist;
		regist.open ( this->filename , ios::out );
		this->_Write ( regist );
		regist.close ( );
		return true;
	}
}

bool User::Save ( )
{
	if ( this->Is_Login ( ) )
	{
		ofstream save;
		this->_Write ( save );
		save.close ( );
		return true;
	}
	else
	{
		return false;
	}
}

bool User::DeleteUser ( )
{
	if ( this->Is_Login ( ) )
	{
		if(remove ( this->filename ))
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

string User::_Crypto ( string str )
{
	string k = "d03a1f3c";
	int c = str.length ( );
	int l = k.length ( );
	string o = "";
	for ( int i = 0; i < c;)
	{
		for ( int j = 0; ( j < c&&i < l ); j++ , i++ )
		{
			char c = char ( int ( str [ i ] ) ^ int ( k [ j ] ) );
			o.append ( string ( &c ) );
		}
	}
	return o;
}

void User::_Write ( ofstream& f )
{
	f << this->_Crypto ( this->username ) << std::endl;
	f << this->_Crypto ( this->password ) << std::endl;
	f << this->_Crypto ( this->_ConverNumToString ( this->player.prestige )) << std::endl;
	f << this->_Crypto ( this->_ConverNumToString ( this->player.bitcoin ) ) << std::endl;
	f << this->_Crypto ( this->_ConverNumToString ( this->player.violence ) ) << std::endl;
	f << this->_Crypto ( this->_ConverNumToString ( this->player.second ) ) << std::endl;
	f << this->_Crypto ( this->_ConverNumToString ( this->player.war_num ) ) << std::endl;
}

string User::_Read ( ifstream & f )
{
	string _tmp;
	getline ( f , _tmp );
	return this->_Crypto ( _tmp );
}

template <class T>
string User::_ConverNumToString ( T d )
{
	std::ostringstream os;
	os << d;
	return os.str ( );
}

template <class T>
T User::_ConvertStringToNum ( const string& str )
{
	std::istringstream iss ( str );
	T num;
	iss >> num;
	return num;
}
