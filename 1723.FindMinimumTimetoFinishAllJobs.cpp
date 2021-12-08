#include "defines.h"


// 贪心的错误样例：[5, 5, 4, 4, 4] 2

class Solution {
public:

    int ans = INT_MAX;

    void dfs(vector<int>& workers, const vector<int>& jobs, int depth) {
        if (depth == jobs.size()) {
            ans = min(ans, *max_element(workers.begin(), workers.end()));
            return;
        }
        set<int> vis;
        for (int i = 0; i < workers.size(); i++) {
            if (vis.find(workers[i]) != vis.end()) {
                continue;
            }
            vis.insert(workers[i]);
            workers[i] += jobs[depth];
            if (workers[i] < ans) {
                dfs(workers, jobs, depth + 1);
            }
            workers[i] -= jobs[depth];
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        vector<int> time(k, 0);
        for (int j: jobs) {
            int mini = min_element(time.begin(), time.end()) - time.begin();
            time[mini] += j;
        }
        ans = *max_element(time.begin(), time.end());

        vector<int> workers(k, 0);
        dfs(workers, jobs, 0);
        return ans;
    }
};

int main(void) {
    Solution s;
    vector<int> jobs = {6518448,8819833,7991995,7454298,2087579,380625,4031400,2905811,4901241,8480231,7750692,3544254};
    int k = 4;
    cout << s.minimumTimeRequired(jobs, k) << " " << 16274131 << endl;
    jobs = {254,256,256,254,251,256,254,253,255,251,251,255};
    k = 10;
    cout << s.minimumTimeRequired(jobs, k) << " " << 504 << endl;
}