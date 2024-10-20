#include <stdio.h>


void selectionSort(int arr[], int n, int *passes, int *comparisons);
void bubbleSort(int arr[], int n, int *passes, int *comparisons);
void insertionSort(int arr[], int n, int *passes, int *comparisons);

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int passes1 = 0, comparisons1 = 0;

    selectionSort(arr1, n1, &passes1, &comparisons1);
    printf("Selection Sort: Passes = %d, Comparisons = %d\n", passes1, comparisons1);

    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int passes2 = 0, comparisons2 = 0;

    bubbleSort(arr2, n2, &passes2, &comparisons2);
    printf("Bubble Sort: Passes = %d, Comparisons = %d\n", passes2, comparisons2);

    int arr3[] = {64, 25, 12, 22, 11};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int passes3 = 0, comparisons3 = 0;

    insertionSort(arr3, n3, &passes3, &comparisons3);
    printf("Insertion Sort: Passes = %d, Comparisons = %d\n", passes3, comparisons3);

    return 0;
}

void selectionSort(int arr[], int n, int *passes, int *comparisons) {
    for (int i = 0; i < n - 1; i++) {
        (*passes)++; 
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++; 
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n, int *passes, int *comparisons) {
    for (int i = 0; i < n - 1; i++) {
        (*passes)++; 
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++; 
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *passes, int *comparisons) {
    for (int i = 1; i < n; i++) {
        (*passes)++; 
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++; 
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        if (j >= 0) {
            (*comparisons)++; 
        }
    }
}
