// LRU cache (IMPORTANT)

#include<iostream>
#include<stack>
using namespace std;

// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// queue (FIFO)
// . . . .


class LRUCache {
public:
    deque<pair<int, int>> q;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(q.size() == 0) return -1;
        for(auto i: q){
            if(i.first == key) {
                q.push_front({i.first, i.second});
                if(q.size() > size) q.pop_back();
                return i.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(q.size() > size) q.pop_back();
        q.push_front({key, value});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */