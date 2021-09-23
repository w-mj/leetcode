#include "defines.h"

class ProductOfNumbers {
public:
    vector<int> cache;
    ProductOfNumbers() {
        cache.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            cache.clear();
            cache.push_back(1);
        } else {
            int last = cache[cache.size()-1];
            cache.push_back(last * num);
        }
    }
    
    int getProduct(int k) {
        if(k < 1 || cache.size() <= k) {
            return 0;
        }
        int n = cache.size();
        int last = cache[cache.size()-1];
        return last / cache[n - k - 1];
    }
};

int main(void) {
    ProductOfNumbers s;
    s.add(3);
    s.add(0);
    s.add(2);
    s.add(5);
    s.add(4);
    cout << s.getProduct(2) << endl;
    cout << s.getProduct(3) << endl;
    cout << s.getProduct(4) << endl;
    s.add(8);
    cout << s.getProduct(2) << endl;
}