#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <vector>
#include "dish.h"
#include "customer.h"
class Customer;
class Order {
    private:
        Customer* m_customer;
        std::vector<Dish*> m_orderedDishes;
        double m_totalPrice;
    public:
        Order() = default;
        Order(Customer* customer);
        Order(const Order& other) = default;
        Order& operator=(const Order& other) = default;
        Order(Order&& other) noexcept;
        Order& operator=(Order&& other) noexcept;
        ~Order();
        double Totalprice()const;
        void addDish(Dish* dish);
        void displayOrder() const;
    };

#endif