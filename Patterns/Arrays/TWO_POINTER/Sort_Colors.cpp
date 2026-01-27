#include <iostream>
#include <vector>
using namespace std;

/* METHOD 1: Two Pointer Approach (Two Pass)
   
   Problem: Sort array of 0s, 1s, and 2s in-place
   - 0 = red, 1 = white, 2 = blue
   - Must solve without using library's sort function
   
   Approach: Two Pointer (Two Pass)
   - Pass 1: Move all 0s to the beginning
     * Use two pointers: left (start), right (end)
     * When nums[left] is 0, move left forward
     * When nums[right] is not 0, move right backward
     * Swap when nums[left] != 0 and nums[right] == 0
   
   - Pass 2: Move all 2s to the end
     * Use two pointers: left (start), right (end)
     * When nums[left] is 1, move left forward
     * When nums[right] is not 2, move right backward
     * Swap when nums[left] == 2 and nums[right] == 1
   
   - Remaining elements are 1s in the middle
   
   Time Complexity: O(n) - two passes
   Space Complexity: O(1) - only uses two pointers
*/

void sortColors(vector<int> &nums) {
    int n = nums.size();
    
    // Pass 1: Move all 0s to the beginning
    int left = 0, right = n - 1;
    
    while (left < right) {
        // Find first non-zero element from left
        while (left < right && nums[left] == 0) {
            left++;
        }
        // Find first zero element from right
        while (left < right && nums[right] != 0) {
            right--;
        }
        // Swap when found
        if (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    
    // Pass 2: Move all 2s to the end
    left = 0;
    right = n - 1;
    
    while (left < right) {
        // Find first 2 element from left
        while (left < right && nums[left] != 2) {
            left++;
        }
        // Find first non-2 element from right
        while (left < right && nums[right] == 2) {
            right--;
        }
        // Swap when found
        if (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
}

/* METHOD 2: Three Pointer Approach (Dutch National Flag - One Pass)
   
   Approach: Three Pointer
   - Use three pointers: low, mid, high
   - low: boundary between 0s and 1s (all elements before low are 0s)
   - mid: current element being examined
   - high: boundary between 1s and 2s (all elements after high are 2s)
   
   Algorithm:
   - If nums[mid] == 0: swap with nums[low], move both pointers right
   - If nums[mid] == 1: move mid pointer right
   - If nums[mid] == 2: swap with nums[high], move high pointer left (don't increment mid)
   
   Time Complexity: O(n) - single pass
   Space Complexity: O(1) - only uses three pointers
*/

void sortColorsDutchFlag(vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap 0 with low pointer and move both
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            // 1 is already in correct relative position, just move mid
            mid++;
        } 
        else {  // nums[mid] == 2
            // Swap 2 with high pointer and move high left
            // Don't move mid because we need to check the swapped element
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


int main() {
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = {2, 0, 2, 1, 1, 0};
    
    // Method 1: Two Pointer Approach
    cout << "METHOD 1: Two Pointer Approach (Two Pass)" << endl;
    cout << "Original array: [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    sortColors(nums1);
    
    cout << "Sorted array:   [";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << endl;
    
    // Method 2: Dutch National Flag Approach
    cout << "METHOD 2: Dutch National Flag Approach (One Pass)" << endl;
    cout << "Original array: [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    sortColorsDutchFlag(nums2);
    
    cout << "Sorted array:   [";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i];
        if (i < nums2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
