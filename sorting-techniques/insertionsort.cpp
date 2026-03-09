#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element we want to "insert"
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shifting
            j--;
        }
        // Place the key in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> data = {12, 11, 13, 5, 6};
    insertionSort(data);

    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    return 0;
}