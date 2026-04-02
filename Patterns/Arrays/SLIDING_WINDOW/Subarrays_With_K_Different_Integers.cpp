/*Problem: Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 
Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4]. */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with exactly k different integers
int subarraysWithKDistinct(vector<int>& nums, int k) {
    // Lambda function to count subarrays with AT MOST k different integers
    auto atMostKDistinct = [&](int k) -> int {
        // HashMap to store frequency of elements in current window
        unordered_map<int, int> count;
        // Left pointer of sliding window
        int left = 0;
        // Variable to store total count of valid subarrays
        int result = 0;
        
        // Iterate through array with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Increment frequency of current element
            count[nums[right]]++;
            
            // If number of distinct integers exceeds k, shrink window from left
            while (count.size() > k) {
                // Decrement frequency of left element
                count[nums[left]]--;
                // If frequency becomes 0, remove element from map
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]);
                }
                // Move left pointer to the right
                left++;
            }
            
            // Add count of all subarrays ending at right with at most k distinct integers
            // (right - left + 1) represents number of subarrays from [left, right]
            result += right - left + 1;
        }
        
        // Return total count of subarrays with at most k distinct integers
        return result;
    };
    
    // Key insight: subarrays with exactly k = atMost(k) - atMost(k-1)
    return atMostKDistinct(k) - atMostKDistinct(k - 1);
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    cout << "Input: nums = [1,2,1,2,3], k = 2" << endl;
    cout << "Output: " << subarraysWithKDistinct(nums1, k1) << endl;
    cout << "Expected: 7" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    cout << "Input: nums = [1,2,1,3,4], k = 3" << endl;
    cout << "Output: " << subarraysWithKDistinct(nums2, k2) << endl;
    cout << "Expected: 3" << endl;
    
    return 0;
}