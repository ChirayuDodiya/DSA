#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> freq;
        int l = 0;
        long long count = 0;

        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }

            // subarrays ending at r
            count += (r - l + 1);
        }
        return count;
    }

public:
    long long subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};


int main(){
    Solution s;
    vector<int> nums={1,2,1,2,3};
    int k=2;
    cout<<s.subarraysWithKDistinct(nums,k)<<endl;
}