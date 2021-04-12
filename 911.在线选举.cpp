/*
 * @lc app=leetcode.cn id=911 lang=cpp
 *
 * [911] 在线选举
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


class TopVotedCandidate {
public:
    vector<int> winner;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times): times(times) {
        size_t sz = persons.size();
        int win = persons[0];
        int votes[5000] = {0};
        for (int i = 0; i < sz; i++) {
            int person = persons[i];
            int time = times[i];
            votes[person]++;
            if (person != win && votes[person] >= votes[win]) {
                win = person;
            }
            winner.push_back(win);
        }
    }
    
    int q(int t) {
        int index = upper_bound(times.begin(),times.end(),t) - times.begin();
        return winner[index];
    }
};


/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
// @lc code=end

#include "defines.h"
#include <string>
int main(void) {
    vector<int> person = {0,0,0,0,0,1,1,1,1,1};
    vector<int> times = {3,6,34,42,64,70,71,77,84,87};
    string str = "12345";
    TopVotedCandidate s(person, times);
    printList(s.times);
    printList(s.winner);
}


// ["TopVotedCandidate","q","q","q","q","q","q","q","q","q","q","q","q","q","q","q","q","q","q","q","q"]
// [[[0,0,0,0,0,1,1,1,1,1],[3,6,34,42,64,70,71,77,84,87]],[40],[66],[77],[78],[30],[98],[57],[64],[65],[68],[18],[69],[45],[97],[72],[100],[84],[60],[61],[49]]