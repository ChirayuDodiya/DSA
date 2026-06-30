#include <bits/stdc++.h>
using namespace std;

// 1D Kadane
int kadane(vector<int> &arr)
{
    int maxSum = arr[0], curr = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        curr = max(arr[i], curr + arr[i]);
        maxSum = max(maxSum, curr);
    }
    return maxSum;
}

// 2D Kadane
int maxSumSubmatrix(vector<vector<int>> &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();
    int ans = INT_MIN;

    for (int left = 0; left < cols; left++)
    {
        vector<int> temp(rows, 0);

        for (int right = left; right < cols; right++)
        {
            for (int i = 0; i < rows; i++)
            {
                temp[i] += mat[i][right];
            }

            // for (int i = 0; i < rows; i++)
            // {
            //     cout<<temp[i]<<" ";
            // }
            // cout<<endl;
            ans = max(ans, kadane(temp));
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}};

    cout << maxSumSubmatrix(mat);
    return 0;
}
