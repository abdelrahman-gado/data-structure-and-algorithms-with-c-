#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>

template <typename HashedObj>
class HashTable
{
public:
    
    explicit HashTable (int size = 101);
    
    bool contains (const HashedObj & x) const;
    
    void makeEmpty();
    bool insert (const HashedObj & x);
    bool insert ( HashedObj && x);
    bool remove (const HashedObj & x);
    
private:
    
    std::vector<std::list<HashedObj>> theLists;
    int currentSize;
    
    void rehash();
    size_t myhash( const HashedObj & x) const;
    
};

#endif // HASHTABLE_H
