// https://leetcode.com/problems/sort-array-by-increasing-frequency
// IMP
// Yes, in a pair (first, second) used inside a min-heap (priority queue with greater<pi>),
// if the frequencies (first value) are the same, it will automatically compare the second value
//  to determine the order.
// // Time Complexity: O(n log n)  
// - O(n) for frequency map construction  
// - O(n log n) for inserting elements into priority queue  
// - O(n log n) for extracting elements from the priority queue  

// Space Complexity: O(n)  
// - O(n) for frequency map  
// - O(n) for priority queue  
// - O(n) for output vector  
