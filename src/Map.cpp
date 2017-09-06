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
    this->_Init_Map_Points();
    this->Update();
}

void Map::_Init_Map_Points()
{
    this->points = new Point* [this->rheight];
    for ( unsigned int i = 0; i < this->rheight; i++ )
        this->points [ i ] = new Point [ this->rwidth ];
    for ( unsigned int i = 0, id = 0; i < this->rheight; i++ )
    {
        for ( unsigned int j = 0; j < this->rwidth; j++ )
        {
            points[i][j].Reset ( id++, i, j );
        }
    }
}

void Map::Show_Map ( bool show_detail )

{
    if ( show_detail )
    {
        cout << endl << "[*]Map name: " << this->name << endl;
        cout << "[*]Map level: " << this->level << endl;
        cout << "[*]Map height: " << ( ( this->height ) - 1 ) / 2 << endl;
        cout << "[*]Map width: " << ( ( this->width ) - 1 ) / 3 << endl;
        cout << "[*]Map preview: " << endl;
    }
    int c = 0;
    for ( unsigned int i = 0; i < ( this->width ) + 3; i++ )
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
    for ( unsigned int i = 0; i < this->height ; i++ )
    {
        for ( unsigned int j = 0; j < ( this->width ) + 3; j++ )
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

Point* Map::Get_Point ( unsigned int _x, unsigned int _y )
{
    return &this->points[_x][_y];
}

void Map::Update()
{
    for ( unsigned int i = 1, k = 0; i < this->height - 1; i += 2, k++ )
    {
        for ( unsigned int j = 1, l = 0; j < this->width - 1; j += 3, l++ )
        {
            if ( this->_map[i][j] == '+' )
            {
                if ( this->_map[i][j + 1] == '+' )
                {
                    this->points[k][l].UpdatePower ( empty_city );
                }
                else if ( this->_map[i][j + 1] == '*' )
                {
                    this->points[k][l].UpdatePower ( player_city );
                }
                else if ( this->_map[i][j + 1] == 'X' )
                {
                    this->points[k][l].UpdatePower ( ai_city );
                }
            }
            else if ( this->_map[i][j] == '*' && this->_map[i][j + 1] == '*' )
            {
                this->points[k][l].UpdatePower ( player );
            }
            else if ( this->_map[i][j] == 'X' && this->_map[i][j + 1] == 'X' )
            {
                this->points[k][l].UpdatePower ( ai );
            }
            else
            {
                this->points[k][l].UpdatePower ( _empty );
            }
        }
    }
}

unsigned int Point::GetX()
{
    return this->x;
}

unsigned int Point::GetY()
{
    return this->y;
}


Map::~Map()
{
    for ( unsigned int i = 0; i < this->rheight; i++ )
        delete [ ]this->points [ i ];
    delete [ ]this->points;
    for ( unsigned int i = 0; i < this->height; i++ )
        delete [ ]this->_map [ i ];
    delete [ ]this->_map;
}


Point::Point ( unsigned int id, unsigned int _x, unsigned int _y )
{
    this->number = 0;
    this->id = id;
    this->x = _x;
    this->y = _y;
}

Point::Point()
{
    this->number = 0;
    this->id = 0;
    this->x = 0;
    this->y = 0;
}

void Point::Reset ( unsigned int id, unsigned int _x, unsigned int _y )
{
    this->id = id;
    this->x = _x;
    this->y = _y;
}

Point::~Point()
{
}
unsigned int Point::GetNumber()
{
    return this->number;
}

unsigned int Point::GetAttack()
{
    return this->attack;
}

unsigned int Point::GetDefense()
{
    return this->defense;
}

int Point::GetLife()
{
    return this->life;
}

enum LocalPower Point::GetPower()
{
    return this->power;
}

string Point::SGetPower()
{
    switch ( this->GetPower() )
    {
        case _empty:
        {
            return string ( "Null" );
            break;
        }
        case player:
        {
            return string ( "Player Base" );
            break;
        }
        case ai:
        {
            return string ( "AI Base" );
            break;
        }
        case player_city:
        {
            return string ( "Player City" );
            break;
        }
        case ai_city:
        {
            return string ( "AI City" );
            break;
        }
        case empty_city:
        {
            return string ( "Empty City" );
            break;
        }
    }
}

void Point::UpdateNumber ( unsigned int number )
{
    this->number = number;
}

void Point::UpdateAttack ( unsigned int attack )
{
    this->attack = attack;
}

void Point::UpdateDefense ( unsigned int defense )
{
    this->defense = defense;
}

void Point::UpdateLife ( unsigned int life )
{
    this->life = life;
}

void Point::UpdatePower ( enum LocalPower power )
{
    this->power = power;
}
