def knapsack_greedy(values, weights, capacity):
    # Calculate value per unit weight for each item
    value_per_weight = [value / weight for value, weight in zip(values, weights)]
    
    # Sort items in decreasing order of value per unit weight
    sorted_items = sorted(range(len(values)), key=lambda k: value_per_weight[k], reverse=True)
    
    total_value = 0
    total_weight = 0
    selected_items = []
    
    for i in sorted_items:
        if total_weight + weights[i] <= capacity:
            total_weight += weights[i]
            total_value += values[i]
            selected_items.append(i)
    
    return total_value, selected_items
