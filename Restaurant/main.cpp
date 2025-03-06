#include <iostream>
#include "restaurant.h"
#include "customer.h"
#include "menu.h"
#include "order.h"
#include "dish.h"
int main(){
    Restaurant ellada;
   
    Dish dish1("xash",1200);
    Dish dish2("xorovac",1300);
    Dish dish3("apur",900);
    ellada.adddishmenu(dish1);
    ellada.adddishmenu(dish2);
    ellada.adddishmenu(dish3);

    ellada.placeNewOrder("Levon");
   return 0;
}