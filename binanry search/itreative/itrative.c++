//leetcode problem no: 704
// leetcode problem difficulty: Easy
// leetcode problem tags: Array, Binary Search
// leetcode problem solution: https://leetcode.com/problems/binary-search/solutions/32950/c-binary-search-solution/
// rules for this code:
// 1. Use C++14 language standard.
// 2. Use the standard library for input/output and vector.
// 3. Implement an iterative binary search algorithm.
// 4. The function should return the index of the target value if found, otherwise return -1.
// 5. The main function should demonstrate the binary search with a sample array and target value.
// This code implements an iterative binary search algorithm in C++.
// This code is designed to search for a target value in a sorted array using binary search.
// The function returns the index of the target value if found, otherwise it returns -1.
// This code is written in C++ and uses the standard library for input/output and vector operations.
// This code is an implementation of an iterative binary search algorithm in C++.
// This code is designed to search for a target value in a sorted array using binary search.



#include <iostream>
#include <vector>
using namespace std;

int iterativeBinarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 3;
    int index = iterativeBinarySearch(arr, target);
    if (index != -1)
        cout << "Found at index: " << index << " value: " << arr[index] << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
