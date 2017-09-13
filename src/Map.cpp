#include "Map.h"

Map::Map ( unsigned int height, unsigned int width, string name, unsigned short level, unsigned char**& data )
{
    this->height = height;
    this->rheight = ( height - 1 ) / 2;
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
    this->InitMap();
}

void Map::InitMap()
{
    this->_Init_Map_Points();
    this->_Init_Power();
    this->_InitCity();
}

void Map::_InitCity ( )
{
    for ( unsigned int i = 0; i < this->rheight; i++ )
    {
        for ( unsigned int j = 0; j < this->rwidth; j++ )
        {
            switch ( points[i][j].GetPower() )
            {
                case _empty:
                {
                    points[i][j].SetLife ( 0 );
                    points[i][j].SetAttack ( 0 );
                    points[i][j].SetDefence ( 0 );
                    break;
                }
                case _player:
                {
                    points[i][j].SetLife ( 3000 );
                    points[i][j].SetAttack ( 0 );
                    points[i][j].SetDefence ( 0 );
                    break;
                }
                case _ai:
                {
                    points[i][j].SetLife ( 3000 );
                    points[i][j].SetAttack ( 0 );
                    points[i][j].SetDefence ( 0 );
                    break;
                }
                case empty_city:
                {
                    points[i][j].SetLife ( 200 );
                    points[i][j].SetAttack ( 0 );
                    points[i][j].SetDefence ( 0 );
                    break;
                }
                case player_city:
                {
                    points[i][j].SetLife ( 0 );
                    points[i][j].SetAttack ( 0 );
                    points[i][j].SetDefence ( 0 );
                    break;
                }
                case ai_city:
                {
                    points[i][j].SetLife ( 0 );
                    points[i][j].SetAttack ( 0 );
                    points[i][j].SetDefence ( 0 );
                    break;
                }
            }
        }
    }
}

void Point::SetNumber ( unsigned int number )
{
    this->number = number;
}

void Point::SetLife ( unsigned int life )
{
    this->life = life;
}

void Point::SetAttack ( unsigned int attack )
{
    this->attack = attack;
}

void Point::SetDefence ( unsigned int defence )
{
    this->defense = defence;
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

unsigned int Map::GetRHeight()
{
    return this->rheight;
}

unsigned int Map::GetRWidth()
{
    return this->rwidth;
}

Soldier* Point::_GetSoldier ( unsigned int _id )
{
    return &this->current_soldiers[_id];
}

unsigned int Point::GetCurrentSoldierNum()
{
    return this->current_soldiers.size();
}

void Map::DrawToMap ( const char& _c, unsigned int _x, unsigned int _y, bool _right )
{
    unsigned int _y_ = ( _x * 3 ) + 1;
    unsigned int _x_ = ( _y * 2 ) + 1;
    if ( _right )
        _y_ += 1;
    this->_map[_x_][_y_] = _c;
}

const char Map::GetChar ( unsigned int _x, unsigned int _y, bool _right )
{
    unsigned int _y_ = ( _x * 3 ) + 1;
    unsigned int _x_ = ( _y * 2 ) + 1;
    if ( _right )
        _y_ += 1;
    return this->_map[_x_][_y_];
}

bool Map::IsEmptyCity ( unsigned int _x, unsigned int _y )
{
    return this->points[_x][_y].GetNumber() == 0;
}

char Map::WhosCity ( unsigned int _x, unsigned int _y )
{
    char _result = ' ';
    switch ( this->points[_x][_y].GetPower( ) )
    {
        case _empty:
        {
            _result = ' ';
            break;
        }
        case _player:
        {
            _result = '*';
            break;
        }
        case _ai:
        {
            _result = 'X';
            break;
        }
        case player_city:
        case ai_city:
        case empty_city:
        {
            _result = '+';
            break;
        }
    }
    return _result;
}


unsigned int Map::GetHeight()
{
    return this->height;
}

unsigned int Map::GetWidth()
{
    return this->width;
}

void Map::AddSoldierToPoint ( unsigned int _x, unsigned int _y, Soldier& _soldier )
{
    this->points[ _x ][ _y ].AddToCurrentSoldier ( _soldier );
}

void Map::RemoveSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id )
{
    this->points[ _x ][ _y ].RemoveFromCurrentSoldier ( _id );
}

void Map::_Init_Power()
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
            else if ( this->_map[i][j] == '*' )
            {
                if ( this->_map[i][j + 1] == '*' )
                {
                    this->points[k][l].UpdatePower ( _player );
                    this->player_base_x = j;
                    this->player_base_y = i;
                }
            }
            else if ( this->_map[i][j] == 'X' && this->_map[i][j + 1] == 'X' )
            {
                this->points[k][l].UpdatePower ( _ai );
                this->ai_base_x = j;
                this->ai_base_y = i;
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
    this->attack = 0;
    this->defense = 0;
    this->life = 0;
    this->number = 0;
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
    string _result;
    switch ( this->GetPower() )
    {
        case _empty:
        {
            _result =  "Null" ;
            break;
        }
        case _player:
        {
            _result =  "Player Base" ;
            break;
        }
        case _ai:
        {
            _result =  "AI Base" ;
            break;
        }
        case player_city:
        {
            _result =  "Player City" ;
            break;
        }
        case ai_city:
        {
            _result =  "AI City" ;
            break;
        }
        case empty_city:
        {
            _result =  "Empty City" ;
            break;
        }
    }
    return _result;
}

void Point::UpdateNumber ( int number )
{
    this->number += number;
}

void Point::UpdateAttack ( int attack )
{
    this->attack += attack;
}

void Point::UpdateDefense ( int defense )
{
    this->defense += defense;
}

void Point::UpdateLife ( int life )
{
    this->life += life;
}

void Point::UpdatePower ( enum LocalPower power )
{
    this->power = power;
}

void Point::AddToCurrentSoldier ( Soldier& soldier )
{
    this->current_soldiers.push_back ( soldier );
    this->UpdateLife ( soldier.GetLife() );
    this->UpdateAttack ( soldier.GetAttack() );
    if(this->GetPower() != _empty)
        this->UpdateDefense ( soldier.GetDefence() );
    this->UpdateNumber ( 1 );
}

void Point::RemoveFromCurrentSoldier ( unsigned int _id )
{
    this->current_soldiers.erase ( this->current_soldiers.end() - 1 );
    this->UpdateLife ( -this->current_soldiers[_id].GetLife() );
    this->UpdateAttack ( -this->current_soldiers[_id].GetAttack() );
    this->UpdateNumber ( -1 );
}
