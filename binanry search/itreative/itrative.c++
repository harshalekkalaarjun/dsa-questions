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
