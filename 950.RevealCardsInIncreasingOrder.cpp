#include "defines.h"

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> ans(deck.size(), 0);
        queue<int> a;
        for (int i = 0; i < deck.size(); i++) {
            a.push(i);
        }

        int cnt = 0;
        while (!a.empty()) {
            ans[a.front()] = deck[cnt];
            a.pop();
            a.push(a.front());
            a.pop();
            cnt++;
        }
        return ans;
    }
};

// int main() {
//     Solution s;
//     vector<int> v = getVectorOfInt("[17,13,11,2,3,5,7]");
//     cout << s.deckRevealedIncreasing(v) << endl;
// }

int main(void) {
    for (int n = 1; n <= 20; n++) {
        queue<int> a;
        for (int i = 0; i < n; i++) {
            a.push(i);
        }
        int last_out = 200000;
        cout << n << ": ";
        while (!a.empty()) {
            // if (a.front() < last_out) {
                cout << a.front() << ' ';
            // }
            last_out = a.front();
            a.pop();
            a.push(a.front());
            a.pop();
        }
        cout << endl;
    }
    return 0;
}