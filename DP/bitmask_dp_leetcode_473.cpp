using namespace std;
#include<bits/stdc++.h>
//method 1
#define ll long long 

int f(int idx,int take,int sum,int req,vector<int>&arr,vector<int>&dp){
    if(idx==arr.size()) return 0;
    if(dp[take]!=-1) return dp[take];
    if((take>>idx)&1) return f(idx+1,take,sum,req,arr,dp);

    int t1= f(idx+1,take,sum,req,arr,dp);
    int t2=0;

    if( sum+arr[idx]<=req ){
        sum+=arr[idx];
        if(sum==req){
            sum=0;
            t2=1+f(0,take|(1<<idx),sum,req,arr,dp);
        }else{
            t2=f(idx+1,take|(1<<idx),sum,req,arr,dp);
        }
    }

    return dp[take]=max(t1,t2);
}

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        ll n=matchsticks.size();
        ll sum=0; for(auto &ii:matchsticks) sum+=ii;

        if(sum%4!=0) return  0;
        sum/=4;

        vector<int>dp((1<<n),-1);

        //index,take,sum,req,vector,memo
        return f(0,0,0,sum,matchsticks,dp)==4;
    }
};

//method 2
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int range=pow(2,n);
        long long totalsum=0;
        for(int i=0;i<n;i++)
        {
            totalsum+=matchsticks[i];
        }

        if(totalsum%4)return false;
        
        long long target=totalsum/4;
        
        vector<long long>store;
        for(int i=1;i<range;i++)
        {
            long long sum=0;
            for(int j=0; j<n; j++)
            {
                if((1<<j) & i) sum+=matchsticks[j];
            }
            if(sum==target)store.push_back(i);
        }
        int m=store.size();
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if((store[i]&store[j])==0)
                for(int k=j+1;k<m;k++)
                {
                    if((store[j]&store[k])==0&&(store[i]&store[k])==0)
                    for(int l=k+1;l<m;l++)
                    {
                        if(((store[k]&store[l])==0)&&
                        ((store[i]&store[l])==0)&&
                        ((store[j]&store[l])==0)&&
                        ((store[i]|store[j]|store[k]|store[l])==range-1))return true;
                    }
                }
            }
        }
        return false;
    }
};

//method 3
class Solution {
private:
    bool recursion(vector<int>&matchsticks,int index,long long &maxrange,vector<long long>&current)
    {
        //base case
        if(index==-1)
        {
            if(current[0]==current[1]&&current[1]==current[2]&&current[2]==current[3])
            return true;

            else return false;
        }
        //recursion
        for(int i=0;i<4;i++)
        {
            if(current[i]+matchsticks[index]<=maxrange)
            {
                current[i]+=matchsticks[index];
                if(recursion(matchsticks,index-1,maxrange,current))return true;
                current[i]-=matchsticks[index];
            }
            if(current[i]==0)break;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        long long sum=0;
        for(auto it:matchsticks)
        {
            sum+=it;
        }
        if(sum%4)return false;
        long long maxrange=sum/4;
        vector<long long>current(4,0);
        sort(matchsticks.begin(),matchsticks.end());
        //matchsticks,index,maxrange,vector<long long>current
        return recursion(matchsticks,n-1,maxrange,current);
    }
};