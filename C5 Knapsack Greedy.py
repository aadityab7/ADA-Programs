def knapsack_greedy(values, weights, capacity):
    n = len(values)
    density = [(values[i] / weights[i], i) for i in range(n)]
    density.sort(reverse=True)
    total_value = 0
    total_weight = 0
    for d, i in density:
        if total_weight + weights[i] <= capacity:
            total_value += values[i]
            total_weight += weights[i]
        else:
            frac = (capacity - total_weight) / weights[i]
            total_value += frac * values[i]
            total_weight += frac * weights[i]
            break
    return total_value
