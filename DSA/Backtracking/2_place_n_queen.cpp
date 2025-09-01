//  leetcode : 51 
// https://leetcode.com/problems/n-queens
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void solve(int row, vector<string>& board, vector<vector<string>>& result, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, result, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, board, result, n);
        return result;
    }
};

int main() {
    Solution sol;
    int n = 4; // Change this to any N
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << endl;
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
