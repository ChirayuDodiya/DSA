#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool bs(vector<int> &arr, int k, int low, int high)
    {
        // if (low > high) return false;

        if (low <= high)
        {
            int mid = (low + high) / 2;
            if (k < arr[mid])
                bs(arr, k, low, mid - 1);
            else if (k > arr[mid])
                bs(arr, k, mid + 1, high);
            else if (k == arr[mid])
                return true;
            else
                return false;
        }
    }

    bool searchInSorted(vector<int> arr, int k)
    {
        int low = 0;
        int high = arr.size() - 1;
        bool flag = bs(arr, k, low, high);
        return flag;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 1, 2, 3, 4, 5, 6};
    int k = 5;
    bool ans = s.searchInSorted(arr, k);
    cout << ans << endl;
    return 0;
}