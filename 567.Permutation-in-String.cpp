/*
Given two strings s1 and s2, write a function to return true 
if s2 contains the permutation of s1. In other words, 
one of the first string's permutations is the substring 
of the second string.
 
Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:

    The input strings only contain lower case letters.
    The length of both given strings is in range [1, 10,000].
*/

#ifdef LOCAL_DEBUG
#include "defines.h"

class Solution {
public:

    void get_permutation(set<string>& pers, string& s1, int s) {
        if (s == s1.size()) {
            cout << s1 << endl;
            // pers.insert(s1);
        }
        for (int i = s; i < s1.size(); i++) {
            swap(s1[i], s1[s]);
            get_permutation(pers, s1, i + 1);
            swap(s1[i], s1[s]);
        }
    }

    bool checkEqual(int s1n[26], int s2n[26]) {
        for (int i = 0; i < 26; i++) {
            if (s1n[i] != s2n[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int s1n[26] = {0}, s2n[26] = {0};
        if (s1.size() > s2.size())
            return false;
        int n1 = s1.size();
        int n2 = s2.size();
        int i;

        for (i = 0; i < n1; i++) {
            s1n[s1[i] - 'a']++;
            s2n[s2[i] - 'a']++;
        }

        if (checkEqual(s1n, s2n))
            return true;

        for (; i < n2; i++) {
            s2n[s2[i - n1] - 'a']--;
            s2n[s2[i] - 'a']++;
            if (checkEqual(s1n, s2n))
                return true;
        }
        return false;
    }
};

int main(void) {
    Solution s;
    cout << s.checkInclusion("ab", "eidbaooo") << endl;
    cout << s.checkInclusion("ab", "eidboaoo") << endl;
    cout << s.checkInclusion("trinitrophenylmethylnitramine",
                        "dinitrophenylhydrazinetrinitrophenylmethylnitramine") << endl;
    cout << s.checkInclusion("ab", "eidbaooo") << endl;

    return 0;
}

#endif