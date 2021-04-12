#ifdef LOCAL_DEBUG
#include "defines.h"

#define IN intervals[i]
#define RE result[j]

bool compare(Interval& a, Interval& b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            Interval& tmp = result.back();
            if (intervals[i].start <= tmp.end) {
                result.back().end = max(tmp.end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;
        int n = intervals.size();
        int to_delete, to_insert = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            to_insert = result.size();
            for (j = 0; j < result.size(); j++) {
                if (IN.start > RE.end)
                    continue;
                else if (IN.end < RE.start) {
                    to_insert = j;
                    j = result.size();
                    break;
                }
                if (IN.start >= RE.start && IN.end <= RE.end) {
                    to_insert = -1;
                    break;
                } else if (IN.start <= RE.start && IN.end >= RE.end) {
                    RE.start = IN.start;
                    to_delete = j + 1;
                    int k = to_delete;
                    while (k < result.size() && IN.end >= result[k].end)
                        k++;
                    if (k < result.size() && IN.end >= result[k].start) {
                        IN.end = result[k].end;
                        k++;
                    }
                    RE.end = IN.end;
                    result.erase(result.begin() + to_delete, result.begin() + k);
                    to_insert = -1;
                    break;
                } else if (IN.start < RE.start && IN.end < RE.end) {
                    RE.start = IN.start;
                    to_insert = -1;
                    break;
                } else if (IN.start > RE.start && IN.end > RE.end) {
                    to_delete = j + 1;
                    int k = to_delete;
                    while (k < result.size() && IN.end >= result[k].end)
                        k++;
                    if (k < result.size() && IN.end >= result[k].start) {
                        IN.end = result[k].end;
                        k++;
                    }
                    RE.end = IN.end;
                    result.erase(result.begin() + to_delete, result.begin() + k);
                    to_insert = -1;
                    break;
                }
            }
            if (to_insert != -1 && j == result.size()) {
                result.insert(result.begin() + to_insert, IN);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution s;
    vector<Interval> in1 = { { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
    vector<Interval> in2 = { { 1, 4 }, { 4, 5 } };
    vector<Interval> in3 = { { 3, 4 }, { 2, 5 }, { 1, 6 }, { 0, 7 } };
    vector<Interval> in4 = { { 7, 9 }, { 6, 7 }, { 1, 5 }, { 6, 7 } };
    vector<Interval> in5 = { { 7, 8 }, { 10, 13 }, { 1, 2 }, { 3, 4 } };
    vector<Interval> in6 = { { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 }, {1, 10} };

    vector<Interval> ou = s.merge(in6);
    for (const auto& i : ou) {
        cout << i.start << ' ' << i.end << endl;
    }
    return 0;
}

#endif