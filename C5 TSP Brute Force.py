import itertools

def tsp_brute_force(graph):
    """
    Computes the shortest path of the Traveling Salesman Problem (TSP) using brute force
    :param graph: an n x n matrix representing the distance between each pair of nodes
    :return: the shortest path of the TSP and its length
    """
    n = len(graph)
    nodes = [i for i in range(n)]
    shortest_path = None
    shortest_path_length = float("inf")

    for path in itertools.permutations(nodes):
        path_length = 0
        for i in range(n - 1):
            path_length += graph[path[i]][path[i+1]]
        path_length += graph[path[-1]][path[0]]  # add the distance from the last node to the first node

        if path_length < shortest_path_length:
            shortest_path = path
            shortest_path_length = path_length

    return shortest_path, shortest_path_length
