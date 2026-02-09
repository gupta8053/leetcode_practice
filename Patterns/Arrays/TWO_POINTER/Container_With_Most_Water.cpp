#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* CONTAINER WITH MOST WATER PROBLEM
   
   Problem: Find two lines that form a container with the most water
   - Container area = min(height[i], height[j]) * (j - i)
   - i is the left line, j is the right line
   - Width = j - i, Height = min(height[i], height[j])
   
   Approach: Two Pointer (Greedy)
   - Start with left pointer at 0, right pointer at n-1
   - The width is maximum at the start
   - Calculate area with current pair
   - Move the pointer pointing to the shorter line inward
     * Why? Moving the taller line can only decrease area (width decreases)
     * Moving the shorter line might find a taller line and increase area
   - Keep track of maximum area found
   
   Why this works (Greedy):
   - At each step, one of the lines will be the limiting factor
   - Moving the taller line pointer guarantees area won't increase
   - Moving the shorter line pointer has a chance to increase area
   
   Time Complexity: O(n) - single pass with two pointers
   Space Complexity: O(1) - only using pointers
   
   Example: height = [1,8,6,2,5,4,8,3,7]
   - Start: left=0 (h=1), right=8 (h=7), area = min(1,7) * 8 = 8
   - Move left (shorter): left=1 (h=8), right=8 (h=7), area = min(8,7) * 7 = 49 (MAX)
   - Continue until pointers meet
   - Result: 49
*/

int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;
    
    while (left < right) {
        // Calculate DISTANCE (width of container)
        int width = right - left;                               // Distance between two lines
        int currentHeight = min(height[left], height[right]);   // Calculate HEIGHT (limiting factor)
        // Water height is limited by the shorter line (can't exceed it)

        int currentArea = width * currentHeight;                // Area = width × height
        
        // Update if current area is larger than max found so far
        maxWater = max(maxWater, currentArea);
        
        // GREEDY CHOICE: Move the SHORTER pointer
        if (height[left] < height[right]) {
            // Left line is shorter, move it right
            // Why? The right line is taller; moving it left only decreases width
            // Moving left might find a taller line to increase area
            left++;
        } else {
            // Right line is shorter or equal, move it left
            right--;
        }
    }
    
    return maxWater;
}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    cout << "Container With Most Water Problem (Two Pointer)" << endl;
    cout << "Height array: [";
    for (int i = 0; i < height.size(); i++) {
        cout << height[i];
        if (i < height.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    int result = maxArea(height);
    
    cout << "Maximum water area: " << result << endl;
    
    return 0;
}
