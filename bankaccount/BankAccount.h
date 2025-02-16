#include <iostream>
#include <string>
class BankAccount{
    std::string m_accountHolder;
    int m_accountNumber;
    double m_balance;
public:
  BankAccount();
  ~BankAccount();
  BankAccount(const std::string &,int ,double);
  BankAccount(const BankAccount&);
  int getAccountNumber()const;
  double getAccountbalance()const;
  std::string getAccountHolder()const;
  void deposit (double amount);
  bool withdraw(double amount);
  void display()const;
};
