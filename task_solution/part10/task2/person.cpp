#include <string.h>
#include "person.h"
#include <iostream>
Person::Person(const string &ln, const char *fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    if (lname != "" && strlen(fname) != 0)
    {
        std::cout << fname << " " << lname << std::endl;
    }
}
void Person::FormalShow() const
{
    if (lname != "" && strlen(fname) != 0)
    {
        std::cout << lname << ", " << fname << std::endl;
    }
}