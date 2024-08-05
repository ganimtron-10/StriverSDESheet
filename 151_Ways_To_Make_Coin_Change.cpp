#include <bits/stdc++.h>

long helper(vector<int> &coins, int i, int amount, vector<vector<long>> &dp)
{
    if (amount == 0)
        return 1;
    if (i < 0 || amount < 0)
        return 0;

    if (dp[i][amount] != -1)
    {
        return dp[i][amount];
    }

    long include = helper(coins, i, amount - coins[i], dp);
    long exclude = helper(coins, i - 1, amount, dp);

    return dp[i][amount] = include + exclude;
}

long coinChange(vector<int> &coins, int amount)
{
    vector<vector<long>> dp(coins.size(), vector<long>(amount + 1, -1));
    long ways = helper(coins, coins.size() - 1, amount, dp);
    return ways;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Convert denominations array to vector
    vector<int> coins(denominations, denominations + n);
    return coinChange(coins, value);
}
