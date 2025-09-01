// to find the maximum sum subbarray


// https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/

// 🧠 Intuition (Kadane’s Algorithm):
// We maintain two variables:

// maxEnding: maximum subarray sum ending at the current index.

// res: overall maximum subarray sum so far.

// At each step:

// You decide whether to:

// Continue the previous subarray: maxEnding + arr[i]

// Start a new subarray at index i: just arr[i]

// Take the maximum of both:
// maxEnding = max(maxEnding + arr[i], arr[i])

// Then update the result:
// res = max(res, maxEnding)