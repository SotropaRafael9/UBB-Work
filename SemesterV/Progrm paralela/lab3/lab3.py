from threading import Thread
import numpy as np
from concurrent.futures import ThreadPoolExecutor, as_completed
import time

def initialize_matrices(size):
    matrix_a = np.random.rand(size, size)
    matrix_b = np.random.rand(size, size)
    return matrix_a, matrix_b


def compute_element(matrix_a, matrix_b, row, col):
    return sum(matrix_a[row][k] * matrix_b[k][col] for k in range(len(matrix_b)))

# Task function to compute a chunk of the resulting matrix
def compute_chunk(matrix_a, matrix_b, result, indices):
    for row, col in indices:
        result[row][col] = compute_element(matrix_a, matrix_b, row, col)

def row_wise_split(size, num_tasks): # divide rows among tasks
    chunk_size = (size * size) // num_tasks
    indices = [(i, j) for i in range(size) for j in range(size)]
    return [indices[i * chunk_size:(i + 1) * chunk_size] for i in range(num_tasks)]

def column_wise_split(size, num_tasks):
    chunk_size = (size * size) // num_tasks
    indices = [(j, i) for i in range(size) for j in range(size)]
    return [indices[i * chunk_size:(i + 1) * chunk_size] for i in range(num_tasks)]

def k_split(size, num_tasks):
    indices = [(i, j) for i in range(size) for j in range(size)]
    return [indices[i::num_tasks] for i in range(num_tasks)]

def run_matrix_multiplication(size, num_tasks, split_method, use_thread_pool):
    matrix_a, matrix_b = initialize_matrices(size)
    result = np.zeros((size, size))

    if split_method == 'row':
        task_indices = row_wise_split(size, num_tasks)
    elif split_method == 'column':
        task_indices = column_wise_split(size, num_tasks)
    elif split_method == 'k_split':
        task_indices = k_split(size, num_tasks)
    else:
        raise ValueError("Unknown split method")

    # Choose threading approach
    start_time = time.time()
    if use_thread_pool:
        with ThreadPoolExecutor(max_workers=num_tasks) as executor:
            futures = [executor.submit(compute_chunk, matrix_a, matrix_b, result, indices)
                       for indices in task_indices]
            for future in as_completed(futures):
                future.result()  # Block until all tasks are completed
    else:
        threads = []
        for indices in task_indices:
            thread = Thread(target=compute_chunk, args=(matrix_a, matrix_b, result, indices))
            thread.start()
            threads.append(thread)
        for thread in threads:
            thread.join()  # Block until all threads are completed

    end_time = time.time()
    print(f"Size: {size}, Tasks: {num_tasks}, Split: {split_method}, Thread Pool: {use_thread_pool}")
    print(f"Execution Time: {end_time - start_time:.4f} seconds\n")
    return result

if __name__ == "__main__":
    matrix_sizes = [100]  
    num_tasks_list = [4]  
    split_methods = ['row', 'column', 'k_split']
    
    for size in matrix_sizes:
        for num_tasks in num_tasks_list:
            for split_method in split_methods:
                run_matrix_multiplication(size, num_tasks, split_method, use_thread_pool=False)
                run_matrix_multiplication(size, num_tasks, split_method, use_thread_pool=True)
