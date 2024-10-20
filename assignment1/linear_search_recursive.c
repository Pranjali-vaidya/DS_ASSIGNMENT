#include <stdio.h>

int linearSearch(int arr[], int n, int target, int index) {
    if (index >= n) {
        return -1; // Target not found
    }
    if (arr[index] == target) {
        return index; // Target found
    }
    return linearSearch(arr, n, target, index + 1); // Recur for the next index
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    int result = linearSearch(arr, n, target, 0);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
