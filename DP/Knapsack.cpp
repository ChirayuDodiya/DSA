#include <bits/stdc++.h>
using namespace std;

bool subsetSum2D(vector<int> &arr, int target)
{
    //If element can be used:
    //ONCE → in take, go to next element
    //MULTIPLE TIMES → in take, go to same element
    int n = arr.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {

            bool not_take = dp[i - 1][j];
            bool take = false;

            if (arr[i - 1] <= j)
            {
                //in case of unbounded knapsack, use this code
                // take = dp[i][j - arr[i - 1]];
                take = dp[i - 1][j - arr[i - 1]];
            }

            dp[i][j] = take || not_take;
        }
    }

    return dp[n][target];
}

bool subsetSum(vector<int> &arr, int target)
{
    // If element can be used:
    // ONCE → iterate backward
    // MULTIPLE TIMES → iterate forward
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr)
    {
        // in case of unbounded knapsack, use this code with forward loop
        // for( int j=num; j<=target; j++) //forward loop
        for (int j = target; j >= num; j--)
        {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 8, 10};
    int target = 11;
    cout << subsetSum(arr, target) << endl;
    cout << subsetSum2D(arr, target) << endl;
    return 0;
}