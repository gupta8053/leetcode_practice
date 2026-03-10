#include <vector>
#include <iostream>
using namespace std;

/**
 * Problem: Subarray Product Less Than K
 * 
 * Given an array of integers nums and an integer k, return the number of 
 * contiguous subarrays where the product of all elements is strictly less than k.
 * 
 * Approach: Sliding Window
 * - Use two pointers (left and right) to maintain a window
 * - Expand window by moving right and multiply product
 * - If product >= k, shrink from left by dividing product
 * - For each position of right, all subarrays from left to right are valid
 * - Add (right - left + 1) subarrays for each valid window position
 * 
 * Time Complexity: O(n) - each element is visited at most twice
 * Space Complexity: O(1) - only using pointers and variables
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Edge case: if k <= 1, no subarray can have product < k
        if (k <= 1) {
            return 0;
        }
        
        int left = 0;
        int count = 0;
        long long product = 1;
        
        // Sliding window with right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Expand window: multiply current element
            product *= nums[right];
            
            // Shrink window from left while product >= k
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            
            // All subarrays ending at right and starting from any index
            // between left and right have product < k
            // There are (right - left + 1) such subarrays
            count += (right - left + 1);
        }
        
        return count;
    }
};

/**
 * Example 1:
 * Input: nums = [10,5,2,6], k = 100
 * Output: 8
 * Valid subarrays: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]
 * 
 * Trace:
 * right=0: product=10, window=[0,0], count += 1 = 1
 * right=1: product=50, window=[0,1], count += 2 = 3 ([10,5], [5])
 * right=2: product=100 >= 100, shrink: left=1, product=10, window=[1,2], count += 2 = 5 ([5,2], [2])
 * right=3: product=60, window=[1,3], count += 3 = 8 ([5,2,6], [2,6], [6])
 * 
 * Example 2:
 * Input: nums = [1,2,3], k = 0
 * Output: 0
 * k=0, edge case handled by returning 0
 */

// Test cases
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << "Example 1: " << sol.numSubarrayProductLessThanK(nums1, k1) << " (Expected: 8)" << endl;
    
    // Example 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << "Example 2: " << sol.numSubarrayProductLessThanK(nums2, k2) << " (Expected: 0)" << endl;
    
    // Additional test case
    vector<int> nums3 = {1, 1, 1, 1};
    int k3 = 2;
    cout << "Example 3: " << sol.numSubarrayProductLessThanK(nums3, k3) << " (Expected: 10)" << endl;
    
    return 0;
}
