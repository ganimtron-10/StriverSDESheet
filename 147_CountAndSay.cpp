#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    // Write your code here.
    string cur = "1";

    for (int i = 1; i < n; i++)
    {
        string newcur = "";
        for (int j = 0; j < cur.size(); j++)
        {
            char cc = cur[j];
            int cnt = 1;
            while (j < cur.size() and cur[j + 1] == cc)
            {
                cnt++;
                j++;
            }
            newcur.push_back(char('0' + cnt));
            newcur.push_back(cc);
        }
        cur = newcur;
    }

    return cur;
}