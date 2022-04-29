#include <vector>
#include <list>

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : buckets (1000000, -1){
    }
    
    void add(int key) {
        int index = hash(key);
        if (buckets[index] == key)
            return;
        buckets[index] = key;
    }
    
    void remove(int key) {
        int index = hash(key);
        if (buckets[index] == key && buckets[index] != -1)
            buckets[index] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = hash(key);
        if (buckets[index] == key)
            return true;
        else
            return false;
    }
    
private:
    std::vector<int> buckets;
    
    int hash(int key)
    {
        int index = (key % 1000001);
        return index;
    }
    
};