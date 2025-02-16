#include "BankSystem.h"
BankSystem::BankSystem(){};
void BankSystem:: addAccount(const std::string & name, int accountNumber,double initialBalance){
      BankAccount b(name,accountNumber,initialBalance);
        m_bank.push_back(b);
}
BankAccount * BankSystem:: findAccount(int accountNumber){
      for (int i = 0;i < m_bank.get_Size();++i)
      {
        if(m_bank.at(i).getAccountNumber() == accountNumber)
        {
          return &m_bank.at(i);
        }
      } 
      return nullptr;
    }
void BankSystem:: transferFunds(int senderAcc,int reciverAcc,double amount)
{
  BankAccount * sender = findAccount(senderAcc);
  BankAccount * reciver = findAccount(reciverAcc);
  if((!reciver) || (!sender))
  {
    exit(-1);
  }
  sender->withdraw(amount);
  reciver->deposit(amount);
}
void BankSystem:: displayAllAccounts()
{
  for(int i=0;i<m_bank.get_Size();++i)
  {
    std::cout<<"holder-"<<m_bank.at(i).getAccountHolder()<<std::endl<<"balance-"<<m_bank.at(i).getAccountbalance()<<std::endl;
  }
}
