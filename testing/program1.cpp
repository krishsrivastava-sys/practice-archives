#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int bottom, int mid, int top) {
    int num = top - bottom + 1;
    vector<int> temp(num); 
    int i = bottom;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= top) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= top) temp[k++] = arr[j++];

    for(int p = 0; p < num; p++) {
        arr[bottom + p] = temp[p];
    }
}
void mergesort(vector <int> &arr, int bottom, int top) {
    if(bottom < top) {
        // if we atleast have 2 elements;
        int mid = bottom + ((top - bottom) / 2);
        // We have the mid point, now recurse.
        mergesort(arr, bottom, mid);
        mergesort(arr, mid + 1, top);
        merge(arr, bottom, mid, top);
    }
};


int main() {
    int count;
    cin >> count;

    if(!(0 <= count && count <= 100)) {
        cerr << "ERROR: Out of bounds input." << endl;
        return 0;
    };

    vector <int> arr;
    arr.reserve(count);

    string input;
    getline(cin, input);
    if(input.empty()) {
        cerr << "Please provide a proper input" << endl;
    }

    stringstream ss(input);
    int temp;
    while(ss >> temp) {
        arr.push_back(temp);
    }
    int size = arr.size();
    int capacity = arr.capacity();

    if(size != capacity) {
        cout << "You have not provided with all the elements for the array.";
    }

    mergesort(arr, 0, size - 1);

    for(int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}