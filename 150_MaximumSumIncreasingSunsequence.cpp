#include <bits/stdc++.h>

int maxSumIS(vector<int> &rack, int n, int i, int prev_i, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][prev_i + 1] != -1)
        return dp[i][prev_i + 1];

    int sum = 0 + maxSumIS(rack, n, i + 1, prev_i, dp);
    if (prev_i == -1 or rack[i] > rack[prev_i])
    {
        sum = max(sum, rack[i] + maxSumIS(rack, n, i + 1, i, dp));
    }

    return dp[i][prev_i + 1] = sum;
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return maxSumIS(rack, n, 0, -1, dp);
}
