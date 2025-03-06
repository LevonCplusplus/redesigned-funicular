#include <iostream>
#include <vector>
#include "dish.h"
#include "order.h"

Order:: Order(Customer* customer){
    m_customer = customer;
}

// Order:: Order(const Order& other){
    
// }
// Order& operator=(const Order& other);  
Order:: Order(Order&& other) noexcept{
    m_customer = other.m_customer;
    other.m_customer = nullptr;
    m_orderedDishes = std::move(other.m_orderedDishes);
    m_totalPrice = other.m_totalPrice;
    
}
Order& Order:: operator=(Order&& other) noexcept
{
    if(this == &other)
    {
        exit(-1);
    }
    m_customer = other.m_customer;
    other.m_customer = nullptr;
    m_orderedDishes = std::move(other.m_orderedDishes);
    m_totalPrice = other.m_totalPrice;
    return *this;
}
Order::~Order() {}
void Order:: addDish(Dish* dish)
{
    m_orderedDishes.push_back(dish);
    m_totalPrice += dish->getPrice();
}
double Order:: Totalprice()const
{
    return m_totalPrice;
}
void Order:: displayOrder() const{
    for(int i = 0; i < m_orderedDishes.size(); ++i)
    {
        m_orderedDishes[i]->display();
    }
}
    