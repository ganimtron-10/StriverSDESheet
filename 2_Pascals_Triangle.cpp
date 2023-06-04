#include <bits/stdc++.h>

vector<long long int> generateRow(int n)
{
    vector<long long int> row;

    row.push_back(1);

    long long int val = 1;
    for (int i = 2; i <= n; i++)
    {
        val *= n - i + 1;
        val /= i - 1;

        row.push_back(val);
    }

    return row;
}

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans;

    for (int i = 1; i <= n; i++)
    {
        ans.push_back(generateRow(i));
    }

    return ans;
}
