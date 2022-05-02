#include "defines.h"
#include <algorithm>
#include <iterator>


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        unordered_map<int, int> time_points;
        for (int i = 0; i < flowers.size(); i++) {
            if (time_points.find(flowers[i][0]) == time_points.end()) {
                time_points[flowers[i][0]] = 0;
            }
            time_points[flowers[i][0]]++;
            if (time_points.find(flowers[i][1]) == time_points.end()) {
                time_points[flowers[i][1]] = 0;
            }
            time_points[flowers[i][1] + 1]--;
        }

        vector<pair<int, int>> blooms;
        blooms.reserve(flowers.size() * 2);
        for (auto& point: time_points) {
            if (point.second == 0) {
                continue;
            }
            blooms.push_back(point);
        }

        sort(blooms.begin(), blooms.end());

        for (int i = 1; i < blooms.size(); i++) {
            blooms[i].second = blooms[i].second + blooms[i - 1].second;
        }

        vector<int> ans(persons.size(), -1);

        for (int i = 0; i < persons.size(); i++) {
            auto lower = lower_bound(blooms.begin(), blooms.end(), persons[i], [](const pair<int, int>& b, int t){return b.first < t;});
            int index = distance(blooms.begin(), lower); 
            if (index == blooms.size()) {
                ans[i] = 0;
            } else if (blooms[index].first == persons[i]) {
                ans[i] = blooms[index].second;
            } else if (index == 0) {
                ans[i] = 0;
            } else {
                ans[i] = blooms[index - 1].second;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> flowers;
    vector<int> persons;
    Solution s;

    flowers = getVectorOfVectorOfInt("[[1,6],[3,7],[9,12],[4,13]]");
    persons = getVectorOfInt("[2,3,7,11]");
    cout << s.fullBloomFlowers(flowers, persons) << endl;

    flowers = getVectorOfVectorOfInt("[[1,10],[3,3]]");
    persons = getVectorOfInt("[3,3,2]");
    cout << s.fullBloomFlowers(flowers, persons) << endl;

    flowers = getVectorOfVectorOfInt("[[2,8],[31,37]]");
    persons = getVectorOfInt("[33,47,45,12]");
    cout << s.fullBloomFlowers(flowers, persons) << endl;
}