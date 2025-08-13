Here’s a brief summary of the three:

---

**1. Dijkstra’s Algorithm**

* **Purpose**: Finds shortest paths from a single source to all other vertices.
* **Edge Weights**: Works only with **non-negative** weights.
* **Approach**: Greedy — repeatedly picks the vertex with the smallest tentative distance and relaxes its edges.
* **Time Complexity**:

  * Using min-heap/priority queue: **O((V + E) log V)**.
  * Without heap: **O(V²)**.

---

**2. Bellman–Ford Algorithm**

* **Purpose**: Single-source shortest paths, even when edges have **negative weights**.
* **Extra Feature**: Can detect **negative weight cycles**.
* **Approach**: Dynamic programming — relaxes all edges **V−1** times.
* **Time Complexity**: **O(V·E)**.

---

**3. Floyd–Warshall Algorithm**

* **Purpose**: Finds shortest paths **between all pairs** of vertices.
* **Edge Weights**: Works with positive and negative weights, detects negative cycles.
* **Approach**: Dynamic programming — progressively considers each vertex as an intermediate node in paths.
* **Time Complexity**: **O(V³)**.

---



Got it — I’ll give you **simple, readable Python code** for Dijkstra’s, Bellman–Ford, and Floyd–Warshall, all using the **same example graph**, then explain each.

---

## **Example Graph**

We’ll use this directed weighted graph (adjacency list form):

```
A ---4---> B
A ---2---> C
B ---3---> C
B ---2---> D
B ---3---> E
C ---1---> B
C ---4---> D
D ---2---> E
E ---1---> D
```

Numbering vertices:

```
A=0, B=1, C=2, D=3, E=4
```

---

## **1. Dijkstra’s Algorithm** (No negative weights)

```python
import heapq

def dijkstra(graph, start):
    dist = {v: float('inf') for v in graph}
    dist[start] = 0
    pq = [(0, start)]  # (distance, vertex)

    while pq:
        curr_dist, u = heapq.heappop(pq)
        if curr_dist > dist[u]:
            continue
        for v, w in graph[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist

graph = {
    0: [(1, 4), (2, 2)],
    1: [(2, 3), (3, 2), (4, 3)],
    2: [(1, 1), (3, 4)],
    3: [(4, 2)],
    4: [(3, 1)]
}

print("Dijkstra:", dijkstra(graph, 0))
```

**Explanation:**

* Starts from node `A(0)`, always expands the closest unvisited node.
* Uses a **priority queue** to efficiently get the next nearest node.
* `dist` holds the shortest distance found so far.

---

## **2. Bellman–Ford Algorithm** (Handles negative weights)

```python
def bellman_ford(edges, V, start):
    dist = [float('inf')] * V
    dist[start] = 0

    for _ in range(V - 1):
        for u, v, w in edges:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    # Check for negative cycles
    for u, v, w in edges:
        if dist[u] + w < dist[v]:
            return "Negative cycle detected"

    return dist

edges = [
    (0, 1, 4), (0, 2, 2),
    (1, 2, 3), (1, 3, 2), (1, 4, 3),
    (2, 1, 1), (2, 3, 4),
    (3, 4, 2),
    (4, 3, 1)
]

print("Bellman-Ford:", bellman_ford(edges, 5, 0))
```

**Explanation:**

* Relaxes **all edges** `V-1` times to ensure shortest paths are found.
* Can detect **negative cycles** after main loop.

---

## **3. Floyd–Warshall Algorithm** (All pairs shortest paths)

```python
def floyd_warshall(matrix):
    V = len(matrix)
    dist = [row[:] for row in matrix]  # Copy matrix

    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

INF = float('inf')
matrix = [
    [0,   4,   2, INF, INF],
    [INF, 0,   3,   2,   3],
    [INF, 1,   0,   4, INF],
    [INF, INF, INF, 0,   2],
    [INF, INF, INF, 1,   0]
]

result = floyd_warshall(matrix)
print("Floyd-Warshall:")
for row in result:
    print(row)
```

**Explanation:**

* `matrix[i][j]` holds the shortest distance from `i` to `j`.
* Iteratively considers each node as an **intermediate** point in the path.

---

✅ **When to use which:**

* **Dijkstra** → Fastest for positive weights, single-source.
* **Bellman–Ford** → Use if negative edges exist or you need negative cycle detection.
* **Floyd–Warshall** → Best for all-pairs shortest paths with small graphs.

---

If you want, I can now **visualize the example graph** so you can follow the steps of all three algorithms more intuitively. That will make it crystal clear.


If you want, I can make you a **side-by-side comparison table** so the differences are crystal clear.
