#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "order.h"
#include "menu.h"
#include "restaurant.h"
    
Restaurant:: Restaurant():m_customers(0),m_orders(0),m_menu{}{};
// Restaurant:: Restaurant(const Restaurant& other){
//     m_menu = other.m_menu;
    
//     for(int i = 0;i < m_customers.size(); ++i )
//     {
//       //m_customers
//     }
// }
// Restaurant& Restaurant:: operator=(const Restaurant& other){
             
// }
void Restaurant :: adddishmenu(Dish& dish)
{
   m_menu.addDish(&dish);
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
    return *this;
}

Restaurant:: ~Restaurant(){
    for(int i = 0;i < m_customers.size(); ++i )
    {
        delete m_customers[i];
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
    std:: cout<<" no such a customer" <<std::endl;
    return nullptr;
}

void Restaurant:: placeNewOrder(const std::string& customerName){
    std::string contactInfo;
    std::cout << "please enter your contact info" << std::endl; 
    std::cin >> contactInfo;
    Customer * cust = new Customer(customerName,contactInfo); 
    Order order(cust);
    showMenu();
    int p = 1;
    while(p)
    {
        std::cout<<"enter dish name"<<std::endl;
        std::string k;
        std:: cin >> k;
        if( m_menu.getDishByName(k) ){
            order.addDish(m_menu.getDishByName(k));
        }
        std::cout << "if you want something else enter 1 \n otherwise enter 0" << std::endl;
        std::cin >> p;
    }
    cust->placeOrder(order);
    m_customers.push_back(std::move(cust));
    m_orders.push_back(order);
    
   std:: cout << "your total price is" << order.Totalprice() << std::endl;
}

void Restaurant:: viewCustomerOrderHistory(const std::string& customerName) const{
    for(int i = 0;i < m_customers.size(); ++i )
    {
        if( m_customers[i] -> getName() == customerName )
        {
          m_customers[i] -> viewOrderHistory();
        }
    }
}
