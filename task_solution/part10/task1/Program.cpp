#include "bank.h"

int main()
{
    Bank bank("Yarik", 3234);
    bank.getInfo();
    bank.deposit(1000);
    bank.deposit(-1);
    bank.withdraw(500);
    bank.withdraw(4000);
    return 0;
}