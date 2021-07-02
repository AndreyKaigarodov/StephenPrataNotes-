#include "golf.h"
#include <string.h>
#include <string>
#include <iostream>
#include <ctype.h>
namespace Golf
{

    void setgolf(golf &gf, const char *fullname, int hp)
    {
        strcpy(gf.fullname, fullname);
        gf.handicap = hp;
    }

    int setgolf(golf &gf)
    {
        std::cout << "Input fullname: ";
        char tmp_inp;
        std::cin.getline(gf.fullname, Len).get();
        std::cout << "Input fullname: ";
        std::cin >> gf.handicap;

        if ((strlen(gf.fullname) == 0) || !isalpha(gf.fullname[0]))
            return 0;
        return 1;
    }

    void handicap(golf &gf, const int hc)
    {
        gf.handicap = hc;
    }

    void showgolf(const golf &gf)
    {
        std::cout << gf.fullname << std::endl;
        std::cout << gf.handicap << std::endl;
    }

}