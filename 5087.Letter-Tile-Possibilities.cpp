#ifdef LOCAL_DEBUG
#include "defines.h"
class Solution {
public:
    int numTilePossibilities(string tiles) {
        if (tiles.size() == 0)
            return 0;
        int ans = 0;
        set<string> cnads;
        set<string> pers;
        sort(tiles.begin(), tiles.end());
        ans = 1;
        pers.insert(tiles);
        cnads.insert(tiles);
        while(next_permutation(tiles.begin(), tiles.end())) {
            cnads.insert(tiles);
            ans++;
        }
        for (string t: cnads) {
            tiles = t;
            for (size_t i = 0; i < tiles.size(); i++) {
                for (size_t l = 1; l <= tiles.size() - i; l++) {
                    string x = tiles.substr(i, l);
                    sort(x.begin(), x.end());
                    if (pers.find(x) != pers.end())
                        continue;
                    //cout << x << "  ";
                    pers.insert(x);
                    int cnt = 1;
                    //cout << "\n====\n";
                    while (next_permutation(x.begin(), x.end())) {
                        //pers.insert(x);
                        cnt++;
                        //cout << x<< endl;
                    }
                    //cout << "\n=====\n";
                    ans += cnt;
                    //cout << cnt << "  " << pers.size() << endl;
                }
            }
        }
        return ans;
    }
};

int main(void) {
    Solution s;
    cout << s.numTilePossibilities("AAB") << endl;
    cout << s.numTilePossibilities("AAABBC") << endl;
    cout << s.numTilePossibilities("EE") << endl;

    return 0;
}

#endif