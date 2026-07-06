# [Minimum travel time](https://www.geeksforgeeks.org/problems/minimum-travel-time/1)
## Hard
You are given an&nbsp;n x n&nbsp;integer matrix&nbsp;grid&nbsp;where each value&nbsp;grid[i][j] represents the height of the&nbsp;cell&nbsp;(i, j).
You can travel from a cell to another 4-directionally adjacent cell if and only the height of both the cells are at most T. You can travel infinite distances in zero time but&nbsp;you must stay within the boundaries of the grid during your travel.
You are currently at cell (0, 0) and the value of T is 0 and you wish to go to cell (n-1,n-1).
Find the minimum time it will take to reach the cell (n, n) if the value of T increase by 1 every second.
&nbsp;
Example 1:
Input:20 21 3Output:3Explanation:At time 0, you are in grid location (0, 0).You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.You cannot reach point (1, 1) until time 3.When time T&nbsp;is 3, we can swim anywhere inside the grid.
&nbsp;
Example 2:
Input:40 1 2 412 13 14 915 5&nbsp;11 103 6 7 8&nbsp;Output:10
&nbsp;
Your Task:You don't need to read or print anything. Your task is to complete the function Solve() which takes an integer n denoting no. of rows and columns&nbsp;of the grid and a matrix grid[][] denoting the grid and return the maximum group of connected group of 1s.
&nbsp;
Constraints:

1 &lt;= n&lt;= 50
0 &lt;= grid[i][j] 
Each value in grid is unique

&nbsp;