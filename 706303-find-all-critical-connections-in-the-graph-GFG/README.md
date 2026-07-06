# [Find all Critical Connections in the Graph](https://www.geeksforgeeks.org/problems/critical-connections/1)
## Hard
A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges where each vertex is distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.
Note: Return the connections in sorted order.
Examples:
Input:
Output: 
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to reach node 0 and 2 from node 1. Also, on removing edge (0, 2), you will not be able to reach node 0and 1 from node 2.
Input:
Output:
2 3
Explanation:
The edge between nodes 2 and 3 is the only Critical connection in the given graph.

Constraints:1 ≤ v, e ≤ 104