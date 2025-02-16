#include "BankAccount.h"
BankAccount::BankAccount():m_accountHolder{"Unknown"},m_accountNumber{0},m_balance{0.0}{};
BankAccount::BankAccount(const std::string & name,int number, double balance){

    m_accountHolder=name;
    m_accountNumber=number;
    m_balance=balance;
}
BankAccount::BankAccount(const BankAccount & other)
{
  this->m_accountHolder=other.m_accountHolder;
  this->m_accountNumber=other.m_accountNumber;
  this->m_balance=other.m_balance;
}
BankAccount::~BankAccount(){
    std::cout<<"object was deleted"<<std::endl;
}
int BankAccount:: getAccountNumber()const{
    return m_accountNumber;
}
std::string BankAccount::getAccountHolder()const{
    return m_accountHolder;
}
double BankAccount:: getAccountbalance()const{
    return m_balance;
}
void BankAccount:: deposit (double amount){
   if(amount<0)
   {
    exit(-1);
   }
    this->m_balance+=amount;
}
bool BankAccount:: withdraw(double amount){
   if(amount <= m_balance)
   {
    m_balance -= amount;
    return true;
   }
   std::cout<<"error"<<std::endl;
   return false;
}
void BankAccount:: display()const{
   std::cout<<"Holder name -"<<m_accountHolder<<std::endl<<"Number -"<<m_accountNumber<<std::endl<<"Balance -"<<m_balance<<std::endl;
}