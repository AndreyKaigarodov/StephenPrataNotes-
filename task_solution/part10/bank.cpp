#include "bank.h"
#include <iostream>
#include <string.h>

Bank::Bank(){
    //m_name = new char[10];
    //m_account_num = new char;
    //m_balance = 0;
}

Bank::Bank(const char* name, const char account_num[17], long balance){
    m_name = new char[strlen(name)+1];
    strcpy(m_name, name);
    strncpy(m_account_num, account_num,15);
    m_balance = balance;
}

void Bank::getInfo(){
    std::cout << m_account_num << std::endl;
    std::cout << m_name << std::endl;
    std::cout << m_balance << std::endl;
}

void Bank::deposit(long cash){

}

void Bank::withdraw(long cash){

}


