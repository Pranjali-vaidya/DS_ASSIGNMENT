#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }
    
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Target found
    }
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target); // Search in the left half
    }
    return binarySearch(arr, mid + 1, right, target); // Search in the right half
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Must be sorted for binary search
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
