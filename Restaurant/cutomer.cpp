#include <iostream>
#include <string>
#include <vector>
#include "order.h"

Customer:: Customer(std::string customerName, std::string contact):m_name(customerName),m_contactInfo(contact),m_orderHistory(0) {}
Customer:: Customer(const Customer& other):Customer(other.m_name,other.m_contactInfo){
    m_orderHistory = other.m_orderHistory;
}
Customer& Customer:: operator=(const Customer& other){
    m_name = other.m_name;
    m_contactInfo = m_contactInfo;
    m_orderHistory = other.m_orderHistory;
}
Customer:: Customer(Customer&& other) noexcept{
    m_name = std::move(other.m_name);
    m_contactInfo = std::move(m_contactInfo);
    m_orderHistory = std::move(other.m_orderHistory);
}
Customer& Customer:: operator=(Customer&& other) noexcept{
    m_name = std::move(other.m_name);
    m_contactInfo = std::move(m_contactInfo);
    m_orderHistory = std::move(other.m_orderHistory);
}
Customer:: ~Customer() = default;
void Customer:: placeOrder(Order order){
    m_orderHistory.push_back(new Order(this));                      //harcerrr
}
void Customer:: viewOrderHistory() const{
    for(int i = 0; i < m_orderHistory.size(); ++i)
    {
        m_orderHistory.displayOrder(); 
    }
}
std::string Customer:: getName() const{
    return m_name;
}
    
    