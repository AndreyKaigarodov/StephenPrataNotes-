#include "person.h"
int main()
{
    Person per;
    per.Show();
    per.FormalShow();
    Person per1 = Person("Andrey", "Kaigarodov");
    per1.Show();
    per1.FormalShow();
    Person per2 = Person("Andrey");
    per2.Show();
    per2.FormalShow();
    return 0;
}
