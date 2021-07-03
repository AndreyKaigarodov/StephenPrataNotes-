#include <string>
using std::string;

class Person
{
private:
    static const short SIZE = 25;
    string lname;
    char fname[SIZE];

public:
    Person() { lname = "", fname[0] = '\0'; };
    Person(const string &ln, const char *fn = "Anon");
    void Show() const;
    void FormalShow() const;
};

