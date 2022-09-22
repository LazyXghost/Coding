// ------------
// We can count occurence in sorted array
// By doing binary search and finding first and last occurence
// ------------

// ------- UNBOUNDED BINARY SEARCH -----
// Searching in infinite sized array can be done by increasing range
// We keep on increasing high until a[high] >= key by multiplying with 2
// Time complexity - O(log(pos))
// -------------------------------------

// Search in sorted rotated array - interviewbit Question
// Finding a peak element - If either A[i-1]>=A[i] or A[i]<=A[i+1], then there is peak on respective side
// Two pointer approach - It never misses the pair and find answer in O(n) time.