#include "defines.h"

class DinnerPlates {
public:
    int cap;
    
    vector<stack<int>> st;
    vector<int> full;
    vector<int> empty;

    DinnerPlates(int capacity): cap(capacity) {
    }
    
    void push(int val) {
        if(empty.size() == 0) {
            empty.emplace_back(st.size());
            sort(empty.begin(), empty.end());
            st.emplace_back(stack<int>());
        }
        st[empty[0]].push(val);
        if (st[empty[0]].size() == 1) {
            full.emplace_back(empty[0]);
            sort(full.begin(), full.end());
        }
        if (st[empty[0]].size() == cap) {
            empty.erase(empty.begin());
        }
    }
    
    int pop() {
        if (full.size() == 0)
            return -1;
        int a = st[full.back()].top();
        st[full.back()].pop();
        if (st[full.back()].size() == cap - 1) {
            empty.emplace_back(full.back());
            sort(empty.begin(), empty.end());
        }
        if (st[full.back()].size() == 0) {
            full.erase(full.end() - 1);
        }
        return a;
    }
    
    int popAtStack(int index) {
        if (index >= st.size() || st[index].size() == 0)
            return -1;
        int a = st[index].top();
        st[index].pop();
        if (st[index].size() == cap - 1) {
            empty.emplace_back(index);
            sort(empty.begin(), empty.end());
        }
        if (st[index].size() == 0) {
            full.erase(find(full.begin(), full.end(), index));
        }
        return a;
    }
};

int main()
{

}