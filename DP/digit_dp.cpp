#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int dp[20][2][20]; // index, tight, count

int solve(string &s, int idx, int tight, int cnt)
{
    if (idx == s.size())
        return cnt;
    if (dp[idx][tight][cnt] != -1)
        return dp[idx][tight][cnt];

    int limit = (tight == 1 ? s[idx] - '0' : 9);
    int ans = 0;

    for (int i = 0; i <= limit; i++)
    {
        int updateCnt = cnt + (i == 3 ? 1 : 0);
        ans += solve(s, idx + 1, (tight & (i == limit)), updateCnt);
    }
    return dp[idx][tight][cnt] = ans;
}

int main()
{

    ll l, r;
    cin >> l >> r;

    string ri = to_string(r);
    memset(dp, -1, sizeof(dp));
    int rightAns = solve(ri, 0, 1, 0);

    string le = to_string(l - 1);
    memset(dp, -1, sizeof(dp));
    int leftAns = solve(le, 0, 1, 0);

    cout << rightAns - leftAns;

    return 0;
}