#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// METHOD 1: Hash Map Approach
// Time Complexity: O(n), Space Complexity: O(n)
vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // Check if complement exists and it's not the same element (hash[complement] != i)
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }
        
        // If no valid pair is found, return an empty vector
        return {};
}

// METHOD 2: Two Pointer Approach
// Time Complexity: O(n log n), Space Complexity: O(n)
// Note: This approach works on sorted arrays; returns original indices
vector<int> twoSumTwoPointer(const vector<int>& nums, int target) {
        // Create pairs of (value, original_index) to track original positions
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); i++) {
            indexed_nums.push_back({nums[i], i});
        }
        
        // Sort by value
        sort(indexed_nums.begin(), indexed_nums.end());
        
        // Two pointers approach on sorted array
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int sum = indexed_nums[left].first + indexed_nums[right].first;
            
            if (sum == target) {
                // Return original indices
                return {indexed_nums[left].second, indexed_nums[right].second};
            } 
            else if (sum < target) {
                left++;  // Need larger sum, move left pointer right
            } 
            else {
                right--;  // Need smaller sum, move right pointer left
            }
        }
        
        // If no valid pair is found, return an empty vector
        return {};
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    // Test Hash Map Method
    cout << "Hash Map Method:" << endl;
    vector<int> result = twoSum(arr, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    // Test Two Pointer Method
    cout << "\nTwo Pointer Method:" << endl;
    vector<int> result2 = twoSumTwoPointer(arr, target);
    
    if (!result2.empty()) {
        cout << "Indices: " << result2[0] << ", " << result2[1] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}