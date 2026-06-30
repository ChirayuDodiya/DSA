#include <bits/stdc++.h>
using namespace std;

class Solution {
    int recursion(int dp[11][2][11],string &ni,int index,int tight,int count)
    {
        //base case
        if(index==ni.size())return count;
        if(dp[index][tight][count]!=-1)return dp[index][tight][count];

        //recursion
        int limit=tight==1 ? ni[index]-'0' : 9;
        int ans=0;
        for(int i=0;i<=limit;i++)
        {
            int updateCount = count+ (i==1 ? 1 : 0);
            ans+=recursion(dp,ni,index+1,tight&(i==limit),updateCount);
        }
        return dp[index][tight][count]=ans;
    }
public:
    int countDigitOne(int n) {
        int dp[11][2][11];
        memset(dp,-1,sizeof(dp));
        string ni=to_string(n);
        return recursion(dp,ni,0,1,0);
    }
};