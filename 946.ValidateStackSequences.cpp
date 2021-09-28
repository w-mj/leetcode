#include "defines.h"

class Solution {
public:
    bool validateStackSequences(const vector<int>& pushed, const vector<int>& popped) {
        stack<int> st;
        int popIdx = 0;
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            while (!st.empty() && popped[popIdx] == st.top()) {
                st.pop();
                popIdx++;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    cout << s.validateStackSequences({1,2,3,4,5}, {4,5,3,2,1}) << endl;
    cout << s.validateStackSequences({1,2,3,4,5}, {4,5,3,1,2}) << endl;
}