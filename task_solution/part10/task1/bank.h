#ifndef Bank_H_
#define Bank_H_

class Bank
{
public:
    Bank(const char *name, long balance = 0);
    void getInfo();
    void deposit(long cash);
    void withdraw(long cash);

private:
    Bank();
    char *m_name;
    char m_account_num[17];
    long m_balance;
    const char *getRandomAccountNum();
    //tatic char* getRndAccountNum();
};
#endif