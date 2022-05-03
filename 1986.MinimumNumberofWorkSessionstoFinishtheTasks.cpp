#include "defines.h"
#include <cstring>

class Solution {
public:
    int memo[1 << 15];

    void solve(int depth, int free, int cur, vector<int> &tasks){
        if (depth == tasks.size()){
            memo[cur] = 1;
            return;
        }

        if (free >= tasks[depth]){
            solve(depth + 1, free - tasks[depth], cur | (1 << depth), tasks);
        }
        solve(depth + 1, free, cur, tasks);
    }

    int minSessions(vector<int> &tasks, int sessionTime) {
        int n = tasks.size();
        for (int i = 0; i < (1<<15); i++) {
            memo[i] = n;
        }
        solve(0, sessionTime, 0, tasks);

        for (int i = 0; i < (1 << n); i++){ 
            for (int j = i; j > 0; j = (j - 1) & i){ 
                memo[i] = min(memo[i], memo[j] + memo[i ^ j]);
            }
        }

        return memo[(1 << n) - 1];
    }
};
// int main(void) {
//   Solution s;
//   vector<int> task;
//   // task = getVectorOfInt("[1,7]");
//   // cout << s.minSessions(task, 7) << endl;
//   task = getVectorOfInt("[4,4,4,4,5,5,5,5,6,6,6,6,7,7]");
//   cout << s.minSessions(task, 15) << endl;
// }

string binary(int n, int len) {
    string ans(len, '0');
    for (int i = 0; i < len; i++) {
        ans[len - i - 1] = (n & 1) + '0';
        n >>= 1;
    }
    return ans;
}


int main() {
    int n = 4;
     for (int i = 0; i < (1 << n); i++) { 
        for (int j = i; j > 0; j = (j - 1) & i){ 
            cout << binary(i, n) << "=" << binary(j, n) << '^' << binary(i ^ j, n) << endl;
            // memo[i] = Math.min(memo[i], memo[j] + memo[i ^ j]);
        }
    }
}