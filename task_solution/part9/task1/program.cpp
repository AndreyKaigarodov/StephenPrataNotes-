#include "golf.h"
#include <iostream>

int main()
{
    
    Golf::golf test;
    Golf::setgolf(test);
    Golf::showgolf(test);
    Golf::setgolf(test, "Loli pop", 20);
    Golf::handicap(test, 200);
    Golf::showgolf(test);
    return 0;
}
