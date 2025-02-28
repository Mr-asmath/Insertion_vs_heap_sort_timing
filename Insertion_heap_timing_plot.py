import matplotlib.pyplot as plt

# Sample data from the C program output
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
