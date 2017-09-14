#include "User.h"

User::User ( const string username, const string password )
{
    this->username = new string ( username );
    this->password = new string ( password );
    this->filename = new string ( string ( ".\\userdata\\" ) + *this->username + string ( ".dat" ) );
    this->is_login = false;
    this->player = 0;
}

User::~User()
{
    delete this->username;
    delete this->password;
    delete this->filename;
}

string User::GetUsername ( )
{
    return *this->username;
}

string User::GetPassword ( )
{
    return *this->password;
}

unsigned int User::SelectPlayer ( short _no )
{
    unsigned int _result;
    if ( this->IsLogin ( ) )
    {
        switch ( _no )
        {
            case 1:
            {
                this->player = & ( this->player1 );
                break;
            }
            case 2:
            {
                this->player = & ( this->player2 );
                break;
            }
            case 3:
            {
                this->player = & ( this->player3 );
                break;
            }
            default:
                _result = 0;
        }
        _result = _no;
    }
    else
        _result = 0;
    return _result;
}

bool User::IsLogin ( )
{
    return this->is_login;
}

bool User::Login ( )
{
    ifstream login;
    bool _result = false;
    login.open ( this->filename->c_str(), ios::in );
    if ( !login )
        _result = false;
    else
    {
        string username, password;
        // Get username.
        username = this->_Read ( login );
        // Get password.
        password = this->_Read ( login );
        if ( username == *this->username && password == *this->password )
        {
            // Get player status
            this->_LoadPlayer ( login );
            // User login success.
            this->is_login = true;
            login.close ( );
            _result = true;
        }
        else
        {
            login.close ( );
            _result = false;
        }
    }
    return _result;
}

bool User::Register ( )
{
    bool _result = false;
    // Test the user if exists.
    ifstream test_user_exists;
    test_user_exists.open ( this->filename->c_str(), ios::in );
    if ( test_user_exists )
    {
        test_user_exists.close ( );
        _result = false;
    }
    else
    {
        test_user_exists.close ( );
        // Ready to register.
        ofstream regist;
        regist.open ( this->filename->c_str(), ios::out );
        this->_Write ( regist );
        regist.close ( );
        _result = true;
    }
    return _result;
}

bool User::Save ( )
{
    bool _result = false;
    if ( this->IsLogin ( ) )
    {
        ofstream save;
        save.open ( this->filename->c_str(), ios::out );
        this->_Write ( save );
        save.close ( );
        _result = true;
    }
    else
        _result = false;
    return _result;
}

bool User::DeleteUser ( )
{
    bool _result = false;
    // Must be login!
    if ( this->IsLogin ( ) )
    {
        if ( remove ( this->filename->c_str ( ) ) )
            _result = true;
        else
            _result = false;
    }
    else
        _result = false;
    return _result;
}

string User::_Encrypt ( string str )
{
    int c = str.length ( );
    string h = "";
    string o = "";
    for ( int i = 0; i < c; i++ )
    {
        if ( str [ i ] >= 'a' && str [ i ] <= 'z' )
            h = int ( str [ i ] ) - 27;
        else if ( str [ i ] >= 'A' && str [ i ] <= 'Z' )
            h = int ( str [ i ] ) + 11;
        else
            h = int ( str [ i ] ) - 14;
        o.append ( string ( h ) );
    }
    return o;
}

string User::_Decrypt ( string str )
{
    int c = str.length ( );
    string h = "";
    string o = "";
    for ( int i = 0; i < c; i++ )
    {
        if ( str [ i ] >= 'F' && str [ i ] <= '_' )
            h = int ( str [ i ] ) + 27;
        else if ( str [ i ] >= 'L' && str [ i ] <= 'e' )
            h = int ( str [ i ] ) - 11;
        else
            h = int ( str [ i ] ) + 14;
        o.append ( string ( h ) );
    }
    return o;
}

// Load player status
void User::_LoadPlayer ( ifstream & login )
{
    // Player1 status
    this->player1.name = this->_Read ( login );
    this->player1.prestige = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player1.bitcoin = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player1.violence = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player1.second = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
    this->player1.war_num = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
    // Player2 status
    this->player2.name = this->_Read ( login );
    this->player2.prestige = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player2.bitcoin = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player2.violence = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player2.second = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
    this->player2.war_num = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
    // Player3 status
    this->player3.name = this->_Read ( login );
    this->player3.prestige = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player3.bitcoin = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player3.violence = this->_ConvertStringToNum<double> ( this->_Read ( login ) );
    this->player3.second = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
    this->player3.war_num = this->_ConvertStringToNum<int> ( this->_Read ( login ) );
}

void User::_Write ( ofstream& f )
{
    // Username and Password
    f << this->_Encrypt ( *this->username ) << std::endl;
    f << this->_Encrypt ( *this->password ) << std::endl;
    // Player1 status
    f << this->_Encrypt ( this->player1.name ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player1.prestige ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player1.bitcoin ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player1.violence ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player1.second ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player1.war_num ) ) << std::endl;
    // Player2 status
    f << this->_Encrypt ( this->player2.name ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player2.prestige ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player2.bitcoin ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player2.violence ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player2.second ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player2.war_num ) ) << std::endl;
    // Player3 status
    f << this->_Encrypt ( this->player3.name ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player3.prestige ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player3.bitcoin ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player3.violence ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player3.second ) ) << std::endl;
    f << this->_Encrypt ( this->_ConverNumToString ( this->player3.war_num ) ) << std::endl;
}

string User::_Read ( ifstream & f )
{
    string _tmp;
    getline ( f, _tmp );
    return this->_Decrypt ( _tmp );
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
