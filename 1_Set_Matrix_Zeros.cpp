#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    // row = matrix[..][0]
    // col = matrix[0][..]

    int col = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;

                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col = 0;
                }
            }
        }
    }

    for (int i = matrix.size() - 1; i > 0; i--)
    {
        for (int j = matrix[i].size() - 1; j > 0; j--)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 or matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = 0;
    }

    if (col == 0)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
}