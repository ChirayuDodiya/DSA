/*
left child=>2x+1
right child=>2x+2

3 condition: if for desired range, the current range:
completly lies      ->return that value directly
overlaps            ->both direction
doesn't lies        ->return the value that will not contribure in our answer
*/

#include<bits/stdc++.h>
using namespace std;

int a[100005],seg[100005];
//building to store max element for that sagment
void build(int index,int low,int high){
    if(low==high)
    {
        seg[index]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*index+1,low,mid);
    build(2*index+2,mid+1,high);
    seg[index]=max(seg[index*2+1],seg[index*2+2]);
}

int query(int index,int low,int high,int l,int r)
{
    //if (low,high) completly lies inside l and r
    //->i am finding for (l,r)
    if(low>=l&&high<=r)
    {
        return seg[index];
    }
    if(high<l||low>r)
    {
        return INT_MIN;
    }
    int mid=(low+high)/2;
    int left=query(2*index+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);
    return max(left,right);

}

//updates a[pos]=val
void update(int index, int low, int high, int pos, int val) {
    if (low == high) {
        seg[index] = val;
        a[pos] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid) update(2 * index + 1, low, mid, pos, val);
    else update(2 * index + 2, mid + 1, high, pos, val);

    seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //index of root,range
    build(0,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }

}