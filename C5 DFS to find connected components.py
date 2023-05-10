# A recursive function to perform DFS traversal
def dfs_util(graph, node, visited):
    visited[node] = True
    print(node, end=' ')
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs_util(graph, neighbor, visited)

# DFS traversal of the graph
def dfs(graph):
    visited = [False] * len(graph)
    for node in range(len(graph)):
        if not visited[node]:
            dfs_util(graph, node, visited)

# Example usage
graph = {
    0: [1, 2],
    1: [0, 2],
    2: [0, 1, 3],
    3: [2]
}

dfs(graph)
