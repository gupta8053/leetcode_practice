#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* MAX CONSECUTIVE ONES III (Sliding Window Pattern)
   
   Problem: Find the maximum number of consecutive 1's if you can flip at most k 0's
   
   Approach: Sliding Window with Two Pointers
   - Maintain a window of elements
   - Expand the window by moving right pointer
   - Count the number of 0's in the current window
   - If zeros exceed k, shrink the window from left
   - The window can contain at most k zeros
   - Track the maximum window size
   
   Why this works:
   - A valid window has at most k zeros
   - By flipping all k zeros to 1's, we get a subarray of all 1's
   - We want the maximum length subarray with at most k zeros
   
   Time Complexity: O(n) - each element visited at most twice (once by right, once by left)
   Space Complexity: O(1) - only using pointers and counter
   
   Example: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
   Window progression:
   - [1,1,1]: 0 zeros, length=3
   - [1,1,1,0]: 1 zero, length=4
   - [1,1,1,0,0]: 2 zeros, length=5
   - [1,1,1,0,0,0]: 3 zeros > k, shrink
   - [1,1,0,0,0]: shrink more
   - [1,0,0,0]: shrink more
   - [0,0,0,1]: shrink more
   - [0,0,1,1,1,1]: 2 zeros, length=6 ✓ (MAX)
   
   Maximum consecutive 1's after flipping at most 2 zeros: 6
*/

int longestOnes(vector<int> &nums, int k) {
    int left = 0, right = 0;
    int zeros = 0;          // Count of zeros in current window
    int maxLength = 0;      // Maximum window size
    
    while (right < nums.size()) {
        // Expand window by moving right pointer
        if (nums[right] == 0) {
            zeros++;
        }
        
        // If we have more than k zeros, shrink window from left
        while (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }
        
        // Update maximum length
        maxLength = max(maxLength, right - left + 1);
        
        // Move right pointer forward
        right++;
    }
    
    return maxLength;
}

int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    
    cout << "Max Consecutive Ones III (Sliding Window)" << endl;
    cout << "Array: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "k (max zeros to flip): " << k << endl;
    cout << endl;
    
    // Show the sliding window process
    cout << "Sliding Window Process:" << endl;
    int left = 0, zeros = 0, maxLength = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) {
            zeros++;
        }
        
        while (zeros > k) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }
        
        int currentLength = right - left + 1;
        maxLength = max(maxLength, currentLength);
        
        cout << "Window [" << left << "," << right << "]: ";
        for (int i = left; i <= right; i++) {
            cout << nums[i];
        }
        cout << " | length=" << currentLength << ", zeros=" << zeros << ", max=" << maxLength << endl;
    }
    
    cout << endl;
    int result = longestOnes(nums, k);
    cout << "Maximum consecutive 1's after flipping at most " << k << " zeros: " << result << endl;
    cout << "Expected: 6" << endl;
    
    return 0;
}
