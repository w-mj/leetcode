#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <climits>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cctype>

#define START_TIMER int __start_timer = clock();
#define END_TIMER int __during_time = (clock() - __start_timer) * 1000 / CLOCKS_PER_SEC; \
        cout << "during " << __during_time << " ms." << endl;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;