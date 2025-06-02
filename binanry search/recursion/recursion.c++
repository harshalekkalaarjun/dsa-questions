#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

int reBinerySearch( vector<int> arr, int str, int end ,int tar ){
    if (str <= end) {
        int mid = str + (end - str)/ 2 ;
        if (arr[mid]== tar){
        return mid;

    }else if ( tar > arr[mid] ){
        return reBinerySearch(arr,mid+1,end , tar);


    }else{
        return reBinerySearch(arr, str, mid - 1, tar);
    }
}

}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 3;
    int index = reBinerySearch(arr, 0, arr.size() - 1, target);
    if (index != -1)
        cout << "Found at index: " << arr[index] << endl;
    else
        cout << "Not found" << endl;
    return 0;
}