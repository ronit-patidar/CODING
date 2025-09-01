// leetcode 378
// 
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

// Why Do We Push the First Element of Each Row into the Min-Heap?
// Since the matrix is sorted row-wise and column-wise, the smallest element is always in 
// the first row and first column. Instead of inserting all elements (which would take extra space 
//     and time), we use the heap smartly.

// // Time Complexity: O((n + k) log n) ~ Worst case: O(n² log n)
// Space Complexity: O(n)