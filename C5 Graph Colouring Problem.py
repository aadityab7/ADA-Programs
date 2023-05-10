import random
import math

def simulated_annealing(graph, initial_temperature, cooling_rate):
    # Initialize the current solution to a random coloring
    current_solution = {}
    for node in graph:
        current_solution[node] = random.randint(1, len(graph))

    # Initialize the temperature and the number of iterations
    temperature = initial_temperature
    iterations = 0

    # Iterate until the temperature is zero
    while temperature > 0:
        # Perturb the current solution by swapping two random colors
        node1 = random.choice(list(graph.keys()))
        node2 = random.choice(list(graph.keys()))
        color1 = current_solution[node1]
        color2 = current_solution[node2]
        new_solution = dict(current_solution)
        new_solution[node1] = color2
        new_solution[node2] = color1

        # Compute the objective function values of the current and new solutions
        current_value = count_colors(current_solution)
        new_value = count_colors(new_solution)

        # If the new solution is better, accept it
        if new_value < current_value:
            current_solution = new_solution
        # If it is worse, accept it with a probability that depends on the temperature
        else:
            probability = math.exp(-(new_value - current_value) / temperature)
            if random.random() < probability:
                current_solution = new_solution

        # Decrease the temperature and increase the number of iterations
        temperature *= cooling_rate
        iterations += 1

    # Return the final solution and the number of iterations
    return current_solution, iterations

def count_colors(solution):
    # Count the number of distinct colors used in the solution
    return len(set(solution.values()))
