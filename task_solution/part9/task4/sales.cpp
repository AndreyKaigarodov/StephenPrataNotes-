#include "sales.h"
#include <iostream>
namespace SALES
{
    using std::cin;
    using std::cout;
    using std::endl;

    void setSales(Sales &s, const double ar[], int n = QUARTERS)
    {
        for (int i = 0; i < n; i++)
        {
            if (i >= QUARTERS)
            {
                double *tmp = getMax(s.sales, s.sales + QUARTERS);
                if (ar[i] < *tmp)
                    *tmp = ar[i];
            }
            else
                s.sales[i] = ar[i];
        }
        culcSales(s);
    }
    void setSales(Sales &s)
    {
        cout << "Input four sales: " << endl;
        for (short i = 0; i < QUARTERS; i++)
        {
            cout << "[" << i << "] : ";
            cin >> s.sales[i];
            //не хочу писать обработку крайних случаев ((((((
        }
        culcSales(s);
    }
    void showSales(const Sales &s)
    {

        cout << "Sales &: " << &s << endl;
        cout << "Sales: ";
        for (int i = 0; i < QUARTERS; i++)
        {
            cout << s.sales[i] << " ";
        }
        cout << endl;
        cout << "Max: " << s.max << endl;
        cout << "Min: " << s.min << endl;
        cout << "Avrg: " << s.average << endl;
    }

    static double *getMax(double *start, double *end)
    {
        int step_from_max = 0;
        for (; start != end; start++, step_from_max++)
        {
            if (*start > *(start - step_from_max))
                step_from_max = 0;
        }
        return (start - step_from_max);
    }

    static void culcSales(Sales &s)
    {
        s.max = s.sales[0];
        s.min = s.sales[0];
        s.average = 0;
        for (double *ptr = s.sales; ptr != s.sales + QUARTERS; ptr++)
        {
            if (*ptr > s.max)
                s.max = *ptr;
            else if (*ptr < s.min)
                s.min = *ptr;
            s.average += *ptr;
        }
        s.average = s.average / QUARTERS;
    }

}