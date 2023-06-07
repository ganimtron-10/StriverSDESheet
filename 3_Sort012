#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    //   Write your code here
    /*
     0 low-1, low mid-1, mid h, h+1 n
          0     1                 2


          1 0 1 1 0 2 1
    */

    int l = 0;
    int mid = 0;
    int h = n - 1;

    while (mid <= h)
    {
        if (arr[mid] == 0)
        {
            swap(arr[l], arr[mid]);
            l++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[h], arr[mid]);
            h--;
        }
    }
}