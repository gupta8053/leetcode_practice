/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find maximum number of fruits that can be picked with 2 baskets
int totalFruit(vector<int>& fruits) {
    // HashMap to store frequency of fruit types in current window
    unordered_map<int, int> basket;
    // Left pointer of sliding window
    int left = 0;
    // Variable to store maximum fruits picked
    int maxFruits = 0;
    
    // Iterate through array with right pointer
    for (int right = 0; right < fruits.size(); right++) {
        // Add current fruit to basket (increment its count)
        basket[fruits[right]]++;
        
        // If number of different fruit types exceeds 2, shrink window from left
        while (basket.size() > 2) {
            // Decrement frequency of left fruit
            basket[fruits[left]]--;
            // If count becomes 0, remove fruit type from basket
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            // Move left pointer to the right
            left++;
        }
        
        // Update maximum fruits count with current window size
        // (right - left + 1) represents number of fruits from [left, right]
        maxFruits = max(maxFruits, right - left + 1);
    }
    
    // Return maximum number of fruits that can be picked
    return maxFruits;
}

int main() {
    // Test Case 1
    vector<int> fruits1 = {1, 2, 1};
    cout << "Input: fruits = [1,2,1]" << endl;
    cout << "Output: " << totalFruit(fruits1) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 2
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Input: fruits = [0,1,2,2]" << endl;
    cout << "Output: " << totalFruit(fruits2) << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 3
    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Input: fruits = [1,2,3,2,2]" << endl;
    cout << "Output: " << totalFruit(fruits3) << endl;
    cout << "Expected: 4" << endl;
    
    return 0;
}