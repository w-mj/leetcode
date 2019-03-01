#include <map>
#include <string>
#include <vector>

class DFA {
public:
    void addpattern(std::string pattern);
    std::vector<int> matches(std::string str);
private:
    struct DFA_node {
        bool final_state = false;
        std::map<char, DFA_node*> trans;
    };
    DFA_node* root = new DFA_node;
};