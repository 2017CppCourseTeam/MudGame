#ifndef MAPBUILDER_H
#define MAPBUILDER_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Map.h"

using namespace std;

class MapBuilder
{
    public:
        MapBuilder(unsigned int height, unsigned int width, string name, unsigned short level);
        ~MapBuilder();

        void DrawMap();
        void ShowMap();
        void SaveMap();

        bool SetPlayerBaseCity(unsigned int x, unsigned int y);
        bool SetAIBaseCity(unsigned int x, unsigned int y);
        bool SetEmptyCity(unsigned int x, unsigned int y);
        bool SetPlayerCity(unsigned int x, unsigned int y);
        bool SetAICity(unsigned int x, unsigned int y);
    private:
        unsigned int* height;
        unsigned int* width;
        unsigned int* _level;
        string* level;
        string* name;
        unsigned char** _map;

        template <class T>
        string _ConverNumToString ( T d );
        string _Encrypt(string str);
        void _Write ( ofstream& f );
        void _InitMap();
};

#endif // MAPBUILDER_H
