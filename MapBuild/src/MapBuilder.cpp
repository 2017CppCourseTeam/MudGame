#include "MapBuilder.h"

MapBuilder::MapBuilder ( unsigned int height, unsigned int width, string name, unsigned short level )
{
    this->height = new unsigned int ( ( height * 2 ) + 1 );
    this->width = new unsigned int ( ( width * 3 ) + 1 );
    this->name = new string ( name );
    this->_level = new unsigned int ( level );
    switch ( level )
    {
        case 1:
            {
                this->level = new string ( "1" );
                break;
            }
        case 2:
            {
                this->level = new string ( "2" );
                break;
            }
        case 3:
            {
                this->level = new string ( "3" );
                break;
            }
        case 4:
            {
                this->level = new string ( "4" );
                break;
            }
        case 5:
            {
                this->level = new string ( "5" );
                break;
            }
        default:
            {
                this->level = new string ( "1" );
                break;
            }
    }
    this->_map = new unsigned char* [ *this->height ];
    for ( unsigned int i = 0; i < *this->height; i++ )
        this->_map [ i ] = new unsigned char [ *this->width ];
    this->_InitMap();
}

MapBuilder::~MapBuilder()
{
    delete this->height;
    delete this->width;
    delete this->name;
    delete this->level;
    delete this->_level;
    for ( unsigned int i = 0; i < *this->height; i++ )
        delete [ ]this->_map [ i ];
    delete [ ]this->_map;
}

void MapBuilder::_InitMap()
{
    for ( unsigned int i = 0; i < *this->height; i++ )
    {
        for ( unsigned int j = 0; j < *this->width; j++ )
        {
            if ( i % 2 == 0 )
            {
                if ( j % 3 == 0 )
                    this->_map[i][j] = '+';
                else
                    this->_map[i][j] = '-';
            }
            else
            {
                if ( j % 3 == 0 )
                    this->_map[i][j] = '|';
                else
                    this->_map[i][j] = ' ';
            }
        }
        cout << endl;
    }
}

void MapBuilder::ShowMap()
{
    cout << endl << "[*]Map name: " << *this->name << endl;
    cout << "[*]Map level: " << *this->level << endl;
    cout << "[*]Map height: " << ( ( *this->height ) - 1 ) / 2 << endl;
    cout << "[*]Map width: " << ( ( *this->width ) - 1 ) / 3 << endl;
    cout << "[*]Map preview: " << endl;
    int c = 0;
    for ( unsigned int i = 0; i < ( *this->width ) + 3; i++ )
    {
        if ( i == 0 )
        {
            cout << " ";
        }
        else if ( i == 1 )
        {
            cout << " ";
        }
        else if ( i == 2 )
        {
            cout << "X";
        }
        else if ( i % 3 != 0 )
        {
            if ( c <= 9 )
                cout << "0";
            cout << c++;
            i++;
        }
        else
            cout << " ";
    }
    cout << endl;
    c = 0;
    for ( unsigned int i = 0; i < *this->height ; i++ )
    {
        for ( unsigned int j = 0; j < ( *this->width ) + 3; j++ )
        {
            if ( j >= 0 && j < 3 )
            {
                if ( i == 0 )
                {
                    if ( j == 0 )
                        cout << " ";
                    else if ( j == 1 )
                        cout << "Y";
                    else if ( j == 2 )
                        cout << " ";
                }
                else if ( i % 2 != 0 )
                {
                    if ( j == 0 )
                    {
                        if ( c <= 9 )
                            cout << "0";
                        cout << c++ << " ";
                    }
                }
                else
                {
                    cout << " ";
                }
            }
            else
                cout << this->_map[i][j - 3];
        }
        cout << endl;
    }
}

