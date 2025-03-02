std::vector<Dish*> m_dishes;



Menu:: Menu(const Menu& other){
    for(int i = 0; i < m_dishes.size(); ++i )
    {
        m_dishes[i]= new Dish(*other.m_dishes[i]);
    }
}
Menu& Menu:: operator=(const Menu& other){
 
    for(int i = 0; i < m_dishes.size(); ++i )
    {
        delete [] m_dishes[i];
    }
    for(int i = 0; i < m_dishes.size(); ++i )
    {
        m_dishes[i]= new Dish(*other.m_dishes[i]);
    }
}
Menu:: Menu(Menu&& other) noexcept{
    
    m_dishes = std::move(other.m_dishes);
}
Menu& Menu:: operator=(Menu&& other) noexcept{
    m_dishes = std::move(other.m_dishes);
}
Menu:: ~Menu(){
   for(int i = 0;i < m_dishes.size(); ++i)
   {
     delete [] m_dishes[i];
   }
}
void Menu:: addDish(Dish* dish){
    m_dishes.push_back(dish);
}
void Menu:: displayMenu() const{
    for( int i = 0; i < m_dishes.size();++i)
    {
        m_dishes[i]-> display();
    }
}
Dish* Menu:: getDishByName(const std::string& dishName) const{
    for( int i = 0; i < m_dishes.size();++i)
    {
        if(m_dishes[i]-> getName() == dishName){
            return m_dishes[i];
        }
    }
}