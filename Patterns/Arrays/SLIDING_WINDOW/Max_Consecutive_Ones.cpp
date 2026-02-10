#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* MAX CONSECUTIVE ONES (Sliding Window Pattern)
   
   Problem: Find the maximum number of consecutive 1's in a binary array
   
   Approach: Simple Sliding Window / Counter
   - Iterate through the array
   - When we see a 1, increment a counter
   - When we see a 0, reset the counter to 0
   - Track the maximum count seen
   
   Why this works:
   - We maintain a "window" of consecutive 1's
   - The window automatically expands when we see 1's
   - The window resets when we see 0
   - This is a variant of sliding window with dynamic window size
   
   Time Complexity: O(n) - single pass through array
   Space Complexity: O(1) - only using counters
   
   Example: nums = [1,1,0,1,1,1]
   - i=0: nums[0]=1, count=1, max=1
   - i=1: nums[1]=1, count=2, max=2
   - i=2: nums[2]=0, count=0, max=2
   - i=3: nums[3]=1, count=1, max=2
   - i=4: nums[4]=1, count=2, max=2
   - i=5: nums[5]=1, count=3, max=3 ✓
   
   Maximum consecutive 1's: 3
*/

int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = 0;      // Current consecutive 1's count
    int maxCount = 0;   // Maximum consecutive 1's found
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            // Current element is 1, increment count
            count++;
        } else {
            // Current element is 0, reset count
            // Update maxCount before resetting
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    
    // Important: Update maxCount one more time after loop ends
    // In case the array ends with 1's like [1,1,1]
    maxCount = max(maxCount, count);
    
    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    
    cout << "Max Consecutive Ones (Sliding Window)" << endl;
    cout << "Array: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << endl;
    
    // Show the process
    cout << "Process:" << endl;
    int count = 0, maxCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            count++;
        } else {
            maxCount = max(maxCount, count);
            cout << "Index " << i << ": Found 0, reset count. Max so far: " << maxCount << endl;
            count = 0;
        }
    }
    maxCount = max(maxCount, count);
    
    cout << endl;
    int result = findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive 1's: " << result << endl;
    cout << "Expected:                3" << endl;
    
    return 0;
}
