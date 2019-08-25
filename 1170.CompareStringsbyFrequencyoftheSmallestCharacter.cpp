#include "defines.h"

int f(const string& s) {
    char c = s[0];
    for (auto t: s)
        if (t < c)
            c = t;
    return count(s.begin(), s.end(), c);
}

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fw, ans;
        // transform(words.begin(), words.end(), fw.begin(), f);
        for (auto x: words) {
            fw.emplace_back(f(x));
        }
        for (auto q: queries) {
            int fq = f(q);
            int a = 0;
            for (int fww: fw) {
                if (fq < fww)
                    a++;
            }
            ans.emplace_back(a);
        }
        // transform(queries.begin(), queries.end(), ans.begin(), [&](const string& q) {
        //     int fq = f(q);
        //     return count_if(fw.begin(), fw.end(), [&](int a){
        //         return fq < a;
        //     });
        // });
        return ans;
    }
};

int main(void) {

}