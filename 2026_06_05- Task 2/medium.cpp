#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> findPeak(const vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool isPeak = true;
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (mat[ni][nj] > mat[i][j]) {
                        isPeak = false;
                        break;
                    }
                }
            }
            
            if (isPeak) {
                return {i, j};
            }
        }
    }
    
    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "Matrix:" << endl;
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    vector<int> peak = findPeak(mat);
    cout << "Peak element at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    cout << "Peak value: " << mat[peak[0]][peak[1]] << endl;
    
    return 0;
}