#ifndef COMMDER_H
#define COMMDER_H
#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Commander
{
    public:
        Commander ( User*& user );
        bool Eval ( string& cmd );
        enum STATUS Get_Status();
    private:
        User* user;
        enum STATUS status;
        vector<string> history;
        void _Show_History();
        void _Show_Manual();
        template <class T>
        T _ConvertStringToNum ( const string& str );
        void _Current_Page();
};
#endif // COMMDER_H
