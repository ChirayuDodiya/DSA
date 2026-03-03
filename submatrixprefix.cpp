#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> pref(n, vector<int>(m, 0));
        
        // Build prefix sum
        pref[0][0] = mat[0][0];
        
        for(int i = 1; i < n; i++)
            pref[i][0] = pref[i-1][0] + mat[i][0];
        
        for(int j = 1; j < m; j++)
            pref[0][j] = pref[0][j-1] + mat[0][j];
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] 
                             - pref[i-1][j-1] + mat[i][j];
            }
        }
        
        int count = 0;
        
        // 1x1 squares
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == x)
                    count++;
        
        // k x k squares (k >= 2)
        for(int k = 2; k <= min(n, m); k++) {
            for(int i = 0; i <= n - k; i++) {
                for(int j = 0; j <= m - k; j++) {
                    
                    int r = i + k - 1;
                    int c = j + k - 1;
                    
                    int sum = pref[r][c];
                    
                    if(i > 0) sum -= pref[i-1][c];
                    if(j > 0) sum -= pref[r][j-1];
                    if(i > 0 && j > 0) sum += pref[i-1][j-1];
                    
                    if(sum == x)
                        count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    vector<vector<int>>vpp={{1,2,1},{2,1,2},{1,2,1}};
    Solution s;
    cout<<s.countSquare(vpp, 6)<<endl;
    return 0;
}