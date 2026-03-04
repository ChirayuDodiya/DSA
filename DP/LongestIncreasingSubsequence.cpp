#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums)// n^2
{ 
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = LIS ending at i
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int lisLength(vector<int> &nums)// nlogn
{                     
    vector<int> temp; // stores the increasing subsequence
    for (int x : nums)
    {
        auto it = lower_bound(temp.begin(), temp.end(), x);
        if (it == temp.end())
            temp.push_back(x);
        else
            *it = x; // replace
    }
    return temp.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Length of LIS = " << lis(arr) << endl;
    cout << "Length of LIS = " << lisLength(arr) << endl;
    return 0;
}