int checkPos(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return j + 1;
    }
    else if (j < 0)
    {
        return i + 1;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 0 + checkPos(s1, s2, i - 1, j - 1, dp);

    return dp[i][j] = min(
               1 + checkPos(s1, s2, i - 1, j - 1, dp),
               min(
                   1 + checkPos(s1, s2, i, j - 1, dp),
                   1 + checkPos(s1, s2, i - 1, j, dp)));
}

int editDistance(string str1, string str2)
{
    // write you code here
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
    return checkPos(str1, str2, str1.size() - 1, str2.size() - 1, dp);
}