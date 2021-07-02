#include "bank.h"
#include <iostream>
#include <string.h>

Bank::Bank()
{
    //m_name = new char;
    //m_account_num = new char;
    m_balance = 0;
}

Bank::Bank(const char *name, const char account_num[17], long balance)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    strcpy(m_account_num, account_num);
    m_balance = balance;
}

void Bank::getInfo()
{
    std::cout << m_account_num << std::endl;
    std::cout << m_name << std::endl;
    std::cout << m_balance << std::endl;
}

void Bank::deposit(long cash)
{
}

void Bank::withdraw(long cash)
{
}
