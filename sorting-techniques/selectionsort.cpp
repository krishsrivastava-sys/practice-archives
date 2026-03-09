#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part
        int min_idx = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        // This is the only swap per pass!
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
        }
    }
}

int main() {
    vector<int> data = {64, 25, 12, 22, 11};
    selectionSort(data);

    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    return 0;
}