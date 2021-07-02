#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    Sales sales;
    Sales sales2;
    double arr[] = {6, 5, 4, 3, 2, 1};
    setSales(sales, arr, 6);
    showSales(sales);
    setSales(sales2);
    showSales(sales2);
}