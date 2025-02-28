# 📌 Sorting Performance Analysis: Insertion Sort vs. Heap Sort

This project compares the performance of **Insertion Sort** and **Heap Sort** by measuring execution time for different input sizes (`n`). The results are plotted to visualize their efficiency.

---

## 🚀 Overview
Sorting algorithms are fundamental in computer science.  
- **Insertion Sort**: Simple, efficient for small datasets, but slow for large inputs (`O(n²)` complexity).  
- **Heap Sort**: A faster, more scalable sorting algorithm (`O(n log n)` complexity).  

This program sorts random numbers using both methods and measures execution time for various values of `n`.

---

## 🛠️ Features
✅ Implements **Insertion Sort** and **Heap Sort** in C.  
✅ Uses **clock()** to measure execution time.  
✅ Compares sorting efficiency for different values of `n`.  
✅ Provides results in **tabular format**.  
✅ Includes **Python script** to plot **time vs. n** graph.  

---

## 📌 Algorithm Explanation
### 🔹 **Insertion Sort**
1. Starts with the second element, placing it in the correct position.
2. Shifts larger elements to the right before inserting the element.
3. Repeats for all elements.
4. **Time Complexity**:  
   - Best Case: **O(n)**
   - Worst Case: **O(n²)**

### 🔹 **Heap Sort**
1. Builds a **Max Heap** from the input array.
2. Extracts the maximum element and moves it to the end.
3. Heapifies the remaining elements.
4. **Time Complexity**:  
   - Best Case: **O(n log n)**
   - Worst Case: **O(n log n)**

---

## 📝 Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
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
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
    int sizes[] = {1000, 5000, 10000, 20000, 50000}; // Different values of n
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("n\tInsertion Sort Time (s)\tHeap Sort Time (s)\n");

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *arr1 = (int *)malloc(size * sizeof(int));
        int *arr2 = (int *)malloc(size * sizeof(int));

        // Generate random numbers
        for (int j = 0; j < size; j++) {
            arr1[j] = rand() % 1000;
            arr2[j] = arr1[j];
        }

        // Measure time for both sorts
        double insertionTime = measureExecutionTime(insertionSort, arr1, size);
        double heapTime = measureExecutionTime(heapSort, arr2, size);

        printf("%d\t%.6f\t\t%.6f\n", size, insertionTime, heapTime);

        free(arr1);
        free(arr2);
    }

    return 0;
}
```


**🎯 Compilation & Execution**

To compile and run the program, use:

```sh

gcc sorting_analysis.c -o sorting_analysis
./sorting_analysis
```

## 📊 Expected Output (Sample)
```css
n       Insertion Sort Time (s)    Heap Sort Time (s)
1000    0.002345                    0.000678
5000    0.058973                    0.004892
10000   0.214385                    0.012678
20000   0.845972                    0.026543
50000   5.672345                    0.098543
```

## 🔹 Observations:

Insertion Sort performs well for small n but slows down significantly for large inputs (O(n²)).
Heap Sort is consistently faster (O(n log n)).

## 📈 Plotting Graph (Python)

To visualize the results, use the following Python script:

```python

import matplotlib.pyplot as plt

# Sample data
n_values = [1000, 5000, 10000, 20000, 50000]
insertion_times = [0.002345, 0.058973, 0.214385, 0.845972, 5.672345]
heap_times = [0.000678, 0.004892, 0.012678, 0.026543, 0.098543]

plt.figure(figsize=(8, 5))
plt.plot(n_values, insertion_times, marker='o', linestyle='-', label='Insertion Sort')
plt.plot(n_values, heap_times, marker='s', linestyle='-', label='Heap Sort')

plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Sorting Time Comparison: Insertion Sort vs. Heap Sort')
plt.legend()
plt.grid()
plt.show()
```

## 🔍 Key Findings

Insertion Sort is inefficient for large datasets because of its O(n²) complexity.
Heap Sort is significantly faster, handling large inputs efficiently.
The graph visually demonstrates Heap Sort’s advantage over Insertion Sort.

## 📚 References

Insertion Sort - GeeksforGeeks

Heap Sort - GeeksforGeeks

Sorting Algorithms - Wikipedia

## ✨ Conclusion

This project illustrates the performance differences between Insertion Sort and Heap Sort.
For large datasets, Heap Sort is clearly superior in terms of efficiency. 🚀

