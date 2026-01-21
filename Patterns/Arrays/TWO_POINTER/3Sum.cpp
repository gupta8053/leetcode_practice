#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 3SUM PROBLEM: Find all unique triplets that sum to 0
   
   Approach: Sort + Two Pointer
   - Sort the array first
   - Fix one element and use two-pointer to find pairs that sum to -nums[i]
   - Skip duplicates to avoid duplicate triplets
   
   Time Complexity: O(n²) - outer loop O(n), two-pointer inner loop O(n)
   Space Complexity: O(1) or O(n) depending on sorting algorithm (excluding output)
*/

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();

    // Early exit for small input
    if (n < 3) return result;

    // Sort the array
    sort(nums.begin(), nums.end());
    
    // Fix one element and find pairs using two-pointer
    for (int i = 0; i < n - 2; i++) {
        // If the first element is positive, no triplet can sum to 0
        if (nums[i] > 0) break;
        
        // Skip duplicate elements for the fixed position
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Two pointer approach to find pairs that sum to -nums[i]
        int left = i + 1, right = n - 1;
        int target = -nums[i];
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == target) {
                // Found a triplet
                result.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates on the left
                while (left < right && nums[left] == nums[left + 1]) left++;
                // Skip duplicates on the right
                while (left < right && nums[right] == nums[right - 1]) right--;
                
                left++;
                right--;
            } 
            else if (sum < target) {
                left++;  // Need larger sum
            } 
            else {
                right--;  // Need smaller sum
            }
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Triplets that sum to 0:" << endl;
    if (result.empty()) {
        cout << "No triplets found" << endl;
    } else {
        for (const auto &triplet : result) {
            cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
        }
    }
    
    return 0;
}
