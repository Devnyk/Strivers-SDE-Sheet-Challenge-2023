bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = m - 1;
    while (i < n and j < m)
    {
        if (mat[i][j] == target)
            return true;
        else if (mat[i][j] > target)
            j++;
        else
            i++;
    }
    return false;
}
