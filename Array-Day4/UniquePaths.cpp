//Recursion (Will give TLE)

#include <bits/stdc++.h>
int rec(int row, int col, int m, int n)
{
    if (row == 0 and col == 0)
        return 1;
    else if (row < 0 or col < 0)
        return 0;

    int right = rec(row, col - 1, m, n, );
    int down = rec(row - 1, col, m, n, );
    return  right + down;
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    int ans = rec(m - 1, n - 1, m, n);
    return ans;
}

//Memoization

#include <bits/stdc++.h>
int rec(int row, int col, int m, int n, vector<vector<int>> &dp)
{
    if (row == 0 and col == 0)
        return 1;
    else if (row < 0 or col < 0)
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];
    int right = rec(row, col - 1, m, n, dp);
    int down = rec(row - 1, col, m, n, dp);
    return dp[row][col] = right + down;
}

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = rec(m - 1, n - 1, m, n, dp);
    return ans;
}

//Tabulation

#include <bits/stdc++.h>
// int rec(int row,int col,int m,int n,vector<vector<int>>&dp)
// {
// 	if(row==0 and col==0) return 1;
// 	else if(row<0 or col<0) return 0;
// 	if(dp[row][col]!=-1) return dp[row][col];
// 	int right=rec(row,col-1,m,n,dp);
// 	int down=rec(row-1,col,m,n,dp);
// 	return dp[row][col]=right+down;
// }

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // int ans=rec(m-1,n-1,m,n,dp);
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j != 0)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0 and i != 0)
                dp[i][j] = dp[i - 1][j];
            else if (i == 0 and j == 0)
                continue;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

//Space Optimized

#include <bits/stdc++.h>
// int rec(int row,int col,int m,int n,vector<vector<int>>&dp)
// {
// 	if(row==0 and col==0) return 1;
// 	else if(row<0 or col<0) return 0;
// 	if(dp[row][col]!=-1) return dp[row][col];
// 	int right=rec(row,col-1,m,n,dp);
// 	int down=rec(row-1,col,m,n,dp);
// 	return dp[row][col]=right+down;
// }

int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<int> prev(m, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;

            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

