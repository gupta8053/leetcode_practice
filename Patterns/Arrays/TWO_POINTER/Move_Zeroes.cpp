#include <iostream>
#include <vector>
using namespace std;

/* MOVE ZEROES PROBLEM
   
   Problem: Move all 0's to the end while maintaining relative order of non-zero elements
   - Must do this in-place without making a copy
   
   Approach: Two Pointer
   - Use insertPos pointer to track where the next non-zero element should be placed
   - Use i pointer to iterate through the array
   - When nums[i] != 0, place it at nums[insertPos] and increment insertPos
   - After iteration, fill remaining positions with zeros
   
   Why this works:
   - First pass: compact all non-zero elements to the left
   - Second pass: fill the rest with zeros
   - This maintains the relative order of non-zero elements
   
   Time Complexity: O(n) - two passes through the array
   Space Complexity: O(1) - in-place, only using two pointers
   
   Example: [0,1,0,3,12]
   - Move non-zeros left: [1,3,12,0,0]
*/

void moveZeroes(vector<int> &nums) {
    int insertPos = 0;
    
    // First pass: move all non-zero elements to the left
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            // Place non-zero element at insertPos
            nums[insertPos] = nums[i];
            insertPos++;
        }
    }
    
    // Second pass: fill remaining positions with zeros
    while (insertPos < nums.size()) {
        nums[insertPos] = 0;
        insertPos++;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Move Zeroes Problem (Two Pointer Approach)" << endl;
    cout << "Original array: [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    moveZeroes(nums);
    
    cout << "Result array:   [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Expected:       [1, 3, 12, 0, 0]" << endl;
    
    return 0;
}
