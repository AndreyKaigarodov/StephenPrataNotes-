// tempover.cpp --- template overloading
#include <iostream>

template <typename T>            // template A
T ShowArray(T arr[], int n);

template <typename T>            // template B
T ShowArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3]; 

// set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    
    cout << "Listing Mr. E's sum of things: "<< ShowArray(things, 6) << endl;  
    // uses template A
    cout << "Listing Mr. E's sum of debts: " << ShowArray(pd, 3) << endl;      // uses template B (more specialized)
    // cin.get();
    return 0;
}

template <typename T>
T ShowArray(T arr[], int n)
{
    using namespace std;
    T res = 0;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        res += arr[i];
    return res;
}

template <typename T>
T ShowArray(T * arr[], int n)
{
    T res = 0;
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++)
        res += *arr[i];
    return res;
}
