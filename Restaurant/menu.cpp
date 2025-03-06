#include "menu.h"
//std::vector<Dish*> m_dishes;
// Menu:: Menu(const Menu& other){
//     for(int i = 0; i < m_dishes.size(); ++i )
//     {
//         m_dishes[i]= new Dish(*ot.m_dishes[i]);
//     }
// }
// Menu& Menu:: operator=(const Menu& other){
 
//     for(int i = 0; i < m_dishes.size(); ++i )
//     {
//         delete [] m_dishes[i];
//     }
//     for(int i = 0; i < m_dishes.size(); ++i )
//     {
//         m_dishes[i]= new Dish(*other.m_dishes[i]);
//     }
// }
Menu:: Menu():m_dishes(0){}
Menu:: Menu(Menu&& other) noexcept{
    
    m_dishes = std::move(other.m_dishes);
}
Menu& Menu:: operator=(Menu&& other) noexcept{
    m_dishes = std::move(other.m_dishes);
    return *this;
}
Menu:: ~Menu(){
//    for(int i = 0;i < m_dishes.size(); ++i)
//    {
//      delete  m_dishes[i];
//    }


}
void Menu:: addDish(Dish* dish){
    m_dishes.push_back(dish);
}
void Menu:: displayMenu() const{
     int k = 1;    
    for( int i = 0; i < m_dishes.size();++i)
    {
       std:: cout<< k++ <<" "; 
       m_dishes[i]-> display();
    }
}
int Menu:: getdishcount()const{
    return m_dishes.size();
}
Dish* Menu:: getDishByName(const std::string& dishName) const{
    for( int i = 0; i < m_dishes.size();++i)
    {
        if(m_dishes[i]-> getName() == dishName){
            return m_dishes[i];
        }
    }
    std:: cout << "we don't have that dish" << std::endl; 
    return nullptr;
}