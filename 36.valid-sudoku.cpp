/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (41.82%)
 * Total Accepted:    217.6K
 * Total Submissions: 518.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define RSIZE 15
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool record[RSIZE] = { 0 };
        int t;
        for (int i = 0; i < 9; i++) {
            // row
            memset(record, 0, RSIZE);
            for (int j = 0; j < 9; j++) {
                t = board[i][j];
                if (t == '.')
                    continue;
                t -= '0';
                if (record[t])
                    return false; 
                record[t] = true;
            }
        }

        for (int i = 0; i < 9; i++) {
            // column
            memset(record, 0, RSIZE);
            for (int j = 0; j < 9; j++) {
                t = board[j][i];
                if (t == '.')
                    continue;
                t -= '0';
                if (record[t])
                    return false;
                record[t] = true;
            }
        }

        for (int i = 0; i < 3; i++) {
            int rs = i * 3;
            for (int j = 0; j < 3; j++) {
                // block
                memset(record, 0, RSIZE);
                int cs = j * 3;
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        t = board[rs + ii][cs + jj];
                        if (t == '.')
                            continue;
                        t -= '0';
                        if (record[t])
                            return false;
                        record[t] = true;
                    }
                }
            }
        }
        return true;
    }
};

#ifdef LOCAL_DEBUG

int main(void) {
    Solution s;
    vector<vector<char>> in = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '6', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };
    
    vector<vector<char>> in2 = {
        { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    vector<vector<char>> in3 = {
        { '.', '.', '4', '.', '.', '.', '6', '3', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '5', '.', '.', '.', '.', '.', '.', '9', '.' }, 
        { '.', '.', '.', '5', '6', '.', '.', '.', '.' }, 
        { '4', '.', '3', '.', '.', '.', '.', '.', '1' }, 
        { '.', '.', '.', '7', '.', '.', '.', '.', '.' }, 
        { '.', '.', '.', '5', '.', '.', '.', '.', '.' }, 
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' }, 
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' }
    };

    cout << s.isValidSudoku(in) << endl;
    cout << s.isValidSudoku(in2) << endl;
    cout << s.isValidSudoku(in3) << endl;

    return 0;
}

#endif

