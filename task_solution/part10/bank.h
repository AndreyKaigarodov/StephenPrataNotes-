#ifndef Bank_H_
#define Bank_H_

class Bank
{
public:
    Bank();
    Bank(const char* name, const char account_num[17] = "asdf", long balance = 0);
    void getInfo();
    void deposit (long cash);
    void withdraw (long cash);
private:
    char* m_name;
    char* m_account_num;
    long m_balance; 
    //tatic char* getRndAccountNum();
};
#endif