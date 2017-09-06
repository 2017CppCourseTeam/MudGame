#include "Map.h"

Map::Map ( unsigned int height, unsigned int width, string name, unsigned short level, unsigned char**& data  )
{
    this->height = height;
    this->rheight =  ( height - 1 ) / 2;
    this->width = width;
    this->rwidth = ( width - 1 ) / 3 ;
    this->name =  name;
    this->level = level;
    this->_map = new unsigned char* [ this->height ];
    for ( unsigned int i = 0; i < this->height; i++ )
        this->_map [ i ] = new unsigned char [ this->width ];
    for ( unsigned int i = 0; i < this->height; i++ )
    {
        for ( unsigned int j = 0; j < this->width; j++ )
        {
            this->_map[i][j] = data[i][j];
        }
    }
}

string Map::_Decrypt ( string str )
{
    int c = str.length ( );
    string h = "";
    string o = "";
    for ( int i = 0; i < c; i++ )
    {
        if ( str [ i ] >= 'F' && str [ i ] <= '_' )
        {
            h = int ( str [ i ] ) + 27;
        }
        else if ( str [ i ] >= 'L' && str [ i ] <= 'e' )
        {
            h = int ( str [ i ] ) - 11;
        }
        else
        {
            h = int ( str [ i ] ) + 14;
        }
        o.append ( string ( h ) );
    }
    return o;
}

template <class T>
T Map::_ConvertStringToNum ( const string& str )
{
    std::istringstream iss ( str );
    T num;
    iss >> num;
    return num;
}

string Map::_Read ( ifstream & f )
{
    string _tmp;
    getline ( f, _tmp );
    return this->_Decrypt ( _tmp );
}

Map::~Map()
{
    for ( unsigned int i = 0; i < this->height; i++ )
        delete [ ]this->_map [ i ];
    delete [ ]this->_map;
}


Point::Point ( unsigned int _x, unsigned int _y )
{
    this->number = 0;
    this->x = _x;
    this->y = _y;
}

Point::~Point()
{
}

