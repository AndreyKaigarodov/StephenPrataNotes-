class Bank
{
public:
    Bank();
    Bank(const char* name, const char account_num[17] = getRndAccountNum(), long balance = 0);
    void getInfo();
    void deposit (long cash);
    void withdraw (long cash);
private:
    char* name;
    char account_num[17];
    long balance; 
    static char* getRndAccountNum();
};