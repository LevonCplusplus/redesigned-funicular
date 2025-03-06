#ifndef DISH_H
#define DISH_H
#include <iostream>
#include <string>
class Dish {
    protected:
        std::string m_name;
        double m_price;
    public:
        Dish(std::string dishName, double dishPrice);
        Dish(const Dish& other) = default;
        Dish& operator=(const Dish& other) = default;
        Dish(Dish&& other) noexcept = default;
        Dish& operator=(Dish&& other) noexcept = default;
        ~Dish() = default;
        virtual void display() const;
        double getPrice() const;
        std::string getName() const;

    };



class Appetizer : public Dish {
        private:
            bool m_isSpicy;
        public:
            Appetizer(std::string dishName, double dishPrice, bool spicy);
            void display() const;
        };

class Entree : public Dish {
        private:
            int m_calories;
        public:
            Entree(std::string dishName, double dishPrice, int cal);
            void display() const;
        };
class Dessert : public Dish {
        private:
            bool m_containsNuts;
        public:
            Dessert(std::string dishName, double dishPrice, bool nuts);
            void display() const;
        };
        
#endif