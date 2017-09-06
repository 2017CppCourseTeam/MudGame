#include "War.h"

War::War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num )
{
    this->life =  prestige ;
    this->magic = violence ;
    this->coin = bitcoin ;
    this->lucky =  war_num ;
    this->poing_selecter = 0;
    this->soldier_selecter = 0;
    this->_Load_Map ( string ( "standard" ), war_num + 1 );
}

War::~War()
{
    delete this->_map;
}

bool War::_Load_Map ( string name, unsigned short level )
{
    ifstream load;
    switch ( level )
    {
        case 1:
        {
            load.open (   ( string ( ".\\map\\" ) + name + string ( "1.dat" ) ).c_str(), ios::in );
            break;
        }
        case 2:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "2.dat" ) ).c_str() ), ios::in );
            break;
        }
        case 3:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "3.dat" ) ).c_str() ), ios::in );
            break;
        }
        case 4:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "4.dat" ) ).c_str() ), ios::in );
            break;
        }
        case 5:
        {
            load.open ( ( ( string ( ".\\map\\" ) + name + string ( "5.dat" ) ).c_str() ), ios::in );
            break;
        }
    }
    string _name = this->_Read ( load );
    string _level = this->_Read ( load );
    unsigned int _height = this->_ConvertStringToNum<unsigned int> ( this->_Read ( load ) );
    unsigned int _width = this->_ConvertStringToNum<unsigned int> ( this->_Read ( load ) );
    unsigned char** data;
    data = new unsigned char* [ _height ];
    for ( unsigned int i = 0; i < _height; i++ )
        data [ i ] = new unsigned char [ _width ];
    string _tmp;
    getline ( load, _tmp );
    for ( unsigned int i = 0, k = 0; i < _height; i++ )
    {
        for ( unsigned int j = 0; j < _width; j++ )
        {
            data[i][j] = _tmp[k++];
        }
    }
    this->_map = new Map ( _height, _width, _name, level, data );
    for ( unsigned int i = 0; i < _height; i++ )
        delete [ ]data [ i ];
    delete [ ]data;
    load.close();
}

template <class T>
T War::_ConvertStringToNum ( const string& str )
{
    istringstream iss ( str );
    T num;
    iss >> num;
    return num;
}

string War::_Decrypt ( string str )
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


string War::_Read ( ifstream & f )
{
    string _tmp;
    getline ( f, _tmp );
    return this->_Decrypt ( _tmp );
}


void War::Show_Status()
{
    cout << endl << endl << "[*]当前状态:" << endl;
    cout << endl << "[*]生命源: " << this->life << endl;
    cout << endl << "[*]魔法源: " << this->magic << endl;
    cout << endl << "[*]金钱: " << this->coin << endl;
    cout << endl << "[*]幸运值: " << this->lucky << endl;
}

void War::Show_Map ( bool show_detail )
{
    this->_map->Show_Map ( show_detail );
}

bool War::Select_Point ( unsigned int _x, unsigned int _y )
{
    if ( _x > this->_map->rwidth || _y > this->_map->rheight )
        return false;
    this->poing_selecter = this->_map->Get_Point ( _x, _y );
    return true;
}

void War::Show_Point_Status()
{
    cout << endl << "[*]当前地点(" << this->poing_selecter->GetX() << this->poing_selecter->GetY() << ")状态：" << endl;
    cout << "归属势力: " << this->poing_selecter->SGetPower() << endl;
    cout << "生命值: " << this->poing_selecter->GetLife() << endl;
    cout << "攻击力: " << this->poing_selecter->GetAttack() << endl;
    cout << "防御力: " << this->poing_selecter->GetDefense() << endl;
    cout << "士兵总数: " << this->poing_selecter->GetNumber() << endl;
}

bool War::Select_Soldier ( unsigned int id )
{
}

void War::Show_Soldier_Status ( unsigned int id )
{
}
