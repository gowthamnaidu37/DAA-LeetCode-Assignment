#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> queens(n, -1); // Index represents row, value represents column of the queen
        backtrack(0, n, queens, results);
        return results;
    }

private:
    void backtrack(int row, int n, vector<int>& queens, vector<vector<string>>& results) {
        if (row == n) {
            results.push_back(constructBoard(queens, n));
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col, queens)) {
                queens[row] = col;
                backtrack(row + 1, n, queens, results);
                queens[row] = -1; // Backtrack
            }
        }
    }

    bool isSafe(int row, int col, vector<int>& queens) {
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    vector<string> constructBoard(vector<int>& queens, int n) {
        vector<string> board;
        for (int i = 0; i < n; ++i) {
            string row(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};
