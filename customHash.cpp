#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main() {
    unordered_set<pair<int,int>, hash_pair> st;
    
    st.insert({1,2});
    st.insert({3,4});

    cout << st.count({1,2}); // 1

    return 0;
}