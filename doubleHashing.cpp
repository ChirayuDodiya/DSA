// this algorithm is useful to compare pref string in O(1)
// suppose string s="abcdeabcd" now i want to find maxLen where pref and suff string are same

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    const long long mod1=1e9+7;
    const long long mod2=1e9+9;
    const long long base=31;
    
    long long getHash1(int l,int r,vector<long long>&hash1,vector<long long>&power1)
    {
        return (hash1[r+1]-hash1[l]*power1[r-l+1]%mod1 + mod1)%mod1;
    }
    
    long long getHash2(int l,int r,vector<long long>&hash2,vector<long long>&power2)
    {
        return (hash2[r+1]-hash2[l]*power2[r-l+1]%mod2 + mod2)%mod2;
    }
    
  public:
    int getLPSLength(string &s) {
        int n=s.length();
        
        vector<long long>hash1(n+1,0),hash2(n+1,0);
        vector<long long>power1(n+1,1),power2(n+1,1);
        
        for(int i=0;i<n;i++)
        {
            hash1[i+1]=(hash1[i]*base + (s[i]-'a'+1))%mod1;
            hash2[i+1]=(hash2[i]*base + (s[i]-'a'+1))%mod2;
            
            power1[i+1]=(power1[i]*base)%mod1;
            power2[i+1]=(power2[i]*base)%mod2;
        }
        
        int ans=0;
        for(int len=1;len<n;len++)
        {
            if(getHash1(0,len-1,hash1,power1)==getHash1(n-len,n-1,hash1,power1)
            &&getHash2(0,len-1,hash2,power2)==getHash2(n-len,n-1,hash2,power2))ans=len;
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    string t;
    cin>>t;
    cout<<s.getLPSLength(t);
    return 0;
}