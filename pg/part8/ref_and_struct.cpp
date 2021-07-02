#include <iostream>
#include <string>
#include <Windows.h>
struct my_struct
{
    std::string name;
    int years_old;
};
void refcubeBAD(int&);
double refcube(const double&);

int main()
{
    std::cout << "tmp value and lvalue rvalue"<< "\n--------------------------" << std::endl;
    //1 - Временная переменная создается, когда аргумент не соответствует ссылочному аргументу
    // Временная переменная создается: При условии, что ссылочный параметр является const
    //  - когда тип аргумента выбран правильно, но параметр не является lvalue
    //  - кодга тип параметра выбран неправильно, но может быть преобразован в правильный тип
    long valLong = 5L;
    int valInt = 5;
    short valShort = 5;
    std::cout << "valInt in power 3" << std::endl;
    std::cout <<"addres valInt: "<< &valInt << std::endl;
    refcubeBAD(valInt);
    std::cout << valInt << std::endl;
    std::cout << "refcubeBAD(valLong) ?" << std::endl;
    // refcubeBAD(valLong); не дает 
    //refcubeBAD(valShort); cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    std::cout <<"addres valShort: "<< &valShort << std::endl;
    double res = refcube(valShort);
    //Можно видеть, что valShort имеет разные адреса => создавалась временная переменная
    std::cout << res << std::endl << std::endl << std::endl<< std::endl;

    std::cout << "ref and struct"<< "\n--------------------------" << std::endl;
    my_struct ms = {};
    
}
/*
    если делать refcubeBAD(double& ref), а потом
    refcubeBAD(x + 0.3) <- это плохо
    refcube(x + 0.3) <- это хорошо
*/
double refcube(const double &ref)
{
    std::cout << "addres ref in refcub(): "<<&ref<<std::endl;
    return ref*ref*ref;
}

void refcubeBAD(int& ref)
{
    std::cout << "addres ref in refcubeBAD(): "<<&ref<<std::endl;
    ref = ref*ref*ref;
}