#include <bits/stdc++.h>

int merge(long long *arr, int l, int mid, int r)
{
    int cnt = 0;
    vector<long long> temp(r - l + 1);

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < k; p++)
    {
        arr[l + p] = temp[p];
    }

    return cnt;
}

int mergeSort(long long *arr, int l, int r)
{
    int cnt = 0;
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid + 1, r);

        cnt += merge(arr, l, mid, r);
    }
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n - 1);
}
