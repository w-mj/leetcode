#include "defines.h"

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size() - 1) {
            return *max_element(arr.begin(), arr.end());
        }

        vector<int> loser;
        loser.reserve(arr.size());
        loser.push_back(0);
        int win_cnt = 0;
        int cur_winner = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (cur_winner > arr[i]) {
                loser.push_back(arr[i]);
                win_cnt += 1;
            } else {
                loser.push_back(cur_winner);
                cur_winner = arr[i];
                win_cnt = 1;
            }
            if (win_cnt == k) {
                return cur_winner;
            }
        }
        loser[0] = cur_winner;
        return getWinner(loser, k);
    }
};


int main() {
    vector<int> arr = getVectorOfInt("[1,25,35,42,68,70]");
    Solution s;
    cout << s.getWinner(arr, 2) << endl;
}