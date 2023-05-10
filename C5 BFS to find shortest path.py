from collections import deque

def bfs_shortest_path(graph, start, end):
    # Initialize a queue for BFS
    queue = deque()
    # Add the start node to the queue
    queue.append(start)
    # Initialize a set to keep track of visited nodes
    visited = set()
    visited.add(start)
    # Initialize a dictionary to keep track of the parent of each node
    parent = {}
    parent[start] = None
    # Loop until the queue is empty
    while queue:
        # Dequeue the next node from the queue
        current_node = queue.popleft()
        # If we have reached the end node, we are done
        if current_node == end:
            # Reconstruct the path from start to end using the parent dictionary
            path = []
            while current_node is not None:
                path.append(current_node)
                current_node = parent[current_node]
            # Reverse the path so that it starts at the start node and ends at the end node
            path.reverse()
            return path
        # Otherwise, add all the neighbors of the current node to the queue
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
                parent[neighbor] = current_node
    # If we reach this point, there is no path from start to end
    return None
