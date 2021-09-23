#include "defines.h"

class SeatManager {
public:
    priority_queue<int, vector<int>, less<int>> qu;
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            qu.push(i);
        }
    }
    
    int reserve() {
        int k = qu.top();
        qu.pop();
        return k;
    }
    
    void unreserve(int seatNumber) {
        qu.push(seatNumber);
    }
};