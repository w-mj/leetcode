#include "defines.h"

static void _split(const std::string &s, char delim, 
                   std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
 
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
 
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    _split(s, delim, elems);
    return elems;
}

struct Trans{
    string city;
    int time;
    int amount;
    string r;
    Trans(const vector<string>& s, const string& r): r(r) {
        city = s[3];
        time = stoi(s[1]);
        amount = stoi(s[2]);
    }
    bool operator<(Trans& ano) {
        return time > ano.time;
    }
};
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        map<string, vector<Trans>> t;
        for (const auto &s: transactions) {
            auto x = split(s, ',');
            if (t.find(x[0]) == t.end())
                t.emplace(x[0], vector<Trans>());
            t[x[0]].emplace_back(x, s);
        }
        set<string> ans;
        for (auto x: t) {
            string last_city;
            int last_time = -1;
            for (auto tran: x.second) {
                if (tran.amount > 1000) {
                    ans.emplace(tran.r);
                }
                for (auto ano: x.second) {
                    if (abs(ano.time - tran.time) <= 60 && ano.city != tran.city) {
                        ans.emplace(tran.r);
                        break;
                    }
                }
            }
        }
        vector<string> a;
        for (auto& x: ans)
            a.emplace_back(x);
        return a;
    }
};