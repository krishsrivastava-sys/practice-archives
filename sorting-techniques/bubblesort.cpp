#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

int main() {
    vector<int> data = {5, 1, 4, 2, 8};
    bubbleSort(data);

    cout << "Sorted array: ";
    for (int x : data) cout << x << " ";
    return 0;
}