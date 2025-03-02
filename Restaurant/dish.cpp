#include <iostream>
#include <string>

Dish::Dish(std::string dishName, double dishPrice):name(dishName),double(price){}

Dish::Dish(const Dish& other):Dish(other.m_name,other.m_price){}

Dish& Dish:: operator=(const Dish& other){
    m_name = other.m_name;
    m_price = m_price;
}
Dish:: Dish(Dish&& other) noexcept{
    m_name = std::move(m_name);
    m_price = other.m_price;
    other.m_price = 0;
}
Dish& Dish:: operator=(Dish&& other) noexcept{
    m_name = std::move(m_name);
    m_price = other.m_price;
    other.m_price = 0;
}
void Dish:: display() const{
    std::cout << "DishName: " << m_name << "\nDishPrice: " << std::endl;
}
double Dish:: getPrice() const{
    return m_price;
}
std::string Dish:: getName() const{
    return m_name;
}

    
    