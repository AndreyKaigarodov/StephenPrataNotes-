/*
схемы хранения
 - внутреннее связывание static
 - внешнее связывание   extern глобальные без статик
 - автоматические локальные
1 вопрос.
а - автоматическая переменная
б - глобальная переменная, в другом файле extern
в - static внутреннее связывание
г - static локальная переменная без связывания
*/

/*
2 вопрос. 
различие между директивой/объявлением using
объявление using:
    синтаксис using Name::value
    Перетаскивает все только имя value
    value = 1+1 допустимо
    int value = 10; ОШИБКА имя уже существует

деректива using:
    синтаксис using namespace Name
    Перетаскивает все имена
    int value = 10; - перекроет value, объявленное ранее
   
*/

/*
3 вопрос переписать код чтобы не было ни объявления,
ни директивы using
#include <iostream> 
using namespace std; 
int main () 
{ 
    double х; 
    cout << "Enter value : " ; 
    while (! (cin >> х) ) 
    { 
        cout << "Bad input. Please enter а number : " ; / / неверный ввод 
        cin.clear(); 
        while(cin.get() != '\n') 
        continue; 
    }
    cout << "Value = " << х << endl ; 
    return О; 
}

Ну тип изменил

#include <iostream> 
int main () 
{ 
    double х; 
    std::cout << "Enter value : " ; 
    while (!(cin >> х)) 
    { 
        std::cout << "Bad input. Please enter а number : " ; // неверный ввод 
        std::cin.clear(); 
        while(std::cin.get() != '\n') 
        continue; 
    }
    std::cout << "Value = " << х << std::endl ; 
    return О; 
}
*/

/*
4 вопрос
Опять переписать код - использовать объявления вместо директив
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl; 
    double x;
    cout << "Enter value: ";
    while(!(cin >> x))
    {
        cout << "Bad input. pls enter a number";
        cin.clear();
        while(cin.get()!='\n') continue;
    }
    cout << "value = " << x << endl;
    return 0;
}
*/
/*
5 вопрос.
чет хз
*/
/*
6 вопрос
    10
    4
    0
    10, 1
    10, -4
*/

/*
7 вопрос
    4, 1, 2
    2
    2
    4, 1, 2
    2
*/