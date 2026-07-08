# [Maximum path sum in matrix](https://www.geeksforgeeks.org/problems/path-in-matrix3805/1)
## Medium
You are given a matrix mat[][] of size n x&nbsp;m where each element is a positive integer. Starting from any cell in the first row, you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, you can move to any of the three possible positions :

(r+1, c-1) — move diagonally to the left.
(r+1, c) — move directly down.
(r+1, c+1) — move diagonally to the right.

Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.
Examples :
Input: mat[][] = [[3, 6, 1], [2, 3, 4], [5, 5, 1]]
Output: 15
Explaination: The best path is (0, 1) -&gt; (1, 2) -&gt; (2, 1). It gives the maximum sum as 15.
Input: mat[][] = [[2, 1, 1], [1, 2, 2]]
Output: 4
Explaination: The best path is (0, 0) -&gt; (1, 1). It gives the maximum sum as 4.
Input: mat[][] = [[25]]
Output: 25
Explaination: (0, 0) is the only cell in mat[][], so maximum path sum will be 25.
Constraints:1 ≤ mat.size() ≤ 5001 ≤ mat[i].size() ≤ 5001 ≤ mat[i][j] ≤ 1000