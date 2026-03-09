#include <stdio.h>
#include <stdlib.h>

// Function Declerations;
void mergesort(int *arr, int bottom, int top);
void merge(int *arr, int bottom, int mid, int top);

int main() {
    int count;
    printf("Enter the number of elements: ");
    if(!scanf("%d", &count)) {// Fail proof scanf, production grade.
        perror("Error, unable to scan the value.");
        return 1;
    }
    int *arr = malloc(count * sizeof(int)); // DMA memory allocation.
    if(!arr) {
        perror("[i] Unable to do memory allocation from heap.");
        return 1;
    }
    for(int i = 0; i < count; i++) {
        printf("Enter element #%d: ", i + 1);
        if(!scanf("%d", &arr[i])) {
            perror("Error, unable to scan the value.");
            return 1;
        }
    }
    mergesort(arr, 0, count - 1);// Array pointer passed.
    free(arr);// Prevents leakage in memory.
    return 0;
}

void mergesort(int *arr, int bottom, int top) {
    // if bottom index is less than top index (checking the array size.)
    if(bottom < top) {
        int midpoint = bottom + (top - bottom) / 2;
        // Recurse Split until we find the mid point;
        mergesort(arr, bottom, midpoint);
        mergesort(arr, midpoint + 1, top);
        merge(arr, bottom, midpoint, top);
    }
}

void merge(int *arr, int bottom, int mid, int top) {
    int num = top - bottom + 1;
    int *temp = malloc(num * sizeof(int));
    if(!temp) {
        perror("Error, unable to allocate memory from heap.");
        exit(1);
    }
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
    // To put left over elements back to temp;
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= top) temp[k++] = arr[j++];
    for(int p = 0; p < num; p++) {
        arr[bottom + p] = temp[p];
    }
    free(temp);
}
