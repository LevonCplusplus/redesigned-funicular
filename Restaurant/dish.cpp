#include <iostream>
#include <string>
#include "dish.h"

Dish:: Dish(std::string dishName, double dishPrice):m_name(dishName),m_price(dishPrice){}

//Dish:: Dish(const Dish& other):Dish(other.m_name,other.m_price){}

// Dish& Dish:: operator=(const Dish& other){
//     if(this == &other)
//     {
//         exit(-1);
//     }
//     m_name = other.m_name;
//     m_price = m_price;
// }
// Dish:: Dish(Dish&& other) noexcept{
//     m_name = std::move(m_name);
//     m_price = other.m_price;
//     other.m_price = 0;
// }
// Dish& Dish:: operator=(Dish&& other) noexcept{
//     if(this == &other)
//     {
//         exit(-1);
//     }
//     m_name = std::move(m_name);
//     m_price = other.m_price;
//     other.m_price = 0;
// }
 void Dish:: display() const{
    std::cout << "DishName: " << m_name << "\tDishPrice: "<< m_price << std::endl;
}
double Dish:: getPrice() const{
    return m_price;
}
std::string Dish:: getName() const{
    return m_name;
}

Appetizer:: Appetizer(std::string dishName, double dishPrice, bool spicy):Dish(dishName,dishPrice){
      m_isSpicy = spicy;
}
void Appetizer::display()const{
    std::cout << "DishName: " << m_name << "\tDishPrice: "<< m_price ;
    if(m_isSpicy)
    {
        std:: cout<< "\tisSpicy" <<std::endl;
    }
}

Entree:: Entree(std::string dishName, double dishPrice, int cal):Dish(dishName,dishPrice){
    m_calories = cal;
}
void Entree:: display() const{
    std::cout << "DishName: " << m_name << "\tDishPrice: "<< m_price <<"\tCalories"<<std::endl; 
}

Dessert:: Dessert(std::string dishName, double dishPrice, bool nuts):Dish(dishName,dishPrice){
    m_containsNuts = nuts;
}
void Dessert:: display()const{
    std::cout << "DishName: " << m_name << "\tDishPrice: "<< m_price ;
    if(m_containsNuts)
    {
        std:: cout<< "\tContain nuts"<<std::endl;
    }
}

    
    