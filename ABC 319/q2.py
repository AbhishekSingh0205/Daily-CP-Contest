print("Name : Varandeep Sahota")
print("Roll Number : 20CS8164")
import numpy as np
from scipy.optimize import linear_sum_assignment

n,m = map(int,input("Enter the n X m of grid :- ").split(' '))
grid = [] 
print("Enter the grid")
for i in range(0,n):
	grid.append(list(map(int,(input().split(' ')))))

cost_matrix = np.array(grid)

supply_nodes = list(input("Enter suply:- ").split(" "))
demand_nodes = list(map(int,input("Enter Demand:- ").split(" ")))

row_ind, col_ind = linear_sum_assignment(cost_matrix)


for i in range(len(supply_nodes)):
    supply_node = supply_nodes[i]
    demand_node = demand_nodes[col_ind[i]]
    cost = cost_matrix[i, col_ind[i]]
    print(f"{supply_node} -> {demand_node} (Cost: {cost})")

total_cost = cost_matrix[row_ind, col_ind].sum()
print(f"Total Transportation Cost: {total_cost}")