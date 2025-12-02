#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string X, string Y) {
    int n = X.size(), m = Y.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0; // length of longest common substring

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0; // reset (substring must be contiguous)
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}

int main() {
    string s1, s2;
    // cout << "Enter first string: ";
    // cin >> s1;
    // cout << "Enter second string: ";
    // cin >> s2;
    s1="pabcdabcdty";
    s2="eabcdabcdfg";

    cout << "Length of Longest Common Substring = " 
         << longestCommonSubstring(s1, s2) << endl;
    return 0;
}
