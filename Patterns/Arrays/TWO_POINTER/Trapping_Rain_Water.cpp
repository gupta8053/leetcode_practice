#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* TRAPPING RAIN WATER PROBLEM
   
   Problem: Calculate how much water can be trapped after raining
   - Given an elevation map, water gets trapped between higher bars
   - Water trapped at position i = min(max_left, max_right) - height[i]
   - max_left: maximum height to the left of position i
   - max_right: maximum height to the right of position i
   
   Approach: Two Pointer (Optimal Space)
   - Use two pointers: left (start), right (end)
   - Track leftMax and rightMax as we move pointers
   - At each position, water trapped = min(leftMax, rightMax) - height
   - Move the pointer with smaller max height inward
   
   Why this works:
   - If leftMax < rightMax, we know water at left = leftMax - height[left]
     (because rightMax is guaranteed to be at least as large as any future leftMax)
   - Similarly for right when rightMax < leftMax
   
   Time Complexity: O(n) - single pass with two pointers
   Space Complexity: O(1) - only using pointers, no extra arrays
   
   Example: height = [0,1,0,2,1,0,1,3,2,1,2,1]
   Water trapped at each position:
   - i=2: between 1 and 2, trapped = 1
   - i=4: between 2 and 3, trapped = 1
   - i=5: between 1 and 3, trapped = 1
   - i=6: between 1 and 3, trapped = 2
   - i=8: between 3 and 2, trapped = 0
   Total: 6 units
*/

int trap(vector<int> &height) {
    if (height.size() < 3) return 0;  // Need at least 3 bars to trap water
    
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;  // Maximum heights seen so far from each side
    int totalWater = 0;
    
    while (left < right) {
        // Update leftMax: track the maximum height seen from the left
        if (height[left] >= leftMax) {
            leftMax = height[left];
        }
        
        // Update rightMax: track the maximum height seen from the right
        if (height[right] >= rightMax) {
            rightMax = height[right];
        }
        
        // Move the pointer with smaller max height and calculate trapped water
        if (leftMax < rightMax) {
            // Left max is smaller, so we know water level at left is determined by leftMax
            // Water trapped = leftMax - height[left]
            totalWater += leftMax - height[left];
            left++;
        } else {
            // Right max is smaller or equal, so we know water level at right is determined by rightMax
            // Water trapped = rightMax - height[right]
            totalWater += rightMax - height[right];
            right--;
        }
    }
    
    return totalWater;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    cout << "Trapping Rain Water Problem (Two Pointer)" << endl;
    cout << "Elevation map: [";
    for (int i = 0; i < height.size(); i++) {
        cout << height[i];
        if (i < height.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    int result = trap(height);
    
    cout << "Water trapped: " << result << " units" << endl;
    cout << "Expected:     6 units" << endl;
    
    return 0;
}
