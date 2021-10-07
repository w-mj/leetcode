#include "defines.h"

class Solution {
public:
    struct Node {
        int n;
        int needs[6] = {0};
        int current = 0;
        Node(int n) {
            this->n = n;
        }
        Node(vector<int>& needs) {
            for (int i = 0; i < needs.size(); i++) {
                this->needs[i] = needs[i];
            }
            n = needs.size();
        }
        bool canBuySpecial(vector<int>& special) {
            for (int i = 0; i < special.size() - 1; i++) {
                if (needs[i] < special[i]) {
                    return false;
                }
            }
            return true;
        }
        bool isFinish() {
            for (int i = 0; i < n; i++) {
                if (needs[i] != 0) {
                    return false;
                }
            }
            return true;
        }
        Node buySpecial(vector<int>& special) {
            Node n(this->n);
            for (int i = 0; i < special.size() - 1; i++) {
                n.needs[i] = needs[i] - special[i];
            }
            n.current = current + special[special.size() - 1];
            return n;
        }
        void buySingle(vector<int>& price) {
            for (int i = 0; i < price.size(); i++) {
                current += needs[i] * price[i];
                needs[i] = 0;
            }
        }
    };

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minPrice = 0;
        for (int i = 0; i < price.size(); i++) {
            minPrice += needs[i] * price[i];
        }  // 上界
        queue<Node> que;
        que.emplace(needs);
        while (!que.empty()) {
            Node n = que.front();
            que.pop();
            for (vector<int>& sp: special) {
                if (n.canBuySpecial(sp)) {
                    Node next = n.buySpecial(sp);
                    if (next.isFinish() && next.current < minPrice) {
                        minPrice = next.current;
                    }
                    if (next.current < minPrice) {
                        que.push(next);
                    }
                }
            }
            n.buySingle(price);
            if (n.current < minPrice) {
                minPrice = n.current;
            }
        }
        return minPrice;
    }
};



int main() {
    Solution s;
    vector<int> price = getVectorOfInt("[2,5]");
    vector<vector<int>> special = getVectorOfVectorOfInt("[[3,0,5],[1,2,10]]");
    vector<int> need = getVectorOfInt("[3,2]");
    cout << s.shoppingOffers(price, special, need) << endl;

    price = getVectorOfInt("[2,3,4]");
    special = getVectorOfVectorOfInt("[[1,1,0,4],[2,2,1,9]]");
    need = getVectorOfInt("[1,2,1]");
    cout << s.shoppingOffers(price, special, need) << endl;
}