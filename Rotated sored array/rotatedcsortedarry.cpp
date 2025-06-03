// search roteted sorted array  ( linear shearch  o(n), bineary search o(log n) )
// Problem: Given a rotated sorted array, find the index of a target value.
//leetcide problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
// leetcode problem no: 33
// leetcode problem difficulty: Medium
// leetcode problem tags: Array, Binary Search
// leetcode problem solution: https://leetcode.com/problems/search-in-rotated-sorted-array/solutions/32950/c-binary-search-solution/
// rules for this code:
// 1. Use C++14 language standard.
// 2. Use the standard library for input/output and vector.
// 3. Implement a binary search algorithm to find the target value in a rotated sorted array.


#include <iostream>

#include <vector>
using namespace std;
// rotated sorted arry 
class Solution {
    public:
    int search (vector <int>& nums , int target) {
        int left = 0;
        int right = nums.size() -1;
        while( left <= right){
            int mid = left +(right - left)/ 2;
            if (nums[mid] == target){
                return mid ; 
            }
            if ( nums[ left]<= nums[mid]){
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            };
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target =4 ;
    int result = sol.search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl;
    return 0;
}