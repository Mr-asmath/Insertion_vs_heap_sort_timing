#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
	int i;
    for ( i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to heapify a subtree with root at index i
void heapify(int arr[], int size, int i) {
    int largest = i;  
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int size) {
	int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for ( i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

// Function to measure execution time
double measureExecutionTime(void (*sortFunction)(int[], int), int arr[], int size) {
    clock_t start, end;
    start = clock();
    sortFunction(arr, size);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int i,j,sizes[] = {1000, 5000, 10000, 20000, 50000}; // Different values of n
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("n\tInsertion Sort Time (s)\tHeap Sort Time (s)\n");

    for ( i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *arr1 = (int *)malloc(size * sizeof(int));
        int *arr2 = (int *)malloc(size * sizeof(int));

        // Generate a random array and duplicate it for both sorting methods
        generateRandomArray(arr1, size);
        for ( j = 0; j < size; j++) {
            arr2[j] = arr1[j];
        }

        // Measure time for Insertion Sort
        double insertionTime = measureExecutionTime(insertionSort, arr1, size);
        
        // Measure time for Heap Sort
        double heapTime = measureExecutionTime(heapSort, arr2, size);

        printf("%d\t%.6f\t\t%.6f\n", size, insertionTime, heapTime);

        free(arr1);
        free(arr2);
    }

    return 0;
}

