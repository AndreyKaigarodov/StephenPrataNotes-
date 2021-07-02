// static.cpp -- using a static local variable
#include <iostream>
#include <string>
// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string &);

int main()
{
    using namespace std;
    string inp_string;
    char next;

    cout << "Enter a line:\n";
    getline(std::cin, inp_string);
    while (inp_string != "")
    {
        strcount(inp_string);
        cout << "Enter next line (empty line to quit):\n";
        getline(std::cin, inp_string);
    }
    cout << "Bye\n";
    // code to keep window open for MSVC++
    /*
cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
    return 0;
}

void strcount(const std::string &ref)
{
    using namespace std;
    static int total = 0; // static local variable
    int count = 0;        // automatic local variable

    cout << "\"" << ref << "\" contains ";
    count = ref.length();
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n";
}
