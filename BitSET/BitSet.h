#include <iostream>
#include <vector>
class  BitSet{
  std::vector <int> bits;
size_t size;
size_t getIndex(size_t) const;
size_t getPos(size_t)const;
public:
BitSet();
BitSet(const BitSet&);
~BitSet();
  void set(size_t pos,bool bit);
void reset(size_t );
void flip(size_t );
bool test(size_t )const;
size_t count()const;
size_t getsize()const;
void print();
};
