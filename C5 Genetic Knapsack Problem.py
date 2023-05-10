import random

# Define the problem and encoding
items = [(1, 10, 5), (2, 4, 3), (3, 7, 2), (4, 5, 1), (5, 1, 2)]
capacity = 10
n_items = len(items)

# Define the genetic algorithm parameters
population_size = 50
mutation_rate = 0.1
n_generations = 100

# Define the fitness function
def fitness(solution):
    total_value = sum(items[i][1] for i in range(n_items) if solution[i])
    total_weight = sum(items[i][2] for i in range(n_items) if solution[i])
    if total_weight > capacity:
        return 0
    else:
        return total_value

# Initialize the population
population = [random.choices([0, 1], k=n_items) for _ in range(population_size)]

# Iterate over the generations
for generation in range(n_generations):
    # Evaluate the fitness of the population
    fitness_values = [fitness(solution) for solution in population]

    # Select the parents for reproduction
    parents = random.choices(population, weights=fitness_values, k=population_size)

    # Perform crossover and mutation
    offspring = []
    for i in range(population_size):
        parent1 = parents[i]
        parent2 = random.choice(parents)
        crossover_point = random.randint(1, n_items - 1)
