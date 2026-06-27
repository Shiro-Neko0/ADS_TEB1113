#include <iostream>
#include <vector>
using namespace std;

void rotateMatrixClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    if (n == 0) return;

    int topLeft = matrix[0][0];

    for (int i = 0; i < n - 1; i++) {
        matrix[i][0] = matrix[i + 1][0];
    }

    for (int j = 0; j < n - 1; j++) {
        matrix[n - 1][j] = matrix[n - 1][j + 1];
    }

    for (int i = n - 1; i > 0; i--) {
        matrix[i][n - 1] = matrix[i - 1][n - 1];
    }

    for (int j = n - 1; j > 1; j--) {
        matrix[0][j] = matrix[0][j - 1];
    }
    
    matrix[0][1] = topLeft;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    
    rotateMatrixClockwise(matrix);
    
    cout << "\nMatrix after rotating:" << endl;
    printMatrix(matrix);
    
    return 0;
}