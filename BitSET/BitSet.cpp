#include "BitSet.h"

BitSet::BitSet():size(0),bits(0){};
BitSet::BitSet(const BitSet & other){
    this->size=other.size;
    this->bits=other.bits;
}
BitSet::~BitSet(){
    std::cout<<"the object was deleted"<<std::endl;
}
void BitSet::set(size_t pos,bool bit){
    size_t index = getIndex(pos);
    size_t pos1 = getPos(pos);
    if(index >= bits.size()){
        bits.resize(index + 1, 0);  
        size = bits.size()*32;
    }
    
    if(bit)
    {
      bits[index] = bits[index] | ( 1 << (32-pos1)); 
    }
    else{
        bits[index]=bits[index] & ~(1 << (32-pos1));
    }
}
void BitSet:: reset(size_t pos)
{
    set(pos,0);
}
void BitSet:: flip(size_t pos)
{
    size_t index = getIndex(pos);
    size_t pos1 = getPos(pos);
    bits[index] = bits[index] ^ (1 << (32-pos1));
}
bool BitSet:: test(size_t pos)const
{
    size_t index = getIndex(pos);
    size_t pos1 = getPos(pos);
    if((bits[index] & (1 << (32-pos1))) == bits[index])
    {
        return true;
    }
   return false;
}
size_t BitSet:: count()const
{ 
    int count=0;
    for(int i=0;i<bits.size();++i)
    {
        int k=bits[i];
        while(k>0)
        {
            if(k & 1 == k)
            {
               count++;
            }
            k/=2;
        }
    }
    return count;
}
void BitSet:: print()
{
    for(int i=0;i<bits.size();++i)
    {
        int k=bits[i];
        int c=32;
        while(c)
        {
            if((k |(1<<c)) == k )
            {
               std::cout<<1<<std::endl;
            }else
            std::cout<<0<<std::endl;
            c--;
        }
    }
}
size_t BitSet:: getsize()const{
    return size;
}
size_t BitSet:: getIndex(size_t pos)const{
    return pos/(sizeof(int)*8);
}
size_t BitSet:: getPos(size_t pos)const{
    return pos%(sizeof(int)*8);
}
