import random

# define the graph as an adjacency matrix
graph = [[0, 1, 1, 1],
         [1, 0, 1, 0],
         [1, 1, 0, 1],
         [1, 0, 1, 0]]

# define the number of colors and the number of iterations
num_colors = 3
num_iterations = 1000

# assign random colors to each node
current_solution = [random.randint(0, num_colors-1) for _ in range(len(graph))]

# evaluate the current solution by counting the number of conflicts
def evaluate(solution):
    conflicts = 0
    for i in range(len(graph)):
        for j in range(i+1, len(graph)):
            if graph[i][j] == 1 and solution[i] == solution[j]:
                conflicts += 1
    return conflicts

# run the local search algorithm
for iteration in range(num_iterations):
    # select a random node and color to change
    node_index = random.randint(0, len(graph)-1)
    old_color = current_solution[node_index]
    new_color = random.randint(0, num_colors-1)
    
    # temporarily change the color and evaluate the new solution
    current_solution[node_index] = new_color
    new_conflicts = evaluate(current_solution)
    
    # if the new solution is better, accept it
    if new_conflicts < evaluate(current_solution):
        current_solution[node_index] = new_color
    # otherwise, revert the color change
    else:
        current_solution[node_index] = old_color

# print the final solution and the number of conflicts
print("Final solution:", current_solution)
print("Number of conflicts:", evaluate(current_solution))
