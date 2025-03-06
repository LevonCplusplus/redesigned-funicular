#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
#include "order.h"
#include "menu.h"
class Restaurant {
    private:
        Menu m_menu;
        std::vector<Customer*> m_customers;
        std::vector<Order> m_orders;
    public:
    
        Restaurant();
        Restaurant(const Restaurant& other);
        Restaurant& operator=(const Restaurant& other);
        Restaurant(Restaurant&& other) noexcept;
        Restaurant& operator=(Restaurant&& other) noexcept;
        ~Restaurant();
        void showMenu() const;
        void adddishmenu(Dish&);
        Customer* getCustomerByName(const std::string& name);
        void placeNewOrder(const std::string& customerName);
        void viewCustomerOrderHistory(const std::string& customerName) const;
    }; 
    
#endif