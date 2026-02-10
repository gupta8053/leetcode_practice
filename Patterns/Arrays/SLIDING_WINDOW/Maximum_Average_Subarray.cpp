#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/* MAXIMUM AVERAGE SUBARRAY OF SIZE K (Sliding Window Pattern)
   
   Problem: Find a contiguous subarray of length k with maximum average value
   
   Approach: Sliding Window
   - Instead of recalculating sum for each subarray (O(n*k)), use a sliding window
   - Calculate sum of first k elements
   - Slide the window by removing leftmost element and adding next element on right
   - This avoids redundant calculations
   
   Key idea:
   - window_sum = sum of current k elements
   - When sliding: window_sum = window_sum - nums[i] + nums[i+k]
   - Average = window_sum / k
   
   Time Complexity: O(n) - single pass through array
   Space Complexity: O(1) - only tracking sum and maximum
   
   Example: nums = [1,12,-5,-6,50,3], k = 4
   Window 1: [1, 12, -5, -6]    sum = 2,   avg = 0.5
   Window 2: [12, -5, -6, 50]   sum = 51,  avg = 12.75 ✓ (MAX)
   Window 3: [-5, -6, 50, 3]    sum = 42,  avg = 10.5
   
   Maximum average: 12.75
*/

double findMaxAverage(vector<int> &nums, int k) {
    // Calculate sum of first k elements
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int maxSum = windowSum;  // Track maximum sum found
    
    // Slide the window: remove left element, add right element
    for (int i = k; i < nums.size(); i++) {
        // Remove the leftmost element of previous window
        // Add the new element on the right
        windowSum = windowSum - nums[i - k] + nums[i];
        
        // Update maximum sum if current sum is larger
        maxSum = max(maxSum, windowSum);
    }
    
    // Return average (maximum sum divided by k)
    return (double)maxSum / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    
    cout << "Maximum Average Subarray of Size K (Sliding Window)" << endl;
    cout << "Array: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "K = " << k << endl;
    cout << endl;
    
    // Show sliding window process
    cout << "Sliding Window Process:" << endl;
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    cout << "Window 1: [";
    for (int i = 0; i < k; i++) {
        cout << nums[i];
        if (i < k - 1) cout << ", ";
    }
    cout << "] sum = " << windowSum << ", avg = " << fixed << setprecision(5) << (double)windowSum / k << endl;
    
    int maxSum = windowSum;
    for (int i = k; i < nums.size(); i++) {
        windowSum = windowSum - nums[i - k] + nums[i];
        if (windowSum > maxSum) maxSum = windowSum;
        
        cout << "Window " << (i - k + 2) << ": [";
        for (int j = i - k + 1; j <= i; j++) {
            cout << nums[j];
            if (j < i) cout << ", ";
        }
        cout << "] sum = " << windowSum << ", avg = " << fixed << setprecision(5) << (double)windowSum / k << endl;
    }
    
    cout << endl;
    double result = findMaxAverage(nums, k);
    cout << "Maximum average: " << fixed << setprecision(5) << result << endl;
    cout << "Expected:       12.75000" << endl;
    
    return 0;
}
