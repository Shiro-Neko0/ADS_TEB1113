#include <iostream>
#include <vector>
using namespace std;

int maxRectangle(vector<vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return 0;
    
    int rows = mat.size();
    int cols = mat[0].size();
    int maxArea = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 0) continue;
            
            int minWidth = cols;
            for (int k = i; k >= 0; k--) {
                int width = 0;
                for (int l = j; l >= 0; l--) {
                    if (mat[k][l] == 1) width++;
                    else break;
                }
                
                minWidth = min(minWidth, width);
                int height = i - k + 1;
                int area = height * minWidth;
                maxArea = max(maxArea, area);
            }
        }
    }
    
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    
    cout << "Matrix:" << endl;
    for (auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    int result = maxRectangle(mat);
    cout << "\nLargest rectangle area: " << result << endl;
    
    return 0;
}