#include <bits/stdc++.h>
using namespace std;

int lcs(string X, string Y) {
    int n = X.size(), m = Y.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(X[i-1] == Y[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
    return dp[n][m]; // length of LCS
}

int main() {
    string s1, s2;
    // cout << "Enter first string: "<<endl;
    // cin >> s1;
    // cout << "Enter second string: "<<endl;
    // cin >> s2;
    s1="aevfrg";
    s2="aiveefpg";

    cout << "Length of LCS = " << lcs(s1, s2) << endl;
    return 0;
}
