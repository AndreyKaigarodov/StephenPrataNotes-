#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <array>
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
#1. Какие разновидности функций являются хорошими кандидатами на то, чтобы
быть встроенными?
Ответ: Если время выполнения функции намного больше, чем время вызова, то такую
функцию нет смысла делать inline. Если функция отрабатывает намного быстрее, чем время,
затраченное на ее вызов, то ее можно сделать inline.

#2. Предположим, что функция song ( ) имеет следующий прототип
void song ( char * name , int times ) ;
    a. Как модифицировать этот прототип , чтобы для переменной times по умолчанию принималось значение 1?
        void song ( char * name , int times=1 ) ;
    б. Какие изменения следует внести в определение функции?
        void song (const? char * name , int times=1 ) ;
    в. Можно ли переменной name присвоить используемое по умолчанию значение
    " О , Му Рара "?
        нет

#3. Напишите перегруженные версии функции iquote(), которая отображает аргументы, заключенные в двойные кавычки. 
Напишите три версии: одну для аргумента типа int, другую для аргумента типа douЫe и третью для аргумента типа string.
Решение:
*/
//Простой вариант
/*
string iquote(int inp)
{
    return to_string(inp);
}
string iquote(double inp)
{
    return to_string(inp);
}
string iquote(string inp)
{
    return inp;
}
*/
//Интересный вариант
template <typename T>
string iquote(T inp)
{
    return to_string(inp);
}

template<> string iquote(string str)
{
    return str;  
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#4. Есть структура:
struct box
{
 char maker[40];
 float height;
 float width;
 float length;
 float volume;
};
/*
a. Напишите функцию, которая имеет формальный аргумент - ссылку на структуру
box и отображает значения каждого члена структуры
б. Напишите функцию, которая имеет формальный аргумент - ссылку на структуру
box и устанавливает член volume в результат произведения членов height, width и length
*/
//решение 4.а
void foo_box(const box& ref)
{
    cout << "maker: " << ref.maker << endl;
    cout << "height: " << ref.height << endl;
    cout << "width: " << ref.width << endl;
    cout << "length: " << ref.length << endl;
    cout << "volume: " << ref.volume << endl; 
}
//решение 4.б
void culc_volum(box& ref)
{
    ref.volume = ref.width*ref.length*ref.height; 
}

/*
Какие изменения понадобится внести в листинг 7.15, чтобы функции fill() и
show () использовали ссылочные параметры?
*/
const int Seasons = 4;
const array<string, Seasons> Snames =
    {"Spring", "Summer", "Fall", "Winter"};

//Было: 
void fill(array<double, Seasons> * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(array<double, Seasons> da)
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    cout << "Total: $" << total << '\n';
}

//Стало:
void fill_ref(array<double, Seasons>& ref_arr)
{
    for(int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> ref_arr[i];
    }
}

void show_ref(array<double, Seasons>& ref_arr) 
{
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << ref_arr.at(i) << '\n';
        total += ref_arr.at(i);
    }
    cout << "Total: $" << total << '\n';
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#6.
double mass(double, double volume=1);
double repeat(string);
double repeat(int, string);
template<typename T>
T average(T arg1,T arg2)
{
    return (arg1 + arg2)/2;
}
char mangle(const char* ptr_ch)
{
    return *ptr_ch;
}
void* mangle(char* ptr_ch)
{
    return static_cast<void*>(ptr_ch);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#7
template<typename T1, typename T2> 
auto max_task7(T1 arg1, T2 arg2)
{
    return (arg1 > arg2) ? arg1 : arg2;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//#8
template<> auto max_task7(box* b1, box* b2) //явная специализация шаблона
{
    //!!!!template<> auto max_task7<box&>(box& b1, box& b2)
    //не получается передать ссылку
    return (b1->volume > b2->volume) ? b1 : b2;
}
//#9 Какие типы назначены переменным v1, v2, v3, v4 и v5 в коде ниже
/*
ing g(int x)
float m = 5.5f;
float& rm = m;
decltype(m) v1 = m; float
decltype(rm) v2 = m; float
decltype((m)) v3 = m; float&
decltype(g(100)) v4; int
decltype(2.0*m) v5; double
*/
int main() 
{
    //3question
    {
    cout << endl<< "3question" << endl;
    int a = 10;
    double b = 40;
    string str = "my string";
    cout << iquote(a) << endl;
    cout << iquote(b) << endl;
    cout << iquote(str) << endl;
    }
    //4question
    {
    cout << endl<< "4question" << endl;
    box box_examle = {"STRUCT", 2,3,4};
    culc_volum(box_examle);
    foo_box(box_examle);
    }
    //5question
    {
        cout << endl<< "5question" << endl;
        array <double, Seasons> test_array;
        //fill_ref(test_array);
        //show_ref(test_array);
    }
    
    //6question
    cout << endl<< "6question" << endl;
    int arg1 = 4;
    int arg2 = 5;
    double dbl1 = 3.4;
    double dbl2 = 4.566;
    cout <<"avr int: "<< average(arg1,arg2) << endl;
    cout <<"avr double: "<< average(dbl1,dbl2) << endl;
    
    char* str = "I'm glad to meet you"; 
    cout << "adress first char in str: " << (void*)str << endl;
    cout << "mangle_define_string: " << mangle(str) << endl;
    cout << "mangle_with_tmp_string: " << mangle("I'm glad to meet you")<< endl;

    //7question
    cout << endl<< "7question" << endl;
    int a1 = 3;
    int a2 = 4;
    double d2 = 11221.12123;
    cout <<"max(a1,a2)" << max_task7(a1,a2) << endl;
    cout <<"max(a1,d2)" << max_task7(a1,d2) << endl; 
    cout <<"max(3,5)" << max_task7(3,5) << endl;

    //8question
    cout << endl<< "8question" << endl;
    box box1 = {"BOX1", 2,3,4};
    box box2 = {"BOX2", 54,23,4};
    cout <<"max is "<< max_task7(&box1, &box2)->maker << endl;
    
    //9question
    #include <typeinfo>
    cout << endl<< "9question" << endl;
    int g(int x);
    float m = 5.5f;
    float& rm = m;
    float test_var = 123.321;
    
    cout << m << endl;
    decltype(m) v1 = m;
    decltype(rm) v2 = m; 
    decltype((m)) v3 = m;
    decltype(g(100)) v4;
    decltype(2.0*m) v5;
    cout<<typeid(v1).name()<<endl;
    cout<<typeid(v2).name()<<endl;
    cout<<typeid(v3).name()<<endl;
    cout<<typeid(v4).name()<<endl;
    cout<<typeid(v5).name()<<endl;
    return 0;
}