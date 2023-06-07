#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int ele = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ele = arr[i];
        }

        if (ele == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int tc = 0;
    for (int i = 0; i < n; i++)
    {
        if (ele == arr[i])
            tc++;
    }

    if (tc > n / 2)
    {
        return ele;
    }
    else
    {
        return -1;
    }
}
