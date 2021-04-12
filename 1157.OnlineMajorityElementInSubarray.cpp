#include "defines.h"

class MajorityChecker {
public:
    vector<int> arr;
    vector<pair<int, int>> qujian[20010];
    MajorityChecker(vector<int>& arr1): arr(arr1) {
        for (size_t i = 0; i < arr1.size(); i++) {
            int x = arr1[i];
            if (qujian[x].empty()) {
                qujian[x].emplace_back(make_pair(i, i));
            } else {
                if (qujian[x].back().second == i - 1)
                    qujian[x].back().second = i;
                else 
                    qujian[x].emplace_back(make_pair(i, i));
            }
        }
        for (size_t i = 0; i < 20010; i++) {
            if (qujian[i].empty()) 
                continue;
            cout << i << " " ;
            for (auto &x: qujian[i]) {
                cout << "(" << x.first << ','<<x.second<<")";
            }
            cout <<endl;
        }
    }
    
    int query(int left, int right, int threshold) {
        int cnt = 0;
        for (int x = 0; x <= 20001; x++) {
            if (qujian[x].empty())
                continue;
            cnt = 0;
            for (auto &q: qujian[x]) {
                int a = q.first;
                int b = q.second;
                a = max(a, left);
                b = min(b, right);
                if (a > b)
                    continue;
                cnt += b - a + 1;
            }
            if (cnt >= threshold)
                return x;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */