#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "order.h"
#include "menu.h"
    
Restaurant:: Restaurant():m_customers(0),m_orders(0),m_menu{}
{}
Restaurant:: Restaurant(const Restaurant& other){
    m_menu = other.m_menu;
    
    for(int i = 0;i < m_customers; ++i )
    {
      m_customers
    }
}
Restaurant& Restaurant:: operator=(const Restaurant& other){
             
}
Restaurant:: Restaurant(Restaurant&& other) noexcept{
    m_menu = std::move(other.m_menu);
    m_customers = std::move(other.m_customers);
    m_orders = std::move(other.m_orders);
}
Restaurant& Restaurant:: operator=(Restaurant&& other) noexcept{
    m_menu = std::move(other.m_menu);
    m_customers = std::move(other.m_customers);
    m_orders = std::move(other.m_orders);
}
Restaurant:: ~Restaurant(){
    for(int i = 0;i < m_customers.size(); ++i )
    {
        delete [] m_customers[i];
    }
}
void Restaurant:: showMenu() const{
    m_menu.displayMenu();
}
Customer* Restaurant:: getCustomerByName(const std::string& name){
    for(int i = 0;i < m_customers.size(); ++i )
    {
        if( m_customers[i] -> getName() == name )
        {
            return m_customers[i];
        }
    }
}
void Restaurant:: placeNewOrder(const std::string& customerName){
    for(int i = 0;i < m_customers.size(); ++i )
    {
        if( m_customers[i] -> getName() == customerName )
        {
            m_customers[i]-> placeOrder();               //harceeeeeeeeeeeeer
        }
    }
}
void Restaurant:: viewCustomerOrderHistory(const std::string& customerName) const{
    for(int i = 0;i < m_customers.size(); ++i )
    {
        if( m_customers[i] -> getName() == customerName )
        {
          m_customers[i] -> viewCustomerOrderHistory();
        }
    }
}