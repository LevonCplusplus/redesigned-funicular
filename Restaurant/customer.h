#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "order.h"
class Customer {
    private:
        std::string m_name;
        std::string m_contactInfo;
        std::vector<Order> m_orderHistory;
    public:
            Customer(std::string customerName, std::string contact);
        Customer(const Customer& other);
        Customer& operator=(const Customer& other);
        Customer(Customer&& other) noexcept;
        Customer& operator=(Customer&& other) noexcept;
        ~Customer() = default;
        void placeOrder(Order order);
        void viewOrderHistory() const;
        std::string getName() const;
    };
#endif
    
    