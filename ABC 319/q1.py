print("Name : Varandeep Sahota")
print("Roll Number : 20CS8164")
import numpy as np
from scipy.optimize import linear_sum_assignment

n,m = map(int,input("Enter the n X m of grid :- ").split(' '))
grid = [] # table
print("Enter the grid")
for i in range(0,n):
	grid.append(list(map(int,(input().split(' ')))))
      
cost_matrix = np.array(grid)

row_indices, col_indices = linear_sum_assignment(cost_matrix)

for i in range(len(row_indices)):
    print(f"Worker {col_indices[i] + 1} -> Task {row_indices[i] + 1} (Cost: {cost_matrix[row_indices[i], col_indices[i]]})")

total_cost = cost_matrix[row_indices, col_indices].sum()
print(f"Total Cost: {total_cost}")