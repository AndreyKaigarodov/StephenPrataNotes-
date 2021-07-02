#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <iterator>

using namespace std;
//1 task
void printSeveralSentence(const char* str_ptr, int amount = 1)
{
    for(int i=0; i < amount; i++)
    {
        cout<<str_ptr;
    }
    cout << endl;
}

//2 task 
struct CandyBar
{
    string name;
    float weight;
    unsigned int calories;
};

void initCandyBar(CandyBar& refCandyBar, const char* name = "Millennium Munch", float weigth = 2.85, unsigned int calories = 350)
{
    refCandyBar.name = name;
    refCandyBar.weight = weigth;
    refCandyBar.calories = calories;
}

void printCandyBar(CandyBar& refCandyBar)
{
    cout<<"struct CandyBar: "<< &refCandyBar << endl;     
    cout<<"Name: "<< refCandyBar.name << endl;
    cout<<"Weigth: " << refCandyBar.weight << endl;
    cout << "calories: " << refCandyBar.calories << endl << endl;
}

//3 task
void toUpperCase(string& ref_str)
{
    for(auto& ch : ref_str)
    {
        ch = toupper(ch);
    }
}

void mainloopTask3()
{
    string user_string;
    cout << "Enter a string (q to quit): ";
    cin >> user_string;
    while(user_string != "q")
    {
        toUpperCase(user_string);
        cout << user_string << endl;
        cout<< "Next sting (q to quit): ";
        cin >> user_string;
    }
    cout << "Bye"<<endl;
}

//4 task Дан прототип:
struct stringy
{
    char* str;
    int ct; //длина строки не считая \0
};
//Даны прототипы void set(stringy& str, char* ), show(stringy& str, int amount = 1), show(char[] ch_ptr, int amount = 1) 
void set(stringy& str_ref, const char ch_ptr[])
{
    //Будем считать, что мы не должны в str хранить \0 
    str_ref.ct = strlen(ch_ptr);
    str_ref.str = new char [str_ref.ct];
    //cout << str_ref.str
    strcpy(str_ref.str, ch_ptr);
}
 
void show(const char ch_ptr[], int amount = 1 )
{
    for(int i=0; i < amount; i++)
    {
        cout<<ch_ptr;
    }
    cout << endl;
}

void show(const stringy& ref_str, int amount = 1)
{
    for(int i=0; i < amount; i++)
    {
        printf("%.*s",ref_str.ct,ref_str.str);
    }
    cout << endl;
}

//5
/*
template <typename T>
T findMax(T* head_arr, T* end_arr)
{
    T max_el = head_arr[0];
    for(; head_arr != end_arr; head_arr++)
    {
        if(*head_arr > max_el) max_el = *head_arr;
    }
    return max_el;
}
*/
template <typename T>
T max5(T* ptr_arr)
{
    T max_val = ptr_arr[0];
    for(int i = 0; i < 5; i++)
    {
        if(*(ptr_arr+i)>max_val ) max_val = *(ptr_arr+i); 
    }
    return(max_val);
}

//6
template <typename T> auto maxn(T* ptr_arr, int n = 1)
{
    cout <<"m1" << endl;
    T max_val = ptr_arr[--n];
    while ((--n)>=0)
    {
        
        if(ptr_arr[n]>max_val) max_val = ptr_arr[n];
    }
    return max_val;
} 
//ля, мб можно лучше
template<> auto maxn<>(const char ** a, int n)
{
    cout << "m2" << endl;
    --n;
    int max_counter = strlen(a[n]);
    const char* ptr_max_str = a[n];
    while ((--n)>=0)
    {
        const char* ptr_str_head = a[n];
        if(strlen(ptr_str_head) >= max_counter)
        {
            ptr_max_str = ptr_str_head;
            max_counter = strlen(ptr_str_head);
        }
    }
   return ptr_max_str;
}

//7
//check tempover.cpp file
int main() 
{
    //#1 task
    cout << endl << "1 TASK" << endl; 
    const char* str_task1 = "test1_str_task1";
    printSeveralSentence(str_task1);
    printSeveralSentence("test1_tmp_string");
    printSeveralSentence("test1_tmp + amount param",3);

    //#2 task
    cout << endl << "2 TASK" << endl; 
    CandyBar test_task2 = {};
    initCandyBar(test_task2);
    printCandyBar(test_task2);
    CandyBar test2_task2 = {};
    initCandyBar(test2_task2, "Some name", 13.223, 334);
    printCandyBar(test2_task2); 

    //#3 task
    cout << endl << "3 TASK" << endl;
    //mainloopTask3();
    
    //#4 task
    cout << endl << "4 TASK" << endl;
    char test_arr[] = "test1_task3";
    stringy str;
    set(str, test_arr);
    test_arr[0]='_';
    show(str, 3);
    show(test_arr);

    //#5 task
    cout << endl << "5 TASK" << endl;  
    int int_arr[] = {11,2,3,-532,55,6,234324,44,55,66,7534543};
    double double_arr[] = {23.66, 23.55,333.11,44.234};
    char ch_arr[] = {'a','b','z','c'};
    //cout << "max in int arr: " << findMax(int_arr, &int_arr[11]) << endl;
    //cout << "max in double arr: " << findMax(double_arr, &double_arr[3] ) << endl;
    //cout << "max in char arr: " << findMax(ch_arr, &ch_arr[3]) << endl;
    cout << "max in int arr (max5): " << max5(int_arr) << endl;
    cout << "max in double arr (max5): " << max5(double_arr) << endl;
    cout << "max in char arr (max5): " << max5(ch_arr) << endl;

    //#6 task
    cout << endl << "6 TASK" << endl;
    cout << "max in int arr (maxn): " << maxn(int_arr,5) << endl;
    cout << "max in double arr (maxn): " << maxn(double_arr,3) << endl;
    const char* str1 = "str12222222";
    const char* str2 = "str22111111";
    const char* str3 = "str33222222";
    const char* ch_ptr_arr[] = {str1, str2, str3};
    cout << maxn(ch_ptr_arr, 3) << endl;
    return 0;
}