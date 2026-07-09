# [Minimum sum partition](https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1)
## Hard
Given an array&nbsp;arr[] &nbsp;containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.
Examples:
Input: arr[] = [1, 6, 11, 5]
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11 Hence, minimum difference is 1.  
Input: arr[] = [1, 4]
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4Hence, minimum difference is 3.
Input: arr[] = [1]
Output: 1
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {}, sum of Subset2 = 0Hence, minimum difference is 1.
Constraints:1 ≤ arr.size()*|sum of array elements| ≤ 1051 &lt;= arr[i] &lt;= 105