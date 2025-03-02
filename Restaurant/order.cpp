#include <iostream>
#include <vector>
#include "dish.h"
#include "customer.h"
Customer* m_customer;
std::vector<Dish*> m_orderedDishes;
double m_totalPrice;

Order(Customer* customer){
    m_customer = customer;
}
Order(const Order& other){
    
}
Order& operator=(const Order& other);
Order(Order&& other) noexcept{
    m_customer = other.m_customer;
    other.m_customer = nullptr;
    m_orderedDishes = std::move(other.m_orderedDishes);
    m_totalPrice = other.m_totalprice;
    
}
Order& operator=(Order&& other) noexcept;
~Order() {
    for(int i = 0; i < m_orderedDishes.size(); ++i)
    {
        delete [] m_orderedDishes[i];
    }
}
void addDish(Dish* dish)
{
    m_orderedDishes.push_back(dish);
    m_totalPrice += dish->getPrice();
}
double Totalprice()const
{
    return m_totalPrice;
}
void displayOrder() const{
    for(int i = 0; i < m_orderedDishes.size(); ++i)
    {
        m_orderedDishes[i]->display();
    }
}
    