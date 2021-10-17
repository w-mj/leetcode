#include "defines.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<int> roadTo[102];        
        for(auto& r: roads) {
            roadTo[r[0]].insert(r[1]);
            roadTo[r[1]].insert(r[0]);
        }
        int maxv = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = roadTo[i].size() + roadTo[j].size();
                if (roadTo[i].find(j) != roadTo[i].end()) {
                    t--;
                }
                maxv = max(maxv, t);
            }
        }
        return maxv;
    }
};

int main() {

}