#include "defines.h"

class Solution {
public:
    bool lmts(int n, vector<vector<int>>& connections, int exp = 0) {
        vector<int> fr(n, 0);
        for (size_t i = 0; i < n; i++)
            fr[i] = i;
        for (size_t i = 0; i < connections.size(); i++) {
            if (i == exp)
                continue;
            auto route = connections[i];
            int a = min(route[0], route[1]);
            int b = max(route[0], route[1]);
            fr[b] = fr[a];
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
    }
};