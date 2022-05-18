#include "defines.h"
#include <iterator>
#include <set>

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, set<string>> needs;
        set<string> recipes_query;

        for (int i = 0; i < recipes.size(); i++) {
            recipes_query.insert(recipes[i]);
            needs[recipes[i]] = set<string>(ingredients[i].begin(), ingredients[i].end());
        }



        queue<string> can_create;

        for (const string& s: supplies) {
            can_create.push(s);
        }

        vector<string> ans;
        while (can_create.size() > 0) {
            string create = can_create.front();
            can_create.pop();
            if (recipes_query.find(create) != recipes_query.end()) {
                ans.push_back(create);
            }

            for (auto itt = needs.begin(); itt != needs.end(); ) {
                auto &item = *itt;
                auto it = item.second.find(create);
                if (it != item.second.end()) {
                    item.second.erase(it);

                    if (item.second.empty()) {
                        can_create.push(item.first);
                        itt = needs.erase(itt);
                        continue;
                    }
                }
                itt++;
            }
        }

        return ans;
    }
};


int main() {
    Solution s;
    vector<string> recipes = {"bread"};
    vector<vector<string>> ingredients = {{"yeast","flour"}};
    vector<string> supplies = {"yeast","flour","corn"};

    cout << s.findAllRecipes(recipes, ingredients, supplies) << endl;

}