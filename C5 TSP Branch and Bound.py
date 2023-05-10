import numpy as np
import heapq

def tsp_bb(dist):
    n = dist.shape[0]
    best_cost = float('inf')
    best_tour = None
    heap = []
    # root node
    heap.append((0, [0], set(range(1, n))))
    while heap:
        lower_bound, tour, unvisited = heapq.heappop(heap)
        if lower_bound >= best_cost:
            continue
        if not unvisited:
            tour.append(0)
            cost = sum(dist[tour[i], tour[i+1]] for i in range(n))
            if cost < best_cost:
                best_cost = cost
                best_tour = tour
        else:
            for v in unvisited:
                new_tour = tour + [v]
                new_unvisited = unvisited - {v}
                new_lower_bound = lower_bound + min(dist[v, u] for u in new_unvisited)
                if new_lower_bound < best_cost:
                    heapq.heappush(heap, (new_lower_bound, new_tour, new_unvisited))
    return best_cost, best_tour
