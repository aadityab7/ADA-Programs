import heapq


def prim(graph):
    """Implementation of Prim's algorithm to find minimum spanning tree of a given graph.
    graph is a dictionary of dictionaries representing the weighted graph.
    Returns a list of edges in the minimum spanning tree.
    """
    visited = set()
    start_vertex = list(graph.keys())[0]  # start with any vertex
    visited.add(start_vertex)

    edges = []
    for neighbor, weight in graph[start_vertex].items():
        heapq.heappush(edges, (weight, start_vertex, neighbor))

    mst = []
    while edges:
        weight, u, v = heapq.heappop(edges)
        if v not in visited:
            visited.add(v)
            mst.append((u, v, weight))
            for neighbor, weight in graph[v].items():
                if neighbor not in visited:
                    heapq.heappush(edges, (weight, v, neighbor))
    return mst
