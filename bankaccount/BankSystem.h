#include <iostream>
#include "BankAccount.h"
#include "vector.h"
class BankSystem{
    Vector <BankAccount> m_bank;
public:
    BankSystem();
    void addAccount(const std::string & name, int accountNumber,double initialBalance);
    BankAccount* findAccount(int accountNumber);
    void transferFunds(int senderAcc,int reciverAcc,double amount);
    void displayAllAccounts();
};