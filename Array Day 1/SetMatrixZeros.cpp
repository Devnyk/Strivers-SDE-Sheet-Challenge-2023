#include <bits/stdc++.h>

void changeMat(vector<vector<int>> &matrix, int row, int col, int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        matrix[row][j] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i][col] = 0;
    }
}

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    vector<int> rows, cols;
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows.push_back(i);
                cols.push_back(j);
            }
        }
    }

    for (int i = 0, j = 0; i < rows.size(), j < cols.size(); i++, j++)
    {
        changeMat(matrix, rows[i], cols[j], n, m);
    }
}
