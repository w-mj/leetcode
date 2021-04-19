#include "defines.h"


class ExamRoom {
public:
    set<int> q;
    int N;
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        int last = -1;
        int ans = 0;
        if (!q.empty()) {
            int maxLength = *q.begin();
            for (int c: q) {
                if (last >= 0) {
                    int length = (c - last) / 2;
                    if (length > maxLength) {
                        ans = last + length;
                        maxLength = length;
                    }
                }
                last = c;
            }
            if (N - last - 1 > maxLength)
                ans = N - 1;
        }
        q.insert(ans);
        return ans;

    }
    
    void leave(int p) {
        q.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */