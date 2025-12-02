#include <iostream>
#include<bits/stdc++.h>
#include <map>
using namespace std;

int main() {
    multimap<string, int> mm;
    mm.insert({"apple", 1});
    mm.insert({"banana", 2});
    mm.insert({"apple", 3});
    mm.insert({"orange", 4});
    mm.insert({"apple", 5});

    // for (auto it = mm.begin(); it != mm.end(); ++it) {
    //     if (it->first == "apple") {
    //         // Get all "apple" values using equal_range
            auto range = mm.equal_range("apple");
            for (auto i = range.first; i != range.second; ++i) {
                cout << i->first << " -> " << i->second << "\n";
            }
            // break; // done with "apple", no need to check further
        // }
    // }
    for(auto it:mm)
    {
        if(it.first=="apple")
        {
            cout<<it.first<<" "<<it.second;
            cout<<endl;
        }
    }
    return 0;
}
