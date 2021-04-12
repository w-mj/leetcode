#include <bits/stdc++.h>
#include "LCtester.h"
using namespace std;

vector<string> split(const string& str, char delim=' ') {
    vector<string> ans;
    auto it = str.begin();
    while (it != str.end()) {
        auto e = find(it, str.cend(), delim);
        ans.emplace_back(it, e);
        if (e == str.cend())
            break;
        it = e + 1;
    }
    return ans;
}


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> r = split(path, '/');
        vector<string> p;
        for (const string& rp: r) {
            if (rp == "." || rp == "")
                continue;
            else if (rp == "..") {
                if (!p.empty())
                    p.pop_back();
            }
            else
                p.emplace_back(rp);
        }
        stringstream ans;
        for (const string& rp: p) {
            ans << "/" << rp;
        }
        if (p.empty())
            return "/";
        return ans.str();
    }
};

template<typename Res, typename... Args>
Res frowarder(Args... args) {
    Solution s;
    return s.simplifyPath(args...);
} 

int main(void) {
    // vector<string> in = {
    //     "/home/",
    //     "/../",
    //     "/home//foo/",
    //     "/a/./b/../../c/",
    //     "/a/../../b/../c//.//",
    //     "/a//b////c/d//././/.."
    // };

    // vector<string> out = {
    //     "/home",
    //     "/",
    //     "/home/foo",
    //     "/c",
    //     "/c",
    //     "/a/b/c"
    // };

    // Solution s;
    // for (size_t i = 0; i < in.size(); i++) {
    //     cout << "Input: " << in[i] << endl;
    //     cout << "Output: " << s.simplifyPath(in[i]) << endl;
    //     cout << "Expect: " << out[i] << endl << endl;
    // }

    Tester<string, string>(__FILE__);

    return 0;
}