#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// Approach -> Hashmap
// Time Complexity -> O(n)
// Space Complexity -> O(n) ( hashmap)

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (mp.count(diff)) {
            return {mp[diff], i};
        }
        mp[nums[i]] = i;
    }

    return {};
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int target;
    cout << "Enter the target: ";
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    if (ans.empty())  
        cout << "No two elements having target sum";
    else 
        for (auto it : ans) cout << " " << it;

    return 0;
}
