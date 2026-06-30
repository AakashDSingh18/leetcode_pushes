# [Shortest path in Directed Acyclic Graph](https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1)
## Medium
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
Find the shortest path from src(0) vertex&nbsp;to all the vertices&nbsp;and if it is impossible to reach any vertex, then return&nbsp;-1 for that vertex.
Examples :
Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]Explanation: Shortest path from 0 to 1 is 0-&gt;1 with edge weight 2. Shortest path from 0 to 2 is 0-&gt;2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]Explanation: Shortest path from 0 to 1 is 0-&gt;1 with edge weight 2. Shortest path from 0 to 2 is 0-&gt;4-&gt;2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0-&gt;4-&gt;5-&gt;3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0-&gt;4 with edge weight 1.Shortest path from 0 to 5 is 0-&gt;4-&gt;5 with edge weight 1+4=5.
Constraint:1 &lt;= V &lt;= 1001 &lt;= E &lt;= min((N*(N-1))/2,4000)0 &lt;= edgesi,0, edgesi,1&nbsp;&lt;&nbsp;n0 &lt;=&nbsp;edgei,2&nbsp;&lt;=105