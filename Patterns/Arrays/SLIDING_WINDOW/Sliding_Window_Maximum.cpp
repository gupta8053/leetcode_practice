#include <vector>
#include <deque>
#include <iostream>
using namespace std;

/**
 * Problem: Sliding Window Maximum
 * 
 * Given an array of integers nums and an integer k, return the maximum value
 * in each sliding window of size k as it moves from left to right.
 * 
 * Approach: Deque (Double-ended Queue)
 * - Use a deque to store indices of elements in decreasing order of their values
 * - For each element, remove indices outside the window from front
 * - Remove elements from back that are smaller than current element (they can't be max)
 * - Add current element's index to back
 * - The front of deque always contains the index of max in current window
 * 
 * Why Deque?
 * - Front gives us the max quickly
 * - We can efficiently remove smaller elements from back
 * - We can efficiently remove out-of-window elements from front
 * 
 * Time Complexity: O(n) - each element added and removed at most once
 * Space Complexity: O(k) - deque stores at most k elements
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;  // stores indices, not values
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices that are outside the current window
            // Window is from (i - k + 1) to i
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove elements from back that are smaller than current element
            // They can never be the maximum while current element is in the window
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // Add current element's index
            dq.push_back(i);
            
            // The window is complete when i >= k - 1
            // The front of deque is the index of max in current window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

/**
 * Example 1:
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * 
 * Trace:
 * i=0: dq=[0], window incomplete
 * i=1: nums[1]=3 > nums[0]=1, pop 0, dq=[1], window incomplete
 * i=2: nums[2]=-1 < nums[1]=3, dq=[1,2], add result[3]
 * i=3: nums[3]=-3 < nums[2]=-1, dq=[1,2,3], add result[3]
 * i=4: nums[4]=5 > all, pop all, dq=[4], add result[5]
 * i=5: nums[5]=3 < nums[4]=5, dq=[4,5], add result[5]
 * i=6: nums[6]=6 > nums[5]=3, pop 5, 6 > nums[4]=5, pop 4, dq=[6], add result[6]
 * i=7: nums[7]=7 > nums[6]=6, pop 6, dq=[7], add result[7]
 * 
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 */

// Test cases
int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k1 = 3;
    vector<int> result1 = sol.maxSlidingWindow(nums1, k1);
    cout << "Example 1: ";
    for (int num : result1) cout << num << " ";
    cout << "(Expected: 3 3 5 5 6 7)" << endl;
    
    // Example 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> result2 = sol.maxSlidingWindow(nums2, k2);
    cout << "Example 2: ";
    for (int num : result2) cout << num << " ";
    cout << "(Expected: 1)" << endl;
    
    // Additional test case: all negative
    vector<int> nums3 = {-1, -3, -2};
    int k3 = 2;
    vector<int> result3 = sol.maxSlidingWindow(nums3, k3);
    cout << "Example 3: ";
    for (int num : result3) cout << num << " ";
    cout << "(Expected: -1 -2)" << endl;
    
    // Additional test case: duplicates
    vector<int> nums4 = {1, 3, 1, 2, 0, 5};
    int k4 = 3;
    vector<int> result4 = sol.maxSlidingWindow(nums4, k4);
    cout << "Example 4: ";
    for (int num : result4) cout << num << " ";
    cout << "(Expected: 3 3 2 5)" << endl;
    
    return 0;
}
