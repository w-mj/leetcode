#include "defines.h"

class MyHashSet {
public:
    bool data[(int)1e6 + 10];
    MyHashSet() {
        memset(data, 0, sizeof(data));
    }
    
    void add(int key) {
        data[key] = 1;
    }
    
    void remove(int key) {
        data[key] = 0;
    }
    
    bool contains(int key) {
        return data[key];
    }
};
