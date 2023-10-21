#include <vector>

using namespace std;

class MatrixSum{
private:
    vector<vector<int>> sum;
public:
    MatrixSum(const vector<vector<int>> &matrix){
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i <= n; i++)
            for (int j = 0; j < n; j++)
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j];
    }
    int query(int r1, int c1, int r2, int c2){
        return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
    }

};