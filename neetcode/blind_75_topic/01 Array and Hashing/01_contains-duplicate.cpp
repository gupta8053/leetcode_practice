/* PROGRAM: 03_Array - Contains Duplicate
YT: https://www.youtube.com/watch?v=MpcFgWRD0E0&list=PLPERBdDHWLi1x0ZxbnCd5t8yxEudSrxxH&index=3
https://leetcode.com/problems/contains-duplicate/
*/
#include <ios>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
    public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hashed;

        for (int n : nums) {
            if (hashed.count(n)) {
                return true;
            }
            //  else hash the current element
            hashed.insert(n);
        }
        
        // if not found
        return false;
    }
};

int main() {
    int arr[] = {1, 2, 3, 1};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    Solution sol;
    bool ret = sol.containsDuplicate(v);
    cout << boolalpha << ret << endl;  // boolalpha to print the boolean value instead of
                                       // numeric(0/1)
    return 0;
}
