#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>> &arr, int n, int m)
{
    cout << "\nMatrix is:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    for (int k = 0; k < min(n, m) / 2; k++)
    {
        int ele = mat[k][k];
        for (int i = 1 + k; i < n - k; i++)
        {
            mat[i - 1][k] = mat[i][k];
        }

        for (int i = 1 + k; i < m - k; i++)
        {
            mat[n - 1 - k][i - 1] = mat[n - 1 - k][i];
        }

        for (int i = n - 2 - k; i >= 0 + k; i--)
        {
            mat[i + 1][m - 1 - k] = mat[i][m - 1 - k];
        }

        for (int i = m - 2 - k; i > 0 + k; i--)
        {
            mat[k][i + 1] = mat[k][i];
        }

        mat[k][1 + k] = ele;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        rotateMatrix(arr, n, m);

        printMat(arr, n, m);
    }
}