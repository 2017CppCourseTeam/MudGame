#ifndef COMMDER_H
#define COMMDER_H
#include <vector>
#include <string>

using namespace std;

class Commder
{
public:
    Commder();
    vector<string> cmd;
    bool Eval();
};
#endif // COMMDER_H
