#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

class NQueens {
private:
    int n;
    vector<vector<int>> board;

    bool isSafe(int row, int col) {
        // Check row on left side
        for (int i = 0; i < col; i++)
            if (board[row][i])
                return false;

        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;

        // Check lower diagonal on left side
        for (int i = row, j = col; j >= 0 && i < n; i++, j--)
            if (board[i][j])
                return false;

        return true;
    }

    bool solveNQueensUtil(int col) {
        if (col >= n)
            return true;

        for (int i = 0; i < n; i++) {
            if (isSafe(i, col)) {
                board[i][col] = 1;

                if (solveNQueensUtil(col + 1))
                    return true;

                board[i][col] = 0;
            }
        }
        return false;
    }

public:
    NQueens(int size) : n(size) {
        board = vector<vector<int>>(n, vector<int>(n, 0));
    }

    bool solveNQueens() {
        if (!solveNQueensUtil(0)) {
            return false;
        }
        return true;
    }
};

int main() {
    // Test cases with different board sizes
    vector<int> board_sizes = {8, 10, 12, 14, 16};
    
    cout << "N-Queens Problem Solution\n";
    cout << "------------------------\n";

    for(int size : board_sizes) {
        cout << "Board Size: " << size << "x" << size << endl;
        
        NQueens nQueens(size);
        
        // Measure execution time
        auto start = high_resolution_clock::now();
        bool solutionExists = nQueens.solveNQueens();
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<microseconds>(end - start).count();
        
        if(solutionExists) {
            cout << "Solution exists for n = " << size << endl;
        } else {
            cout << "No solution exists for n = " << size << endl;
        }
        
        cout << "Time Taken: " << duration << " microseconds" << endl;
        cout << "----------------------------------------" << endl;
    }
    
    return 0;
}