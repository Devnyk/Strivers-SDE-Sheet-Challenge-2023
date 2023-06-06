#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    while (top < bottom and left < right)
    {
        int temp = mat[top][left];
        for (int i = top; i < bottom; i++)
        {
            mat[i][left] = mat[i + 1][left];
        }

        for (int i = left; i < right; i++)
        {
            mat[bottom][i] = mat[bottom][i + 1];
        }

        for (int i = bottom; i > top; i--)
        {
            mat[i][right] = mat[i - 1][right];
        }

        for (int i = right; i > left; i--)
        {
            mat[top][i] = mat[top][i - 1];
        }
        mat[top][left + 1] = temp;
        top++;
        bottom--;
        left++;
        right--;
    }
}
