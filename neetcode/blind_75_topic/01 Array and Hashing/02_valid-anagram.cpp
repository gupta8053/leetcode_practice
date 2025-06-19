/* PROGRAM: 29_String - Valid Anagram
YT: https://www.youtube.com/watch?v=MpcFgWRD0E0&list=PLPERBdDHWLi1x0ZxbnCd5t8yxEudSrxxH&index=3
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the lengths are different, they can't be anagrams
        if (s.length() != t.length()) return false;

        // Create a count array of size 128 (ASCII character set) and initialize all elements to 0
        // It will track the difference in frequency of characters between both strings
        vector<int> count(128, 0);

        // Traverse both strings simultaneously
        for (int i = 0; i < s.length(); ++i) {
            // Increment the count of the character from string `s`
            count[s[i]]++;
            // Decrement the count of the character from string `t`
            count[t[i]]--;
        }

        // After the loop, if `s` and `t` are anagrams,
        // the count array should contain only zeros (all character frequencies balanced)
        for (int c : count) {
            // If any count is not zero, the characters differ in frequency
            if (c != 0) return false;
        }

        // All characters matched in frequency => `s` and `t` are anagrams
        return true;
    }
};

int main() {
    // Declare two strings to compare
    string s = "anagram", t = "nagaram";

    Solution sol;

    // boolalpha makes the output display as "true"/"false" instead of "1"/"0"
    cout << boolalpha << sol.isAnagram(s, t) << endl;

    return 0;
}
