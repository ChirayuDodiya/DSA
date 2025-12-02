#include <bits/stdc++.h>
using namespace std;

//not dp😂
int longestIncreasingSubstring(string s) {
    int n = s.size();
    if (n == 0) return 0;

    int curr = 1, ans = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1]) {
            curr++;
            ans = max(ans, curr);
        } else {
            curr = 1; // reset because substring must be contiguous
        }
    }
    return ans;
}

int main() {
    string s;
    // cout << "Enter string: ";
    // cin >> s;
    s="aaabc";

    cout << "Length of Longest Increasing Substring = "
         << longestIncreasingSubstring(s) << endl;
    return 0;
}
