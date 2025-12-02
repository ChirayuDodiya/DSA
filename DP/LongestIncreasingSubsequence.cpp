#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // dp[i] = LIS ending at i
    int ans = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << "Length of LIS = " << lis(arr) << endl;
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int lis(vector<int>& nums) {
//     vector<int> temp; // stores the increasing subsequence
//     for(int x : nums) {
//         auto it = lower_bound(temp.begin(), temp.end(), x);
//         if(it == temp.end()) 
//             temp.push_back(x);
//         else 
//             *it = x; // replace
//     }
//     return temp.size();
// }

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter elements: ";
//     for(int i=0; i<n; i++) cin >> arr[i];

//     cout << "Length of LIS = " << lis(arr) << endl;
//     return 0;
// }
