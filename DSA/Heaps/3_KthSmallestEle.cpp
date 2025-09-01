//  https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Kth Smallest -> MaxHeap 
// Kth largest -> Minheap 

// four methods to solve 
// arr={10,20,-4,6,18,24,105,118}
// k=3;
// return kth smallest that is 10
// 1) inbulid sort then return arr[k-1]
// 2) selection sort -> sort array upto k elements and return arr[k-1]
// 3) quick sort -> O(n) ,O(n^2) in worst case
//  hint : check and add conditions for pivot == k , pivot < k ,pivot > k(revise on gfg)
// 4) using heap 
    // a )
    // insert in maxheap of size k(BETTER THAN MIN HEAP)
    // tc = O(nlogk)
    // sc = O(k)

    // b)
    // insert in minheap and than remove top element k-1 times
    // tc -> O(nlogn) 
    // tc -> O(n) 

// Time Complexity: O(n log k)
// Space Complexity: O(k)
