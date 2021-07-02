#include <iostream>
#include <array>
#include <string>
//Вопросы
//1
char actor[30];
short bersie[100];
float chuck[13];
long double dipsea[64];
//2
std::array<int, 30> m_actor;
std::array<short, 100> m_bersie;
std::array<float, 13> m_chuck;
std::array<long double, 64> m_dipsea;
//3
int arr[5] = {1,3,5,7,9};
//4
int even = *arr + *(arr+4);
//5
std::array<float, 4> ideas = {1,2,3,4};
float* ptr_second_el = &ideas.at(1);
//6
char mystring[] = "cheeseburger";
//7
std::string my_string = "Waldorf Salad";
//8
struct fish
{
    std::string type;
    int weight;
    float length;
};
//9
fish my_fish = {"myFish", 10,1.5};
//10
enum Response {no, yes, maybe};
//11
double ted = 10.4;
double* ted_ptr = &ted;
//12
float arrFloat[] = {1,2,3,4,5,6,7,8,9,10}; //arraFloat - указатель на первый элемент 
//13
int* CreateArray(){
    int tmp_length; 
    std::cin >> tmp_length;
    int* arr = new int[tmp_length];
    std::cout << arr << std::endl;
    return arr; 
}
int main(){
    using namespace std;
    
    cout << my_fish.type << endl;
    cout << no << endl;
    cout << *ted_ptr << endl;
    cout << "first el: " << *arrFloat << " sec el: " << *(arrFloat + 9) << endl;
    
    int* arr = CreateArray();
    cout << arr << endl;
    *arr = 1;
    *(arr + 1) = 2;
    cout << *arr << " "<< *(arr + 1) << endl;
    //delete arr;

    string s = "Home of the j olly byte s ";
    cout << (int*)&(s[0]) <<endl;

    return 0;
}

