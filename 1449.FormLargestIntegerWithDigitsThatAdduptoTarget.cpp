#include "defines.h"

class Solution {
public:
  bool isBigger(const string &n1, const string &n2) {
    if (n1.size() != n2.size()) {
      return n1.size() > n2.size();
    }
    for (int i = 0; i < n1.size(); i++) {
      if (n1[i] != n2[i]) {
        return n1[i] > n2[i];
      }
    }
    return false;
  }

  string largestNumber(vector<int> &cost, int target) {
    vector<string> dp(target + 1);
    for (int i = 0; i <= target; i++) {
      dp[i] = "0";
    }
    dp[0] = "";
    for (int i = 0; i < 9; i++) {
      for (int t = 1; t <= target; t++) {
        if (t - cost[i] >= 0 && dp[t - cost[i]] != "0") {
          string s = to_string(i + 1) + dp[t - cost[i]];
          if (isBigger(s, dp[t])) {
            dp[t] = s;
          }
        }
      }
    }
    return dp[target];
  }
};

int main(void) {
  Solution s;
  vector<int> cost = getVectorOfInt("[4,3,2,5,6,7,2,5,5]");
  cout << s.largestNumber(cost, 9) << endl;
  cost = getVectorOfInt("[7,6,5,5,5,6,8,7,8]");
  cout << s.largestNumber(cost, 12) << endl;
  cost = getVectorOfInt("[2,4,6,2,4,6,4,4,4]");
  cout << s.largestNumber(cost, 5) << endl;
  cost = getVectorOfInt("[1,1,1,1,1,1,1,3,2]");
  cout << s.largestNumber(cost, 10) << endl;
  cost = getVectorOfInt("[13,12,9,12,15,11,10,11,15]");
  cout << s.largestNumber(cost, 52) << endl;

  /*
7772
85
0
7777777777
97333
  */
}