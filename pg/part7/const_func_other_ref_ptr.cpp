#include <iostream>
using namespace std;

//заголовок может быть и таким:
//void foo (int* arr) так как в c++ int* ~ int[]
//чтобы не угробить массив можно заюзать const
//void foo(const int arr[])
void foo(int arr[]){
    //arr[0] = 100; эквивалент ниже
    *arr = 100;
}

//1 2 3 4 5 6 - поэтому n+1 (элементов то нам шесть нужно)
//0 1 2 3 4 5
//a a a a a \0
char * buildstring(char c, int n){
    char * ch = new char[n+1];
    ch[n] = '\0';
    while (n-- > 0)
    {
        cout << n << endl;
        ch[n]=c;
    }
    return ch;
}

void rec_func(int n){
    if(n != 0){
        cout << "go forward: "<< n << endl;
        rec_func(--n);
    }
    cout << "go back" << endl;
}

//Указатель на функцию и прочие приколдесы
double algoritmPlus (int a, int b){
    return a + b;
}

double algoritmMultiply (int a, int b){
    return a*b;
}
void calcSalaty(int a, int b, double (*pf)(int,int)){
    cout << "DAI DEHTr:" <<  pf(a,b) << endl;
}

int main(){
    /*
    int arr[] = {1,2,3,4,5};
    foo(arr);
    cout << *arr << endl;
    */
    
    /*константность
    //Очень интересный мув с указателями
    int **pp2;
    int *p1;
    int n = 13;
    pp2 = &p1;
    *pp2 = &n;
    cout << "pp2: " << pp2 <<endl;
    cout << "*pp2: " << *pp2 <<endl;
    cout << "**pp2: " << **pp2 <<endl;
    cout << "p1: " << p1 <<endl;
    cout << "*p1: " << *p1 <<endl;
    cout << "&n: " << &n <<endl;
    */
    
    /*работа с о строкой char*
    char * ch = buildstring('a', 5);
    cout << ch <<endl;
    delete []ch;
    */
    
    //rec_func(5); оцените размотку стека вызова функции
    
    //Указатель на функцю
    /*
    double (*pf)(int, int); //double *pf(int,int) - без скобок, это функция, которая вернет double*
    //Разблокируй одну из pf и получи приз
    //pf = algoritmPlus;
    pf = algoritmMultiply;
    calcSalaty(100,30,pf);   
    //поэтому ставим скобки, чтобы pf указывала на функцию
    //рил интересное дело внизу, вызов из указателя тк имя функции - указатель
    //и разыменование указателя - это тоже функция
    cout << pf(5,5)<<endl;
    cout << (*pf)(6,6)<<endl;
    */

   /*
   с помощью inline компилятор понимает, что данную функцию
   нужно раскрыть именно в этом месте. а не загружать ее 
   в оперативную память и обращаться к ней через некоторое время
   */
    /*ссылку нельзя поменять, но можно присвоить 
    ссылке указатель и менять указатьль C: */
    
    int my_value = 1;
    int my_value2 = 2;
    int* ptr_val = &my_value;
    int* &ref_ptr = ptr_val;
    ref_ptr = &my_value2;
    cout << *ref_ptr;

    /* 395 стр хороший промер с полиформизмом для ostream и ofstream*/

    /* 395 стр аргументы по умолчанию */
    /* 400 стр Перегрузки функции, на
    401 стр интересный пример с r-value и l-value для перегрузок */ 

    return 0;
}