#include <bits/stdc++.h>
using namespace std;

class NQueen {
private:
    int N;
    vector<vector<int>> board;

    bool isSafe(int row, int col) {
        // Check this row on left side
        for (int i = 0; i < col; i++)
            if (board[row][i]) return false;

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]) return false;

        // Check lower diagonal on left side
        for (int i = row, j = col; i < N && j >= 0; i++, j--)
            if (board[i][j]) return false;

        return true;
    }

    bool solveNQUtil(int col) {
        if (col >= N) return true;

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;

                if (solveNQUtil(col + 1)) return true;

                board[i][col] = 0; // backtrack
            }
        }
        return false;
    }

public:
    NQueen(int n) {
        N = n;
        board.assign(N, vector<int>(N, 0));
    }

    void solve() {
        if (!solveNQUtil(0)) {
            cout << "Solution does not exist" << endl;
            return;
        }
        printSolution();
    }

    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << endl;
        }
    }
};

int main() {
    int N = 8; // Example: 8-Queen problem
    NQueen q(N);
    q.solve();

    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;
    return 0;
}