string MapBuilder::_Encrypt ( string str )
{
    int c = str.length ( );
    string h = "";
    string o = "";
    for ( int i = 0; i < c; i++ )
    {
        if ( str [ i ] >= 'a' && str [ i ] <= 'z' )
        {
            h = int ( str [ i ] ) - 27;
        }
        else if ( str [ i ] >= 'A' && str [ i ] <= 'Z' )
        {
            h = int ( str [ i ] ) + 11;
        }
        else
        {
            h = int ( str [ i ] ) - 14;
        }
        o.append ( string ( h ) );
    }
    return o;
}

void MapBuilder::_Write ( ofstream& f )
{
    f << this->_Encrypt ( *this->name ) << endl;
    f << this->_Encrypt ( *this->level ) << endl;
    f << this->_Encrypt ( _ConverNumToString ( *this->height ) ) << endl;
    f << this->_Encrypt ( _ConverNumToString ( *this->width ) ) << endl;
    for ( unsigned int i = 0; i < *this->height; i++ )
    {
        for ( unsigned int j = 0; j < *this->width; j++ )
        {
            f << this->_map[i][j];
        }
    }
}

void MapBuilder::SaveMap()
{
    Map _map ( *this->height, *this->width, *this->name, *this->_level, this->_map );
    ofstream save ;
    save.open ( ( ( string ( ".\\map\\" ) + *this->name + *this->level + string ( ".dat" ) ).c_str() ), ios::trunc );
    this->_Write ( save );
    save.close ( );
}

bool MapBuilder::SetPlayerBaseCity ( unsigned int x, unsigned int y )
{
    unsigned int _x = ( 2 * y ) + 1;
    unsigned int _y = ( 3 * x ) + 1;
    if ( _x >= *this->height || _y >= *this->width )
        return false;
    if ( this->_map[_x][_y] == ' ' )
    {
        this->_map[_x][_y] = '*';
        this->_map[_x][_y + 1] = '*';
        return true;
    }
    else
        return false;
}

bool MapBuilder::SetAIBaseCity ( unsigned int x, unsigned int y )
{
    unsigned int _x = ( 2 * y ) + 1;
    unsigned int _y = ( 3 * x ) + 1;
    if ( _x >= *this->height || _y >= *this->width )
        return false;
    if ( this->_map[_x][_y] == ' ' )
    {
        this->_map[_x][_y] = 'X';
        this->_map[_x][_y + 1] = 'X';
        return true;
    }
    else
        return false;
}

bool MapBuilder::SetEmptyCity ( unsigned int x, unsigned int y )
{
    unsigned int _x = ( 2 * y ) + 1;
    unsigned int _y = ( 3 * x ) + 1;
    if ( _x >= *this->height || _y >= *this->width )
        return false;
    if ( this->_map[_x][_y] == ' ' )
    {
        this->_map[_x][_y] = '+';
        this->_map[_x][_y + 1] = '+';
        return true;
    }
    else
        return false;
}

bool MapBuilder::SetPlayerCity ( unsigned int x, unsigned int y )
{
    unsigned int _x = ( 2 * y ) + 1;
    unsigned int _y = ( 3 * x ) + 1;
    if ( _x >= *this->height || _y >= *this->width )
        return false;
    if ( this->_map[_x][_y] == ' ' )
    {
        this->_map[_x][_y] = '+';
        this->_map[_x][_y + 1] = '*';
        return true;
    }
    else
        return false;
}

bool MapBuilder::SetAICity ( unsigned int x, unsigned int y )
{
    unsigned int _x = ( 2 * y ) + 1;
    unsigned int _y = ( 3 * x ) + 1;
    if ( _x >= *this->height || _y >= *this->width )
        return false;
    if ( this->_map[_x][_y] == ' ' )
    {
        this->_map[_x][_y] = '+';
        this->_map[_x][_y + 1] = 'X';
        return true;
    }
    else
        return false;
}

template <class T>
string MapBuilder::_ConverNumToString ( T d )
{
    std::ostringstream os;
    os << d;
    return os.str ( );
}
