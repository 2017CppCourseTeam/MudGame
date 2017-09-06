#include "MapBuilder.h"

int main()
{
    cout << "MapBuilder for MudGame V0.1!" << endl;
    bool confirm = false;
    MapBuilder* Builder;
    while ( !confirm )
    {
        string _MapName;
        unsigned short _level;
        unsigned int _height, _width;
        cout << endl << "[*]Map name: ";
        cin >> _MapName;
        cout << endl << "[*]Map level: ";
        cin >> _level;
        cout << endl << "[*]Map height: ";
        cin >> _height;
        cout << endl << "[*]Map width: ";
        cin >> _width;
        Builder = new MapBuilder ( _height, _width, _MapName, _level );
        Builder->ShowMap();
        cout << endl << "[*]Confirm this map?(y/n): ";
        string _choice;
        cin >> _choice;
        if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            confirm = true;
        else
            delete Builder;
    }
    confirm = false;
    int _x, _y;
    while ( true )
    {
        cout << endl << "[*]Set player base city:(exp: 0 0) ";
        cin >> _x >> _y;
        if ( Builder->SetPlayerBaseCity ( _x, _y ) )
        {
            cout << "[*]Set success." << endl;
            Builder->ShowMap();
            break;
        }
        else
        {
            cout << "[!]This point (" << _x << ", " << _y << ") has set another city or has out of range.";
        }
    }
    while ( true )
    {
        cout << endl << "[*]Set AI base city:(exp: 0 0) ";
        cin >> _x >> _y;
        if ( Builder->SetAIBaseCity ( _x, _y ) )
        {
            cout << "[*]Set success." << endl;
            Builder->ShowMap();
            break;
        }
        else
        {
            cout << "[!]This point (" << _x << ", " << _y << ") has set another city or has out of range.";
        }
    }
    while ( true )
    {
        while ( true )
        {
            cout << endl << "[*]Set empty city:(exp: 0 0)(-1 -1 for quit) ";
            cin >> _x >> _y;
            if ( _x == -1 && _y == -1 )
                break;
            else  if ( Builder->SetEmptyCity ( _x, _y ) )
            {
                cout << "[*]Set success." << endl;
                Builder->ShowMap();
            }
            else
            {
                cout << "[!]This point (" << _x << ", " << _y << ") has set another city or has out of range.";
            }
        }
        while ( true )
        {
            cout << endl << "[*]Set player city:(exp: 0 0)(-1 -1 for quit) ";
            cin >> _x >> _y;
            if ( _x == -1 && _y == -1 )
                break;
            else  if ( Builder->SetPlayerCity ( _x, _y ) )
            {
                cout << "[*]Set success." << endl;
                Builder->ShowMap();
            }
            else
            {
                cout << "[!]This point (" << _x << ", " << _y << ") has set another city or has out of range.";
            }
        }
        while ( true )
        {
            cout << endl << "[*]Set ai city:(exp: 0 0)(-1 -1 for quit) ";
            cin >> _x >> _y;
            if ( _x == -1 && _y == -1 )
                break;
            else  if ( Builder->SetAICity ( _x, _y ) )
            {
                cout << "[*]Set success." << endl;
                Builder->ShowMap();
            }
            else
            {
                cout << "[!]This point (" << _x << ", " << _y << ") has set another city or has out of range.";
            }
        }
        cout << endl << "[*]Final map:" << endl;
        Builder->ShowMap();
        string _choice;
        cout << endl << "[*]Confirm?(y/n)";
        cin >> _choice;
        if ( _choice == string ( "y" ) || _choice == string ( "Y" ) )
            break;
    }
    cout << endl << "[*]Saving map...";
    Builder->SaveMap();
    cout << endl << "[*]Done.";
    delete Builder;
    return 0;
}
