def activity_selection(start, finish):
    n = len(start)
    activities = []
    i = 0
    for j in range(n):
        if start[j] >= finish[i]:
            activities.append(j)
            i = j
    return activities
