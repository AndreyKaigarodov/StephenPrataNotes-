#include <iostream>
#include <string.h>

char buffer[512];
const int amount = 2;
struct chaff
{
    char dross[20];
    int slag;
};
void setVal(chaff &cf, const char *ch, const int slag);
void show(const chaff &cf);
int main()
{
    buffer[0] = 'a';
    std::cout << "buffer[0] addr: " << (void *)&buffer[0] << " " << buffer[0] << std::endl;

    chaff *arr_ptr = new (buffer) chaff[amount];
    chaff *arr_ptr2 = new chaff[amount];
    std::cout << (void *)buffer << std::endl;
    std::cout << arr_ptr << std::endl;
    setVal(arr_ptr[0], "first elem", 12);
    setVal(arr_ptr[1], "second elem", 5);
    setVal(arr_ptr2[0], "first elem2", 12);
    setVal(arr_ptr2[1], "second elem2", 5);
    for (int i = 0; arr_ptr + i != &arr_ptr[amount]; i++)
    {
        show(arr_ptr[i]);
        show(arr_ptr2[i]);
    }
    for (int i = 0; i != 499; i++)
        std::cout << (void *)&buffer[i] << std::endl;
    return 0;
}

void setVal(chaff &cf, const char *ch, const int slag)
{
    strcpy(cf.dross, ch);
    cf.slag = slag;
}

void show(const chaff &cf)
{
    std::cout << "chaff addr:" << &cf << std::endl;
    std::cout << "chaff dross: " << cf.dross << std::endl;
    std::cout << "chaff slag: " << cf.slag << std::endl;
}