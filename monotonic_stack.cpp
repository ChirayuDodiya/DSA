#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;   // stores indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            nse[i] = st.top();

        st.push(i);
    }
    return nse;
}


vector<int> nextGreaterIndex(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, n);
    stack<int> st;   // stores indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();

        if (!st.empty())
            nge[i] = st.top();

        st.push(i);
    }
    return nge;
}

int main(){
    vector<int> arr = {1, 3, 2, 4};
    vector<int> nse = nextSmallerIndex(arr);
    vector<int> nge = nextGreaterIndex(arr);

    for (int i = 0; i < nse.size(); i++) {
        cout << "Next smaller element index " << arr[i] << " is " << nse[i] << endl;
        cout << "Next greater element index " << arr[i] << " is " << nge[i] << endl;
    }
    return 0;
}
