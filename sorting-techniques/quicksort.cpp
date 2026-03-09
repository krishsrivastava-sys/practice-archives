#include <bits/stdc++.h>
using namespace std;


void quicksort(vector<int> &arr, int bottom, int top) {
    if (bottom < top) {
        int pivot = top; 
        int i = bottom - 1; // Your style: i starts before the current section
        int j = bottom;     // Your style: j starts at the beginning of the section

        // The logic you wrote, but bounded by 'pivot'
        while (j < pivot) {
            if (arr[j] < arr[pivot]) {
                i++;
                swap(arr[i], arr[j]);
            }
            j++; // Move to next element
        }

        // Swap pivot into its final place (i + 1)
        swap(arr[i + 1], arr[pivot]);
        int partition_index = i + 1;

        // Recurse: Use the new boundaries
        quicksort(arr, bottom, partition_index - 1); // Sort left side
        quicksort(arr, partition_index + 1, top);    // Sort right side
    }
}

int main() {
    int size;
    if (!(cin >> size)) return 0;
    vector<int> arr(size);
    for(int i = 0; i < size; i++) cin >> arr[i];

    if (size > 1) {
        quicksort(arr, 0, size - 1);
    }

    for(int x : arr) cout << x << " ";
    return 0;
}