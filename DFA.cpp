#include "DFA.h"

using namespace std;
void DFA::addpattern(string pattern) {
    DFA_node* c = root;
    for (int i = 0; i < pattern.size(); i++) {
        if (c->trans.find(pattern[i]) == c->trans.end()) {
            // no such transport
            c->trans.insert(make_pair(pattern[i], new DFA_node));
        } 
        c = c->trans[pattern[i]];
        if (i == pattern.size() - 1) 
            c -> final_state = true; // final state
    }
}

vector<int> DFA::matches(string str) {
    vector<int> ans;
    DFA_node* c = root;
    for (int i = 0; i < str.size(); i++) {
        if (c->trans.find(str[i]) != c->trans.end()) {
            c = c->trans[str[i]];
            if (c->final_state)
                ans.push_back(i);
        }
    }
    return ans;
}