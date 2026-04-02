#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find minimal length of subarray with sum >= target
int minSubArrayLen(int target, vector<int>& nums) {
    // Left pointer of sliding window
    int left = 0;
    // Variable to store current window sum
    int currentSum = 0;
    // Variable to store minimal length found (initialize to INT_MAX)
    int minLength = INT_MAX;
    
    // Iterate through array with right pointer
    for (int right = 0; right < nums.size(); right++) {
        // Add current element to window sum
        currentSum += nums[right];
        
        // While current sum is >= target, try to shrink window from left
        while (currentSum >= target) {
            // Update minimal length with current window size
            // (right - left + 1) represents current window length
            minLength = min(minLength, right - left + 1);
            
            // Remove left element from current sum
            currentSum -= nums[left];
            // Move left pointer to the right to shrink window
            left++;
        }
    }
    
    // If minLength is still INT_MAX, no valid subarray found, return 0
    // Otherwise return the minimal length found
    return minLength == INT_MAX ? 0 : minLength;
}

int main() {
    // Test Case 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Input: target = 7, nums = [2,3,1,2,4,3]" << endl;
    cout << "Output: " << minSubArrayLen(target1, nums1) << endl;
    cout << "Expected: 2" << endl;
    cout << "Explanation: The subarray [4,3] has the minimal length." << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    cout << "Input: target = 4, nums = [1,4,4]" << endl;
    cout << "Output: " << minSubArrayLen(target2, nums2) << endl;
    cout << "Expected: 1" << endl;
    cout << "Explanation: The subarray [4] has sum >= 4." << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    cout << "Input: target = 11, nums = [1,1,1,1,1,1,1,1]" << endl;
    cout << "Output: " << minSubArrayLen(target3, nums3) << endl;
    cout << "Expected: 0" << endl;
    cout << "Explanation: No subarray has sum >= 11." << endl;
    
    return 0;
}