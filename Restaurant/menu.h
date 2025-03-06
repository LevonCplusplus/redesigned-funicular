#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <vector>
#include <string>
#include "dish.h"
class Menu {
    private:
        std::vector<Dish*> m_dishes;
    public:
        Menu();
        // Menu(const Menu& other);
        // Menu& operator=(const Menu& other);
        Menu(Menu&& other) noexcept;
        Menu& operator=(Menu&& other) noexcept;
        ~Menu();
        void addDish(Dish* dish);
        void displayMenu() const;
        int getdishcount()const;
        Dish* getDishByName(const std::string& dishName) const;
    };
#endif