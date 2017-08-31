#ifndef COMMDER_H
#define COMMDER_H
#include <iostream>
#include <vector>
#include <string>
#include "user.h"

using namespace std;

class Commder
{
public:
    enum STATUS {main = 0, practice, war, exit};
    enum STATUS status;

    Commder ( User*& user );

    bool Eval ( string& cmd );
private:
    User* user;
    vector<string> history;
    void _Show_History();
    void _Show_Manual();
    void _Current_Page();
};
#endif // COMMDER_H
