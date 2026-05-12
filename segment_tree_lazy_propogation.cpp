#include <bits/stdc++.h>
using namespace std;

class ST{
    vector<int>st,lazy;
    public:
    ST(int n){
        st.resize(4*n);
        lazy.resize(4*n);
    }
    void build(int index,int low,int high,int arr[])
    {
        if(low==high)
        {
            st[index]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        st[index]=st[2*index+1]+st[2*index+2];
    }
    void update(int index,int low,int high,int l,int r,int val)
    {
        //update the previous remaining updates
        //and propogate downwards
        if(lazy[index]!=0)
        {
            st[index]+=lazy[index]*(high-low+1);
            //propogate the lazy update downwards
            //for the remaining nodes to get updated
            if(low!=high)
            {
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            lazy[index]=0;
        }

        //no overlap
        //don't do anything and return
        //low high l r or l r low high
        if(high<l || r<low)
        {
            return;
        }

        //complete overlap
        //l low high r
        if(low>=l && high<=r)
        {
            st[index]+=(high-low+1)*val;
            //if a leaf node
            if(low!=high)
            {
                lazy[2*index+1]+=val;
                lazy[2*index+2]+=val;
            }
            return;
        }

        //last case has to be partial overlap
        int mid=(low+high)/2;
        update(2*index+1,low,mid,l,r,val);
        update(2*index+2,mid+1,high,l,r,val);
        st[index]=st[2*index+1]+st[2*index+2];
    }
    int query(int index,int low,int high,int l,int r)
    {

        //update if any update are remaining
        //as the node will stay fresh and updated
        if(lazy[index]!=0)
        {
            st[index]+=lazy[index]*(high-low+1);
            //propogate the lazy update downwards
            //for the remaining nodes to get updated
            if(low!=high)
            {
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            lazy[index]=0;
        }        

        //no overlap return 0;
        if(high< l || r<low)
        {
            return 0;
        }

        //complete overlap
        if(low>=l && high<=r)return st[index];

        int mid=(low+high)/2;

        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return left+right;
    }
};

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    ST tree(n);
    tree.build(0, 0, n-1, arr);
    
    int q;
    cin >> q;
    while(q--){
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<tree.query(0,0,n-1,l,r)<<endl;
        }
        else
        {
            int l,r,val;
            cin>>l>>r>>val;
            tree.update(0,0,n-1,l,r,val);
        }
    }
    
    return 0;
}