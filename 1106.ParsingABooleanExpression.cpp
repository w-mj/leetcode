#ifdef LOCAL_DEBUG
#include "defines.h"

struct Exp {
    int op; // 0 & 1 | 2 !
    vector<Exp> children;
    Exp(string& str, int s, int e) {
        // cout <<str.substr(s, e - s)<<endl;
        if (str[s] == '&') {
            op = 0;
        } else if (str[s] == '|') {
            op = 1; 
        } else if (str[s] == '!'){
            op = 2;
        } else if (str[s] == 't') {
          op = 5;
        } else if (str[s] == 'f') {
          op = 6;
        }
        int i = s + 2 ;
        int b = 1;
        int lasti = i;
        while (i < e) {
            if (str[i] == '(') {
                b++;
            }
            
            if (b == 1 && (str[i] == ',' || str[i] == ')')) {
                children.emplace_back(str, lasti, i);
                lasti = i + 1;
            }
            if (str[i] == ')') {
                b--;
            }
          i++;
        }
    }
    bool cal() {
      if (op == 5)
          return true;
      if (op == 6)
          return false;
        if (op == 2) {
            return ! children[0].cal();
        }
        if (op == 1) {
            for (auto x: children) {
                if (x.cal() == true)
                    return true;
            }
            return false;
        }
        if (op == 0) {
            for (auto x: children) {
                if (x.cal() == false)
                    return false;
            }
            return true;
        }
        //cout << "EE" <<op;
      return true;
    }
};
class Solution {
public:
    bool parseBoolExpr(string expression) {
        Exp e(expression, 0, expression.size());
        return e.cal();
    }
};

int main(void) {
    Solution s;
    cout << s.parseBoolExpr("!(f)") << endl;
    cout << s.parseBoolExpr("|(f,t)") << endl;
    cout << s.parseBoolExpr("&(t,f)") << endl;
    cout << s.parseBoolExpr("|(&(t,f,t),!(t))") << endl;

    return 0;
}

#endif