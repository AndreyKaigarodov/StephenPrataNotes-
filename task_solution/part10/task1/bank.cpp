#include "bank.h"
#include <iostream>
#include <string.h>

Bank::Bank() {}

Bank::Bank(const char *name, long balance)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    const char *rnd_num = getRandomAccountNum();
    strcpy(m_account_num, rnd_num);
    m_balance = balance;
}

const char *Bank::getRandomAccountNum()
{
    char *ch_ptr = new char[17];
    ch_ptr[17] = '\0';
    for (char *tmp_ptr = ch_ptr; *tmp_ptr != '\0'; tmp_ptr++)
    {
        int a = 10;
        *tmp_ptr = (char)a;
    }
    return ch_ptr;
}

void Bank::getInfo()
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Bank account: " << m_account_num << std::endl;
    std::cout << "Balance: " << m_balance << std::endl;
}
//модификатор конст
void Bank::deposit(long cash)
{
    if (cash > 0)
    {
        m_balance += cash;
        std::cout << "Balance: " << m_balance << std::endl;
        std::cout << "Sucess, add: " << cash << std::endl;
    }
    else
    {
        std::cout << "error: bad value of cahs !" << std::endl;
    }
}

void Bank::withdraw(long cash)
{
    std::cout << "Balance: " << m_balance << std::endl;
    if (m_balance >= cash)
    {
        m_balance -= cash;
        std::cout << "Cash: " << cash << std::endl;
    }
    else
    {
        std::cout << "error: not enough funds to withdraw !" << std::endl;
    }
}
