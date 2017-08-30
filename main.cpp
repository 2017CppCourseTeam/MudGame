#include <iostream>
#include "user.h"
using namespace std;

int main()
{
    User user("123", "123");
    user.Login();
    user.Register();
    user.Login();
    return 0;
}
