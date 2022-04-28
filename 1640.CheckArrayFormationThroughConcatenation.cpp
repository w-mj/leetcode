#include "defines.h"


class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        size_t total_size = 0;
        for (vector<int>& piece: pieces) {
            for (int i = 0; i < arr.size(); i++) {
                if (piece[0] == arr[i]) {
                    for (int j = 0; j < piece.size(); j++) {
                        if (piece[j] != arr[i + j]) {
                            return false;
                        }
                    }
                    total_size += piece.size();
                    break;
                }
            }
        }
        return total_size == arr.size();
    }
};