string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    bool isDifferent = false;
    string result = "";
    int s1 = arr[0].size();
    for (int i = 0; i < s1; i++)
    {
        for (string s : arr)
        {
            if (i >= s.size() or s[i] != arr[0][i])
            {
                isDifferent = true;
            }
        }
        if (isDifferent)
        {
            return result;
        }
        else
        {
            result += arr[0][i];
        }
    }
    return result;
}
